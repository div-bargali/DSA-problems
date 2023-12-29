class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& vis, int row, int col, int prevC, int newColor, int n, int m) {
        // base case
        if(row < 0 || row > n-1 || col < 0 || col > m-1)
            return;
        if(image[row][col] != prevC || vis[row][col])
            return;
        
        vis[row][col] = true;
        image[row][col] = newColor;
        
        for(int i = 0; i < 4; ++i){
            int x = row + dx[i];
            int y = col + dy[i];
            
            dfs(image, vis, x, y, prevC, newColor, n, m);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        int co = image[sr][sc];
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        
        dfs(image, vis, sr, sc, co, newColor, row, col);
        return image;
    }
};