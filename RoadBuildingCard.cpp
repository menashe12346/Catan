#include "RoadBuildingCard.hpp"

namespace ariel {

void RoadBuildingCard::play(Player& player, std::vector<std::string> places1, std::vector<int> placesNum1, std::vector<std::string> places2, std::vector<int> placesNum2, Board& board) {
    player.bricks += 2; // because the player is placing 2 roads
    player.wood += 2;
    player.placeRoad(places1, placesNum1, board);
    player.placeRoad(places2, placesNum2, board);
    std::cout << "Road Building card played by " << player.getName() << ": You can build two roads without cost." << std::endl;
}

} // namespace ariel
