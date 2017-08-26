class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        do {
            ans+=((n-1)%26+'A');
            n=(n-1)/26;
        } while(n);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
