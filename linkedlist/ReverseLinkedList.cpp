#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
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

    ListNode* reversedList1 = reverseList(head1);
    printList(reversedList1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    ListNode* reversedList2 = reverseList(head2);
    printList(reversedList2);

    ListNode* head3 = nullptr;

    ListNode* reversedList3 = reverseList(head3);
    printList(reversedList3);

    return 0;
}
