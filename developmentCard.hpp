#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "player.hpp"
#include "tile.hpp"

using namespace std;

namespace ariel {
    class DevelopmentCard {
    public:
        virtual std::string getType() const = 0; // for polymorphism, making the class abstract. this function also must be overridden because it doesnt have base implementation.
        virtual void play(Player& player) = 0;
    };

    class ProgressCard : public DevelopmentCard {
    public:
    };

    class KnightCard : public DevelopmentCard {
    public:
        std::string getType() const override;
        void play(Player& player) override;
        static Tile* getKnight();
        static void setKnight(const std::string& terrain, int number);
    private:
        static Tile* knight;
    };

    class VictoryPointCard : public DevelopmentCard {
    public:
        std::string getType() const override;
        void play(Player& player) override;
    };

    class MonopolyCard : public ProgressCard {
    public:
        std::string getType() const override;
        void play(Player& player, std::vector<Player>& players) override;
    };

    class RoadBuildingCard : public ProgressCard {
    public:
        std::string getType() const override;
        void play(Player& player) override;
    };

    class YearOfPlentyCard : public ProgressCard {
    public:
        std::string getType() const override;
        void play(Player& player) override;
    };

    #endif
}