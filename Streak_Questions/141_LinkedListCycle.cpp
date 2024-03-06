#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
};

bool hasCycle(ListNode *head)
{

    if (!head or !head->next)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast ? fast->next : fast;
    } while (slow && fast && slow != fast);

    return slow == fast;
}

int main()
{

    return 0;
}