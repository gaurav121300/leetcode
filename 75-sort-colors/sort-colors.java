class Solution {
    public void sortColors(int[] nums) {
        int countZero = 0;
        int countOne = 0;
        int countTwo = 0;

        for(int num : nums){
            if(num == 0) countZero++;
            if(num == 1) countOne++;
            if(num == 2) countTwo++;
        }

        // countZero = 2 countOne = 3  countTwo = 4

        int index = 0;
        for(int i = 0;i<countZero;i++){
            nums[index] = 0;   //[0,0]
            index++;
        }

        for(int i = 0;i<countOne;i++){
            nums[index] = 1;
            index++;
        }

        for(int i = 0;i<countTwo;i++){
            nums[index] = 2;
            index++;
        }


    }
}