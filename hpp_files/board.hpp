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
    private:
        std::vector<Tile> tiles;     ///< Vector of tiles on the board
        std::set<Road> roads;        ///< Set of roads on the board
        std::set<Settlement> settlements; ///< Set of settlements on the board
        std::set<City> Cities;       ///< Set of cities on the board

    public:

        /// @brief Default constructor to initialize the board with tiles
        Board();

        /// @brief Get the tiles on the board
        /// @return A constant reference to the vector of tiles
        std::vector<Tile>& getTiles();

        /// @brief Get the roads on the board
        /// @return A constant reference to the set of roads
        std::set<Road>& getRoads();

        /// @brief Get the settlements on the board
        /// @return A constant reference to the set of settlements
        std::set<Settlement>& getSettlements();

        /// @brief Get the cities on the board
        /// @return A constant reference to the set of cities
        std::set<City>& getCities();

        /// @brief Assignment operator to assign one board to another
        /// @param other The other board to assign from
        /// @return Reference to the assigned board
        Board& operator=(const Board& other);

        /// @brief Check if a road can be placed on the board
        /// @param road The road to check
        /// @return True if the road can be placed, false otherwise
        bool isPossibleRoad(const Road& road) const;

        /// @brief Check if a settlement can be placed on the board
        /// @param settlement The settlement to check
        /// @param city The city to check
        /// @return True if the settlement can be placed, false otherwise
        bool isPossibleSettlement(const Settlement& settlement, const City& city) const;
    };
} // namespace ariel

#endif // BOARD_HPP