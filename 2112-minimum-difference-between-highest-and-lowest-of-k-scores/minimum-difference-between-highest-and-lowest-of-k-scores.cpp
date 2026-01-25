class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minm = INT_MAX;
        for(int i = 0;i<=n-k;i++){
            minm = min(minm,nums[i+k-1]-nums[i]);
        }
        return minm;
    }
};