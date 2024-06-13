#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hpp_files/board.hpp"
#include "hpp_files/tile.hpp"
#include "hpp_files/player.hpp"
#include "hpp_files/city.hpp"
#include "hpp_files/settlement.hpp"
#include "hpp_files/road.hpp"
#include "hpp_files/developmentCard.hpp"
#include "hpp_files/knightCard.hpp"
#include "hpp_files/MonopolyCard.hpp"
#include "hpp_files/RoadBuildingCard.hpp"
#include "hpp_files/YearOfPlentyCard.hpp"
#include "hpp_files/VictoryPointCard.hpp"

using namespace ariel;

// Test cases for game initialization and setup

TEST_CASE("Board Initialization") {
    Board board;
    board.initialize();
    CHECK(board.getTileCount() == 19);
}

TEST_CASE("Tile Initialization") {
    Tile tile;
    tile.initialize();
    CHECK(tile.getResourceType() != ResourceType::NONE);
}

TEST_CASE("Player Initialization") {
    Player player("Alice");
    player.initialize();
    CHECK(player.getResourceCount() == 0);
    CHECK(player.getVictoryPoints() == 0);
}

TEST_CASE("City Initialization") {
    City city;
    city.initialize();
    CHECK(city.getLevel() == 1);
}

TEST_CASE("Settlement Initialization") {
    Settlement settlement;
    settlement.initialize();
    CHECK(settlement.getLevel() == 1);
}

TEST_CASE("Road Initialization") {
    Road road;
    road.initialize();
    CHECK(road.getLength() == 1);
}

// Test cases for game mechanics

TEST_CASE("Place Initial Settlements") {
    Board board;
    Player player("Alice");
    board.placeInitialSettlements(player);
    CHECK(player.getSettlementCount() == 1);
}

TEST_CASE("Place Road") {
    Board board;
    Player player("Alice");
    board.placeRoad(player, 1, 2);
    CHECK(player.getRoadCount() == 1);
}

TEST_CASE("Place Settlement") {
    Board board;
    Player player("Alice");
    board.placeSettlement(player, 1);
    CHECK(player.getSettlementCount() == 1);
}

TEST_CASE("Place City") {
    Board board;
    Player player("Alice");
    board.placeCity(player, 1);
    CHECK(player.getCityCount() == 1);
}

TEST_CASE("Collect Resources") {
    Board board;
    Player player("Alice");
    board.collectResources(player);
    CHECK(player.getResourceCount() > 0);
}

TEST_CASE("Build Settlement") {
    Player player("Alice");
    player.buildSettlement();
    CHECK(player.getSettlementCount() == 1);
}

TEST_CASE("Build Road") {
    Player player("Alice");
    player.buildRoad();
    CHECK(player.getRoadCount() == 1);
}

TEST_CASE("Build City") {
    Player player("Alice");
    player.buildCity();
    CHECK(player.getCityCount() == 1);
}

// Test cases for development cards

TEST_CASE("Draw Development Card") {
    Player player("Alice");
    DevelopmentCard card = player.drawDevelopmentCard();
    CHECK(card.getType() != DevelopmentCardType::NONE);
}

TEST_CASE("Play Knight Card") {
    Player player("Alice");
    KnightCard knightCard;
    knightCard.play(player);
    CHECK(player.hasUsedDevelopmentCard(knightCard));
}

TEST_CASE("Play Monopoly Card") {
    Player player1("Alice");
    Player player2("Bob");
    MonopolyCard monopolyCard;
    player1.addResource(WHEAT, 5);
    player2.addResource(WHEAT, 3);
    monopolyCard.play(player1, WHEAT);
    CHECK(player1.getResourceCount(WHEAT) == 8);
    CHECK(player2.getResourceCount(WHEAT) == 0);
}

TEST_CASE("Play Road Building Card") {
    Board board;
    Player player("Alice");
    RoadBuildingCard roadBuildingCard;
    roadBuildingCard.play(player, board);
    CHECK(player.getRoadCount() == 2);
}

TEST_CASE("Play Year Of Plenty Card") {
    Player player("Alice");
    YearOfPlentyCard yearOfPlentyCard;
    yearOfPlentyCard.play(player, WHEAT, WOOD);
    CHECK(player.getResourceCount(WHEAT) == 1);
    CHECK(player.getResourceCount(WOOD) == 1);
}

TEST_CASE("Play Victory Point Card") {
    Player player("Alice");
    VictoryPointCard victoryPointCard;
    victoryPointCard.play(player);
    CHECK(player.getVictoryPoints() == 1);
}