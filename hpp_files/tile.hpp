#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <string>
#include <set>

namespace ariel {

class Tile {
private:
    std::string terrain;
    int number;
    std::set<Tile*> nearby_areas;

public:
    /// @brief Default constructor initializing terrain to an empty string and number to 0
    Tile();

    /// @brief Parameterized constructor
    /// @param terrain The type of terrain for the tile
    /// @param number The number assigned to the tile
    Tile(const std::string& terrain, int number);

    /// @brief Copy constructor
    /// @param other The tile object to copy from
    Tile(const Tile& other);

    /// @brief Get the terrain type
    /// @return The terrain type as a string
    std::string getTerrain() const;

    /// @brief Get the number assigned to the tile
    /// @return The number as an integer
    int getNumber() const;

    /// @brief Set the terrain type
    /// @param terrain The terrain type to set
    void setTerrain(const std::string& terrain);

    /// @brief Set the number assigned to the tile
    /// @param number The number to set
    void setNumber(int number);

    /// @brief Getter for nearby_areas
    /// @return A constant reference to the set of nearby tiles
    const std::set<Tile*>& getNearbyAreas() const;

    /// @brief Set nearby areas for the tile
    /// @param nearbyTiles A list of pointers to the nearby tiles
    void setNearbyAreas(const std::initializer_list<Tile*>& nearbyTiles);

    /// @brief Assignment operator
    /// @param other The tile object to assign from
    /// @return The current tile object
    Tile& operator=(const Tile& other);

    /// @brief Equality operator
    /// @param other The tile object to compare with
    /// @return True if the tiles are equal, false otherwise
    bool operator==(const Tile& other) const;

    /// @brief Inequality operator
    /// @param other The tile object to compare with
    /// @return True if the tiles are not equal, false otherwise
    bool operator!=(const Tile& other) const;

    /// @brief Less-than operator (to make a set)
    /// @param other The tile object to compare with
    /// @return True if the current tile is less than the other, false otherwise
    bool operator<(const Tile& other) const;

    /// @brief Output operator implementation
    /// @param os The output stream
    /// @param tile The tile object to output
    /// @return The output stream
    friend std::ostream& operator<<(std::ostream& os, const Tile& tile);
};

} // namespace ariel

#endif // TILE_HPP