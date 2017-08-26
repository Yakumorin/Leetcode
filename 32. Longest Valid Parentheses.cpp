class Solution {
public:
    int longestValidParentheses(string s) {
        int sum = 0, ans = 0, now = 0;
        vector<pair<int,int>> st;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == '(') {
                if(now > 0) {
                    st.push_back({sum, now});
                    now = 0;
                }
                sum++;
            }
            else {
                sum--;
                if(sum < 0) {
                    sum = 0;
                    now = 0;
                    st.clear();
                }else {
                    now++;
                    if(!st.empty() && st.back().first == sum) {
                        now += st.back().second;
                        st.pop_back();
                    }
                    ans = max(ans, now);
                }
            }
        }
        return ans*2;
    }
};
