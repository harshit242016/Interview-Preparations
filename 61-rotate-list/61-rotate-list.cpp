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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head or !head->next or !k)
        {
            return head;
        }
        
        int count = 1;
        
        ListNode *ptr = head;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
            count++;
        }
        
        k = k%count;
        ptr -> next = head;
        ListNode *curr = head;
        
        for(int i = 0;i<count-k-1;i++)
        {
            curr = curr->next;
        }
        
        head = curr->next;
        curr -> next = NULL;
        return head;
    }
};