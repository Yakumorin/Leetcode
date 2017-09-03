class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> table;
        for(auto ch:s) table[ch]++;
        for(auto ch:t) {
            if(!table[ch]) return false;
            table[ch]--;
        }
        return true;
    }
};
