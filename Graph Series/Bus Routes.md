# Rotting Oranges 🍊

🔗 **LeetCode Problem Link:**
https://leetcode.com/problems/bus-routes/

## 🧠 Approach

- The problem is solved using **Breadth-First Search (BFS)** to ensure the minimum number of buses is taken.
- Each **bus stop** is treated as a node, and each **bus route** connects multiple stops.

### Key Idea
- Instead of moving stop-to-stop, we move **bus-to-bus**.
- Each BFS level represents **taking one bus**.

### Steps:
1. Create a mapping of **bus stop → list of bus routes** passing through it.
2. Start BFS from the `source` stop.
3. For the current stop:
    - Traverse all bus routes that include this stop.
    - For each **unvisited bus route**, add all its stops to the queue.
4. Maintain:
    - `busVisited` to avoid reusing the same bus.
    - `stopVisited` to avoid revisiting stops.
5. Increase the bus count after each BFS level.
6. When the `target` stop is reached, return the bus count.
7. If BFS ends without reaching the target, return `-1`.

This guarantees the **minimum number of buses** required to reach the destination.

---

## C++ Solution:

```cpp
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                mp[routes[i][j]].push_back(i);
            }
        }
        queue<int> q;
        unordered_map<int, bool> busVisited;
        unordered_map<int, bool> stopVisited;

        q.push(source);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int a = 0; a < size; a++) {
                int stop = q.front();
                q.pop();
                if (stop == target) {
                    return res;
                }
                for (auto bus : mp[stop]) {
                    if (busVisited.find(bus) == busVisited.end()) {
                        for (int i = 0; i < routes[bus].size(); i++) {
                            if (stopVisited.find(routes[bus][i]) ==
                                stopVisited.end()) {
                                q.push(routes[bus][i]);
                                stopVisited[routes[bus][i]] = true;
                            }
                        }
                        busVisited[bus] = true;
                    }
                }
            }
            res += 1;
        }
        return -1;
    }
};
```

## Java Solution:

```java
import java.util.*;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {

        if (source == target) return 0;

        // Map: bus stop -> list of bus indices
        Map<Integer, List<Integer>> stopToBus = new HashMap<>();

        for (int i = 0; i < routes.length; i++) {
            for (int stop : routes[i]) {
                stopToBus.computeIfAbsent(stop, k -> new ArrayList<>()).add(i);
            }
        }

        Queue<Integer> q = new LinkedList<>();
        Set<Integer> busVisited = new HashSet<>();
        Set<Integer> stopVisited = new HashSet<>();

        q.offer(source);
        stopVisited.add(source);

        int buses = 0;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int stop = q.poll();

                if (stop == target) {
                    return buses;
                }

                for (int bus : stopToBus.getOrDefault(stop, new ArrayList<>())) {
                    if (!busVisited.contains(bus)) {

                        for (int nextStop : routes[bus]) {
                            if (!stopVisited.contains(nextStop)) {
                                q.offer(nextStop);
                                stopVisited.add(nextStop);
                            }
                        }

                        busVisited.add(bus);
                    }
                }
            }
            buses++;
        }

        return -1;
    }
}


```
## ⏱ Time and Space Complexity

### Time Complexity
- **O(N × M)**  
  Where:
- `N` = number of bus routes
- `M` = average number of stops per route

Each bus route is processed at most once, and all its stops are traversed during BFS.

---

### Space Complexity
- **O(N × M)**  
  Used for:
- Mapping bus stops to bus routes
- BFS queue storing stops
- Visited sets for buses and stops
