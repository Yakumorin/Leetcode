class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> co;
        for(auto s:nums) co[s]++;
        priority_queue<pair<int,int>> heap;
        for(auto key:co) 
            heap.push(make_pair(key.second, key.first));
        
        vector<int> res;
        for(int i=0; i<k; ++i) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
