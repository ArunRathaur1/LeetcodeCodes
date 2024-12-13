class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1, head); // Dummy node to simplify edge cases
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // Skip all nodes with the same value
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next; // Link prev to the node after duplicates
            } else {
                prev = curr; // Move prev to the current node if no duplicates
            }
            curr = curr->next; // Move to the next node
        }

        return dummy->next;
    }
};
