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

    class DevelopmentCard;
    class MonopolyCard;
    class KnightCard;
    class RoadBuildingCard;
    class YearOfPlentyCard;

    class Player {
    private:
        void showCards() const;
    public:
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

        Player();
        Player(string name);
        string getName() const;
        bool isPossibleRoad(Road myRoad);
        bool isPossibleSettlement(Settlement mySettelemnt);
        void placeSettelemnt(vector<string> places, vector<int> placesNum, Board &board);
        void placeRoad(vector<string> places, vector<int> placesNum, Board &board);
        void placeCity(vector<string> places, vector<int> placesNum, Board &board);
        void distributeResources(int num);
        void getCards(string resource, int amount);
        bool resource_exist(string resource, int num);
        void discardCards();
        void takeAllResources(Player &other, string resource);
        void playDevelopmentCard(KnightCard& card);
        void buyDevelopmentCard();
        void printPoints();

        bool operator==(const Player &player) const;
    };
}

#endif
