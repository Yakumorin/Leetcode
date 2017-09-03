class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> a;
        vector<int> res;
        for(auto x: nums1)
            a[x]++;
        for(auto x: nums2)
            if(a[x]) {
                res.push_back(x);
                a[x]--;
            }
        return res;
    }
};
