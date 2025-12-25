class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        int n = happiness.size();
        long long sum = 0;

        for(int i = 0;i<k;i++){
           int curr = happiness[i] - i;
           if(curr <= 0) break;
           sum += curr;
        }
        return sum;
    }
};