class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        for(int i=0; i<numRows; ++i) {
            vector<int> ans;
            ans.push_back(1);
            for(int j=1; j<i; ++j)
                ans.push_back(result[i-1][j-1] + result[i-1][j]);
            if(i) ans.push_back(1);
            result.push_back(ans);
        }
        return result;
    }
};
