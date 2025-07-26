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

void insert_at_tail1(Node1 *&head, Node1 *&tail, int val)
{
    Node1 *newNode = new Node1(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void print_list(Node1 *head)
{
    Node1 *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void sort_doubly_linked_list(Node1 *head)
{
    for (Node1 *i = head; i != NULL; i = i->next)
    {
        for (Node1 *j = i->next; j != NULL; j = j->next)
        {
            if (i->val > j->val)
            {
                swap(i->val, j->val);
            }
        }
    }
}

int main()
{
    Node1 *head = NULL;
    Node1 *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail1(head, tail, val);
    }

    sort_doubly_linked_list(head);
    print_list(head);

    return 0;
}
