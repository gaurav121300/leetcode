/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long maxProd = 0;
    long long totalSum = 0;
    int MOD = 1e9 + 7;
    
    int findMaxProduct(TreeNode* root){
        if(!root) return 0;
        long long leftSum = findMaxProduct(root->left);
        long long rightSum = findMaxProduct(root->right);
        long long subSum = root->val + leftSum + rightSum;

        if(subSum != totalSum)
        maxProd = max(maxProd,subSum * (totalSum - subSum));

        return subSum;
    }

    int helper(TreeNode* root){
       if(!root) return 0;
       int leftSum = helper(root->left);
       int rightSum = helper(root->right);
       return root->val + leftSum + rightSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum = helper(root);
        findMaxProduct(root);
        return maxProd % MOD;
    }
};