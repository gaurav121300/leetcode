class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;   // remainder -> index

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int rem = (k == 0) ? sum : sum % k;

            if (mp.find(rem) != mp.end()) {
                // length at least 2
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;  // store first occurrence
            }
        }
        return false;
    }
};
