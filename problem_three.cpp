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

bool is_palindrome(Node1 *head, Node1 *tail)
{
    while (head != NULL && tail != NULL && head != tail && head->prev != tail)
    {
        if (head->val != tail->val)
        {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
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

    if (is_palindrome(head, tail))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
