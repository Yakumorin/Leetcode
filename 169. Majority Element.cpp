class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, ti = 0;
        for(auto x:nums) {
            if(ti == 0) {
                major = x;
                ti = 1;
            } else if(x == major){
                ti++;
            } else {
                ti--;
            }
        }
        return major;
    }
};
