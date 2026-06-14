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

    ListNode* rev(ListNode *node){
        ListNode* prev=NULL;
        while(node){
            ListNode* nxt=node->next;
            node->next=prev;
            prev=node;
            node=nxt;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        slow=rev(slow);
        int maxi=-1e9;
        while(slow && head){
            maxi=max(maxi, slow->val+head->val);
            head=head->next;
            slow=slow->next;
        }
        return maxi;        
    }
};