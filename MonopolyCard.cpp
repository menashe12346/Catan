#include "MonopolyCard.hpp"

namespace ariel {

void MonopolyCard::play(Player& player, std::vector<Player*>& players) {
    std::string resource;
    std::cout << "Enter the resource you want to monopolize: ";
    std::cin >> resource;
    for (auto& other_player : players) {
        if (other_player != &player) {
            player.takeAllResources(*other_player, resource);
        }
    }
    std::cout << "Monopoly card played by " << player.getName() << ": All " << resource << " taken from other players." << std::endl;
}

} // namespace ariel
