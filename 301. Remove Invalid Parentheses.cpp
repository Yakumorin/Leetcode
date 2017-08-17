class Solution {
    int minNum;
    vector<string> store;
    unordered_map<string, bool> table;
    void dfs(string s, int pos, int stacks, int res, string tmp) {
        if(pos == s.size()) {
            if(stacks == 0 && res == 0) {
                if(!table[tmp]) {
                    table[tmp] = 1;
                    store.push_back(tmp);
                }
            }
            return;
        }
        if(s[pos] != '(' && s[pos] != ')') dfs(s, pos+1, stacks, res, tmp+s[pos]);
        if(s[pos] == '(') {
            if(res) dfs(s, pos+1, stacks, res-1, tmp);
            dfs(s, pos+1, stacks+1, res, tmp+'(');
        }
        if(s[pos] == ')') {
            if(stacks) dfs(s, pos+1, stacks-1, res, tmp+')');
            if(res) dfs(s, pos+1, stacks, res-1, tmp);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        minNum = 0;
        store.clear();
        table.clear();
        int stacks = 0;
        for(auto ch:s) {
            if(ch == '(') {
                stacks++;
            }else if(ch == ')') {
                stacks?--stacks:++minNum;
            }
        }
        minNum += stacks;
        dfs(s, 0, 0, minNum, "");
        return store;
    }
};
