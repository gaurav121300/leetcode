class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0, zeros = 0, right = 0, maxlen = 0;

        while(right < nums.length){
            if(nums[right] == 0) zeros++;

            while(zeros > 1) {
                if(nums[left] == 0) zeros--;
                left++;
            }

            maxlen = Math.max(maxlen,right - left); //most important -1 for deleting
            right++;
        }
        return maxlen;
    }
}