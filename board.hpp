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
    private:


    public:
        vector<Tile> tiles;
        set<Road> roads;
        set<Settlement> settlements;
        bool isPossibleRoad(Road road);
        bool isPossibleSettlement(Settlement settlement);
        Board();

    };

}

#endif
