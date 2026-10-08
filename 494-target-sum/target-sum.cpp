class Solution {
public:
    int solve(int index, vector<int>& nums, int target, int sum) {

        // Base case
        if (index == nums.size()) {

            if (sum == target)
                return 1;

            return 0;
        }

        // Add the current number
        int add = solve(index + 1, nums, target, sum + nums[index]);

        // Subtract the current number
        int subtract = solve(index + 1, nums, target, sum - nums[index]);

        return add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, 0,target );
    }
};