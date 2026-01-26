class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int minmDiff = INT_MAX;
        vector<int>subset;
        for(int i = 0;i<arr.size()-1;i++){
            int Diff = arr[i+1] - arr[i];
            if(Diff < minmDiff){
                minmDiff = Diff;
            }
        }

        for(int i = 0;i<arr.size()-1;i++){
            subset.clear();
            for(int j = i+1;j<arr.size();j++){
                if(arr[j] - arr[i] == minmDiff){
                subset.push_back(arr[i]);
                subset.push_back(arr[j]);
                break;
            }else if(arr[j] - arr[i] > minmDiff) break;
            else continue;
            }
            if(!subset.empty())
            ans.push_back(subset);
        }
        
        return ans;
    }
};