# CSES Problem Set Solutions

This repository contains my solutions to problems from the [CSES Problem Set](https://cses.fi/problemset/), a collection of competitive programming practice problems.

## About CSES

The CSES Problem Set is a collection of algorithmic programming problems designed for learning and practicing competitive programming. It covers various topics including:

- Introductory Problems
- Sorting and Searching
- Dynamic Programming
- Graph Algorithms
- Range Queries
- Tree Algorithms
- Mathematics
- String Algorithms
- Geometry
- Advanced Techniques

## Repository Structure

```text
├── introductory_problems/    # Basic problems to get started
├── Dynamic-Programming/      # DP problems and solutions
├── Graph-Algorithms/         # Graph algorithm problems and solutions
└── ...                      # More categories as I progress
```

## Problems Solved

### Introductory Problems

- [Bit Strings](https://cses.fi/problemset/task/1617) - [`introductory_problems/Bit_Strings.cpp`](introductory_problems/Bit_Strings.cpp)
- [Trailing Zeros](https://cses.fi/problemset/task/1618) - [`introductory_problems/Trailing_Zeros.cpp`](introductory_problems/Trailing_Zeros.cpp)
- [Coin Piles](https://cses.fi/problemset/task/1754) - [`introductory_problems/Coin_Piles.cpp`](introductory_problems/Coin_Piles.cpp)

### Dynamic Programming

- [Dice Combinations](https://cses.fi/problemset/task/1633) - [`Dynamic-Programming/Dice_Combinations.cpp`](Dynamic-Programming/Dice_Combinations.cpp)
- [Minimizing Coins](https://cses.fi/problemset/task/1634) - [`Dynamic-Programming/Minimizing_Coins.cpp`](Dynamic-Programming/Minimizing_Coins.cpp)
- [Coin Combinations I](https://cses.fi/problemset/task/1635) - [`Dynamic-Programming/Coin_Combinations_I.cpp`](Dynamic-Programming/Coin_Combinations_I.cpp)
- [Coin Combinations II](https://cses.fi/problemset/task/1636) - [`Dynamic-Programming/Coin_Combinations_II.cpp`](Dynamic-Programming/Coin_Combinations_II.cpp)
- [Removing Digits](https://cses.fi/problemset/task/1637) - [`Dynamic-Programming/Removing_Digits.cpp`](Dynamic-Programming/Removing_Digits.cpp)
- [Grid Paths](https://cses.fi/problemset/task/1638) - [`Dynamic-Programming/Grid_Paths_I.cpp`](Dynamic-Programming/Grid_Paths_I.cpp)
- [Book Shop](https://cses.fi/problemset/task/1158) - [`Dynamic-Programming/Book_Shop.cpp`](Dynamic-Programming/Book_Shop.cpp)
- [Array Description](https://cses.fi/problemset/task/1746) - [`Dynamic-Programming/Array_Description.cpp`](Dynamic-Programming/Array_Description.cpp)  
- [Edit Distance](https://cses.fi/problemset/task/1639) - [`Dynamic-Programming/Edit_Distance.cpp`](Dynamic-Programming/Edit_Distance.cpp)
- [Rectangle Cutting](https://cses.fi/problemset/task/1744) - [`Dynamic-Programming/Rectangle_Cutting.cpp`](Dynamic-Programming/Rectangle_Cutting.cpp)
- [Money Sums](https://cses.fi/problemset/task/1745) - [`Dynamic-Programming/Money_Sums.cpp`](Dynamic-Programming/Money_Sums.cpp)
- [Removal Game](https://cses.fi/problemset/task/1097) - [`Dynamic-Programming/Removal_Game.cpp`](Dynamic-Programming/Removal_Game.cpp)
- [Two Sets II](https://cses.fi/problemset/task/1093) - [`Dynamic-Programming/Two_Sets_II.cpp`](Dynamic-Programming/Two_Sets_II.cpp)
- [Increasing Subsequence](https://cses.fi/problemset/task/1145) - [`Dynamic-Programming/Increasing_Subsequence.cpp`](Dynamic-Programming/Increasing_Subsequence.cpp)
- [Projects](https://cses.fi/problemset/task/1140) - [`Dynamic-Programming/Projects.cpp`](Dynamic-Programming/Projects.cpp)
- [Elevator Rides](https://cses.fi/problemset/task/1653) - [`Dynamic-Programming/Elevator_Rides.cpp`](Dynamic-Programming/Elevator_Rides.cpp)
- [Counting Tilings](https://cses.fi/problemset/task/2181) - [`Dynamic-Programming/Counting_Tilings.cpp`](Dynamic-Programming/Counting_Tilings.cpp)
- [Counting Towers](https://cses.fi/problemset/task/2413) - [`Dynamic-Programming/Counting_Towers.cpp`](Dynamic-Programming/Counting_Towers.cpp)
- [Longest Common Subsequence](https://cses.fi/problemset/task/1143) - [`Dynamic-Programming/Longest_Common_Subsequence.cpp`](Dynamic-Programming/Longest_Common_Subsequence.cpp)
- [Increasing Subsequence II](https://cses.fi/problemset/task/1146) - [`Dynamic-Programming/Increasing_Subsequence_II.cpp`](Dynamic-Programming/Increasing_Subsequence_II.cpp)
- [Mountain Range](https://cses.fi/problemset/task/1141) - [`Dynamic-Programming/Mountain_Range.cpp`](Dynamic-Programming/Mountain_Range.cpp)

### Graph Algorithms

- [Counting Rooms](https://cses.fi/problemset/task/1192) - [`Graph-Algorithms/Counting_Rooms.cpp`](Graph-Algorithms/Counting_Rooms.cpp)
- [Labyrinth](https://cses.fi/problemset/task/1193) - [`Graph-Algorithms/Labyrinth.cpp`](Graph-Algorithms/Labyrinth.cpp)
- [Building Roads](https://cses.fi/problemset/task/1666) - [`Graph-Algorithms/Building_Roads.cpp`](Graph-Algorithms/Building_Roads.cpp)
- [Message Route](https://cses.fi/problemset/task/1667) - [`Graph-Algorithms/Message_Route.cpp`](Graph-Algorithms/Message_Route.cpp)
- [Building Teams](https://cses.fi/problemset/task/1668) - [`Graph-Algorithms/Building_Teams.cpp`](Graph-Algorithms/Building_Teams.cpp)
- [Round Trip](https://cses.fi/problemset/task/1669) - [`Graph-Algorithms/Round_Trip.cpp`](Graph-Algorithms/Round_Trip.cpp)
- [Monsters](https://cses.fi/problemset/task/1194) - [`Graph-Algorithms/Monsters.cpp`](Graph-Algorithms/Monsters.cpp)
- [Shortest Routes I](https://cses.fi/problemset/task/1671) - [`Graph-Algorithms/Shortest_Routes_I.cpp`](Graph-Algorithms/Shortest_Routes_I.cpp)
- [Shortest Routes II](https://cses.fi/problemset/task/1672) - [`Graph-Algorithms/Shortest_Routes_II.cpp`](Graph-Algorithms/Shortest_Routes_II.cpp)
- [High Score](https://cses.fi/problemset/task/1673) - [`Graph-Algorithms/High_Score.cpp`](Graph-Algorithms/High_Score.cpp)
- [Flight Discount](https://cses.fi/problemset/task/1195) - [`Graph-Algorithms/Flight_Discount.cpp`](Graph-Algorithms/Flight_Discount.cpp)

## How to Build and Run

This repository includes a comprehensive Makefile for easy compilation, formatting, and running of solutions:

```bash
# Compile a specific file
make compile FILE=Dynamic-Programming/Dice_Combinations.cpp

# Compile with debug flags
make debug FILE=Dynamic-Programming/Dice_Combinations.cpp

# Compile and run a specific file
make run FILE=Dynamic-Programming/Dice_Combinations.cpp

# Format a specific file using clang-format
make format FILE=Dynamic-Programming/Dice_Combinations.cpp

# Format all C++ files in the repository
make format-all

# Clean compiled files
make clean

# Or compile directly with g++
g++ -o solution Dynamic-Programming/Dice_Combinations.cpp
./solution
```

## Progress

- 🟢 **Introductory Problems**: 3/19 solved
- 🟢 **Dynamic Programming**: 21/19 solved
- 🔴 **Sorting and Searching**: 0/35 solved
- � **Graph Algorithms**: 11/36 solved
- 🔴 **Range Queries**: 0/19 solved
- 🔴 **Tree Algorithms**: 0/16 solved

## Notes

- All solutions are written in C++
- Solutions aim for efficiency and clarity
- Each solution includes comments explaining the approach
- Time and space complexity are noted where relevant

## Resources

- [CSES Problem Set](https://cses.fi/problemset/)
- [CSES Book - Competitive Programming Handbook](https://cses.fi/book/)
- [CP-Algorithms](https://cp-algorithms.com/)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
