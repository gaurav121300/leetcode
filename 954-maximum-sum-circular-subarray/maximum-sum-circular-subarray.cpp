class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], currMax = 0;
        int minSum = nums[0], currMin = 0;

        for(int i = 0;i<nums.size();i++){
            currMax = max(nums[i],currMax + nums[i]);
            maxSum = max(maxSum,currMax);

            currMin = min(nums[i],currMin + nums[i]);
            minSum = min(minSum , currMin);

            totalSum = totalSum + nums[i];
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum,totalSum - minSum);
    }
};