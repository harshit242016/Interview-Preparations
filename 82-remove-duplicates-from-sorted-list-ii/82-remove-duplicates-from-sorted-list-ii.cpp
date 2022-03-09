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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL)
        {
            return head;
        }
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode *curr = head;
        ListNode *prev = &dummy;
        while(curr!=NULL)
        {
            while(curr->next != NULL and curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            if(prev->next == curr)
            {
                prev = prev->next;
            }
            else
            {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};