class Solution {
public:
    void help(int start, int k, int n, vector<int> ans,
              vector<vector<int>>& allSubsets) {
       if(ans.size() == k && n == 0){
        allSubsets.push_back(ans);
        return;
       }

       for(int i = start; i<=9;i++){
        ans.push_back(i);
        help(i+1,k,n-i,ans,allSubsets);
        ans.pop_back();
       }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        help(1, k, n, ans, allSubsets);
        return allSubsets;
    }
};