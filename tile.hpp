#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <set>

namespace ariel {
    class Tile {
    public:
        std::string terrain;
        int number;
        std::set<Tile*> nearby_areas;

        // Constructors
        Tile();
        Tile(const std::string& terrain, int number);

        // Copy constructor
        Tile(const Tile& other);

        // Assignment operator
        Tile& operator=(const Tile& other);

        // Destructor
        ~Tile();

        // Comparison operators
        bool operator==(const Tile& other) const;
        bool operator<(const Tile& other) const;

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Tile& tile);
    };
}

#endif // TILE_HPP
