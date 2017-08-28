class Solution {
    int n;
    vector<int> bits;
    void bit_add(int x) {
        while(x <= n) {
            bits[x]++;
            x += x&(-x);
        }
    }
    int bit_sum(int x) {
        int res = 0;
        while(x) {
            res += bits[x];
            x -= x&(-x);
        }
        return res;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        n = nums.size();
        if(!n) return res;
        bits.resize(n+1);
        unordered_map<int, int> dict;
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        for(int i=0; i<n; ++i)
            dict[sorted_nums[i]] = i+1;
        for(int i=n-1; i>=0; --i) {
            res.push_back(bit_sum(dict[nums[i]]-1));
            bit_add(dict[nums[i]]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
