class Solution {
    public double findMaxAverage(int[] nums, int k) {
       int n = nums.length;
       int l =  0 , r = k - 1;
       int sum = 0;

       for(int i = 0;i <= r;i++){
        sum += nums[i];
       }
       int maxSum = sum;

       while(r < n-1){
        sum = sum - nums[l];
        l++;
        r++;
        sum = sum + nums[r];
        maxSum = Math.max(maxSum,sum);
       }
       return (double) maxSum / k;
    }
}