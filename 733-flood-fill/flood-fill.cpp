class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image,int oldColor, int newColor) {

        int m = image.size();
        int n = image[0].size();

        // boundary check
        if (row < 0 || row >= m || col < 0 || col >= n)
            return;

        // color mismatch check
        if (image[row][col] != oldColor)
            return;

        // change color
        image[row][col] = newColor;

        // move in 4 directions
        dfs(row - 1, col, image, oldColor, newColor); // up
        dfs(row + 1, col, image, oldColor, newColor); // down
        dfs(row, col - 1, image, oldColor, newColor); // left
        dfs(row, col + 1, image, oldColor, newColor); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,  int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        // edge case: if same color, do nothing
        if (oldColor == color)
            return image;

        dfs(sr, sc, image, oldColor, color);
        return image;
    }
};
