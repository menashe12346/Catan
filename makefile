CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
SRC = board.cpp catan.cpp Demo.cpp player.cpp
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
