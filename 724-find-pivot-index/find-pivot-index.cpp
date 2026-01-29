class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0,right,sumLeft = 0,sumRight = 0,pivot = -1;
        for(int i = 0;i<n;i++){
            right = i+1;
            while(left < i){
                sumLeft += nums[left];
                left++;
            }

            while(right < n){
                sumRight += nums[right];
                right++; 
            }

            if(sumLeft == sumRight){
            pivot = i;
            break;
            }

            sumLeft = 0,sumRight = 0,left = 0;
        }
        return pivot;
    }
};