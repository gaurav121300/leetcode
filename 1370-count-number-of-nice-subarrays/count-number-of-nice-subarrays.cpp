class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int &num : nums){
            num = num & 1;
        }

        int cnt = 0 , currSum = 0;
        map<int,int>freq;
        freq[0] = 1;

        for(int num : nums){
            currSum += num;

            if(freq.count(currSum - k)){
                cnt += freq[currSum - k];
            }
            freq[currSum] += 1;
        }
        return cnt;
    }
};