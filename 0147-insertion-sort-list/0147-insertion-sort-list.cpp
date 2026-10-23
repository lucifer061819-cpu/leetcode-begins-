class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            ListNode* prev = &dummy;

            // Find correct position
            while (prev->next && prev->next->val <= curr->val) {
                prev = prev->next;
            }

            // Insert current node
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy.next;
    }
};