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
    {
        return head; // edge case
    }
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