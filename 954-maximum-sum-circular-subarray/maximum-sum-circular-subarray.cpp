class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        int maxSum = INT_MIN, currMax = 0;
        int minSum = INT_MAX, currMin = 0;

        for(int num : nums) {
            // Normal Kadane (max)
            currMax += num;
            maxSum = max(maxSum, currMax);
            if(currMax < 0) currMax = 0;

            // Min Kadane
            currMin += num;
            minSum = min(minSum, currMin);
            if(currMin > 0) currMin = 0;

            total += num;
        }

        // Edge case: all negative
        if(maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }
};