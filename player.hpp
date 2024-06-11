//326648532
//menashe7676@gmail.com

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <memory> 
#include <string>
#include "developmentCard.hpp"
#include "board.hpp"
#include "tile.hpp"
#include "settlement.hpp"
#include "city.hpp"
#include "road.hpp"

using namespace std;

class DevelopmentCard; // Forward declaration

namespace ariel {
    class Player {
    private:
        void showCards() const;
        std::vector<std::unique_ptr<DevelopmentCard>> developmentCards;
    public:
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
        void placeSettelemnt(vector<string> places, vector<int> placesNum,Board &board);
        void placeRoad(vector<string> places, vector<int> placesNum,Board &board);
        void placeCity(vector<string> places, vector<int> placesNum,Board &board);
        void distributeResources(int num);
        void getCards(string resource, int amount);
        bool resource_exist(string resource, int num);
        void discardCards();
        void takeAllResources(Player &other, string resource);
        void playDevelopmentCard(DevelopmentCard& card);
        void playDevelopmentCard(DevelopmentCard& card, std::vector<Player>& players);  // Overloaded for MonopolyCard
        void playDevelopmentCard(DevelopmentCard& card, vector<string> places1, vector<int> placesNum1, vector<string> places2, vector<int> placesNum2, Board board); // Overloaded for RoadBuildingCard
        void playDevelopmentCard(DevelopmentCard& card, string resource1, string resource2); 
        void buyDevelopmentCard();
        void printPoints();

        bool operator==(const Player &player) const;
    };
}

#endif