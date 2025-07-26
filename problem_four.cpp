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

int get_size(Node1 *head)
{
    int count = 0;
    Node1 *tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void print_left_to_right(Node1 *head)
{
    Node1 *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_right_to_left(Node1 *tail)
{
    Node1 *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert_at_index(Node1 *&head, Node1 *&tail, int index, int val)
{
    int size = get_size(head);
    if (index < 0 || index > size)
    {
        cout << "Invalid" << endl;
        return;
    }

    Node1 *newNode = new Node1(val);

    if (index == 0)
    {
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    else if (index == size)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    {
        Node1 *tmp = head;
        for (int i = 0; i < index - 1; i++)
        {
            tmp = tmp->next;
        }

        Node1 *nextNode = tmp->next;
        tmp->next = newNode;
        newNode->prev = tmp;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    print_left_to_right(head);
    print_right_to_left(tail);
}

int main()
{
    Node1 *head = NULL;
    Node1 *tail = NULL;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;
        insert_at_index(head, tail, X, V);
    }

    return 0;
}
