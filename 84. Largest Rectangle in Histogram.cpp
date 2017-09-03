class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int ans = 0;
        vector<pair<int,int>> st;
        vector<int> f(heights.size());
        for(int i=0; i<heights.size(); ++i) {
            int y=0;
            while(!st.empty() && heights[i]<=st.back().first) {
                y += st.back().second;
                st.pop_back();
            }
            f[i] = y;
            st.push_back({heights[i], y+1});
        }
        st.clear();
        for(int i=heights.size()-1; i>=0; --i) {
            int y=0;
            while(!st.empty() && heights[i]<=st.back().first) {
                y += st.back().second;
                st.pop_back();
            }
            ans = max(ans, heights[i]*(y+f[i]+1));
            st.push_back({heights[i], y+1});
        }
        return ans;
    }
};
