class Solution {
    public String reverseWords(String s) {
        String result = "";
        int i = s.length() - 1;

        while(i >= 0){
            //skip the spaces
            while(i >= 0 && s.charAt(i) == ' ')
            i--;

            int j = i;
            while(i >= 0 && s.charAt(i) != ' ')
            i--;

            //extract word
            String word = s.substring(i+1,j+1);

            //add to result
            if(result.length() == 0){
                result = word;
            }else{
                result = result + " " + word;
            }
        }
        return result.trim();
    }
}