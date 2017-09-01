class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0, total=0, now=0;;
        for(int i=0; i<gas.size(); ++i) {
            now = now+gas[i]-cost[i];
            if(now < 0) {
                total += now;
                start = i+1;
                now = 0;
            }
        }
        return total+now<0? -1 : start;
    }
};
