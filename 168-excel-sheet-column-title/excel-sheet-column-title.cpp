class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber > 0){
            columnNumber--;
            int num = columnNumber % 26;
            char ch = 'A' + num  ;
            ans =  ch + ans ;
            columnNumber /= 26;
        }
        return ans;
    }
};