INC_DIR := include/
OBJ_DIR := obj/
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix $(OBJ_DIR),$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -g -std=c++11 -I $(INC_DIR)


calculator: $(OBJ_FILES)
	g++ -o $@ $(CC_FLAGS) $^

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

obj/%.o: src/%.cpp
	g++ $(CC_FLAGS) -c -o $@ $<

clean:
	rm -rf obj
	rm calculator
