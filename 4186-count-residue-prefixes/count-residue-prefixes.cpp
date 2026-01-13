class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.length();
        unordered_set<char>chars;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            chars.insert(s[i]);
            if(chars.size() == (i+1) % 3){
                cnt++;
            }
        }
        return cnt;
    }
};