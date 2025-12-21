class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
          if(ans.empty()){
                ans.push_back(intervals[0]);
            }

        for(int i = 1;i<n;i++){
                vector<int>&v = ans.back();
                int end = v[1];


                if(end >= intervals[i][0]){
                    v[1] = max(end,intervals[i][1]);
                }else{
                    ans.push_back(intervals[i]);
                }
            }
        
        return ans;
    }
};