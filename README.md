# Project Overview

This project involves the implementation of a C++ program that models a game environment using `Tile` and `Road` classes. These classes are designed to be used in hash-based containers like `std::unordered_set`.

## Tile Class

To use `Tile` objects in `std::unordered_set`, the following features were added:

1. **Default Constructor**:
   - Required to create `Tile` objects without initial values, ensuring compatibility with the container.

2. **Equality Operator (`operator==`)**:
   - Enables comparison between two `Tile` objects, necessary for checking the presence of elements in the set.

3. **Custom Hash Function**:
   - Provides a unique hash value for each `Tile` object, ensuring efficient storage and retrieval in `std::unordered_set`.

## Road Class

To use `Road` objects in `std::unordered_set`, the following features were added:

1. **Equality Operator (`operator==`)**:
   - Enables comparison between two `Road` objects, ensuring that roads connecting the same tiles are considered equal.

2. **Custom Hash Function**:
   - Provides a unique hash value for each `Road` object based on the hash values of the connected `Tile` objects, ensuring proper distribution in `std::unordered_set`.

## Summary

These additions ensure that `Tile` and `Road` objects can be used effectively in hash-based containers, supporting efficient storage, retrieval, and comparison within the game environment.
