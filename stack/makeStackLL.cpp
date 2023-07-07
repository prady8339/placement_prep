#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
};
int main()
{
    Node *head = NULL;
    Node *remp = NULL;

    int i = 1;

    while (i <= 10)
    {

        Node *temp = new Node();
        temp->data = i;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            remp = head;
        }
        remp->next = temp;
        i++;
        remp = remp->next;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " - ";
        temp = temp->next;
    }
}
