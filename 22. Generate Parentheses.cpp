class Solution {
    vector<string> res;
    int n;
    string now;
    void go(int x, int left) {
        if(left > n+n-x) return;
        if(x == n+n && left == 0) {
            res.push_back(now);
            return;
        }
        now[x] = '(';
        go(x+1, left+1);
        if(left) {
            now[x] = ')';
            go(x+1, left-1);
        }
    }
public:
    vector<string> generateParenthesis(int _n) {
        res.clear();
        n = _n;
        for(int i=0; i<n+n; ++i)
            now += "(";
        go(0, 0);
        return res;
    }
};
