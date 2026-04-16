cmake_minimum_required(VERSION 3.16)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA Trie/trie.cpp
        "Graph Series/Topological_Ordereding/Topological_Sort.cpp"
        "Graph Series/Topological_Ordereding/Topological_Sort.h"
        "Graph Series/DSU/DSU.cpp"
        "Graph Series/DSU/DSURank.cpp"
        "Graph Series/DSU/DSURank.h"
        "Graph Series/DSU/DSU_Path_Compression.cpp"
        "Graph Series/DSU/DSU_Path_Compression.h"
        "Sliding Window/FixedWindow.cpp"
        "Sliding Window/VariableWindow.cpp"
        "Sliding Window/LongestSubstringRepeatingWithoutRepeatingCharacter.cpp"
        "Sliding Window/LongestRepeatingCharacterReplacement.cpp"
        "Sliding Window/DietPlanPerformance.cpp"
        "Sliding Window/BinarySubarrayWithSumK.cpp"
        "Sliding Window/PermutationInStrings.cpp"
        "Graph Series/Algorithms/Kruskal.cpp"
        "Sliding Window/MaxConsecutiveOnes3.cpp"
        "Sliding Window/FruitsIntoBaskets.cpp"
        "Sliding Window/NiceSubarray.cpp"
        "Sliding Window/NumberofSubstringsContainingAllThreeCharacters .cpp"
        Heap/Heap_Implementation.cpp
        Heap/Check_if_an_array_represents_a_max_heap.cpp
        "Heap/ Min Heap to Max Heap.cpp"
        "Heap/Kth Largest Element in an Array.cpp"
        "Heap/k sorted array.cpp"
        "Heap/Merge k Sorted Lists.cpp"
        "Heap/Task Scheduling.cpp"
        Heap/MinimumNumberOfRefuelingStops.cpp
        "Heap/Maximum Performance of a Team.cpp"
        "Graph Series/Algorithms/Dijikstra.cpp"
        "Graph Series/Algorithms/BellmanFord .cpp"
        "Heap/Hand of Straights.cpp"
        "HackWithInfy/MSS with K swaps.cpp"
        "HackWithInfy/Query(Easy).cpp"
        HackWithInfy/GoodSubarray.cpp
        Recursion/stoi.cpp
        Recursion/pow.cpp
        "Recursion/count good numbers.cpp"
        "Recursion/Combination Sum.cpp"
        "Recursion/Combination Sum 2.cpp"
        "Recursion/Combination Sum 3.cpp"
        "Recursion/Subset 1.cpp"
        "Recursion/Subset 2.cpp"
        "Recursion/Letter Combinations Of Phone Number.cpp"
        "Recursion/Generate Paranthesis.cpp"
        "Recursion/N Queens.cpp"
        "Recursion/Rat in a Maze.cpp"
        "Recursion/word break.cpp"
        "Recursion/M colouring Problem.cpp"
        "Dynamic Programming/House Robber 2.cpp"
        "Dynamic Programming/Geek's Training.cpp"
        "HackWithInfy/Food Stamps.cpp")
