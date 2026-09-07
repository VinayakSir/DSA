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
int Length(ListNode*head){
    ListNode*temp=head;
    if(!head)return 0;
    int length=1;
    while(temp->next){
        length++;
        temp=temp->next;
    }
    return length;
}

    
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int n = Length(head);
    k = k % n;
    if (k == 0) return head;

    // last node
    ListNode* lastnode = head;
    while (lastnode->next)     lastnode = lastnode->next;
    

    // index = n - k - 1 (new tail)
    int idx = n - k - 1;
    ListNode* index = head;
    for (int i = 0; i < idx; i++)     index = index->next;
    

    // rotation
    ListNode* newhead = index->next;
    index->next = NULL;
    lastnode->next = head;

    return newhead;
}

};