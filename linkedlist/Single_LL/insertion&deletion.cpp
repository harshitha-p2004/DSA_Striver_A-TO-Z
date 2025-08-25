

#include<iostream>
using namespace std;

class node{
    public:
int data;
node *next;

node(int data1,node* next1)
{
    data=data1;
    next=next1;
}
node(int data1)
{
data =data1;
next=nullptr;
}
};


node* insertathead(node* head, int val)
{
    return new node(val,head);
}

node* inserattail(node *head, int val)
{
    node *temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=new node(val);
    return head;
}

node* insertatpos(node *head, int val,int k)
{
    if(head==nullptr)
    {
        if(k==1)
        return new node(val);
    }
    if(k==1)
    {
        return new node(val,head);
    }
    node* temp=head;
    int cnt=0;
    node *newnode= new node(val);
    while(temp!=0)
    {
        cnt++;
        if(cnt==k-1)
        {
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

node* insertele(node *head, int val, int k)
{
    if(head->data==k)
    {
        return new node(val,head);
    }
    node* temp=head;
    node *newnode= new node(val);
    while(temp->next!=0)
    {
        if(temp->next->data==k)
        {
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

node* deleteathead(node* head)
{
    node *temp=head;
    head=head->next;
    free(temp);
    return head;
}

node* deleteattail(node* head)
{
    if(head==nullptr)return head;
    node* temp=head;
    while(temp->next->next!=0)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=0;
    return head;
}

node * deleteatpos(node* head, int k)
{
    if(head==nullptr)return head;
    if(k==1)
    {
        node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    node *temp=head;
    while(temp!=0)
    {
        cnt++;
        if(cnt==k-1)
        {
            node *d=temp->next;
            temp->next=temp->next->next;
            delete d;
            break;
        }
        temp=temp->next;
    }
    return head;
}

node *deleteval(node *head, int k)
{
    if(head==nullptr)return head;
    if(head->data==k)
    {
        node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    
    node *temp=head;
    while(temp!=0)
    {
        
        if(temp->next->data==k)
        {
            node *d=temp->next;
            temp->next=temp->next->next;
            delete d;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
  node *head=nullptr;
  head=insertathead(head,1);
  head=inserattail(head,100);
  head=insertatpos(head,99,2);
  head=insertathead(head,13);
  head=inserattail(head,32);
  head=insertele(head, 56,32);
  head=insertele(head,78,13);
  head=inserattail(head,45);
  head=insertele(head,569,99);
  head=deleteval(head,45);
  node *temp=head;
  while(temp!=0)
  {
    cout<<temp->data<<"\t";
    temp=temp->next;
  }

    return 0;
}
