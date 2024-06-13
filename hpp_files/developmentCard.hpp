#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <iostream>

namespace ariel {

// forward declaration
class Player;

class DevelopmentCard {
public:
    /// @brief Virtual destructor for polymorphism
    virtual ~DevelopmentCard() = default;
};

} // namespace ariel

// Since DevelopmentCard is an abstract base class, it may not have any implementation.

#endif // DEVELOPMENTCARD_HPP
