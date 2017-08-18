class Solution {
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        if(x && grid[x-1][y] == '1') dfs(grid, x-1, y);
        if(x+1<grid.size() && grid[x+1][y] == '1') dfs(grid, x+1, y);
        if(y && grid[x][y-1] == '1') dfs(grid, x, y-1);
        if(y+1<grid[0].size() && grid[x][y+1] == '1') dfs(grid, x, y+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[i].size(); ++j) {
                if(grid[i][j] == '0') continue;
                num++;
                dfs(grid, i, j);
            }
        return num;
    }
};
