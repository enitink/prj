#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    map<int, set<int>> xmap, ymap;

    int findEqualOrLower(const std::set<int>& s, int num) {
        auto it = s.lower_bound(num);
        if (it == s.begin() && *it > num) {
            return 0; // No element is less than or equal to num
        }
        if (it == s.end() || *it > num) {
            --it; // Move to the previous element
        }
        return *it;
    }

    void moveToNextPos(int currdir, int& xpos, int& ypos, int c) {
        if (!dir[currdir][0]) { //moving in y direction, x is 0
            int ymap[ypos]
        } else {

        }
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for(auto& o:obstacles) {
            xmap[o[0]].insert(o[1]);
            ymap[o[1]].insert(o[0]);
        }
        int xpos=0, ypos=0;
        int currdir = 0;
        for(auto& c:commands) {
            if (c==-1){
                currdir = (currdir+1)%4;
            } else if (c==-2){
                currdir--;
                if(currdir<0)
                    currdir=3;
            } else {
                moveToNextPos(currdir, xpos, ypos, c);
            }
        }
        return (xpos*xpos) + (ypos*ypos);
    }
};


class Solution {
private:
    static const int HASH_MULTIPLIER =
        60013;  // Slightly larger than 2 * max coordinate value

    // Hash function to convert (x, y) coordinates to a unique integer value
    int hashCoordinates(int x, int y) { return x + HASH_MULTIPLIER * y; }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Store obstacles in an unordered_set for efficient lookup
        unordered_set<int> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(hashCoordinates(obstacle[0], obstacle[1]));
        }

        // Define direction vectors: North, East, South, West
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> currentPosition = {0, 0};
        int maxDistanceSquared = 0;
        int currentDirection = 0;  // 0: North, 1: East, 2: South, 3: West

        for (int command : commands) {
            if (command == -1) {
                // Turn right
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if (command == -2) {
                // Turn left
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }

            // Move forward
            vector<int> direction = directions[currentDirection];
            for (int step = 0; step < command; step++) {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                if (obstacleSet.contains(hashCoordinates(nextX, nextY))) {
                    break;
                }
                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistanceSquared =
                max(maxDistanceSquared,
                    currentPosition[0] * currentPosition[0] +
                        currentPosition[1] * currentPosition[1]);
        }

        return maxDistanceSquared;
    }
};