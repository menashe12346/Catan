#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <memory>
#include <string>
#include <algorithm>
#include "board.hpp"
#include "tile.hpp"
#include "settlement.hpp"
#include "city.hpp"
#include "road.hpp"

using namespace std;

namespace ariel {

    // forward declaration
    class DevelopmentCard;
    class MonopolyCard;
    class KnightCard;
    class RoadBuildingCard;
    class YearOfPlentyCard;

    class Player {
    private:

        std::vector<std::unique_ptr<DevelopmentCard>> developmentCards;
        string name;
        set<Settlement> possibleSettlements;
        set<Road> possibleRoads;
        set<Settlement> mySettlements;
        set<Road> myRoads;
        set<City> myCities;

        int wood; // עץ
        int bricks; // לבנה
        int wheat; // שיבולת
        int ore; // ברזל
        int wool; // צמר 

        /// @brief Check if a road placement is possible
        /// @param myRoad The road to check
        /// @return True if the road can be placed, false otherwise
        bool isPossibleRoad(Road myRoad);

        /// @brief Check if a settlement placement is possible
        /// @param mySettelemnt The settlement to check
        /// @return True if the settlement can be placed, false otherwise
        bool isPossibleSettlement(Settlement mySettelemnt);

        /// @brief Displays the player's development cards
        void showCards() const;

    public:

        /// @brief Parameterized constructor
        /// @param name Player's name
        Player(string name);

        /// @brief Get the player's name
        /// @return The player's name
        string getName() const;

        /// @brief Set the player's name
        /// @param name The player's name
        void setName(const string& name);

        /// @brief Get the player's development cards
        /// @return A reference to the development cards
        std::vector<std::unique_ptr<DevelopmentCard>>& getDevelopmentCards();

        /// @brief Get the player's settlements
        /// @return A reference to the settlements
        const set<Settlement>& getSettlements() const;

        /// @brief Get the player's roads
        /// @return A reference to the roads
        const set<Road>& getRoads() const;

        /// @brief Get the player's cities
        /// @return A reference to the cities
        const set<City>& getCities() const;

        /// @brief Get the player's wood amount
        /// @return The player's wood amount
        int getWood() const;

        /// @brief Set the player's wood amount
        /// @param amount The wood amount
        void setWood(int amount);

        /// @brief Get the player's brick amount
        /// @return The player's brick amount
        int getBricks() const;

        /// @brief Set the player's brick amount
        /// @param amount The brick amount
        void setBricks(int amount);

        /// @brief Get the player's wheat amount
        /// @return The player's wheat amount
        int getWheat() const;

        /// @brief Set the player's wheat amount
        /// @param amount The wheat amount
        void setWheat(int amount);

        /// @brief Get the player's ore amount
        /// @return The player's ore amount
        int getOre() const;

        /// @brief Set the player's ore amount
        /// @param amount The ore amount
        void setOre(int amount);

        /// @brief Get the player's wool amount
        /// @return The player's wool amount
        int getWool() const;

        /// @brief Set the player's wool amount
        /// @param amount The wool amount
        void setWool(int amount);

        /// @brief Place a settlement on the board
        /// @param places Names of the places
        /// @param placesNum Numbers of the places
        /// @param board The game board
        void placeSettelemnt(vector<string> places, vector<int> placesNum, Board &board);

        /// @brief Place a road on the board
        /// @param places Names of the places
        /// @param placesNum Numbers of the places
        /// @param board The game board
        void placeRoad(vector<string> places, vector<int> placesNum, Board &board);

        /// @brief Place a city on the board
        /// @param places Names of the places
        /// @param placesNum Numbers of the places
        /// @param board The game board
        void placeCity(vector<string> places, vector<int> placesNum, Board &board);

        /// @brief Get cards of a specific resource
        /// @param resource The resource to get
        /// @param amount The amount to get
        void getCards(string resource, int amount);

        /// @brief Check if the player has enough of a specific resource
        /// @param resource The resource to check
        /// @param num The required amount
        /// @return True if the player has enough, false otherwise
        bool resource_exist(string resource, int num);

        /// @brief Discard cards when the dice number is 7
        void discardCards();

        /// @brief Distribute resources based on the dice number
        /// @param num The dice number
        void distributeResources(int num);

        /// @brief Take all resources of a specific type from another player
        /// @param other The player to take resources from
        /// @param resource The resource type to take
        void takeAllResources(Player &other, string resource);

        /// @brief Buy a development card
        void buyDevelopmentCard();

        /// @brief Get the player's points
        /// @return The player's points
        int myPoints();

        /// @brief Print the player's points
        void printPoints();

        /// @brief Print all information about the player
        void printAllInfo();

        /// @brief Equality operator
        /// @param player The other player to compare with
        /// @return True if the players are equal, false otherwise
        bool operator==(const Player &player) const;
    };
}

#endif // PLAYER_H