
class Solution {
    vector<int> f;
    int find(int x) {
        if(f[x] == x) return x;
        return f[x] = find(f[x]);
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        f.clear();
        for(int i=0; i<n; ++i) f.push_back(i);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<i; ++j)
                if(M[i][j])
                    if(find(i) < find(j))
                        f[find(j)] = f[i];
                    else
                        f[find(i)] = f[j];
        }
        int res = 0;
        for(int i=0; i<n; ++i)
            if(f[i] == i)
                res++;
        return res;
    }
};
