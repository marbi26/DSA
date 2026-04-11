#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    // Step 1: Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    ListNode* prev = NULL;
    ListNode* curr = slow;
    while (curr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    // Step 3: Compare
    ListNode* left = head;
    ListNode* right = prev;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

int main() {
    // Test 1: 1 -> 2 -> 2 -> 1  (true)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << boolalpha << isPalindrome(head) << endl;

    // Test 2: 1 -> 2  (false)
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    cout << boolalpha << isPalindrome(head2) << endl;

    // Test 3: 1 -> 2 -> 3 -> 2 -> 1  (true)
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(2);
    head3->next->next->next->next = new ListNode(1);
    cout << boolalpha << isPalindrome(head3) << endl;

    // Test 4: single node 1  (true)
    ListNode* head4 = new ListNode(1);
    cout << boolalpha << isPalindrome(head4) << endl;

    return 0;
}
