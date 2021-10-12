#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data)
{
    struct Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

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

int main()
{
    // Number of linked lists
    int k = 3;
 
    // Number of elements in each list
    int n = 4;
 
    // an array of pointers storing the
    // head nodes of the linked lists
    vector<Node*> arr(k);
 
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    // Merge all lists
    Solution obj;
    
    Node *ans = obj.mergeKLists(arr);
 
    printList(head);
 
    return 0;
}
