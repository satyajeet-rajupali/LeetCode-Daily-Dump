#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
};

ListNode *middleNode(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{

    return 0;
}