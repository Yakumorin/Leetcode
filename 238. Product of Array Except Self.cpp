class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        vector<int> output;
        for(int i=0; i<nums.size(); ++i) {
            output.push_back(sum);
            sum *= nums[i];
        }
        sum = 1;
        for(int i=nums.size()-1; i>=0; --i) {
            output[i] *= sum;
            sum *= nums[i];
        }
        return output;
    }
};
