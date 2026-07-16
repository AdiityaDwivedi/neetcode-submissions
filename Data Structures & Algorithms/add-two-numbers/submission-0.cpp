class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 != NULL || temp2 != NULL || carry != 0) {
            int k1 = 0, k2 = 0;

            if(temp1 != NULL) {
                k1 = temp1 -> val;
                temp1 = temp1 -> next;
            }

            if(temp2 != NULL) {
                k2 = temp2 -> val;
                temp2 = temp2 -> next;
            }

            int sum = k1 + k2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);

            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail -> next = newNode;
                tail = newNode;
            }
        }

        return head;
    }
};