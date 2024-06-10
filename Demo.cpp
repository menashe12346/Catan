#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"

using namespace std;
using namespace ariel;

int main()
{
    cout << "Creating players..." << endl;
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    cout << "Players created successfully." << endl;

    cout << "Initializing Catan game..." << endl;
    Board board;
    Catan catan(p1, p2, p3);
    cout << "Catan game initialized successfully." << endl;

    cout << "Placing settlements and roads for player 1..." << endl;

    vector<string> places = {"Forest", "Mountains", "Desert"};
    vector<int> placesNum = {3, 8, 10};
    p1.placeSettelemnt(places, placesNum, board);

    places = {"Forest", "Mountains"};
    placesNum = {3, 8};
    p1.placeRoad(places, placesNum, board);

    places = {"Agricultural Land", "Desert", "Mountains"};
    placesNum = {12, 6, 10};
    p1.placeSettelemnt(places, placesNum, board);

    places = {"Agricultural Land", "Desert"};
    placesNum = {12, 6};
    p1.placeRoad(places, placesNum, board);

    cout << "Settlements and roads for player 1 placed successfully." << endl;

    cout << "Placing settlements and roads for player 2..." << endl;
    places = {"Mountains", "Pasture Land", "Sea"};
    placesNum = {8, 5, 0};
    p2.placeSettelemnt(places, placesNum, board);
    places = {"Mountains", "Pasture Land"};
    placesNum = {8, 5};
    p2.placeRoad(places, placesNum, board);
    cout << "Settlements and roads for player 2 placed successfully." << endl;

    cout << "Placing settlements and roads for player 3..." << endl;
    places = {"Mountains", "Pasture Land", "Sea"};
    placesNum = {10, 2, 0};
    p3.placeSettelemnt(places, placesNum, board);
    p3.placeRoad(places, placesNum, board);
    cout << "Settlements and roads for player 3 placed successfully." << endl;

    cout << "Player 1's turn actions..." << endl;
    p1.rollDice(p2, p3);                                    // Simulating dice roll for player 1
    p1.placeRoad({"Forest", "Hills"}, {5, 6}, board); // Placing a road for player 1
    p1.endTurn();                                     // Ending turn for player 1
    cout << "Player 1's turn actions completed." << endl;

    cout << "Player 2's turn actions..." << endl;
    p2.rollDice(p2, p3); // Simulating dice roll for player 2
    p2.endTurn();  // Ending turn for player 2
    cout << "Player 2's turn actions completed." << endl;

    cout << "Player 3's turn actions..." << endl;
    p3.rollDice(p2, p3); // Simulating dice roll for player 3
    p3.endTurn();  // Ending turn for player 3
    cout << "Player 3's turn actions completed." << endl;

    return 0;
}
