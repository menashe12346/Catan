CXX = g++
CXXFLAGS = -std=c++14 -Wall -I./hpp_files

TARGET = catan
SOURCES = Demo.cpp cpp_files/MonopolyCard.cpp cpp_files/RoadBuildingCard.cpp \
          cpp_files/YearOfPlentyCard.cpp cpp_files/board.cpp cpp_files/catan.cpp \
          cpp_files/city.cpp cpp_files/knightCard.cpp cpp_files/player.cpp \
          cpp_files/road.cpp cpp_files/settlement.cpp cpp_files/tile.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
