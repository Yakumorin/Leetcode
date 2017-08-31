class Solution {
    int block[9], row[9], col[9];
    void dfs(int n, vector<vector<char>>& board, vector<pair<int, int>> &emptycell, bool &find) {
        if(find) return;
        if(n == 0) {
            find = 1;
            return;
        }
        int mi = 10, mp;
        for(int i=0; i<n; ++i) {
        int res=0;
        int x = emptycell[i].first, y = emptycell[i].second;
            for(int j=0; j<9; ++j)
                if(!(row[x]&(1<<j)) && !(col[y]&(1<<j)) && !(block[(x/3)*3+(y/3)]&(1<<j)))
                    ++res;
            if(res < mi) {
                mi = res;
                mp = i;
            }
        }
        swap(emptycell[mp], emptycell[n-1]);
        int x = emptycell[n-1].first, y = emptycell[n-1].second;
        for(int i=0; i<9; ++i)
            if(!(row[x]&(1<<i)) && !(col[y]&(1<<i)) && !(block[(x/3)*3+(y/3)]&(1<<i))) {
                board[x][y] = i+'1';
                row[x] ^= 1<<i;
                col[y] ^= 1<<i;
                block[(x/3)*3+(y/3)] ^= 1<<i;
                
                dfs(n-1, board, emptycell, find);
                if(find) return;
                
                row[x] ^= 1<<i;
                col[y] ^= 1<<i;
                block[(x/3)*3+(y/3)] ^= 1<<i;
            }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i)
            block[i] = col[i] = row[i] = 0;
        vector<pair<int, int>> emptycell;
        for(int i=0; i<9; ++i)
            for(int j=0; j<9; ++j) {
                if(board[i][j] == '.')
                    emptycell.push_back({i,j});
                else {
                    row[i] |= 1<<(board[i][j]-'1');
                    col[j] |= 1<<(board[i][j]-'1');
                    block[(i/3)*3+(j/3)] |= 1<<(board[i][j]-'1');
                }
            }
        int n = emptycell.size();
        bool find = 0;
        dfs(n, board, emptycell, find);
    }
};
