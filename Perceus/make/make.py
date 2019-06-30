import os, datetime, time, sys

class CompilerSettings:
    def __init__(self, include_directories = [], library_directories = [], libs = [], comp_settings = [], static = False, compiler = "g++"):
        self.compiler = compiler
        self.include_directories = include_directories
        self.libs = libs
        self.library_directories = library_directories
        self.comp_settings = comp_settings
        self.static = static
        self.extra_objs = []

    def outFile(self, outFile, directory, extension = ".o"):
        if self.compiler == "g++":
            return "-o " + directory + "/" + outFile.name + extension

    def compFlagsForLibrary(self, ):
        if self.compiler == "g++":
            setts = (" ").join(self.comp_settings)

            if self.static:
                setts += "--static"

            return setts + " -c"

    def libraryLink(self, LIBRARY = True):
        if self.compiler == "g++" and LIBRARY:
            return "-shared"

        return " "

    def includes(self, projDir):
        if self.compiler == "g++":
            return "-I" + projDir + (" -I" + projDir).join(self.include_directories)

    def libraries(self, projDir):
        r = ""

        if len(self.library_directories) > 0:
            r += " -L" + projDir + (" -L" + projDir).join(self.library_directories)

        if len(self.libs) > 0:
            r += " -l" + (" -l").join(self.libs)

        return r

class colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class SourceFile:
    def __init__(self, DIR, include_directories, project_dir, exists = True):
        self.name = DIR.split("/")[len(DIR.split("/")) - 1].split(".")[0]
        self.fileLocation = DIR
        self.project_dir = project_dir
        self.include_directories = include_directories
        self.dependancies = self.getDependancies()

        if exists:
            statbuff = os.stat(DIR)
            self.modificationTime = statbuff.st_mtime

    def setModTimeNow(self):
        date = datetime.datetime.now()
        modTime = time.mktime(date.timetuple())
        os.utime(self.fileLocation, (modTime, modTime))

        for x in range(len(self.dependancies)):
            self.dependancies[x].setModTimeNow()

    def dependenciesChanged(self):
        diff = 100

        for dep in self.dependancies:
            if dep.modificationTime - self.modificationTime > diff:
                return True

        return False

    def getDependancies(self):
        fin = []
        if self.fileLocation.split(".")[len(self.fileLocation.split(".")) - 1].lower() == 'cpp':
            includes = []

            with open(self.fileLocation, 'r') as f:
                for line in f:
                    if line.strip()[:len('#include "')] == '#include "':
                        includes.append(line.strip())

            for x in range(len(includes)):
                includes[x] = includes[x][10:-1]

            for loc in self.include_directories:
                if os.path.isdir(self.project_dir + loc):
                    for name in includes:
                        if os.path.exists(self.project_dir + loc + "/" + name):
                            fin.append(SourceFile(self.project_dir + loc + "/" + name, self.include_directories, self.project_dir))

        return fin
            


