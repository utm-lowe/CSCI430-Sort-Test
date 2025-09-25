CXX := g++
CXXFLAGS := -g -std=c++17 -Wall -Wextra -O2 -Iinclude -Isorts

SRC := $(wildcard src/*.cpp sorts/*.cpp)
SORTS := $(wildcard sorts/*.h)
OBJ := $(SRC:.cpp=.o)

BIN := sort-test

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

src/%.o: src/%.cpp include/%.hpp include/sorts.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

sorts/%.o: sorts/%.cpp sorts/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

include/sorts.h: $(SORTS)
	./sortGen.sh	

clean:
	rm -f $(OBJ) $(BIN) include/sorts.h
