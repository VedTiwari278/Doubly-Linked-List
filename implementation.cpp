                                                                                                  
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
   cout<<"1.Insert at beg \t 2.Insert at last \t 3.Insert at mid ";     // User choice accepted to implement singly linked list  
int ch;
cin>>ch;
switch(ch){
    case 1:
           int item;
           cout<<"Enter data to be inserted : ";
           cin>>item;
           insert_at_beg(item);    // Beginning insertion 
           Traversing();
           break;
    case 2: int value;
           cout<<"Enter data to be inserted : ";
           cin>>value;
           insert_at_End(value); // Last insertion 
           Traversing();
            break;

    case 3:int mid;
           cout<<"Enter data to be inserted : ";
           cin>>mid;
           insert_at_Mid(mid);   // Mid insertion
           Traversing(); 
           break;
    return 0;
}
cout<<"\nTo perform operation enter 1 "<<endl;
cin>>con;
}
}