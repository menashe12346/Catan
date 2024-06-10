//326648532
//menashe7676@gmail.com

#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include <iostream>
#include <set>
#include "tile.hpp"

using namespace std;

namespace ariel {
    class Settlement {
    private:

    public:
        string nameOfOwner;
        set<Tile>nearby_areas;

        Settlement();
        Settlement(string nameOfOwner, Tile tile1, Tile tile2, Tile tile3);

        bool operator==(const Settlement& other) const;
        bool operator<(const Settlement& other) const;

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Settlement& settlement);
};

}


#endif
