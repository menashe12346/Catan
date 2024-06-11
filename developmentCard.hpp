#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <iostream>


// Forward declaration
namespace ariel {
class Player;

class DevelopmentCard {
public:
    virtual ~DevelopmentCard() = default; // Virtual destructor for polymorphism
};

} // namespace ariel

#endif // DEVELOPMENTCARD_HPP
