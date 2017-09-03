class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>>build;
        int cur = 0;
        while(cur<buildings.size() || !build.empty()) {
            int curX = build.empty()?buildings[cur][0]:build.top().second;
            if(cur>=buildings.size() || curX < buildings[cur][0]) {
                while(!build.empty() && build.top().second <= curX) build.pop();
            } else {
                curX = buildings[cur][0];
                while(cur<buildings.size() && buildings[cur][0] == curX) {
                    build.push({buildings[cur][2], buildings[cur][1]});
                    cur++;
                }
            }
            int curH = build.empty()?0:build.top().first;
            if(res.empty() || (res.back().second != curH)) res.push_back({curX, curH});
        }
            
        return res;
    }
};
