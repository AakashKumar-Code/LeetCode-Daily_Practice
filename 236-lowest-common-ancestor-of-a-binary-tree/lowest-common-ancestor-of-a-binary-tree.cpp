/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* lft=solve(root->left, p, q);
        TreeNode* rgt=solve(root->right, p, q);
        if(lft==NULL && rgt!=NULL) return rgt;
        else if(lft!=NULL && rgt==NULL) return lft;
        else if(lft!=NULL && rgt!=NULL) return root;
        else return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);        
    }
};