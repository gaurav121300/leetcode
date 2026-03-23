class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int totalSum = 0;
        
        for(int num : nums){
            totalSum += num;
        }

        int leftSum = 0;

        for(int i = 0;i<n;i++){
            int rightSum = totalSum - nums[i] - leftSum;

            if(leftSum == rightSum) return i;

            leftSum += nums[i];
        }
        return -1;
    }
}