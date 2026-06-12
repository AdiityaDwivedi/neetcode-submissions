class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        while(temp != NULL) {
            st.push(temp -> val);
            temp = temp -> next;
        }

        ListNode* temp2 = head;

        while(temp2 != NULL) {
            temp2 -> val = st.top();
            st.pop();
            temp2 = temp2 -> next;
        }

        return head;
    }
};
