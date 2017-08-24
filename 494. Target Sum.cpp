class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int,int> now;
        now[0] = 1;
        for(int i=0; i<nums.size(); ++i) {
            unordered_map<int,int> next;
            for(auto x:now) {
                next[x.first+nums[i]] += x.second;
                next[x.first-nums[i]] += x.second;
            }
            now = next;
        }
        return now[S];
    }
};
