#include "MonopolyCard.hpp"

namespace ariel {

void MonopolyCard::play(Player& player, std::vector<std::reference_wrapper<ariel::Player>> players, const std::string& resource) {
    for (auto& other_player_ref : players) {
        Player& other_player = other_player_ref.get();  // Dereference the reference wrapper
        if (&other_player != &player) {
            player.takeAllResources(other_player, resource);
        }
    }
    std::cout << "Monopoly card played by " << player.getName() << ": All " << resource << " taken from other players." << std::endl;
}

} // namespace ariel
