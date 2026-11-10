#include <bits/stdc++.h>
using namespace std;

/**
 * =================================================================================================
 * 61. Rotate List
 * =================================================================================================
 */

// Rotate List
// Solution: Circular Linked List and return new head

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head; // edge case

    int n = 1;
    ListNode *end = head;
    while (end->next != nullptr)
    {
        end = end->next;
        n++;
    }
    k %= n;
    // 2
    if (k == 0)
        return head;

    // circular
    end->next = head;

    ListNode *t = head; // new tail
    for (int i = 0; i < n - k - 1; ++i)
    {
        t = t->next;
    }
    ListNode *res = t->next;
    t->next = nullptr;
    return res;
}

int main()
{
    return 0;
}

/**
 * =================================================================================================
 * 141. Linked List Cycle
 * =================================================================================================
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Floyd's Cycle Detection (Two Pointers) - Recommended
bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    // Example usage:
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creates a cycle

    if (hasCycle(head))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle." << endl;
    }

    // Clean up memory (not shown here for brevity)
    return 0;
}
