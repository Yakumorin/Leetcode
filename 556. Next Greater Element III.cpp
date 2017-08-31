class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n) {
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(), digits.end());
        bool ok = 0;
        for(int i=0; i+1<digits.size(); ++i)
            if(digits[i] < digits[i+1])
                ok = 1;
        if(!ok) return -1;
        for(int i=digits.size()-2; i>=0; --i) {
            if(digits[i] < digits[i+1]) {
                int x = digits[i], t = 10, pos;
                for(int j=i+1; j<digits.size(); ++j)
                    if(digits[j] > x && digits[j] < t) {
                        t = digits[j];
                        pos = j;
                    }
                swap(digits[i], digits[pos]);
                sort(digits.begin()+i+1, digits.end());
                break;
            }
        }
        long long res = 0;
        for(int i=0; i<digits.size(); ++i)
            res = res*10 + digits[i];
        if(res >= (1LL << 31)) return -1;
        return res;
    }
};
