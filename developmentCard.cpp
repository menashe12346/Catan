#include "developmentCard.hpp"
#include "player.hpp"  // Include the full definition of Player

namespace ariel {

    DevelopmentCard::DevelopmentCard(DevelopmentCardType type) : type(type) {}

    KnightCard::KnightCard() : DevelopmentCard(KNIGHT) {}

    Tile* KnightCard::knight = nullptr;

    std::string KnightCard::getType() const {
        return "Knight";
    }

    Tile* KnightCard::getKnight() {
        return knight;
    }

    void KnightCard::setKnight(const std::string& terrain, int number) {
        if (knight == nullptr) {
            knight = new Tile(terrain, number);
        } else {
            // Update the existing knight object
            knight->setTerrain(terrain);
            knight->setNumber(number);
        }
    }

    void KnightCard::play(Player& player) {
        string terrain;
        int num;
        std::cout << "Enter a resource and a number of a tile you want to put the knight on (e.g., Agricultural Land 4 ): ";
        std::cin >> terrain >> num;
        Tile knight(terrain, num);
        this->knight = &knight;
        std::cout << "Knight card played by " << player.getName() << ": Move the robber to tile with " << terrain << " and number " << num << std::endl;
    }

    VictoryPointCard::VictoryPointCard() : DevelopmentCard(VICTORY_POINT) {}

    std::string VictoryPointCard::getType() const {
        return "VictoryPoint";
    }

    void VictoryPointCard::play(Player& player) {
        std::cout << "Victory Point card played by " << player.getName() << std::endl;
        // Logic for adding a victory point to the player
    }

    MonopolyCard::MonopolyCard() : DevelopmentCard(MONOPOLY) {}

    std::string MonopolyCard::getType() const {
        return "Progress: Monopoly";
    }

    void MonopolyCard::play(Player& player) {
        std::cout << "Monopoly card played by " << player.getName() << ": Implement your monopoly logic here." << std::endl;
    }

    void MonopolyCard::play(Player& player, std::vector<Player>& players) {
        std::string resource;
        std::cout << "Enter the resource you want to monopolize: ";
        std::cin >> resource;
        for (auto& other_player : players) {
            if (&other_player != &player) {
                player.takeAllResources(other_player, resource);
            }
        }
        std::cout << "Monopoly card played by " << player.getName() << ": All " << resource << " taken from other players." << std::endl;
    }

    RoadBuildingCard::RoadBuildingCard() : DevelopmentCard(ROAD_BUILDING) {}

    std::string RoadBuildingCard::getType() const {
        return "Progress: RoadBuilding";
    }

    void RoadBuildingCard::play(Player& player) {
        std::cout << "Road Building card played by " << player.getName() << ": Implement your road building logic here." << std::endl;
    }

    void RoadBuildingCard::play(Player& player, std::vector<std::string> places1, std::vector<int> placesNum1, std::vector<std::string> places2, std::vector<int> placesNum2, Board& board) {
        player.bricks += 2; // because the player placing 2 roads
        player.wood += 2;
        player.placeRoad(places1, placesNum1, board);
        player.placeRoad(places2, placesNum2, board);
        std::cout << "Road Building card played by " << player.getName() << ": You can build two roads without cost." << std::endl;
    }

    YearOfPlentyCard::YearOfPlentyCard() : DevelopmentCard(YEAR_OF_PLENTY) {}

    std::string YearOfPlentyCard::getType() const {
        return "Progress: YearOfPlenty";
    }

    void YearOfPlentyCard::play(Player& player) {
        std::cout << "Year of Plenty card played by " << player.getName() << ": Implement your year of plenty logic here." << std::endl;
    }

    void YearOfPlentyCard::play(Player& player, std::string resource1, std::string resource2) {
        player.getCards(resource1, 1);
        player.getCards(resource2, 1);
        std::cout << "Year of Plenty card played by " << player.getName() << ": You received " << resource1 << " and " << resource2 << " from the bank." << std::endl;
    }

}
