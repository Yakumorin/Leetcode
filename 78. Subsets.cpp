class Solution {
    vector<vector<int>> res;
    void dfs(int x, vector<int>& nums, vector<int> now) {
        if(x == nums.size()) {
            res.push_back(now);
            return;
        }
        dfs(x+1, nums, now);
        now.push_back(nums[x]);
        dfs(x+1, nums, now);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> tmp;
        dfs(0, nums, tmp);
        return res;
    }
};
