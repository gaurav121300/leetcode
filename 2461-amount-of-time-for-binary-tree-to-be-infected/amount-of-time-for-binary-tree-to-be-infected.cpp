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
    void markParent(TreeNode* root,  unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->left){
                parent[front->left] = front;
                q.push(front->left);
            }

            if(front->right){
                parent[front->right] = front;
                q.push(front->right);
            }
        }
    }
    TreeNode* findTarget(TreeNode* root,int start){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == start) return front;

            if(front->right) q.push(front->right);
            if(front->left) q.push(front->left);
        }
        return NULL;
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target = findTarget(root,start);
        unordered_map<TreeNode*,TreeNode*>parent;
        markParent(root,parent);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        int minutes = 0;

        visited[target] = true;
        q.push(target);

        while(!q.empty()){
            int size = q.size();
            minutes++;

            for(int i = 0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if(front->right && !visited[front->right]){
                    visited[front->right] = true;
                    q.push(front->right);
                }

                if(parent[front] && !visited[parent[front]]){
                    visited[parent[front]] = true;
                    q.push(parent[front]);
                }
            }
        }
        return (minutes - 1);
    }
};