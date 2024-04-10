/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n=lists.size();
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;

        for(int i=0; i<n; i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* d=new ListNode(-1);
        ListNode* nxt=d;

        while(!pq.empty()){
            ListNode* node=pq.top().second;
            pq.pop();
            nxt->next=node;
            nxt=node;
            node=node->next;
            if(node){
                pq.push({node->val, node});
            }
        }

        return d->next;
        
    }
};