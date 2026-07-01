class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;

        for (int i = 0; i < n; i++) {
            int Product = nums[i];

            maxProduct = max(maxProduct, Product);
            for (int j = i + 1; j < n; j++) {
                Product = Product * nums[j];
                 maxProduct = max(maxProduct, Product);
            }
        }
        return maxProduct;
    }
};