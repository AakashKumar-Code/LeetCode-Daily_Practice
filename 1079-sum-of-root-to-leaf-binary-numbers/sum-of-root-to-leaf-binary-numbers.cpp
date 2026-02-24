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

    void solve(TreeNode* node, int curr, int &sum){
      if(!node) return;
      curr=((curr<<1)|node->val);
      if(!node->left && !node->right){
        sum+=curr;
        return;
      }
      solve(node->left, curr,sum);
      solve(node->right, curr, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
      int sum=0;
      solve(root, 0, sum);
      return sum;        
    }
};