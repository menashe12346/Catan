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

namespace ariel {
    class Board {
    public:
        std::vector<Tile> tiles;
        std::set<Road> roads;
        std::set<Settlement> settlements;

        Board();
        bool isPossibleRoad(const Road& road) const;
        bool isPossibleSettlement(const Settlement& settlement) const;
    };
}

#endif // BOARD_HPP
