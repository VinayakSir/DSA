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
    ListNode* Reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* prev = NULL;

    while (current) {
        ListNode* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

ListNode* findKthNode(ListNode* head, int k) {
    ListNode* temp = head;
    k--;

    while (temp && k > 0) {
        temp = temp->next;
        k--;
    }
    return temp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode* temp = head;
    ListNode* prev = NULL;

    while (temp) {
        ListNode* KthNode = findKthNode(temp, k);

        if (KthNode == NULL) {
            if (prev) prev->next = temp;
            break;
        }

        ListNode* nextNode = KthNode->next;
        KthNode->next = NULL;

        ListNode* newHead = Reverse(temp);

        if (temp == head)
            head = newHead;
        else
            prev->next = newHead;

        prev = temp;
        temp = nextNode;
    }

    return head;
}
};