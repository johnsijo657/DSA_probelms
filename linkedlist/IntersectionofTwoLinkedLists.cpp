#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    while (p1 != p2) {
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }

    return p1;
}

ListNode* createList(int arr[], int n, int intersectPos) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* intersectNode = nullptr;

    for (int i = 0; i < n; ++i) {
        ListNode* newNode = new ListNode(arr[i]);
        if (i == intersectPos) {
            intersectNode = newNode;
        }
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {4,1,8,4,5};
    ListNode* listA = createList(arr1, 5, 2);

    int arr2[] = {5,6,1,8,4,5};
    ListNode* listB = createList(arr2, 6, 3);

    ListNode* result1 = getIntersectionNode(listA, listB);
    if (result1) {
        cout << "Intersected at " << result1->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    int arr3[] = {1,9,1,2,4};
    ListNode* listC = createList(arr3, 5, 3);

    int arr4[] = {3,2,4};
    ListNode* listD = createList(arr4, 3, 1);

    ListNode* result2 = getIntersectionNode(listC, listD);
    if (result2) {
        cout << "Intersected at " << result2->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    int arr5[] = {2,6,4};
    ListNode* listE = createList(arr5, 3, -1);

    int arr6[] = {1,5};
    ListNode* listF = createList(arr6, 2, -1);

    ListNode* result3 = getIntersectionNode(listE, listF);
    if (result3) {
        cout << "Intersected at " << result3->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
