SRC_DIR = ../src
OBJ_DIR = ../obj
INC_DIR = -I../include -I../extern/glfw-3.3/include -I../extern/glew-2.1.0/include
OUT_DIR = ../bin
LIB_DIR = -L../extern/glfw-3.3/build/src
LIBS    = -lglfw3 -lX11 -lGL

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

SRC_FILES := $(call rwildcard, $(SRC_DIR), *.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

LINKER_FLAGS = -shared

ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
    detected_OS := Windows
	EXTENSION := dll --out-implib
else
	COMP_FLAGS := -fPIC -std=c++17 -D_PCS_DEBUG
	EXTENSION := so
    detected_OS := $(shell uname)  # same as "uname -s"
endif

empty = 
space = $(empty) $(empty)

EXE_NAME = perceus

# Linux = .so
# MacOS = .dylib
# Windows = .dll

main: $(OBJ_FILES)
	g++ $(LINKER_FLAGS) -o $(OUT_DIR)/lib$(EXE_NAME).$(EXTENSION) $^ ../obj/glew.o $(LIB_DIR) $(LIBS)

clean:
	rm $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(COMP_FLAGS) -c -o $@ $< $(INC_DIR)
	
glew:
	g++ -fPIC --static -DGLEW_STATIC -c -o $(OBJ_DIR)/glew.o ../extern/glew-2.1.0/src/glew.c -I../extern/glew-2.1.0/include

run:
	../$(EXE_NAME).$(EXTENSION)
