#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    unordered_map<Node*, Node*> nodeMap; 

   
    Node* current = head;
    while (current) {
        Node* copy = new Node(current->val);
        nodeMap[current] = copy;
        current = current->next;
    }

   
    current = head;
    while (current) {
        nodeMap[current]->next = nodeMap[current->next];
        nodeMap[current]->random = nodeMap[current->random];
        current = current->next;
    }

    
    current = head;
    Node* copiedHead = nodeMap[head];
    while (current) {
        nodeMap[current]->next = nodeMap[current->next];
        current = current->next;
    }

    return copiedHead;
}


void printRandomList(Node* head) {
    while (head) {
        cout << "[" << head->val << ",";
        if (head->random) {
            cout << head->random->val;
        } else {
            cout << "null";
        }
        cout << "] ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example 1
    Node* head1 = new Node(7);
    head1->next = new Node(13);
    head1->next->next = new Node(11);
    head1->next->next->next = new Node(10);
    head1->next->next->next->next = new Node(1);
    head1->next->random = head1;
    head1->next->next->random = head1->next->next->next->next;
    head1->next->next->next->random = head1->next->next;
    head1->next->next->next->next->random = head1;

    Node* copiedList1 = copyRandomList(head1);
    printRandomList(copiedList1); // Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

    // Example 2
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->random = head2->next;
    head2->next->random = head2->next;

    Node* copiedList2 = copyRandomList(head2);
    printRandomList(copiedList2); // Output: [[1,1],[2,1]]

    // Example 3
    Node* head3 = new Node(3);
    head3->next = new Node(3);
    head3->next->next = new Node(3);
    head3->next->random = head3;

    Node* copiedList3 = copyRandomList(head3);
    printRandomList(copiedList3); // Output: [[3,null],[3,0],[3,null]]

    return 0;
}
