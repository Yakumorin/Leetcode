class Solution {
public:
    vector<int> maxNumber(vector<int> nums1, vector<int> nums2, int k) {
        int n=nums1.size();
        vector<int> best;
        for(int i=0; i<=k&&i<=n; ++i)
            if(k-i <= nums2.size())
                best = max(best, merge(maxNumber(nums1, i), maxNumber(nums2, k-i)));
        return best;
    }
    vector<int> maxNumber(vector<int>& nums1, int k) {
        vector<int> res;
        int kill = nums1.size() - k;
        for(auto num:nums1) {
            while(kill && res.size() && res.back() < num) {
                res.pop_back();
                kill--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
    vector<int> merge(vector<int> s1, vector<int> s2) {
        vector<int> res;
        while(s1.size() + s2.size()) {
            vector<int>& now = s1 > s2 ? s1 : s2;
            res.push_back(now[0]);
            now.erase(now.begin());
        }
        return res;
    }
};
