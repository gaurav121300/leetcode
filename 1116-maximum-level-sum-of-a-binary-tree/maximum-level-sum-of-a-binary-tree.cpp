/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 1;
        queue<TreeNode*> q;
        int sum = 0;
        int maxSum = INT_MIN;
        int level = 0;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                sum += front->val;

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            ans.push_back(sum);
            sum = 0;
        }
        for(int i = 0;i<ans.size();i++){
            if(ans[i] > maxSum){
                maxSum = ans[i];
                level = i+1;
            }
        }
        return level;
    }
};