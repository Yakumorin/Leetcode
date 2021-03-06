class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> ab;
        int res = 0;
        for(auto a:A)
            for(auto b:B)
                ab[a+b]++;
        for(auto c:C)
            for(auto d:D)
                res += ab[-c-d];
        return res;
    }
};
