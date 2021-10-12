class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        
        else if(l2 == NULL)
            return l1;
        
        else if(l1->val <= l2->val)
        {
            l1->next = merge(l1->next, l2);
            
            return l1;
        }
        
        else{
            l2->next = merge(l1, l2->next);
            
            return l2;
        }
        return NULL;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        
        for(int i = 0; i < lists.size(); i++)
        {
            head = merge(head, lists[i]);
        }
        
        return head;
    }
};
