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

    vector<int>solve(TreeNode* root, int &k, int &ans){
        if(!root) return {0};
        if(!root->left && !root->right) return {1};
        vector<int>lft=solve(root->left, k, ans);
        vector<int>rgt=solve(root->right, k, ans);
        vector<int>res;
        for(int &i:lft){
            for(int &j:rgt){
                if((i!=0 && j!=0) && i+j<=k) ans++;
            }
        }
        for(int &i:lft){
            if(i!=0 && i+1<=k) res.push_back(i+1);
        }
        for(int &j:rgt){
            if(j!=0 && j+1<=k) res.push_back(j+1);
        }
        return res;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        solve(root, distance, ans);
        return ans;
    }
};