class Project:
    def __init__(self, name, settings, project_dir = "./", bin_dir = "bin", obj_dir = "obj", src_dir = "src", shared = True, link = True):
        self.settings    = settings
        self.linkProject = link
        self.project_dir = project_dir
        self.src_dir     = src_dir
        self.obj_dir     = obj_dir
        self.bin_dir     = bin_dir
        self.shared      = shared
        self.name        = name

        self.source_files = []

        self.project_folders = {
            src_dir: False, obj_dir: False, bin_dir: False
        }

        for key in self.project_folders.keys():
            if not os.path.isdir(self.project_dir + key):
                print(colors.WARNING + "Missing folder [ " + colors.BOLD + project_dir + key + colors.ENDC + colors.WARNING + " ]. Creating" + colors.ENDC)
                os.mkdir(project_dir + key)

        print (colors.OKGREEN + "Project [ " + colors.BOLD + name + colors.ENDC + colors.OKGREEN + " ] initialized successfully" + colors.ENDC)

    def execCommand(self, command, prnt = False):
        if (prnt):
            print(command)
        os.system(command)

    def make(self):
        obj_files, files = self.collectSourceFiles()

        self.logInfo("Collected " + colors.BOLD + str(len(files)) + colors.ENDC + colors.OKGREEN + " source file(s) to compile")

        for f in files:
            self.compileSource(f)

        if self.linkProject:
            self.link()

    def clean(self):
        self.logInfo("Cleaning object directory ")
        for f in os.listdir(self.project_dir + self.obj_dir):
            os.remove(self.project_dir + self.obj_dir + "/" + f)

    def recompile(self):
        self.logInfo("Recompiling project")
        self.clean()
        self.make()

    def compileSource(self, srcFile):
        self.logInfo("Compiling to file " + colors.BOLD + self.project_dir + self.obj_dir + "/" + srcFile.name + colors.ENDC + colors.OKGREEN + "")
        self.execCommand(
            self.settings.compiler + " " + 
            self.settings.compFlagsForLibrary() + " " + 
            self.settings.outFile(srcFile, self.project_dir + self.obj_dir) + " " +
            srcFile.fileLocation + " " +
            self.settings.includes(self.project_dir),
            False
        )
        srcFile.setModTimeNow()

    def logInfo(self, message):
        print(colors.OKGREEN + "[ " + colors.BOLD + self.name + colors.ENDC + colors.OKGREEN + " ]: " + message + colors.ENDC)

    def link(self):
        word = ["executable", "", ""]

        if sys.platform == "win32":
            word[1] = ".exe"

        if self.shared: 
            word = ["library", "", "lib"]
            if sys.platform == "win32":
                if not self.settings.static:
                    word[1] = ".dll"
                else:
                    word[1] = ".lib"

            if sys.platform == "linux":
                if not self.settings.static:
                    word[1] = ".so"
                else:
                    word[1] = ".a"
            

        fileName = word[2] + self.name.lower() + word[1]
        self.logInfo("Linking to " + word[0] + " file: " + colors.BOLD + self.project_dir + self.bin_dir + "/" + fileName)

        obj_files, srcs = self.collectSourceFiles(False)

        self.execCommand(
            self.settings.compiler + " " +
            self.settings.libraryLink(self.shared) + " " +
            self.settings.outFile(SourceFile(fileName, self.settings.include_directories, self.project_dir, False), self.project_dir + self.bin_dir, word[1]) + " " +
            (" ").join([x.fileLocation for x in obj_files]) + " " +
            self.settings.libraries(self.project_dir),
            False
        )

    def collectSourceFiles(self, prt = True):
        # Total src file objects
        files     = []
        # Amount of compiled .o files
        obj_files = []
        # Src files that (a) dont have a .o file or (b) are out of date
        toCompile = []

        def skimFolder(folder):
            fs = []
            for f in os.listdir(folder):
                if not "." in f:
                    fs += skimFolder(folder + "/" + f)
                else:
                    fs.append( SourceFile(folder + "/" + f, self.settings.include_directories, self.project_dir) )
            return fs
        
        # Populate the files list
        files = skimFolder(self.project_dir + self.src_dir)

        if prt:
            self.logInfo("Collected " + colors.BOLD + str(len(files)) + colors.ENDC + colors.OKGREEN + " source file(s)")

        # Populate the obj_files list
        obj_files = skimFolder(self.project_dir + self.obj_dir)

        if prt:
            self.logInfo("Collected " + colors.BOLD + str(len(obj_files)) + colors.ENDC + colors.OKGREEN + " object file(s)")

        diff = 100
        for src in files:
            found = False

            for obj in obj_files:
                if src.name == obj.name:
                    # Check mod time
                    if obj.modificationTime - src.modificationTime < 0:# or src.dependenciesChanged():
                        found = False
                    else:
                        found = True
                    break
            
            if not found:
                toCompile.append(src)
                
        return (obj_files, toCompile)

def run(projects):
    if len(sys.argv) - 1 == 0:
        for proj in projects:
            proj.make()

    elif sys.argv[1].lower() == "make":
        for proj in projects:
            proj.make()

    elif sys.argv[1].lower() == "clean":
        for proj in projects:
            proj.clean()

    elif sys.argv[1].lower() == "recompile":
        for proj in projects:
            proj.recompile()


if __name__ == "__main__":
    glewSettings = CompilerSettings(["include"], [], [], ["-g", "", "-DGLEW_STATIC", "-fPIC "], True)
    glewProj = Project("glew", glewSettings, "./Perceus/extern/glew-2.1.0/", "", "../../obj", link = False)
    #glewProj.make()

    settings = CompilerSettings(["include", "extern/glfw-3.3/include", "extern/glew-2.1.0/include"], ["extern/glfw-3.3/build/src"], ["glfw3", "X11", "GL"], ["-g", "", "-std=c++17", "-O1", "-fPIC", "-D_PCS_DEBUG"])
    project = Project("Perceus", settings, "./Perceus/")
    #project.make()

    clientSettings = CompilerSettings(["../src/headers", "../Perceus/include"], ["../Perceus/bin"], ["perceus"], ["-std=c++17"])
    clientProject = Project("Client", clientSettings, "./Client/", shared = False)
    #clientProject.make()

    projects = [glewProj, project, clientProject]
    run(projects)
