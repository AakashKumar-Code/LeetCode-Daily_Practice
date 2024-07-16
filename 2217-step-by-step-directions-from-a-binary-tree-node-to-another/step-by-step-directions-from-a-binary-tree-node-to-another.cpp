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

    TreeNode* lowestCommonAncestor(TreeNode* root, int s, int e){
        if(!root) return NULL;
        if(root->val==s || root->val==e) return root;
        TreeNode* l=lowestCommonAncestor(root->left, s, e);
        TreeNode* r=lowestCommonAncestor(root->right, s, e);
        if(l&&r) return root;
        return l?l:r;
    }

    bool solve(TreeNode* lca, int t, string &p){
        if(!lca) return 0;
        if(lca->val==t){
            return 1;
        }
        p.push_back('L');
        if(solve(lca->left, t, p)==1){
            return 1;
        }
        p.pop_back();
        p.push_back('R');
        if(solve(lca->right, t, p)==1){
            return 1;
        }
        p.pop_back();
        return 0;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=lowestCommonAncestor(root, startValue, destValue);
        
        string path1="";
        string path2="";

        solve(lca, startValue, path1);
        solve(lca, destValue, path2);

        string res(path1.length(), 'U');
        res+=path2;
        return res;
    }
};