class Solution {
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& longest) {
        if(longest[x][y] != -1) return longest[x][y];
        longest[x][y] = 1;
        if(x && matrix[x-1][y] > matrix[x][y]) longest[x][y] = max(longest[x][y], dfs(x-1, y, matrix, longest) + 1);
        if(y && matrix[x][y-1] > matrix[x][y]) longest[x][y] = max(longest[x][y], dfs(x, y-1, matrix, longest) + 1);
        if(x+1 < matrix.size() && matrix[x+1][y] > matrix[x][y]) longest[x][y] = max(longest[x][y], dfs(x+1, y, matrix, longest) + 1);
        if(y+1 < matrix[x].size() && matrix[x][y+1] > matrix[x][y]) longest[x][y] = max(longest[x][y], dfs(x, y+1, matrix, longest) + 1);
        return longest[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size()) return 0;
        vector<vector<int>> longest(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 0;
        for(int i=0; i<matrix.size(); ++i)
            for(int j=0; j<matrix[i].size(); ++j)
                ans = max(dfs(i, j, matrix, longest), ans);
        return ans;        
    }
};
