class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto s : nums) x ^= s;
        x = x & (-x); // lastbit diff
        int a = 0, b = 0;
        for(auto s : nums)
            if(s & x) a ^= s;
            else b ^= s;
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};
