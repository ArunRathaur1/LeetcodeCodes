class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Calculate the length of the list
        int length = 1;  // We start at 1 because we are considering the head
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        // Step 2: Compute the effective rotations needed (k % length)
        k = k % length;
        if (k == 0) return head;

        // Step 3: Find the new tail, which will be at position (length - k - 1)
        ListNode* newTail = head;
        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }

        // Step 4: Make the current tail point to the head
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        // Step 5: Connect the old tail to the old head
        temp->next = head;

        return newHead;
    }
};
