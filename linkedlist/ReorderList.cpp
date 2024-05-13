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

void reorderList(ListNode* head) {
    if (!head || !head->next) {
        return;
    }

    
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow->next;
    slow->next = nullptr;

    
    secondHalf = reverseList(secondHalf);

    
    ListNode* current = head;
    ListNode* temp = nullptr;

    while (current && secondHalf) {
        temp = current->next;
        current->next = secondHalf;
        secondHalf = secondHalf->next;
        current->next->next = temp;
        current = temp;
    }
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    reorderList(head1);
    printList(head1); // Output: 1 4 2 3

    // Example 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    reorderList(head2);
    printList(head2); // Output: 1 5 2 4 3

    return 0;
}
