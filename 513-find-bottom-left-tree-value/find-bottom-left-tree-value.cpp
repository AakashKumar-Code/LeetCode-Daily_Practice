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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int left=-1;
        while(!q.empty()){
            int sz=q.size();
            bool flag=0;
            for(int i=0; i<sz; i++){
                TreeNode* node=q.front();
                q.pop();
                if(flag==0){
                    flag=1;
                    left=node->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return left;
    }
};