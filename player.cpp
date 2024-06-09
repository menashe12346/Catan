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

    void Player::getCards(const Tile &tile) {
        if (tile.terrain == "Mountains") {
            this->ore += 1;
        } else if (tile.terrain == "Forest") {
            this->wood += 1;
        } else if (tile.terrain == "Agricultural_Land") {
            this->wheat += 1;
        } else if (tile.terrain == "Pasture_Land"){
            this->wool += 1;
        }  else if (tile.terrain == "Hills") {
            this->bricks += 1;
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
                                cout <<"1" << endl;

        Tile tile1 (places[0], placesNum[0]);
        Tile tile2 (places[1], placesNum[1]);
        Tile tile3 (places[2], placesNum[2]);
                                cout <<"2" << endl;

        Settlement settlement(this->name, tile1, tile2, tile3);
        if((this->isPossibleSettlement(settlement) || board.settlements.size()<6) && board.isPossibleSettlement(settlement)){
                                    cout <<"3" << endl;

            board.settlements.insert(settlement);
                        cout <<"4" << endl;

            //when we put the first settlements
            if(board.settlements.size()<6){
                this->getCards(tile1);
                this->getCards(tile2);
                this->getCards(tile3);
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
        cout <<"Settlement placed succesfully" << endl;
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

    // Function to roll two dice
    void Player::rollDice(Player &p2, Player &p3) {
        // Seed the random number generator with the current time
        srand(static_cast<unsigned int>(time(nullptr)));
        
        // Generate two random numbers between 1 and 6
        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1;
        int sum = die1 + die2;

        for(auto &settlement : this->mySettlements)
        {
            for(auto &tile : settlement.nearby_areas)
            {
                if(tile.number == sum){
                    this->getCards(tile);
                }
            }
        }

        for(auto &settlement : p2.mySettlements)
        {
            for(auto &tile : settlement.nearby_areas)
            {
                if(tile.number == sum){
                    p2.getCards(tile);
                }
            }
        }

        for(auto &settlement : p3.mySettlements)
        {
            for(auto &tile : settlement.nearby_areas)
            {
                if(tile.number == sum){
                    p3.getCards(tile);
                }
            }
        }

        cout << this->name << " rolled the dices and got " << sum <<endl;
    }

    void Player::endTurn(){
        
    }
    void Player::trade(Player anotherPlayer, string, string, int, int){
        anotherPlayer.name="";

    }
    void Player::buyDevelopmentCard(){

    }
    void Player::printPoints(){

    }
}