class Solution {
public:
    int solve(int number,vector<int>&nums){
        if(number == 2) return -1;
        for(int i = 1;i<number;i++){
            if((i | i+1) == number) return i;
        }
        return -1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        for(int i = 0;i<n;i++){
           ans[i] = solve(nums[i],nums);
        }
        return ans;
    }
};