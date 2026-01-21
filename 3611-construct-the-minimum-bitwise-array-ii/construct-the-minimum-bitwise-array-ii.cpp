class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int num : nums){
            if(num == 2)
            {
                 ans.push_back(-1);
                 continue;
            }
            int val = num;
            int d = 0;
            while((val & (1 << d)) != 0){
                d++;
            }
            val -= (1 << (d-1));
            ans.push_back(val);
        }
        return ans;
    }
};