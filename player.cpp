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
        this->wood = 0;
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
        if (resource == "Mountains") {
            this->ore += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<"ore" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<"ore" << endl;
            }
        } else if (resource == "Forest") {
            this->wood += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<"wood" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<"wood" << endl;
            }
        } else if (resource == "Agricultural Land") {
            this->wheat += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<"wheat" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<"wheat" << endl;
            }
        } else if (resource == "Pasture Land"){
            this->wool += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<"wool" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<"wool" << endl;
            }
        }  else if (resource == "Hills") {
            this->bricks += amount;
            if(amount>0) {
                cout << this->name << " earned " << amount <<"bricks" << endl;
            } else if (amount<0){
                cout << this->name << " lost " << amount <<"bricks" << endl;
            }
        } 
    }

    void Player::placeSettelemnt(vector<string> places, vector<int> placesNum,Board &board){
         if (places.size() < 3 || placesNum.size() < 3) {
        // Handle the error (e.g., throw an exception or return early)
        throw std::invalid_argument("Not enough places or placesNum provided");
        }
        if((this->bricks < 1 || this->wood < 1 || this->wheat < 1 || this->wool < 1) && board.settlements.size()>6){
            cout <<"Insufficient resources" << endl;
            return;
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

        for(auto &settlement : this->mySettlements)
        {
            for(auto &tile : settlement.nearby_areas)
            {
                if(tile.number == num){
                    this->getCards(tile.terrain, 1);
                }
            }
        }
    }

    void Player::buyDevelopmentCard(){

    }
    void Player::printPoints(){

    }

    bool Player::operator==(const Player &player) const{
        return this->getName() == player.getName();
    }
}