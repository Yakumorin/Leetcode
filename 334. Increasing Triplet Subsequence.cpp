class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minx1=INT_MAX, minx2=INT_MAX;
        for(auto x : nums) {
            if(x > minx2) return 1;
            if(x > minx1 && x < minx2) minx2 = x;
            if(x < minx1) minx1 = x;
        }
        return 0;
    }
};
