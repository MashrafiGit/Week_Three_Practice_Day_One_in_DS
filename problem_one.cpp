#include <bits/stdc++.h>
using namespace std;

class Node1
{
public:
    int val;
    Node1 *next;
    Node1 *prev;

    Node1(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Node2
{
public:
    int val;
    Node2 *next;
    Node2 *prev;

    Node2(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail1(Node1 *&head, Node1 *&tail, int val)
{
    Node1 *newNode1 = new Node1(val);
    if (head == NULL)
    {
        head = newNode1;
        tail = newNode1;
    }
    else
    {
        tail->next = newNode1;
        newNode1->prev = tail;
        tail = newNode1;
    }
}

void insert_at_tail2(Node2 *&head, Node2 *&tail, int val)
{
    Node2 *newNode2 = new Node2(val);
    if (head == NULL)
    {
        head = newNode2;
        tail = newNode2;
    }
    else
    {
        tail->next = newNode2;
        newNode2->prev = tail;
        tail = newNode2;
    }
}

bool compare_lists(Node1 *head1, Node1 *tail1, Node2 *head2, Node2 *tail2)
{
    Node1 *current1 = head1;
    Node2 *current2 = head2;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->val != current2->val)
        {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 != NULL || current2 != NULL)
    {
        return false;
    }
    return true;
}

int main()
{
    Node1 *head1 = NULL;
    Node1 *tail1 = NULL;

    int val1;
    while (true)
    {
        cin >> val1;
        if (val1 == -1)
        {
            break;
        }
        insert_at_tail1(head1, tail1, val1);
    }

    Node2 *head2 = NULL;
    Node2 *tail2 = NULL;

    int val2;
    while (true)
    {
        cin >> val2;
        if (val2 == -1)
        {
            break;
        }
        insert_at_tail2(head2, tail2, val2);
    }

    bool isEqual = compare_lists(head1, tail1, head2, tail2);

    isEqual ? cout << "YES" : cout << "NO";

    return 0;
}
