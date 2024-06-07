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
    Catan catan(p1, p2, p3);
    cout << "Catan game initialized successfully." << endl;

    // Starting of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer(); // should print the name of the starting player, assume it is Amit.
    Board board = catan.getBoard(); // get the board of the game.

    vector<string> places = {"Forest", "Mountains", "Desert"};
    vector<int> placesNum = {3, 8, 10};
    p1.placeSettelemnt(places, placesNum, board);

    places = {"Forest", "Mountains"};
    placesNum = {3, 8};
    p1.placeRoad(places, placesNum, board);

    return 0;
}
