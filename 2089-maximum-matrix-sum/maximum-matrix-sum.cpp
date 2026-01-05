class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;
        int count = 0;
        bool containsZero = false;
        int minm = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += abs(matrix[i][j]);

                minm = min(minm,abs(matrix[i][j]));
                if (matrix[i][j] < 0)
                    count++;
                if (matrix[i][j] == 0)
                    containsZero = true;
            }
        }
        if (!containsZero) {
            if(count & 1){
                sum -= (2 * minm);
            }
        }
        return sum;
    }
};