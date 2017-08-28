class Solution {
    bool isNumber(char ch) {
        return ch>='0'&&ch<='9';
    }
public:
    int calculate(string s) {
        vector<int> intnum;
        vector<char> op;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == ' ') continue;
            if(isNumber(s[i])) {
                int r=s[i]-'0';
                while(i+1<s.size() && isNumber(s[i+1])) {
                    i++;
                    r=r*10+s[i]-'0';
                }
                intnum.push_back(r);
            } else {
                op.push_back(s[i]);
            }
        }
        if(intnum.empty()) return 0;
        if(op.empty()) return intnum[0];
        vector<int> intnum2;
        vector<char> op2;
        intnum2.push_back(intnum[0]);
        for(int i=0; i<op.size(); ++i)
            if(op[i]=='*' || op[i]=='/') {
                if(op[i]=='*') intnum2.back() *= intnum[i+1];
                else intnum2.back() /= intnum[i+1];
            } else {
                op2.push_back(op[i]);
                intnum2.push_back(intnum[i+1]);
            }
        int res=intnum2[0];
        for(int i=0; i<op2.size(); ++i)
            if(op2[i]=='+')
                res += intnum2[i+1];
            else
                res -= intnum2[i+1];
        return res;
    }
};
