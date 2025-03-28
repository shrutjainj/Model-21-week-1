#include<iostream>
using namespace std;
class Node
{
public:
    int value;
    Node* next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class Linkedlist
{
public:
    Node* head;
    Node* tail;
    int size;
    Linkedlist()
    {
        head = tail = NULL; // Ek kali linked list banai mani
        size = 0;
    }
    void insertAtEnd(int value)
    {
        Node* temp = new Node(value);
        if(size == 0) head = tail = temp;
        else
        {
            tail->next = temp; // temp is 8000 yaha tail is 8 and tail ke next address me 8000
            tail = temp; // tail ko 8000 bana dyaa
        } // apne pass linked list ha [1,2,3,8] tail  is the that 8
        // apan ko linked list banani ha [1,2,3,8,8000] tail me 8000 ka address daaldo and ab line 34 me tail me 8000 daaldo
        size++;
    }
    void insertAtHead( int value)
    {
        Node* temp = new Node(value);
        if(size == 0) head = tail = temp;
        else
        {
            temp->next = head; // temp me head ka address
            head = temp; // temp ko head(start) of the linked list banao 
        }
        size++;
    }

    void insertAtIndex(int i, int value)
    {
        if(i < 0 || i > size) cout<<"invalid syntax is then"<<endl;
        else if(i == 0) insertAtHead(value);
        else if(i == size) insertAtEnd(value);
        else // (i>0 && i<size)
        {
            Node* a = new Node(value);
            Node* temp = head;
            for(int j=0; j<i-1; j++)
            {
                temp = temp->next;
            }
            a->next = temp->next;
            temp->next = a;
            size++;
        }
    }
    void display()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->value<<endl;
            temp = temp->next; 
        }
    }
};
int main()
{
    Linkedlist li;
    li.insertAtEnd(10);
    li.insertAtEnd(20);
    li.insertAtEnd(100);
    li.insertAtHead(5);
    li.insertAtHead(1);
    li.insertAtIndex(4, 80);
    cout<<li.size;
    cout<<endl;
    li.display();
    return 0;
}