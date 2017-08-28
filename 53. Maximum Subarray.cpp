class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mi = 0, s = 0, ans = nums[0];
        for(int i=0; i<nums.size(); ++i) {
            s += nums[i];
            if(s - mi > ans) ans = s - mi;
            if(s < mi) mi = s;
        }
        return ans;
    }
};
