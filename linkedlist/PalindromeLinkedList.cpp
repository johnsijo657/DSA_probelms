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

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseList(slow->next);
    slow = slow->next;

    while (slow != nullptr) {
        if (head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }

    return true;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);

    cout << (isPalindrome(head1) ? "true" : "false") << endl;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << (isPalindrome(head2) ? "true" : "false") << endl;

    return 0;
}
