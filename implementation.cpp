                                                                                                  
/*   
         Implementation of all operations of Doubly Linked List .
*/

#include <iostream>
using namespace std;

struct Node {
   int data;
   struct Node *next;
   struct Node *prev;
};


/* 
   =======================
   ALL INSERTION OPERAION 
   =======================
*/


Node *head = NULL;

/*   Insertion of item at the Head  */

void insert_at_beg(int data) 
{
    Node* newnode = new Node();
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=head;
    head = newnode;
    cout << "Inserted: " << newnode->data <<endl;
}
  
/* Insertion of item at the End  */
 
void insert_at_End(int data){
 Node*temp=head;
 Node* newnode=new Node();
 newnode->data=data;
 newnode->next=NULL;
 while(temp->next!=NULL){
   temp=temp->next;
 } 
 temp->next=newnode;
 newnode->prev=temp;
 
}

/*
  Insertion of item in the mid of linked list
 
*/


void insert_at_Mid(int data){
   Node* newnode=new Node();
   newnode->data=data;
   newnode->next=NULL;
   int key;
   cout<<"Enter Key value after which you want to insert";
   cin>>key;
   Node* temp=head;
   while(temp->data!=key){
      temp=temp->next;
   }
   newnode->next=temp->next;
   temp->next=newnode;
}

/*

    ======================
    ALL DELETION OPERATION
    ======================

*/

/*
  Deletion from the head/Start 
*/
void delete_from_head(){
Node* temp=head;
if(head->next==NULL){
   cout<<"List is Empty now .";
}
head=temp->next;
temp->next->prev=NULL;
}

/*
   Deletion from the Tail/End
*/
void delete_from_End(){
Node*temp=head;

if(head->next==NULL){
   cout<<"List is Empty now .";
}

while(temp->next!=NULL){
   temp=temp->next;
}
temp->prev->next=NULL;
}


// Node* head = nullptr;

void delete_from_Mid() {
    int key;
    cout << "Enter key to delete from the linked list: ";
    cin >> key;

    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* temp = head;

    // Traverse the list to find the node with the given key
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found
    if (temp == nullptr) {
        cout << "Key not found in the list." << endl;
        return;
    }

    // If the node to be deleted is the last node
    if (temp->next == nullptr) {
        cout << "The key is at the end of the list. Nothing to delete after it." << endl;
        return;
    }

    Node* node_to_delete = temp->next;

    // Update the links to remove the node from the list
    if (node_to_delete->next != nullptr) {
        node_to_delete->next->prev = temp;
    }
    temp->next = node_to_delete->next;

    // Free the memory of the node to be deleted
    delete node_to_delete;

    cout << "Node after the key has been deleted." << endl;
}

/*  Traversing of Doubly linked list */

void Traversing(){
   Node* temp=head;
   cout<<"\nElements of Linked List : ";
   while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
   }
}

int main()
{
int con=1;
while(con==1){
   cout<<"Choose your option : \n";
   cout<<"1.Insert at beg \t 2.Insert at last \t 3.Insert at mid \t 4.Delete from head \t 5.Delete from End/Tail \t 6.Delete the given node";     // User choice accepted to implement singly linked list  
int ch;
cin>>ch;
switch(ch){
    case 1:
           int item;
           cout<<"Enter data to be inserted : ";
           cin>>item;
           insert_at_beg(item);        // Beginning insertion 
           Traversing();
           break;
    case 2: int value;
           cout<<"Enter data to be inserted : ";
           cin>>value;
           insert_at_End(value);      // Last insertion 
           Traversing();
            break;

    case 3:int mid;
           cout<<"Enter data to be inserted : ";
           cin>>mid;
           insert_at_Mid(mid);       // Mid insertion
           Traversing(); 
           break;
         
    case 4:delete_from_head();      // Deletion from the head
           Traversing();
           break;
    case 5:delete_from_End();       // Deletion from the End/Tail
           Traversing();
           break;
         
    case 6:delete_from_Mid();
           Traversing();
           break;
    return 0;
}
cout<<"\nTo perform operation enter 1 "<<endl;
cin>>con;
}
}


/*

                  Created by Ved Tiwari

*/