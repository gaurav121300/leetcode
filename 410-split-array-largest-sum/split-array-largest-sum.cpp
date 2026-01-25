class Solution {
public:
    int sum(vector<int>&nums){
        int summ = 0;
        for(int i = 0;i<nums.size();i++){
            summ += nums[i];
        }
        return summ;
    }

    int solve(vector<int>&nums,int partition){
        int initialPart = 1, sum = 0;
        for(int i = 0;i<nums.size();i++){
            if(sum + nums[i] <= partition)
            sum += nums[i];
            else{
                initialPart++;
                sum = nums[i];
            }
        }
        return initialPart;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = sum(nums);
        while(low <= high){
             int mid = (low + high) / 2;
             int part = solve(nums,mid);
             if(part > k) low = mid + 1;
             else high = mid - 1;
        }
        return low;
    }
};