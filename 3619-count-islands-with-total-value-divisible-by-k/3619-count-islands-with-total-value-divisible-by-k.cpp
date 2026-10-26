#include <vector>
#include <queue>

class Solution {
public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int divisibleIslandsCount = 0;
        
        // Directions array for 4-directional movement (Up, Down, Left, Right)
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the cell value is greater than 0, it is part of an unvisited island
                if (grid[i][j] > 0) {
                    long long islandSum = 0;
                    std::queue<std::pair<int, int>> q;
                    
                    // Start BFS
                    q.push({i, j});
                    islandSum += grid[i][j];
                    grid[i][j] = 0; // Mark as visited by setting to 0
                    
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        
                        for (int d = 0; d < 4; ++d) {
                            int nr = r + dirs[d][0];
                            int nc = c + dirs[d][1];
                            
                            // Check boundaries and if the neighboring cell is land (> 0)
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                islandSum += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark as visited
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    // Check if the total island sum is divisible by k
                    if (islandSum % k == 0) {
                        divisibleIslandsCount++;
                    }
                }
            }
        }
        
        return divisibleIslandsCount;
    }
};
