class Solution {
public:
    bool isValid(string s) {
        vector<char> stacks;
        unordered_map<char, int> match;
        match['('] = ')';
        match['['] = ']';
        match['{'] = '}';
        for(auto ch:s) {
            if(ch=='(' || ch=='{' || ch=='[') {
                stacks.push_back(ch);
            } else {
                if(stacks.empty() || ch != match[stacks.back()]) return 0;
                stacks.pop_back();
            }
        }
        if(!stacks.empty()) return 0;
        return 1;
    }
};
