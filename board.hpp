#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "tile.hpp"
#include "settlement.hpp"
#include "city.hpp"
#include "road.hpp"

using namespace std;

namespace ariel {
    class Board {
    public:
        std::vector<Tile> tiles;
        std::set<Road> roads;
        std::set<Settlement> settlements;
        std::set<City> Cities;

        Board();
        Board(const Board& other);             // Copy constructor
        Board& operator=(const Board& other);  // Assignment operator
        bool isPossibleRoad(const Road& road) const;
        bool isPossibleSettlement(const Settlement& settlement) const;
    };
}

#endif // BOARD_HPP
