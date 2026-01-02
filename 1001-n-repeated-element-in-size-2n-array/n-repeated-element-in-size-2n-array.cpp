class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if(nums[0] == nums[nums.size()-1]) return nums[0];
        for(int i = 0; i<nums.size();i++){
            if(i+1>=nums.size()) continue;
          if(nums[i] == nums[i+1]) return nums[i];
          if(i+2<nums.size() && nums[i] == nums[i+2]) return nums[i];
        }
        return -1;
    }
};