    /*

#include "tile_hash.hpp"

// Define the hash function outside the header
std::size_t std::hash<ariel::Tile>::operator()(const ariel::Tile& t) const {
    return std::hash<std::string>()(t.terrain) ^ std::hash<int>()(t.number);
    std::hash<std::string>()(t.terrain): Generates a hash value for the terrain string.
    std::hash<int>()(t.number): Generates a hash value for the number integer.
    ^ (bitwise XOR): Combines these two hash values into a single hash value.

}
    */

