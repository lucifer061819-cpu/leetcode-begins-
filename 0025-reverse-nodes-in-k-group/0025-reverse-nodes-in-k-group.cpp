class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int count = 0;

        while (current != nullptr && count < k) {
            current = current->next;
            count++;
        }

        if (count < k)
            return head;

        ListNode* prev = nullptr;
        current = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head->next = reverseKGroup(current, k);

        return prev;
    }
};