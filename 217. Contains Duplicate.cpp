class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> table;
        for(auto x:nums) {
            if(table[x]) return true;
            table[x]=true;
        }
        return false;
    }
};
