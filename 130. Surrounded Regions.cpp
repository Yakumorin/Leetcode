class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int n=board.size(), m=board[0].size();
        int visited[n+1][m+1];
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j) {
                if(board[i][j] == 'X') continue;
                if(visited[i][j]) continue;
                bool touch = 0;
                vector<pair<int, int>> q;
                q.push_back({i,j});
                visited[i][j]=1;
                for(int k=0; k<q.size(); ++k) {
                    auto x = q[k].first, y = q[k].second;
                    if(x==0 || x+1==n || y==0 || y+1==m) touch = 1;
                    if(x&& board[x-1][y]=='O' && !visited[x-1][y]) {
                        q.push_back({x-1,y});
                        visited[x-1][y]=1;
                    }
                    if(x+1<n && board[x+1][y]=='O' && !visited[x+1][y]) {
                        q.push_back({x+1,y});
                        visited[x+1][y]=1;
                    }
                    if(y&& board[x][y-1]=='O' && !visited[x][y-1]) {
                        q.push_back({x,y-1});
                        visited[x][y-1]=1;
                    }
                    if(y+1<m && board[x][y+1]=='O' && !visited[x][y+1]) {
                        q.push_back({x,y+1});
                        visited[x][y+1]=1;
                    }
                }
                if(!touch) {
                    for(int k=0; k<q.size(); ++k) {
                        auto x = q[k].first, y = q[k].second;
                        board[x][y] = 'X';
                    }
                }
            }
    }
};
