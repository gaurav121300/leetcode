class Solution {
public:
    int findSum(int startRow,int startCol,int endRow,int endCol,vector<vector<int>>& mat){
        int sum = 0;

        for(int i = startRow;i <= endRow;i++){
            for(int j = startCol; j <= endCol; j++){
                sum += mat[i][j];
            }
        }
        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        int maxlen = 0;

        for(int i = 0; i < m;i++){
            int bestSide = 0;
            for(int j = 0; j < n;j++){
                for(int offset = 0;offset < min(m-i,n-j);offset++){
                    int r2 = i + offset;
                    int c2 = j + offset;

                    int val = findSum(i,j,r2,c2,mat);
                    if(val <= threshold){
                        bestSide = offset + 1;
                    }else break;
                }
                maxlen = max(maxlen,bestSide);
            }
            
        }
        return maxlen;
    }
};