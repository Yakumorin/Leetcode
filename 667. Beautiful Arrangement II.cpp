class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int l=1, r=n;
        res.push_back(l);
        l++;
        while(k>1) {
            res.push_back(r);
            r--;
            k--;
            if(k==1) {
                 while(l<=r) {
                    res.push_back(r);
                    r--;
                 }
            } else {
                res.push_back(l);
                l++;
            }
            k--;
        }
        if(k==1) {
            while(l<=r) {
                res.push_back(l);
                l++;
            }
        }
        return res;
    }
};
