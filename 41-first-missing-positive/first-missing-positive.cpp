class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int x :  nums){
            st.insert(x);
        }

        for(int x = 1; x <= n+1; x++){
            if(st.find(x) == st.end()){
                return x;
            }
        }
        return 5;
    }
};