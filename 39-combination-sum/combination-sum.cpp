class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>&ans,int target,int start,vector<int>&curr){
        
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i  =  start;  i  < candidates.size();i++){
            if(candidates[i] > target){
                break;
            }

            curr.push_back(candidates[i]);

            solve(candidates,ans,target -  candidates[i],i,curr);

            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,target,0,curr);
        return ans;
    }
};