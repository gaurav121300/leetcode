class Solution {
    public int findNumbers(int[] nums) {
        int count = 0; //to count even number of digits

        for(int i = 0;i<nums.length;i++){
            int digitCnt = 0;
            int num = nums[i];

            while(num > 0){
                num = num / 10;
                digitCnt++;
            }

            if(digitCnt % 2 == 0)
            count++;
        }
        return count;
    }
}