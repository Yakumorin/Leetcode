class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> table;
        for(int x:nums)
            table.insert(x);
        
        int ans = 0;
        for(int x:nums) {
            if(!table.count(x)) continue;
            int l = x, r = x;
            table.erase(x);
            while(table.count(l-1)) {
                l--;
                table.erase(l);
            }
            while(table.count(r+1)) {
                r++;
                table.erase(r);
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
