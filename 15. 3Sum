class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0; i<n; i++) {
            int target = -nums[i];
            int h = i+1, t=n-1;
            while(h<t) {
                while(h<t && nums[h] + nums[t] > target) --t;
                while(h<t && nums[h] + nums[t] < target) ++h;
                if(h<t && nums[h] + nums[t] == target) {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[h];
                    tmp[2] = nums[t];
                    while(h<t && nums[h] == tmp[1]) ++h;
                    while(h<t && nums[t] == tmp[2]) --t;
                    res.push_back(tmp);
                }
            }
            while(i+1<n && nums[i] == nums[i+1]) ++i;
        }
        return res;
    }
};
