class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int tot=0;
        vector<vector<int>> next;
        vector<int> tmp(128, 0);
        next.push_back(tmp);
        
        for(auto t:wordDict) {
            int p=0;
            for(auto ch:t) {
                if(!next[p][ch]) {
                    ++tot;
                    vector<int> tmp2(128, 0);
                    next.push_back(tmp2);
                    next[p][ch] = tot;
                }
                p = next[p][ch];
            }
            next[p][0] = 1;
        }
        set<int> now, to;
        now.insert(0);
        for(auto ch:s) {
            to.clear();
            for(auto x:now)
                if(next[x][ch]) {
                    to.insert(next[x][ch]);
                    if(next[next[x][ch]][0]) to.insert(0);
                }
            now = to;
        }
        for(auto x:now)
            if(x == 0)
                return 1;
        return 0;
    }
};
