/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        unordered_map<Node*, Node*>mpp;
        unordered_set<Node*>vis;

        queue<Node*>q;
        q.push(node);
        vis.insert(node);

        while(!q.empty()){
            Node* root=q.front();
            q.pop();

            Node* copyN=new Node(root->val);
            mpp[root]=copyN;

            for(auto it:root->neighbors){
                if(vis.find(it)==vis.end()){
                    vis.insert(it);
                    q.push(it);
                }
            }
        }

        unordered_set<Node*>vis1;

        q.push(node);
        vis1.insert(node);

        while(!q.empty()){
            Node* root=q.front();
            q.pop();

            vector<Node*>tmp;
            for(auto it:root->neighbors){
                if(vis1.find(it)==vis1.end()){
                    vis1.insert(it);
                    q.push(it);
                }
                tmp.push_back(mpp[it]);
            }
            mpp[root]->neighbors=tmp;
        }
        return mpp[node];        
    }
};