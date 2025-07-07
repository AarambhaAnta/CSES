# 🏆 CSES Problem Set Solutions

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://cplusplus.com/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Problems Solved](https://img.shields.io/badge/Problems%20Solved-40+-orange.svg)](#-progress-tracking)
[![Last Updated](https://img.shields.io/badge/Last%20Updated-July%202025-brightgreen.svg)](#-progress-tracking)

> A comprehensive collection of competitive programming solutions

---

This repository contains my solutions to problems from the [CSES Problem Set](https://cses.fi/problemset/), a collection of competitive programming practice problems designed to help programmers improve their algorithmic thinking and problem-solving skills.

## 📋 Table of Contents

- [About CSES](#-about-cses)
- [Repository Structure](#-repository-structure)
- [Problems Solved](#-problems-solved)
- [How to Build and Run](#️-how-to-build-and-run)
- [Progress Tracking](#-progress-tracking)
- [Difficulty Levels](#️-difficulty-levels)
- [Contributing](#-contributing)
- [Learning Notes](#-learning-notes)
- [Resources](#-resources)
- [License](#-license)

## 🎯 About CSES

The CSES Problem Set is a collection of algorithmic programming problems designed for learning and practicing competitive programming. It covers various topics including:

- 🔢 **Introductory Problems** - Basic concepts and mathematical problems
- 🔍 **Sorting and Searching** - Fundamental algorithms and data structures
- 🧮 **Dynamic Programming** - Optimization problems using memoization
- 🕸️ **Graph Algorithms** - Graph traversal, shortest paths, and connectivity
- 📊 **Range Queries** - Efficient data structures for range operations
- 🌳 **Tree Algorithms** - Tree traversal, LCA, and tree dynamic programming
- 🔢 **Mathematics** - Number theory, combinatorics, and probability
- 🔤 **String Algorithms** - Pattern matching and string processing
- 📐 **Geometry** - Computational geometry problems
- ⚡ **Advanced Techniques** - Complex algorithms and optimizations

## 📁 Repository Structure

```text
📦 cses/
├── 📁 introductory_problems/      # 🟢 Basic problems to get started (3/19)
├── 📁 Dynamic-Programming/        # 🟢 DP problems and solutions (21/19)
├── 📁 Graph-Algorithms/          # 🟡 Graph algorithm problems (16/36)
├── 📄 Makefile                   # Build automation and utilities
├── 📄 README.md                  # This documentation
└── 📄 LICENSE                    # MIT License
```

> **Note**: Each directory contains C++ solutions with detailed comments explaining the approach, time complexity, and space complexity.

## 🧩 Problems Solved

### 🔢 Introductory Problems (3/19 solved)

| Problem | Solution | Difficulty | Topics |
|---------|----------|------------|---------|
| [Bit Strings](https://cses.fi/problemset/task/1617) | [`Bit_Strings.cpp`](introductory_problems/Bit_Strings.cpp) | 🟢 Easy | Math, Modular Arithmetic |
| [Trailing Zeros](https://cses.fi/problemset/task/1618) | [`Trailing_Zeros.cpp`](introductory_problems/Trailing_Zeros.cpp) | 🟢 Easy | Math, Factorials |
| [Coin Piles](https://cses.fi/problemset/task/1754) | [`Coin_Piles.cpp`](introductory_problems/Coin_Piles.cpp) | 🟢 Easy | Math, Logic |

### 🧮 Dynamic Programming (21/19 solved)

> Click to expand Dynamic Programming solutions

| Problem | Solution | Difficulty | Topics |
|---------|----------|------------|---------|
| [Dice Combinations](https://cses.fi/problemset/task/1633) | [`Dice_Combinations.cpp`](Dynamic-Programming/Dice_Combinations.cpp) | 🟢 Easy | Basic DP |
| [Minimizing Coins](https://cses.fi/problemset/task/1634) | [`Minimizing_Coins.cpp`](Dynamic-Programming/Minimizing_Coins.cpp) | 🟢 Easy | Coin Change DP |
| [Coin Combinations I](https://cses.fi/problemset/task/1635) | [`Coin_Combinations_I.cpp`](Dynamic-Programming/Coin_Combinations_I.cpp) | 🟢 Easy | Coin Change DP |
| [Coin Combinations II](https://cses.fi/problemset/task/1636) | [`Coin_Combinations_II.cpp`](Dynamic-Programming/Coin_Combinations_II.cpp) | 🟢 Easy | Coin Change DP |
| [Removing Digits](https://cses.fi/problemset/task/1637) | [`Removing_Digits.cpp`](Dynamic-Programming/Removing_Digits.cpp) | 🟢 Easy | Digit DP |
| [Grid Paths](https://cses.fi/problemset/task/1638) | [`Grid_Paths_I.cpp`](Dynamic-Programming/Grid_Paths_I.cpp) | 🟡 Medium | 2D DP, Paths |
| [Book Shop](https://cses.fi/problemset/task/1158) | [`Book_Shop.cpp`](Dynamic-Programming/Book_Shop.cpp) | 🟡 Medium | Knapsack DP |
| [Array Description](https://cses.fi/problemset/task/1746) | [`Array_Description.cpp`](Dynamic-Programming/Array_Description.cpp) | 🟡 Medium | Constraint DP |
| [Edit Distance](https://cses.fi/problemset/task/1639) | [`Edit_Distance.cpp`](Dynamic-Programming/Edit_Distance.cpp) | 🟡 Medium | String DP |
| [Rectangle Cutting](https://cses.fi/problemset/task/1744) | [`Rectangle_Cutting.cpp`](Dynamic-Programming/Rectangle_Cutting.cpp) | 🟡 Medium | 2D DP |
| [Money Sums](https://cses.fi/problemset/task/1745) | [`Money_Sums.cpp`](Dynamic-Programming/Money_Sums.cpp) | 🟡 Medium | Subset Sum DP |
| [Removal Game](https://cses.fi/problemset/task/1097) | [`Removal_Game.cpp`](Dynamic-Programming/Removal_Game.cpp) | 🟡 Medium | Game DP |
| [Two Sets II](https://cses.fi/problemset/task/1093) | [`Two_Sets_II.cpp`](Dynamic-Programming/Two_Sets_II.cpp) | 🟡 Medium | Combinatorial DP |
| [Increasing Subsequence](https://cses.fi/problemset/task/1145) | [`Increasing_Subsequence.cpp`](Dynamic-Programming/Increasing_Subsequence.cpp) | 🟡 Medium | LIS, Binary Search |
| [Projects](https://cses.fi/problemset/task/1140) | [`Projects.cpp`](Dynamic-Programming/Projects.cpp) | 🟡 Medium | Interval DP |
| [Elevator Rides](https://cses.fi/problemset/task/1653) | [`Elevator_Rides.cpp`](Dynamic-Programming/Elevator_Rides.cpp) | 🔴 Hard | Bitmask DP |
| [Counting Tilings](https://cses.fi/problemset/task/2181) | [`Counting_Tilings.cpp`](Dynamic-Programming/Counting_Tilings.cpp) | 🔴 Hard | Bitmask DP |
| [Counting Towers](https://cses.fi/problemset/task/2413) | [`Counting_Towers.cpp`](Dynamic-Programming/Counting_Towers.cpp) | 🔴 Hard | Advanced DP |
| [Longest Common Subsequence](https://cses.fi/problemset/task/1143) | [`Longest_Common_Subsequence.cpp`](Dynamic-Programming/Longest_Common_Subsequence.cpp) | 🟡 Medium | String DP |
| [Increasing Subsequence II](https://cses.fi/problemset/task/1146) | [`Increasing_Subsequence_II.cpp`](Dynamic-Programming/Increasing_Subsequence_II.cpp) | 🟡 Medium | LIS Variants |
| [Mountain Range](https://cses.fi/problemset/task/1141) | [`Mountain_Range.cpp`](Dynamic-Programming/Mountain_Range.cpp) | 🔴 Hard | Catalan Numbers |

### 🕸️ Graph Algorithms (16/36 solved)

> Click to expand Graph Algorithms solutions

| Problem | Solution | Difficulty | Topics |
|---------|----------|------------|---------|
| [Counting Rooms](https://cses.fi/problemset/task/1192) | [`Counting_Rooms.cpp`](Graph-Algorithms/Counting_Rooms.cpp) | 🟢 Easy | DFS, Flood Fill |
| [Labyrinth](https://cses.fi/problemset/task/1193) | [`Labyrinth.cpp`](Graph-Algorithms/Labyrinth.cpp) | 🟢 Easy | BFS, Shortest Path |
| [Building Roads](https://cses.fi/problemset/task/1666) | [`Building_Roads.cpp`](Graph-Algorithms/Building_Roads.cpp) | 🟢 Easy | Union-Find, Connected Components |
| [Message Route](https://cses.fi/problemset/task/1667) | [`Message_Route.cpp`](Graph-Algorithms/Message_Route.cpp) | 🟢 Easy | BFS, Path Reconstruction |
| [Building Teams](https://cses.fi/problemset/task/1668) | [`Building_Teams.cpp`](Graph-Algorithms/Building_Teams.cpp) | 🟡 Medium | Bipartite Graph, DFS |
| [Round Trip](https://cses.fi/problemset/task/1669) | [`Round_Trip.cpp`](Graph-Algorithms/Round_Trip.cpp) | 🟡 Medium | Cycle Detection, DFS |
| [Round Trip II](https://cses.fi/problemset/task/1678) | [`Round_Trip_II.cpp`](Graph-Algorithms/Round_Trip_II.cpp) | 🟡 Medium | Directed Cycle Detection |
| [Monsters](https://cses.fi/problemset/task/1194) | [`Monsters.cpp`](Graph-Algorithms/Monsters.cpp) | 🟡 Medium | Multi-source BFS |
| [Shortest Routes I](https://cses.fi/problemset/task/1671) | [`Shortest_Routes_I.cpp`](Graph-Algorithms/Shortest_Routes_I.cpp) | 🟡 Medium | Dijkstra's Algorithm |
| [Shortest Routes II](https://cses.fi/problemset/task/1672) | [`Shortest_Routes_II.cpp`](Graph-Algorithms/Shortest_Routes_II.cpp) | 🟡 Medium | Floyd-Warshall |
| [High Score](https://cses.fi/problemset/task/1673) | [`High_Score.cpp`](Graph-Algorithms/High_Score.cpp) | 🟡 Medium | Bellman-Ford, Negative Cycles |
| [Flight Discount](https://cses.fi/problemset/task/1195) | [`Flight_Discount.cpp`](Graph-Algorithms/Flight_Discount.cpp) | 🟡 Medium | Modified Dijkstra |
| [Cycle Finding](https://cses.fi/problemset/task/1197) | [`Cycle_Finding.cpp`](Graph-Algorithms/Cycle_Finding.cpp) | 🟡 Medium | Bellman-Ford, Cycle Detection |
| [Flight Routes](https://cses.fi/problemset/task/1196) | [`Flight_Routes.cpp`](Graph-Algorithms/Flight_Routes.cpp) | 🔴 Hard | K Shortest Paths |
| [Course Schedule](https://cses.fi/problemset/task/1679) | [`Course_Schedule.cpp`](Graph-Algorithms/Course_Schedule.cpp) | 🟡 Medium | Topological Sort |
| [Longest Flight Route](https://cses.fi/problemset/task/1680) | [`Longest_Flight_Route.cpp`](Graph-Algorithms/Longest_Flight_Route.cpp) | 🟡 Medium | Topological Sort, DP |

## ⚙️ How to Build and Run

This repository includes a comprehensive Makefile for easy compilation, formatting, and running of solutions:

### 🚀 Quick Start

```bash
# Clone the repository
git clone https://github.com/yourusername/cses.git
cd cses

# Compile and run a specific solution
make run FILE=Dynamic-Programming/Dice_Combinations.cpp
```

### 🔧 Available Commands

```bash
# Compilation
make compile FILE=Dynamic-Programming/Dice_Combinations.cpp    # Standard compilation
make debug FILE=Dynamic-Programming/Dice_Combinations.cpp      # Debug build with flags

# Execution
make run FILE=Dynamic-Programming/Dice_Combinations.cpp        # Compile and run

# Code Formatting
make format FILE=Dynamic-Programming/Dice_Combinations.cpp     # Format specific file
make format-all                                               # Format all C++ files

# Cleanup
make clean                                                     # Remove compiled files
```

### 🛠️ Manual Compilation

```bash
# Basic compilation
g++ -std=c++17 -O2 -Wall -o solution Dynamic-Programming/Dice_Combinations.cpp
./solution

# Debug compilation
g++ -std=c++17 -g -Wall -DDEBUG -o solution Dynamic-Programming/Dice_Combinations.cpp
./solution
```

### 📝 Input/Output

Most problems expect input from stdin and output to stdout. You can:

```bash
# Run with input file
./solution < input.txt

# Run with input file and save output
./solution < input.txt > output.txt

# Interactive testing
./solution
# (then type input manually)
```

## 📊 Progress Tracking

### 📈 Overall Statistics

```text
Total Problems Solved: 40/300+ (13.3%)
Current Focus: Graph Algorithms & Advanced DP
Average Daily Progress: 2-3 problems
```

### 📋 Category Breakdown

| Category | Solved | Total | Progress | Status |
|----------|--------|-------|----------|---------|
| 🔢 **Introductory Problems** | 3 | 19 | ████░░░░░░ | 15.8% |
| 🧮 **Dynamic Programming** | 21 | 19 | ██████████ | 110.5% |
| 🔍 **Sorting and Searching** | 0 | 35 | ░░░░░░░░░░ | 0% |
| 🕸️ **Graph Algorithms** | 16 | 36 | ████░░░░░░ | 44.4% |
| 📊 **Range Queries** | 0 | 19 | ░░░░░░░░░░ | 0% |
| 🌳 **Tree Algorithms** | 0 | 16 | ░░░░░░░░░░ | 0% |
| 🔢 **Mathematics** | 0 | 31 | ░░░░░░░░░░ | 0% |
| 🔤 **String Algorithms** | 0 | 17 | ░░░░░░░░░░ | 0% |
| 📐 **Geometry** | 0 | 7 | ░░░░░░░░░░ | 0% |
| ⚡ **Advanced Techniques** | 0 | 24 | ░░░░░░░░░░ | 0% |

### 🏆 Achievements

- ✅ **DP Master**: Solved more DP problems than available in the set!
- ✅ **Graph Explorer**: Completed 44% of graph algorithms
- 🎯 **Next Milestone**: Complete 50% of Graph Algorithms (18/36)

## 🎚️ Difficulty Levels

### 🟢 Easy (Beginner-friendly)

Problems that involve basic algorithms, simple math, or straightforward implementation.

### 🟡 Medium (Intermediate)

Problems requiring knowledge of common algorithms, data structures, or mathematical concepts.

### 🔴 Hard (Advanced)

Complex problems involving advanced techniques, optimizations, or deep algorithmic knowledge.

## 🤝 Contributing

Feel free to suggest improvements or alternative solutions! Here's how you can contribute:

1. **Fork** the repository
2. **Create** a new branch for your feature
3. **Add** your solution with proper comments
4. **Test** your solution thoroughly
5. **Submit** a pull request

### 📝 Solution Guidelines

- Include time and space complexity analysis
- Add detailed comments explaining the approach
- Follow consistent coding style (use `make format`)
- Test with multiple test cases
- Include problem link and description

## 💡 Learning Notes

### 🧠 Key Insights

- **Dynamic Programming**: Master the art of breaking problems into subproblems
- **Graph Algorithms**: Understanding different traversal methods is crucial
- **Time Complexity**: Always consider the constraints when choosing algorithms
- **Edge Cases**: Pay special attention to boundary conditions

### 📚 Recommended Study Order

1. **Start with**: Introductory Problems (build confidence)
2. **Move to**: Basic Dynamic Programming
3. **Then tackle**: Graph fundamentals (DFS, BFS)
4. **Progress to**: Advanced DP and Graph algorithms
5. **Finally**: Specialized topics (Strings, Geometry, etc.)

## 📚 Resources

### 🎯 Official CSES Resources

- [CSES Problem Set](https://cses.fi/problemset/) - The main problem collection
- [CSES Book - Competitive Programming Handbook](https://cses.fi/book/) - Comprehensive guide
- [CSES Statistics](https://cses.fi/problemset/stats/) - Problem difficulty and solve rates

### 📖 Learning Resources

- [CP-Algorithms](https://cp-algorithms.com/) - Algorithmic tutorials and implementations
- [GeeksforGeeks](https://www.geeksforgeeks.org/) - Programming concepts and problems
- [LeetCode](https://leetcode.com/) - Additional practice problems
- [Codeforces](https://codeforces.com/) - Competitive programming contests

### 🛠️ Development Tools

- [C++ Reference](https://cppreference.com/) - Complete C++ documentation
- [Competitive Programming 4](https://cpbook.net/) - Steven Halim's comprehensive book
- [USACO Guide](https://usaco.guide/) - Structured competitive programming curriculum
- [VisuAlgo](https://visualgo.net/) - Algorithm visualizations

### 📺 Video Resources

- [Errichto](https://www.youtube.com/c/Errichto) - Competitive programming tutorials
- [William Fiset](https://www.youtube.com/c/WilliamFiset-videos) - Data structures and algorithms
- [Back To Back SWE](https://www.youtube.com/c/BackToBackSWE) - Interview preparation

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

> Happy Coding! 🚀
>
> *Found this helpful? Give it a ⭐ on GitHub!*

[⬆ Back to Top](#-cses-problem-set-solutions)
