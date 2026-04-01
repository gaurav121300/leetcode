import java.util.*;

class Solution {
    public int firstOccurrence(int []nums,int size,int target){
        int start = 0, end = size - 1;
        int ans = -1;

        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target ){
                ans = mid;
                end = mid - 1;
            }else if(nums[mid] > target) end = mid - 1;

            else start = mid + 1;
        }
        return ans;
    }


    public int lastOccurrence(int []nums,int size,int target){
        int start = 0, end = size - 1;
        int ans = -1;

        while(start <= end){
              int mid = (start + end) / 2;
            if(nums[mid] == target ){
                ans = mid;
                start = mid + 1;
            }else if(nums[mid] > target) end = mid - 1;

            else start = mid + 1;
        }
        return ans;
    }

    public int[] searchRange(int[] nums, int target) {
        int size = nums.length;

        int first = firstOccurrence(nums, size, target);
        int last = lastOccurrence(nums, size, target);

        // return new int[]{first, last};
        int []arr = {first,last};
        return arr;
    }
}