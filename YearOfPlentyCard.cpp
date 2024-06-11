#include "YearOfPlentyCard.hpp"

namespace ariel {

void YearOfPlentyCard::play(Player& player, std::string resource1, std::string resource2) {
    player.getCards(resource1, 1);
    player.getCards(resource2, 1);
    std::cout << "Year of Plenty card played by " << player.getName() << ": You received " << resource1 << " and " << resource2 << " from the bank." << std::endl;
}

} // namespace ariel
