class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(int i = 0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                index = i+1;
            }else break;
        }

        if(index == 0 || index == n-1)  return false;
        for(int j = index;j<n-1;j++){
            if(nums[j] > nums[j+1])
            index = j+1;
            else break;
        }
         
         if(index == n-1) return false;

        for(int k = index;k<n-1;k++){
            if(nums[k] < nums[k+1])
            index = k+1;
            else break;
        }

        if(index == n-1) return true;
        return false;
    }
};