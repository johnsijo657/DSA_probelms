#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slow = dummy;
    ListNode* fast = dummy;

    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    ListNode* result1 = removeNthFromEnd(head1, 2);
    printList(result1);
    ListNode* head2 = new ListNode(1);
    ListNode* result2 = removeNthFromEnd(head2, 1);
    printList(result2);
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    ListNode* result3 = removeNthFromEnd(head3, 1);
    printList(result3);
    return 0;
}
