class Solution {
    int MARK = -10000000;
    public void markRow(int i,int col,int[][] matrix){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] != 0)
            matrix[i][j] = MARK;
        }
    }

     public void markCol(int j,int row,int[][] matrix){
        for(int i = 0; i < row; i++){
            if(matrix[i][j] != 0)
            matrix[i][j] = MARK;
        }
    }
    public void setZeroes(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == 0){
                    markRow(i,col,matrix);
                    markCol(j,row,matrix);
                }
            }
        }
           for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == MARK)
                matrix[i][j] = 0;
            }
        }
    }
}