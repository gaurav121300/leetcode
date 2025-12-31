class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;

        if (total % k != 0) return false;
        int target = total / k;

        int maxMask = 1 << n;
        vector<int> dp(maxMask, -1);
        dp[0] = 0;

        for (int mask = 0; mask < maxMask; mask++) {
            if (dp[mask] == -1) continue;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    int newSum = dp[mask] + nums[i];
                    if (newSum <= target) {
                        int newMask = mask | (1 << i);
                        dp[newMask] = newSum % target;
                    }
                }
            }
        }

        return dp[maxMask - 1] == 0;
    }
};
