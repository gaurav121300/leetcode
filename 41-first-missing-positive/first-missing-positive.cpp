class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int expAns = 1;

        for(int x : nums){
            if(x == expAns)
            expAns++;
        }
        return expAns;
    }
};