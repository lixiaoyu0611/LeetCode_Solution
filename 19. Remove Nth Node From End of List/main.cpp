/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* behind = head;
        while (front != NULL) {
            front = front->next;
            if (n-- < 0) behind = behind->next;
            }
            if (n == 0) head = head->next;
            else behind->next = behind->next->next;
            return head;
    }
};