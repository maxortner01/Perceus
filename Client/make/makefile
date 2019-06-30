SRC_DIR = ../src/source
OBJ_DIR = ../obj
INC_DIR = ,../src/headers,../../Perceus/include
OUT_DIR = ..
LIB_DIR = ../../Perceus/bin

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
CURRENT_PATH := $(shell pwd)

EXE_NAME = main
EXTENSION = 

empty:=
comma:= ,
space:=$(empty) $(empty)

main: $(OBJ_FILES)
	g++ -o $(OUT_DIR)/$(EXE_NAME)$(EXTENSION) $^ -L$(LIB_DIR) -lperceus

clean:
	rm $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -std=c++17 -c -o $@ $< $(subst $(comma),$(space)-I,$(INC_DIR))
	
run:
	../$(EXE_NAME)$(EXTENSION)