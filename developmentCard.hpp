#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "player.hpp"
#include "tile.hpp"
#include "board.hpp"

using namespace std;

namespace ariel {

    enum DevelopmentCardType {
        KNIGHT,
        VICTORY_POINT,
        ROAD_BUILDING,
        YEAR_OF_PLENTY,
        MONOPOLY
    };

    class DevelopmentCard {
    public:
        DevelopmentCard(DevelopmentCardType type);
        virtual ~DevelopmentCard() = default; // Virtual destructor for polymorphism
        virtual std::string getType() const = 0; // Abstract method for polymorphism
        virtual void play(Player& player) = 0; // Pure virtual method
        virtual void play(Player& player, vector<string> places1, vector<int> placesNum1, vector<string> places2, vector<int> placesNum2, Board& board) { }
        virtual void play(Player& player, std::vector<Player>& players) { }
        virtual void play(Player& player, string resource1, string resource2) { }
    private:
        DevelopmentCardType type;
    };

    class KnightCard : public DevelopmentCard {
    public:
        KnightCard();
        std::string getType() const override;
        void play(Player& player) override;
        static Tile* getKnight();
        static void setKnight(const std::string& terrain, int number);
    private:
        static Tile* knight;
    };

    class VictoryPointCard : public DevelopmentCard {
    public:
        VictoryPointCard();
        std::string getType() const override;
        void play(Player& player) override;
    };

    class MonopolyCard : public DevelopmentCard {
    public:
        MonopolyCard();
        std::string getType() const override;
        void play(Player& player, vector<Player>& players) override;
    };

    class RoadBuildingCard : public DevelopmentCard {
    public:
        RoadBuildingCard();
        std::string getType() const override;
        void play(Player& player, vector<string> places1, vector<int> placesNum1, vector<string> places2, vector<int> placesNum2, Board& board) override;
    };

    class YearOfPlentyCard : public DevelopmentCard {
    public:
        YearOfPlentyCard();
        std::string getType() const override;
        void play(Player& player, string resource1, string resource2) override;
    };

}

#endif // DEVELOPMENTCARD_HPP
