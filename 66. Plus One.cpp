class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        bool all9 = 1;
        digits[n-1]++;
        for(int i=n-1; i>=0; --i) {
            if(digits[i]==10) {
                if(i) digits[i-1]++;
                digits[i]=0;
            }
            else{
                all9 = 0;
                break;
            }
        }
        if(all9) {
            vector<int> res(n+1, 0);
            res[0]=1;
            return res;
        }
        return digits;
    }
};
