class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int i=0;
        while(i<nums.size()) {
            if(nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for(int i=0; i<nums.size(); ++i)
            if(i != nums[i]-1)
                res.push_back(i+1);
        return res;
    }
};
