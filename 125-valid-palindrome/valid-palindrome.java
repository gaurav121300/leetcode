class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();

        int i = 0;
        int j = s.length() - 1;

        while(i < j){
            while(i < j && !isValid(s.charAt(i))){
                i++;
            }

            while(i < j && !isValid(s.charAt(j))){
                j--;
            }

            if(s.charAt(i) != s.charAt(j))
            return false;

            i++;
            j--;

        }

      return true;

        
    }

      public boolean isValid(char ch){
            return ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
        }
}