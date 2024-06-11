#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <set>
#include <string>

using namespace std;

namespace ariel {
    class Tile {
    public:
        std::string terrain;
        int number;
        std::set<Tile*> nearby_areas;

        // Constructors
        Tile(); // Default constructor
        Tile(const std::string& terrain, int number);

        // Copy constructor
        Tile(const Tile& other);

        //Getters and Setters
        string getTerrain() const;
        int getNumber() const;
        void setTerrain(const std::string& terrain);
        void setNumber(int number);

        // Assignment operator
        Tile& operator=(const Tile& other);

        // Comparison operators
        bool operator==(const Tile& other) const;
        bool operator!=(const Tile& other) const;
        bool operator<(const Tile& other) const;

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Tile& tile);
    };
}

#endif // TILE_HPP
