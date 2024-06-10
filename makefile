CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g
SRC = board.cpp catan.cpp Demo.cpp player.cpp city.cpp road.cpp settlement.cpp tile.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = catan

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
