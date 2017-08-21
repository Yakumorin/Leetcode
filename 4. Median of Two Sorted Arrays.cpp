class Solution {
    int count(int x, vector<int>& num) {
        int l=0, r=num.size()-1, mid;
        int ans = 0;
        while(l <= r) {
            mid = (l + r)/2;
            if(num[mid] <= x) {
                ans = mid + 1;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int sum = n + m;
        int t1, t2;
        if(sum % 2 == 0) {
            t1 = sum/2;
            t2 = sum/2 + 1;
        } else t1 = t2 = sum/2 + 1;
        
        if(n == 0) 
            return (nums2[t1-1] + nums2[t2-1])/2.0;
        
        if(m == 0) 
            return (nums1[t1-1] + nums1[t2-1])/2.0;
        
        
        int ans1, ans2;
        int l = min(nums1[0], nums2[0]), r = max(nums1[n-1], nums2[m-1]), mid;
        while(l < r) {
            mid = ((long long)l + r)/2;
            int t = count(mid, nums1) + count(mid, nums2);
            if(t >= t1) r = mid;
            else l = mid + 1;
        }
        ans1 = l;
        
        l = min(nums1[0], nums2[0]), r = max(nums1[n-1], nums2[m-1]), mid;
        while(l < r) {
            mid = ((long long)l + r)/2;
            int t = count(mid, nums1) + count(mid, nums2);
            if(t >= t2) r = mid;
            else l = mid + 1;
        }
        ans2 = l;
        return (ans1 + ans2)/2.0;
    }
};
