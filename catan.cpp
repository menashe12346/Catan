#include "catan.hpp"

namespace ariel {
    Catan::Catan(Player& p1, Player& p2, Player& p3) : player1(p1), player2(p2), player3(p3),currentPlayer(&player1) {
        std::srand(std::time(nullptr)); // Seed the random number generator once
        std::cout << "Catan game constructor called." << std::endl;
        std::cout << "Catan game initialized with players: " << player1.name << ", " << player2.name << ", " << player3.name << std::endl;
        std::cout << "Starting player is " << (*currentPlayer).name << std::endl;
    }

    void Catan::rollDice(Player& player) {
        if(*currentPlayer == player)
        {
            // Generate two random numbers between 1 and 6
            int die1 = rand() % 6 + 1;
            int die2 = rand() % 6 + 1;
            int sum = die1 + die2;        
            cout << player.name << " rolled the dices and got " << sum << endl;
            if(sum == 7){
                player1.discardCards();
                player2.discardCards();
                player3.discardCards();
                string terrain;
                int num;
                std::cout << "Enter a resource and a number of a tile you want to put the knight on (e.g., Agricultural Land 4 ): ";
                std::cin >> terrain >> num;
                KnightCard::setKnight(terrain, num);
            } else{
                player1.distributeResources(sum);
                player2.distributeResources(sum);
                player3.distributeResources(sum);
            }
        }else{
            cout << "its not " + player.getName() + "'s turn, its now " + (*currentPlayer).getName() + "'s turn" << endl;
        }
    }

    void Catan::endTurn(Player& player) {
        if (currentPlayer == &player) {
            std::cout << player.getName() << "'s turn has ended." << std::endl;
            if (currentPlayer == &player1) {
                currentPlayer = &player2;
            } else if (currentPlayer == &player2) {
                currentPlayer = &player3;
            } else {
                currentPlayer = &player1;
            }
            std::cout << "It's now " << currentPlayer->getName() << "'s turn." << std::endl;
        } else {
            std::cout << "It's not your turn to end, it's now " << currentPlayer->getName() << "'s turn" << std::endl;
        }
    }

    void Catan::trade(Player &First_Player, Player &Second_Player, string resource1, string resource2, int num1, int num2){
        if((*this->currentPlayer) == First_Player && First_Player.resource_exist(resource1, num1) && Second_Player.resource_exist(resource2, num2))
        {
        First_Player.getCards(resource1, num1*(-1)); //remove this resource
        First_Player.getCards(resource2, num2);
        Second_Player.getCards(resource2, num2*(-1)); //remove this resource
        Second_Player.getCards(resource1, num1);
        } else {
            cout << "its not " + First_Player.getName() + "'s turn, its now " + (*currentPlayer).getName() + "'s turn" << endl;
        }
    }

    void Catan::playDevelopmentCard(Player &player, string resource) {
        if((*this->currentPlayer) == player){
            // Uses std::find_if to iterate through the developmentCards vector
            auto it = std::find_if(player.developmentCards.begin(), player.developmentCards.end(), [](const std::unique_ptr<DevelopmentCard>& card) {
                return dynamic_cast<MonopolyCard*>(card.get()) != nullptr;
            });

            if (it != player.developmentCards.end()) {
                MonopolyCard* monopolyCard = dynamic_cast<MonopolyCard*>(it->get());
                if (monopolyCard) {
                    std::vector<std::reference_wrapper<ariel::Player>> players = {player1, player2, player3};
                    monopolyCard->play(player, players, resource);  // Play the MonopolyCard
                    player.developmentCards.erase(it);  // Remove the card from the vector
                    std::cout << "Monopoly card played successfully." << std::endl;
                    this->endTurn(player);  
                }
            } else {
                std::cout << "You do not have a Monopoly card." << std::endl;
            }
        } else {
            cout << "its not " + player.getName() + "'s turn, its now " + (*currentPlayer).getName() + "'s turn" << endl;
        }
    }

    void Catan::playDevelopmentCard(Player &player, std::vector<std::string> places1, std::vector<int> placesNum1, std::vector<std::string> places2, std::vector<int> placesNum2, Board& board) {
        // Check if the current player is the one calling the method
        if (*this->currentPlayer == player) {
            // Use std::find_if to iterate through the developmentCards vector
            auto it = std::find_if(player.developmentCards.begin(), player.developmentCards.end(), [](const std::unique_ptr<DevelopmentCard>& card) {
                return dynamic_cast<RoadBuildingCard*>(card.get()) != nullptr;
            });

            if (it != player.developmentCards.end()) {
                RoadBuildingCard* roadBuildingCard = dynamic_cast<RoadBuildingCard*>(it->get());
                if (roadBuildingCard) {
                    roadBuildingCard->play(player, places1, placesNum1, places2, placesNum2, board);  // Play the RoadBuildingCard
                    player.developmentCards.erase(it);  // Remove the card from the vector
                    std::cout << "Road Building card played successfully." << std::endl;
                    this->endTurn(player);  
                }
            } else {
                std::cout << "You do not have a Road Building card." << std::endl;
            }
        } else {
            std::cout << "It's not " + player.getName() + "'s turn, it's now " + this->currentPlayer->getName() + "'s turn" << std::endl;
        }
    }

    void Catan::playDevelopmentCard(Player& player, const std::string& resource1, const std::string& resource2) {
        // Check if the current player is the one calling the method
        if (*this->currentPlayer == player) {
            // Use std::find_if to iterate through the developmentCards vector
            auto it = std::find_if(player.developmentCards.begin(), player.developmentCards.end(), [](const std::unique_ptr<DevelopmentCard>& card) {
                return dynamic_cast<YearOfPlentyCard*>(card.get()) != nullptr;
            });

            if (it != player.developmentCards.end()) {
                YearOfPlentyCard* yearOfPlentyCard = dynamic_cast<YearOfPlentyCard*>(it->get());
                if (yearOfPlentyCard) {
                    yearOfPlentyCard->play(player, resource1, resource2);  // Play the YearOfPlentyCard
                    player.developmentCards.erase(it);  // Remove the card from the vector
                    std::cout << "Year of Plenty card played successfully." << std::endl;
                    this->endTurn(player);  
                }
            } else {
                std::cout << "You do not have a Year of Plenty card." << std::endl;
            }
        } else {
            std::cout << "It's not " + player.getName() + "'s turn, it's now " + this->currentPlayer->getName() + "'s turn" << std::endl;
        }
    }

    void Catan::playDevelopmentCard(Player& player) {
        // Check if the current player is the one calling the method
        if (*this->currentPlayer == player) {
            // Use std::find_if to iterate through the developmentCards vector
            auto it = std::find_if(player.developmentCards.begin(), player.developmentCards.end(), [](const std::unique_ptr<DevelopmentCard>& card) {
                return dynamic_cast<KnightCard*>(card.get()) != nullptr;
            });

            if (it != player.developmentCards.end()) {
                KnightCard* knightCard = dynamic_cast<KnightCard*>(it->get());
                if (knightCard) {
                    knightCard->play(player);  // Play the KnightCard
                    player.developmentCards.erase(it);  // Remove the card from the vector
                    std::cout << "Knight card played successfully." << std::endl;
                    this->endTurn(player);  
                }
            } else {
                std::cout << "You do not have a Knight card." << std::endl;
            }
        } else {
            std::cout << "It's not " + player.getName() + "'s turn, it's now " + this->currentPlayer->getName() + "'s turn" << std::endl;
        }
    }

    void Catan::printWinner() {
        // Your logic to print the winner
    }
}
