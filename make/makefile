SRC_DIR = ../src
OBJ_DIR = ../obj
INC_DIR = ../include
OUT_DIR = ../bin

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

SRC_FILES := $(call rwildcard, $(SRC_DIR), *.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

LINKER_FLAGS = -shared

ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
    detected_OS := Windows
	EXTENSION := dll --out-implib
else
	COMP_FLAGS := -fPIC
	EXTENSION := so
    detected_OS := $(shell uname)  # same as "uname -s"
endif


EXE_NAME = perceus

# Linux = .so
# MacOS = .dylib
# Windows = .dll

main: $(OBJ_FILES)
	g++ $(LINKER_FLAGS) -o $(OUT_DIR)/lib$(EXE_NAME).$(EXTENSION) $^

clean:
	rm $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(COMP_FLAGS) -c -o $@ $< -I$(INC_DIR)
	
run:
	../$(EXE_NAME).$(EXTENSION)