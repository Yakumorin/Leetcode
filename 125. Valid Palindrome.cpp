class Solution {
    bool isNumber(char x) {
        return x>='0' && x<='9';
    }
    bool isAlpha(char x) {
        return (x>='a' && x<='z') || (x>='A' && x<='Z');
    }
public:
    bool isPalindrome(string s) {
        if(s.empty()) return 1;
        int l=0, r=s.size()-1;
        while(l<=r) {
            while(l<=r && !isNumber(s[l]) && !isAlpha(s[l])) ++l;
            while(l<=r && !isNumber(s[r]) && !isAlpha(s[r])) --r;
            if(s[l]>='A'&&s[l]<='Z') s[l]=s[l]-'A'+'a';
            if(s[r]>='A'&&s[r]<='Z') s[r]=s[r]-'A'+'a';
            if(l<=r && s[l] != s[r]) return 0;
            l++; r--;
        }
        return 1;
    }
};
