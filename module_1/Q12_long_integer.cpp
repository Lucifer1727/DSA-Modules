/*
Q.12) Write a function to compare two long integer linked lists and determine which one is
greater, less than, or equal to the other
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x = 0)
    {
        data = x;
        next = NULL;
    }
};
// function to insert at beginning
void insertAtBeginning(node *&head, int data)
{
    node *newNode = new node(data);
    newNode->next = head;
    head = newNode;
}
// function to print the linked list
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}
// function to know size of linked list
int size(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// function to convert int to linkedlist
node *intToLink(string n)
{
    node *link = new node();
    link = link->next;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        insertAtBeginning(link, n[i] - '0');
    }

    return link;
}
// comparison function for linked list
void compare(node *a1, node *a2)
{
    if (size(a1) > size(a2))
    {
        cout << "First is greater than Second" << endl;
        return;
    }
    else if (size(a1) < size(a2))
    {
        cout << "First is smaller than Second" << endl;
        return;
    }
    else
    {
        while (a1 != NULL)
        {
            if (a1->data > a2->data)
            {
                cout << "First is greater than Second" << endl;
                return;
            }
            else if (a1->data < a2->data)
            {
                cout << "First is smaller than Second" << endl;
                return;
            }
            a1 = a1->next;
            a2 = a2->next;
        }
        cout<<"Both are same\n";
    }
    return;
}

void test() {
    // Test case 1: Both linked lists are equal
    string x1 = "123456789";
    string x2 = "123456789";
    node *n1 = intToLink(x1);
    node *n2 = intToLink(x2);
    compare(n1, n2); // Expected output: Both are same

    // Test case 2: First linked list is greater than second
    x1 = "123456789";
    x2 = "987654321";
    n1 = intToLink(x1);
    n2 = intToLink(x2);
    compare(n1, n2); // Expected output: First is smaller than Second

    // Test case 3: Second linked list is greater than first
    x1 = "987654321";
    x2 = "123456789";
    n1 = intToLink(x1);
    n2 = intToLink(x2);
    compare(n1, n2); // Expected output: First is greater than Second
}

int main()
{
    test();
    return 0;
}