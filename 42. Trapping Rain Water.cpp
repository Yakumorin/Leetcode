class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> st;
        int ans = 0;
        for(int i=0; i<height.size(); ++i) {
            int mins = 0;
            while(!st.empty() && height[st.back()]<=height[i]) {
                ans += (height[st.back()]-mins) * (i-st.back()-1);
                mins = height[st.back()];
                st.pop_back();
            }
            if(!st.empty()) ans += (height[i]-mins) * (i-st.back()-1);
            st.push_back(i);
        }
        return ans;
    }
};
