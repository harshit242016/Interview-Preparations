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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode *ptr = &dummy;
        
        int rem = 0;
        while(l1 or l2 or rem)
        {
            if(l1)
            {
                rem += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                rem += l2->val;
                l2 = l2->next;
            }
            
            ptr -> next = new ListNode(rem%10);
            ptr = ptr->next;
            rem = rem/10;
        }
        return dummy.next;
    }
};