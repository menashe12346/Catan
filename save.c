/*
enum class Terrain {
    Mountains,
    Forest,
    Pasture_Land,
    Agricultural_Land,
    Hills
};
*/

/*
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

*/

/*
void Player::playDevelopmentCard(MonopolyCard& card, std::vector<Player>& players) {
        std::vector<Player> playerPtrs = {&players[0], &players[1]};  // Vector of pointers to players
        card.play(*this, playerPtrs);  // Calls the overloaded play method for MonopolyCard
    }

    void Player::playDevelopmentCard(RoadBuildingCard& card, vector<string> places1, vector<int> placesNum1, vector<string> places2, vector<int> placesNum2, Board board) 
    {
        card.play(*this, places1, placesNum1, places2, placesNum2, board);
    }

    void Player::playDevelopmentCard(YearOfPlentyCard& card, string resource1, string resource2) 
    {
        card.play(*this, resource1, resource2);
    }


        void playDevelopmentCard(MonopolyCard& card, std::vector<Player>& players);  // Overloaded for MonopolyCard
        void playDevelopmentCard(RoadBuildingCard& card, vector<string> places1, vector<int> placesNum1, vector<string> places2, vector<int> placesNum2, Board board); // Overloaded for RoadBuildingCard
        void playDevelopmentCard(YearOfPlentyCard& card, string resource1, string resource2);
*/