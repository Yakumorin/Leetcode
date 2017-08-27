class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>count;
        for(int i=0; i<=num; ++i) {
            int x = i, t = 0;
            while(x) {
                ++t;
                x -= x&(-x);
            }
            count.push_back(t);
        }
        return count;
    }
};
