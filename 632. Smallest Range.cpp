class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        priority_queue<pair<int,pair<int,int>>> heap;
        int maxn = -1000000, gap = 1000000;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i].size() == 0) return res;
            maxn = max(maxn, nums[i][0]);
            heap.push({-nums[i][0], {0,i}});
        }
        while(1) {
            pair<int,pair<int,int>>x = heap.top();
            heap.pop();
            if(maxn + x.first < gap) {
                res.clear();
                gap = maxn + x.first;
                res.push_back(-x.first);
                res.push_back(maxn);
            }
            x.second.first++;
            if(x.second.first == nums[x.second.second].size()) break;
            x.first = -nums[x.second.second][x.second.first];
            maxn = max(maxn, -x.first);
            heap.push(x);
        }
        return res;
    }
};
