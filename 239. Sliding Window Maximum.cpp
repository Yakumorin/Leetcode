class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for(int i=0; i<k-1; ++i) {
            while(!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
        }
        for(int i=k-1; i<nums.size(); ++i) {
            while(!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
            res.push_back(q.front());
            if(nums[i-k+1] == q.front()) q.pop_front();
        }
        return res;
    }
};
