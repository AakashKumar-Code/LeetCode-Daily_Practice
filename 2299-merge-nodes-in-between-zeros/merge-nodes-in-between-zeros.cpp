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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* newH=new ListNode(-1);
        ListNode* nxt=newH;
        ListNode* node=head;

        while(node){
            if(node->val==0 && sum>0){
                ListNode* newN=new ListNode(sum);
                nxt->next=newN;
                nxt=nxt->next;
                sum=0;                
            }
            sum+=node->val;
            node=node->next;
        }
        return newH->next;
        
    }
};