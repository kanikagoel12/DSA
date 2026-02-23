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
        "Sliding Window/NumberofSubstringsContainingAllThreeCharacters .cpp")
