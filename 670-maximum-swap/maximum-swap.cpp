class Solution {
public:
    int maximumSwap(int num){
        string s = to_string(num);
        int length = s.size();
        int idx = 0;
        for(int i = 0; i<length;i++){
            int maxi = -1;
            for(int j = i+1;j<length;j++){
                if(s[i] - '0' < s[j] - '0'){
                   if(s[j] - '0' >= maxi){
                    maxi = s[j] - '0';
                    idx = j;
                   }
                }
            }
            if(maxi != -1) {
                swap(s[idx],s[i]);
                break;
            }
        }
        int ans = stoi(s);
        return ans;
    }
};