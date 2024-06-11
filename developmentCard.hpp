#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "tile.hpp"
#include "board.hpp"

// Forward declaration
class Player;

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
        virtual void play(Player& player, std::vector<Player>&) { }
        virtual void play(Player& player, std::vector<std::string>, std::vector<int>, std::vector<std::string>, std::vector<int>, Board&) { }
        virtual void play(Player& player, std::string, std::string) { }
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
        void play(Player& player) override;  // Pure virtual method implementation
        void play(Player& player, std::vector<Player>& players) override;
    };

    class RoadBuildingCard : public DevelopmentCard {
    public:
        RoadBuildingCard();
        std::string getType() const override;
        void play(Player& player) override;  // Pure virtual method implementation
        void play(Player& player, std::vector<std::string> places1, std::vector<int> placesNum1, std::vector<std::string> places2, std::vector<int> placesNum2, Board& board) override;
    };

    class YearOfPlentyCard : public DevelopmentCard {
    public:
        YearOfPlentyCard();
        std::string getType() const override;
        void play(Player& player) override;  // Pure virtual method implementation
        void play(Player& player, std::string resource1, std::string resource2) override;
    };

}

#endif // DEVELOPMENTCARD_HPP
