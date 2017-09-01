class Solution {
    vector<vector<int>> res;
    void dfs(int x, vector<int>& nums, vector<int> now) {
        if(x == nums.size()) {
            res.push_back(now);
            return;
        }
        int i=x;
        while(i+1<nums.size() && nums[i+1]==nums[x]) i++;
        dfs(i+1, nums, now);
        for(int j=x; j<=i; ++j) {
            now.push_back(nums[x]);
            dfs(i+1, nums, now);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(0, nums, tmp);
        return res;
    }
};
