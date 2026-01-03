class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int ans = INT_MAX;
        int sum = 0;
        int left = 0,r = 0;

        while(r < nums.size()){
           mpp[nums[r]]++;
           if(mpp[nums[r]] == 1) 
           sum += nums[r];

           while(sum >= k){
            ans = min(ans,r - left + 1);
            mpp[nums[left]]--;
            if(mpp[nums[left]] == 0)
            sum -= nums[left];
            left++;
           }
           r++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};