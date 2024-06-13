#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hpp_files/player.hpp"
#include "hpp_files/catan.hpp"
#include "hpp_files/board.hpp"

using namespace ariel;

TEST_CASE("Player::placeSettelemnt, placeRoad, placeCity") {
    Player p1("Amit");
    Player p2("adam");
    Player p3("david");

    Catan catan(p1,p2,p3);

    Board &board = catan.getBoard();

    p1.setOre(5);
    p1.setWheat(5);
    
    std::vector<std::string> places = {"Forest", "Mountains", "Hills"};
    std::vector<int> placesNum = {3, 8, 10};
    CHECK_NOTHROW(p1.placeSettelemnt(places, placesNum, board));
    CHECK_NOTHROW(p1.placeCity(places, placesNum, board));

    places = {"Forest", "Mountains", "Hills"};
    placesNum = {3, 8, 10};
    CHECK_THROWS_AS(p1.placeSettelemnt(places, placesNum, board), std::runtime_error); // Invalid placement

    places = {"Forest", "Mountains"};
    placesNum = {3, 8};
    CHECK_NOTHROW(p1.placeRoad(places, placesNum, board));
}

TEST_CASE("Catan::rollDice") {
    Player p1("Amit"), p2("Yossi"), p3("Dana");
    Catan game(p1, p2, p3);

    CHECK_NOTHROW(game.rollDice(p1));
    CHECK_NOTHROW(game.endTurn(p1));
    CHECK_THROWS_AS(game.rollDice(p1), std::runtime_error); // Not p1's turn again
}

TEST_CASE("Catan::endTurn") {
    Player p1("Amit"), p2("Yossi"), p3("Dana");
    Catan game(p1, p2, p3);

    CHECK_NOTHROW(game.endTurn(p1));
}

TEST_CASE("Catan::trade") {
    Player p1("Amit"), p2("Yossi"), p3("Dana");
    Catan game(p1, p2, p3);
    p1.setWood(2);
    p2.setBricks(2);

    CHECK_NOTHROW(game.trade(p1, p2, "wood", "brick", 1, 1));
}

TEST_CASE("Catan::playDevelopmentCard") {
    Player p1("Amit"), p2("Yossi"), p3("Dana");
    Catan game(p1, p2, p3);
    Board& board = game.getBoard();
    p2.setOre(30);
    p2.setWool(30);
    p2.setWheat(30);

    CHECK_NOTHROW(p1.placeSettelemnt({"Pasture Land", "Hills", "Forest"}, {5, 8, 3}, board));

    for(int i=0;i<30;i++){
        CHECK_NOTHROW(p2.buyDevelopmentCard(););
    }

    CHECK_NOTHROW(game.playDevelopmentCard(p2, {"Hills", "Forest"}, {8, 3}, {"Pasture Land", "Hills"}, {5, 8}, board));
    CHECK_NOTHROW(game.playDevelopmentCard(p2, "wool"));
    CHECK_NOTHROW(game.playDevelopmentCard(p2, "wood", "ore"));
    CHECK_NOTHROW(game.playDevelopmentCard(p2));
}

TEST_CASE("Catan::printWinner") {
    Player p1("Amit"), p2("Yossi"), p3("Dana");
    Catan game(p1, p2, p3);

    // Just check that the function doesn't throw any exceptions
    CHECK_NOTHROW(game.printWinner());
}
