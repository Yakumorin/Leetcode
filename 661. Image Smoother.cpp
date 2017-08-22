class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res;
        for(int i=0; i<M.size(); ++i) {
            vector<int> tmp;
            for(int j=0; j<M[0].size(); ++j) {
                int cnt=0, sum=0;
                for(int dx=-1; dx<=1; ++dx)
                    for(int dy=-1; dy<=1; ++dy)
                        if(i+dx<M.size() && i+dx>=0 && j+dy<M[0].size() && j+dy>=0) {
                            sum += M[i+dx][j+dy];
                            cnt++;
                        }
                tmp.push_back(sum/cnt);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
