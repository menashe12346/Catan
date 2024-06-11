//326648532
//menashe7676@gmail.com

#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

namespace ariel {
    Player::Player(){
    }

    Player::Player(string name){
        this->name = name;
        this->wood = 10;
        this->bricks = 0;
        this->wheat = 0;
        this->ore = 0;
        this->wool = 0;
    }

    string Player::getName() const {
        return name;
    }

    bool Player::isPossibleRoad(Road myRoad){
        for(const auto& PossibleRoad : this->possibleRoads ){
            if(myRoad==PossibleRoad){
                return true;
            }
        }
        return false;
    }


    bool Player::isPossibleSettlement(Settlement mySettlement){
        for(const auto& PossibleSettlement : this->possibleSettlements ){
            if(mySettlement==PossibleSettlement){
                return true;
            }
        }
        return false;
    }

    void Player::getCards(string resource, int amount) {
        if (resource == "Mountains" || resource == "ore") {
            this->ore += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<" ore" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<" ore" << endl;
            }
        } else if (resource == "Forest" || resource == "wood") {
            this->wood += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<" wood" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<" wood" << endl;
            }
        } else if (resource == "Agricultural Land" || resource == "wheat") {
            this->wheat += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<" wheat" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<" wheat" << endl;
            }
        } else if (resource == "Pasture Land" || resource == "wool"){
            this->wool += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<" wool" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<" wool" << endl;
            }
        }  else if (resource == "Hills" || resource == "brick") {
            this->bricks += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<" brick" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<" bricks" << endl;
            }
        } 
    }

    bool Player::resource_exist(string resource, int num){
        if (resource == "Mountains" || resource == "ore") {
            if(this->ore - num < 0) throw std::runtime_error("Insufficient resources");
        } else if (resource == "Forest" || resource == "wood") {
            if(this->wood - num < 0) throw std::runtime_error("Insufficient resources");
        } else if (resource == "Agricultural Land" || resource == "wheat") {
            if(this->wheat - num < 0) throw std::runtime_error("Insufficient resources");
        } else if (resource == "Pasture Land" || resource == "wool"){
            if(this->wool - num < 0) throw std::runtime_error("Insufficient resources");
        }  else if (resource == "Hills" || resource == "brick") {
            if(this->bricks - num < 0) throw std::runtime_error("Insufficient resources");
        } 
        return true;
    }

    void Player::placeSettelemnt(vector<string> places, vector<int> placesNum,Board &board){
         if (places.size() < 3 || placesNum.size() < 3) {
        // Handle the error (e.g., throw an exception or return early)
        throw std::invalid_argument("Not enough places or placesNum provided");
        }
        if((this->bricks < 1 || this->wood < 1 || this->wheat < 1 || this->wool < 1) && board.settlements.size()>6){
            throw std::runtime_error("Insufficient resources");
        }

        Tile tile1 (places[0], placesNum[0]);
        Tile tile2 (places[1], placesNum[1]);
        Tile tile3 (places[2], placesNum[2]);

        Settlement settlement(this->name, tile1, tile2, tile3);
        if((this->isPossibleSettlement(settlement) || board.settlements.size()<6) && board.isPossibleSettlement(settlement)){
            board.settlements.insert(settlement);
            //when we put the first settlements
            if(board.settlements.size()<=6){
                this->getCards(tile1.terrain, 1);
                this->getCards(tile2.terrain, 1);
                this->getCards(tile3.terrain, 1);
            } else{ 
                this->bricks--;
                this->wood--;
                this->wheat --;
                this->wool--;
            }
            
            Road road1(this->name, tile1, tile2);
            Road road2(this->name, tile1, tile3);
            Road road3(this->name, tile2, tile3);

            this->possibleRoads.insert(road1);
            this->possibleRoads.insert(road2);
            this->possibleRoads.insert(road3);
        }else{
            throw std::runtime_error("cant place settlement here");
        }
        this->mySettlements.insert(settlement);
        cout <<"Settlement placed succesfully: \n" << settlement << endl;
    }

    void Player::placeRoad(vector<string> places, vector<int> placesNum,Board &board){
        if (places.size() < 2 || placesNum.size() < 2) {
        // Handle the error (e.g., throw an exception or return early)
        throw std::invalid_argument("Not enough places or placesNum provided");
        }

        if((this->bricks < 1 || this->wood < 1) && board.settlements.size()>6){
            cout <<"Insufficient resources" << endl;
            return;
        }

        Tile tile1 (places[0], placesNum[0]);
        Tile tile2 (places[1], placesNum[1]);
        Road road(this->name, tile1, tile2);
        if((isPossibleRoad(road) || board.settlements.size()<6) && board.isPossibleRoad(road)){
            this->possibleRoads.erase(road); //remove from possible Roads if exist
            board.roads.insert(road);
            if(board.roads.size() > 6){
                this->bricks--;
                this->wood--;
            }

            // Find the common neighbors(should be 2) between tile1 and tile2
            for (auto& neighbor : tile1.nearby_areas) {
                /*
                tile2.nearby_areas.find(neighbor) searches for the neighbor tile in tile2's nearby_areas.
                If neighbor is found in tile2.nearby_areas, the find function returns an iterator to the element. 
                If not found, it returns tile2.nearby_areas.end().
                end() function returns an iterator to the past-the-end element in the container (i.e to the end of the unordered set)
                */
                if (tile2.nearby_areas.find(neighbor) != tile2.nearby_areas.end()) {
                    Road road1(this->name, tile1, *neighbor); // Dereference the pointer to get the Tile object
                    Road road2(this->name, tile2, *neighbor); // Dereference the pointer to get the Tile object
                    // Insert the roads into the board's road set
                    this->possibleRoads.insert(road1);
                    this->possibleRoads.insert(road2);
                }
            }
        }else{
            throw std::runtime_error("cant place road here");
        }
        this->myRoads.insert(road);
        cout <<"Road placed succesfully" << endl;
    }

    void Player::placeCity(vector<string> places, vector<int> placesNum,Board &board){
         if (places.size() < 3 || placesNum.size() < 3) {
        // Handle the error (e.g., throw an exception or return early)
        throw std::invalid_argument("Not enough places or placesNum provided");
        }
        if(this->ore < 3 || this->wheat < 2){
            cout <<"Insufficient resources" << endl;
            return;
        }
        Tile tile1 (places[0], placesNum[0]);
        Tile tile2 (places[1], placesNum[1]);
        Tile tile3 (places[2], placesNum[2]);
        Settlement settlement(this->name, tile1, tile2, tile3);
        if(this->mySettlements.find(settlement) != this->mySettlements.end()){
            board.settlements.erase(settlement);
        }else{
            throw std::runtime_error("cant place settlement here");
        }
        this->bricks--;
        this->wood--;
        this->wheat --;
        this->wool--;
        City city(this->name, tile1, tile2, tile3);
        this->myCities.insert(city);
        cout <<"City placed succesfully" << endl;
    }

    // Function to get Resources
    void Player::distributeResources(int num) {

        for(const auto &settlement : this->mySettlements)
        {
            for(const auto &tile : settlement.nearby_areas)
            {
                if(tile.number == num && tile != *(KnightCard::getKnight())){
                    this->getCards(tile.terrain, 1);
                }
            }
        }
    }

    void Player::showCards() const {
        std::cout << "Cards of " << this->getName() << ": " << "wood" << ": " << wood << ", " << "wool" << ": " << wool << ", " << "bricks" << ": " << bricks << ", " << "ore" << ": " << ore << ", " <<  "wheat" << ": " << wheat << ", " << std::endl;
    }

    void Player::discardCards() 
    {
        int totalCards = this->bricks + this->ore + this->wheat + this->wood + this->wool;

        if (totalCards > 7) {
            std::cout << this->getName() << " has " << totalCards << " cards and needs to discard " << totalCards / 2 << " cards." << std::endl;

            int cardsToDiscard = totalCards / 2;
            while (cardsToDiscard > 0) {
                std::string resource;
                int amount;
                showCards();
                cout << cardsToDiscard << " cards needs to be discard" << endl;
                std::cout << "Enter the resource to discard and the amount (e.g., wood 2): ";
                std::cin >> resource >> amount;

                if(amount <= cardsToDiscard)
                {
                    if (resource_exist(resource, amount)) {
                        getCards(resource, -amount);
                        cardsToDiscard -= amount;
                    } else {
                        std::cout << "You do not have enough " << resource << " to discard. Try again." << std::endl;
                    }
                } else{
                        std::cout << "too much cards to discard. Try again." << std::endl;
                }
            }

            std::cout << "Discard completed." << std::endl;
        }
    }

    void Player::takeAllResources(Player &other, string resource){
        int count;
        while(other.resource_exist(resource, 1)){
            other.getCards(resource, -1);
            this->getCards(resource, 1);
            count++;
        }
        cout << this->name << " took all " << resource << " from " << other.name << endl;
    }

    void Player::placeTowRoads(){
        string place1, place2;
        int number1, number2;
        
        std::cout << "Enter two places and their numbers for the first road (e.g., Agricultural Land 4 Pasture Land 5): ";
        std::cin >> place1 >> number1 >> place2 >> number2;
        this->placeRoad({place1, place2}, {number1, number2});
    }

    void Player::playDevelopmentCard(DevelopmentCard& card) 
    {
        card.play(*this);
    }

    void Player::buyDevelopmentCard() {
        // Check if the player has enough resources
        bool canBuy = true;
        for (const auto& resource : cost) {
            if (!resource_exist(resource, 1)) {
                canBuy = false;
                break;
            }
        }

        if (canBuy) {
            // Deduct the cost
            for (const auto& resource : cost) {
                getCards(resource, -1);
            }

            // Randomly select a development card type
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(0, 2); // 3 types of cards

            DevelopmentCard* newCard = nullptr;
            int cardType = distr(gen);

            if (cardType == 0) {
                // Randomly select a progress card type
                std::uniform_int_distribution<> progressDistr(0, 2);
                int progressType = progressDistr(gen);
                if (progressType == 0) {
                    newCard = new MonopolyCard();
                } else if (progressType == 1) {
                    newCard = new RoadBuildingCard();
                } else {
                    newCard = new YearOfPlentyCard();
                }
            } else if (cardType == 1) {
                newCard = new KnightCard();
            } else {
                newCard = new VictoryPointCard();
            }

            // Add the new development card to the player's collection
            developmentCards.push_back(newCard);

            std::cout << "Development card bought successfully." << std::endl;
        } else {
            std::cout << "Not enough resources to buy a development card." << std::endl;
        }
    }

    void Player::printPoints(){

    }

    bool Player::operator==(const Player &player) const{
        return this->getName() == player.getName();
    }
}