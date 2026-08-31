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
        vector<int>tmp;
        ListNode* node=head->next;
        ListNode* prev=head;
        int ind=1;

        while(node){
            if(node->next){
                int amt=node->val;
                int nxt=node->next->val;
                int prv=prev->val;

                if((amt>nxt && amt>prv) || (amt<nxt && amt<prv)){
                    tmp.push_back(ind);
                }
            }
            ind++;
            prev=node;
            node=node->next;
        }

        if(tmp.size()<=1) return {-1, -1};

        int minD=1e9;

        for(int i=1; i<tmp.size(); i++){
            minD=min(minD, tmp[i]-tmp[i-1]);
        }

        return {minD, tmp[tmp.size()-1]-tmp[0]};

    }
};