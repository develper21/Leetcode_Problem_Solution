/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    /**
     * Adds two numbers represented as linked lists.
     *
     * @param l1 The first linked list, representing the first number.
     * @param l2 The second linked list, representing the second number.
     * @return The sum as a linked list.
     */
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Initialize a dummy head for the result linked list.  This simplifies the logic
        // for creating the first node of the result.
        ListNode dummyHead = new ListNode(0);

        // `current` node will traverse the result linked list as we build it.
        ListNode current = dummyHead;

        // `carry` stores the carry-over value from each digit addition. Initialized to 0.
        int carry = 0;

        // Iterate as long as either linked list has nodes remaining, or there's a carry.
        while (l1 != null || l2 != null || carry != 0) {
            // Get the values from the current nodes of l1 and l2.  If a list is exhausted,
            // treat its value as 0.
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;

            // Calculate the sum of the current digits and the carry.
            int sum = x + y + carry;

            // Update the carry for the next digit.  The carry is the tens digit of the sum.
            carry = sum / 10;

            // The digit to add to the result linked list is the ones digit of the sum.
            current.next = new ListNode(sum % 10);

            // Move `current` to the newly created node.
            current = current.next;

            // Advance l1 and l2 if they are not null.
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }

        // After the loop, the `dummyHead.next` points to the head of the result linked list.
        return dummyHead.next;
    }
}