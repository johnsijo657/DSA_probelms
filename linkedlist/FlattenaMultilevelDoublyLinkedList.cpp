#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

Node* flatten(Node* head) {
    if (!head) return head;

    Node* current = head;
    while (current) {
        if (current->child) {
            Node* nextNode = current->next;
            Node* childList = flatten(current->child);
            current->next = childList;
            childList->prev = current;
            current->child = nullptr;

            while (current->next) {
                current = current->next;
            }

            current->next = nextNode;
            if (nextNode) {
                nextNode->prev = current;
            }
        }
        current = current->next;
    }
    return head;
}


void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example 1
    Node* head1 = new Node();
    head1->val = 1;
    head1->next = new Node();
    head1->next->val = 2;
    head1->next->prev = head1;
    head1->next->next = new Node();
    head1->next->next->val = 3;
    head1->next->next->prev = head1->next;
    head1->next->next->next = new Node();
    head1->next->next->next->val = 4;
    head1->next->next->next->prev = head1->next->next;
    head1->next->next->next->next = new Node();
    head1->next->next->next->next->val = 5;
    head1->next->next->next->next->prev = head1->next->next->next;
    head1->next->next->next->next->next = new Node();
    head1->next->next->next->next->next->val = 6;
    head1->next->next->next->next->next->prev = head1->next->next->next;
    head1->next->next->child = new Node();
    head1->next->next->child->val = 7;
    head1->next->next->child->next = new Node();
    head1->next->next->child->next->val = 8;
    head1->next->next->child->next->prev = head1->next->next->child;
    head1->next->next->child->next->child = new Node();
    head1->next->next->child->next->child->val = 11;
    head1->next->next->child->next->child->prev = head1->next->next->child->next;
    head1->next->next->child->next->child->next = new Node();
    head1->next->next->child->next->child->next->val = 12;
    head1->next->next->child->next->child->next->prev = head1->next->next->child->next->child;
    head1->next->next->next->next->next->child = new Node();
    head1->next->next->next->next->next->child->val = 9;
    head1->next->next->next->next->next->child->next = new Node();
    head1->next->next->next->next->next->child->next->val = 10;
    head1->next->next->next->next->next->child->next->prev = head1->next->next->next->next->next->child;
    head1->next->next->next->next->next->next = nullptr;

    Node* flattenedList1 = flatten(head1);
    printList(flattenedList1);

    // Example 2
    Node* head2 = new Node();
    head2->val = 1;
    head2->next = new Node();
    head2->next->val = 2;
    head2->next->prev = head2;
    head2->next->next = nullptr;
    head2->next->child = new Node();
    head2->next->child->val = 3;
    head2->next->child->next = nullptr;

    Node* flattenedList2 = flatten(head2);
    printList(flattenedList2);

    // Example 3
    Node* head3 = nullptr;

    Node* flattenedList3 = flatten(head3);
    printList(flattenedList3);

    return 0;
}
