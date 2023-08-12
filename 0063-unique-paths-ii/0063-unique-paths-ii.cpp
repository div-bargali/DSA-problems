// initial thoughts - 
// looked like a dfs problem initially, explore all tha paths using dfs 
// and then keep a count of all valid paths
// Q - How to keep track that a path explored is unique? - Backtracking
// Q2 - What if a path from (i, j) is already explored and we reach that cell again? - Memoize all the unique paths from a cell.
class Solution {
public:
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    int memo[101][101];
    
    bool isValid(vector<vector<int>>& grid, int x, int y, int r, int c) {
        if (x < 0 || y < 0 || x >= r || y >= c || grid[x][y] == 1) return false;
        return true;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(memo, 0, sizeof(memo));
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        return dfs(0, 0, rows, cols, obstacleGrid);
    }
    
    int dfs(int x, int y, int r, int c, vector<vector<int>>& grid) {
        if (memo[x][y] != 0) return memo[x][y];
        
        if (grid[x][y] == 1) return 0; // Obstacle encountered
        
        if (x == r - 1 && y == c - 1) return 1; // Destination reached
        
        int paths = 0;
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(grid, nx, ny, r, c)) {
                paths += dfs(nx, ny, r, c, grid);
            }
        }
        memo[x][y] = paths; // Memoize the result
        return paths;
    }
};
