#include "board.hpp"
#include <array>

namespace ariel {

    Board::Board() : tiles(19) {
        // Initialize the board with 19 tiles
        tiles[0] = {"Mountains", 9};
        tiles[1] = {"Pasture Land", 2};
        tiles[2] = {"Forest", 9};
        tiles[3] = {"Agricultural Land", 12};
        tiles[4] = {"Hills", 6};
        tiles[5] = {"Pasture Land", 4};
        tiles[6] = {"Hills", 10};
        tiles[7] = {"Agricultural Land", 9};
        tiles[8] = {"Forest", 11};
        tiles[9] = {"Desert", 0};
        tiles[10] = {"Forest", 3};
        tiles[11] = {"Mountains", 8};
        tiles[12] = {"Forest", 8};
        tiles[13] = {"Mountains", 3};
        tiles[14] = {"Agricultural Land", 4};
        tiles[15] = {"Pasture Land", 5};
        tiles[16] = {"Hills", 5};
        tiles[17] = {"Agricultural Land", 6};
        tiles[18] = {"Pasture Land", 11};

        // Initialize neighbors using indices
        tiles[0].nearby_areas = { &tiles[1], &tiles[3], &tiles[4] };
        tiles[1].nearby_areas = { &tiles[0], &tiles[2], &tiles[4], &tiles[5] };
        tiles[2].nearby_areas = { &tiles[1], &tiles[5], &tiles[6] };
        tiles[3].nearby_areas = { &tiles[0], &tiles[4], &tiles[7], &tiles[8] };
        tiles[4].nearby_areas = { &tiles[0], &tiles[1], &tiles[3], &tiles[5], &tiles[8], &tiles[9] };
        tiles[5].nearby_areas = { &tiles[1], &tiles[2], &tiles[4], &tiles[6], &tiles[9], &tiles[10] };
        tiles[6].nearby_areas = { &tiles[2], &tiles[5], &tiles[10], &tiles[11] };
        tiles[7].nearby_areas = { &tiles[3], &tiles[8], &tiles[12] };
        tiles[8].nearby_areas = { &tiles[3], &tiles[4], &tiles[7], &tiles[9], &tiles[12], &tiles[13] };
        tiles[9].nearby_areas = { &tiles[4], &tiles[5], &tiles[8], &tiles[10], &tiles[13], &tiles[14] };
        tiles[10].nearby_areas = { &tiles[5], &tiles[6], &tiles[9], &tiles[11], &tiles[14], &tiles[15] };
        tiles[11].nearby_areas = { &tiles[6], &tiles[10], &tiles[15] };
        tiles[12].nearby_areas = { &tiles[7], &tiles[8], &tiles[16] };
        tiles[13].nearby_areas = { &tiles[8], &tiles[9], &tiles[16], &tiles[17] };
        tiles[14].nearby_areas = { &tiles[9], &tiles[10], &tiles[17], &tiles[18] };
        tiles[15].nearby_areas = { &tiles[10], &tiles[11], &tiles[18] };
        tiles[16].nearby_areas = { &tiles[12], &tiles[13], &tiles[17] };
        tiles[17].nearby_areas = { &tiles[13], &tiles[14], &tiles[16], &tiles[18] };
        tiles[18].nearby_areas = { &tiles[14], &tiles[15], &tiles[17] };
    }

    bool Board::isPossibleRoad(const Road& road) const {
        auto it = roads.find(road);
        if (it != roads.end()) {
            // Dereference the iterator to access the Road object and print its nameOfOwner
            cout << it->nameOfOwner << endl;
            return false;
        }
        return true;
    }

    bool Board::isPossibleSettlement(const Settlement& settlement) const {
        for (const auto& settlement : settlements) {
                // Ensure there are at least 3 elements in nearby_areas
                if (settlement.nearby_areas.size() >= 3) {
                    auto it = settlement.nearby_areas.begin();
                    auto tile1 = *it;
                    ++it;
                    auto tile2 = *it;
                    ++it;
                    auto tile3 = *it;

                    cout << tile1 << endl;
                    cout << tile2 << endl;
                    cout << tile3 << endl;
                } else {
                    cout << "Not enough nearby areas for settlement: " << settlement << endl;
                }
        }
                            cout << settlement << endl;
        auto it = settlements.find(settlement);
        if (it != settlements.end()) {
            // Dereference the iterator to access the Road object and print its nameOfOwner
            cout << it->nameOfOwner << endl;
            return false;
        }
        return true;    
        }

     // Copy constructor
    Board::Board(const Board& other) : tiles(other.tiles), roads(other.roads), settlements(other.settlements) {
        std::cout << "Board copy constructor called" << std::endl;
    }

    // Assignment operator
    Board& Board::operator=(const Board& other) {
        std::cout << "Board assignment operator called" << std::endl;
        if (this != &other) {
            tiles = other.tiles;
            roads = other.roads;
            settlements = other.settlements;
        }
        return *this;
    }


}
