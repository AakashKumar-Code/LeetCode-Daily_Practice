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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* node=head->next;
        vector<int>arr;
        int cnt=2;

        ListNode* prev=head;
        while(node->next){
            if((node->val>prev->val && node->val>node->next->val) ||
             (node->val<prev->val && node->val<node->next->val)){
                arr.push_back(cnt);
             }
             cnt++;
             prev=node;
             node=node->next;
        }

        int mini=1e9;
        int sz=arr.size();

        if(sz<=1) return {-1, -1};

        for(int i=1; i<sz; i++){
            mini=min(mini, arr[i]-arr[i-1]);
        }

        return {mini, arr[sz-1]-arr[0]};
    }
};