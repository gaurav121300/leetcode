class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto num : nums){
            mpp[num]++;
        }
        for(auto it = mpp.begin();it != mpp.end();it++){
            if(it->second > 1) return it->first;
        }
        return -1;
    }
};