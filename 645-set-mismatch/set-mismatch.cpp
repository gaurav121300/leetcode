class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n + 1);
        int twoTimes = 0;
        int oneTimes = 0;

        for(int x : nums){
            freq[x]++;
        }

        for(int i = 1;i<=n;i++){
            if(freq[i] == 2)
            twoTimes = i;

            if(freq[i] == 0)
            oneTimes = i;;
        }
        return {twoTimes,oneTimes};
    }
};