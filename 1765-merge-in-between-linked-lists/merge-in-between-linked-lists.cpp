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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* end=list2;
        while(end!=NULL && end->next!=NULL){
            end=end->next;
        }
        ListNode* bNext=list1;
        while(b>=0){
            bNext=bNext->next;
            b--;
        }
        end->next=bNext;
        if(a==0){
            return list2;
        }
        ListNode* aPrev=list1;
        while(a>1){
            aPrev=aPrev->next;
            a--;
        }
        aPrev->next=list2;
        return list1;

        
    }
};