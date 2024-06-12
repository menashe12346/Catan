#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"

using namespace std;
using namespace ariel;

int main()
{
    cout << "Creating players..." << endl;
    ariel::Player p1("Amit");
    ariel::Player p2("Yossi");
    ariel::Player p3("Dana");
    cout << "Players created successfully." << endl;

    cout << "Initializing Catan game..." << endl;
    Board board;
    Catan catan(p1, p2, p3);
    cout << "Catan game initialized successfully." << endl;

    cout << "Placing settlements and roads for player 1..." << endl;

    vector<string> places = {"Forest", "Mountains", "Hills"};
    vector<int> placesNum = {3, 8, 10};
    p1.placeSettelemnt(places, placesNum, board);

    places = {"Forest", "Mountains"};
    placesNum = {3, 8};
    p1.placeRoad(places, placesNum, board);

    places = {"Agricultural Land", "Hills", "Mountains"};
    placesNum = {12, 6, 10};
    p1.placeSettelemnt(places, placesNum, board);

    places = {"Agricultural Land", "Hills"};
    placesNum = {12, 6};
    p1.placeRoad(places, placesNum, board);

    cout << "Settlements and roads for player 1 placed successfully." << endl;

    cout << "Placing settlements and roads for player 2..." << endl;

    places = {"Mountains", "Pasture Land", "Sea"};
    placesNum = {8, 5, 0};
    p2.placeSettelemnt(places, placesNum, board);

    try
    {
        p3.placeSettelemnt(places, placesNum, board); // p3 tries to place a settlement in the same location as p2.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    places = {"Mountains", "Pasture Land"};
    placesNum = {8, 5};
    p2.placeRoad(places, placesNum, board);

    places = {"Forest", "Pasture Land", "Hills"};
    placesNum = {9, 4, 10};
    p2.placeSettelemnt(places, placesNum, board);

    places = {"Forest", "Pasture Land"};
    placesNum = {9, 4};
    p2.placeRoad(places, placesNum, board);

    cout << "Settlements and roads for player 2 placed successfully." << endl;

    cout << "Placing settlements and roads for player 3..." << endl;

    places = {"Mountains", "Pasture Land", "Sea"};
    placesNum = {10, 2, 0};
    p3.placeSettelemnt(places, placesNum, board);

    places = {"Mountains", "Pasture Land"};
    placesNum = {10, 2};
    p3.placeRoad(places, placesNum, board);

    places = {"Agricultural Land", "Pasture Land", "Pasture Land"};
    placesNum = {4, 5, 11};
    p3.placeSettelemnt(places, placesNum, board);

    places = {"Agricultural Land", "Pasture Land"};
    placesNum = {4, 5};
    p3.placeRoad(places, placesNum, board);

    cout << "Settlements and roads for player 3 placed successfully." << endl;

    cout << "Player 1's turn actions..." << endl;
    catan.rollDice(p1);                                    // Simulating dice roll for player 1
    p1.placeRoad({"Forest", "Hills"}, {5, 6}, board); // Placing a road for player 1
    catan.endTurn(p1);                                     // Ending turn for player 1
    cout << "Player 1's turn actions completed." << endl;

    cout << "Player 2's turn actions..." << endl;
    catan.rollDice(p2); // Simulating dice roll for player 2
    catan.endTurn(p2);  // Ending turn for player 2
    cout << "Player 2's turn actions completed." << endl;

    cout << "Player 3's turn actions..." << endl;
    catan.rollDice(p3); // Simulating dice roll for player 3
    catan.endTurn(p3);  // Ending turn for player 3
    cout << "Player 3's turn actions completed." << endl;

    try{
        catan.rollDice(p2); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    catan.rollDice(p1);                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
    catan.trade(p1, p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    catan.endTurn(p1);                        // p1 ends his turn.

    catan.rollDice(p2);           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    for(int i=0;i<30;i++){
    p2.buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
    }

    vector<string> places1 = {"Pasture Land", "Hills"};
    vector<int> placesNum1 = {4, 10};
    vector<string> places2 = {"Mountains", "sea"};
    vector<int> placesNum2 = {8, 0};
    catan.playDevelopmentCard(p2, places1, placesNum1, places2, placesNum2, board); // the turn ends right after

    places = {"Agricultural Land", "Pasture Land", "Pasture Land"};
    placesNum = {4, 5, 11};
    p3.placeCity(places, placesNum, board);

    return 0;
}
