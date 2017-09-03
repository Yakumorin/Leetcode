class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> table;
        for(auto ch:s) table[ch]++;
        for(int i=0; i<s.size(); ++i)
            if(table[s[i]] == 1)
                return i;
        return -1;
    }
};
