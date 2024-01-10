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

    unordered_map<TreeNode*, TreeNode*>parent;
    TreeNode* target;

    void markParent(TreeNode* root, int start){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start) target=node;
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }

    }

    int amountOfTime(TreeNode* root, int start) {
        target=NULL;
        markParent(root, start);
        unordered_map<TreeNode*, bool>vis;
        vis[target]=1;
        int cnt=0;
        queue<TreeNode*>q;
        q.push(target);
        while(!q.empty()){
            
            int n=q.size();
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
            }
            cnt+=1;
        }
        return cnt-1;
    }
};