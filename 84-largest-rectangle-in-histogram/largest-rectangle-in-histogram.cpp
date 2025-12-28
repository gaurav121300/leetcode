class Solution {
public:
   vector<int>PSE(vector<int>& heights){
    int n = heights.size();
        vector<int>pse(n);
        stack<int>st;

        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
   }

    
    vector<int>NSE(vector<int>& heights){
        int n = heights.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--){

            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse = NSE(heights);
        vector<int>pse = PSE(heights);

        int ans = 0;
        for(int i = 0;i<n;i++){
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];
            ans = max(ans,area);
        }
        return ans;
    }
};