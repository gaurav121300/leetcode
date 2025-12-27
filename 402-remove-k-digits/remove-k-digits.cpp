class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        if(k == num.size()) return "0";
        for(char c : num){
            while(!st.empty() && c < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

             reverse(ans.begin(),ans.end());

        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

   
        return ans.empty() ? "0" : ans;
    }
};