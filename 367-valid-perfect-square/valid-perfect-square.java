class Solution {
    public boolean isPerfectSquare(int num) {
       return check(num,1);
    }

    boolean check(int num,int i){
        if(i > Math.sqrt(num)) return false;

        if(i * i == num) return true;

        return check(num,i+1);
    }
}