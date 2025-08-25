#include<iostream>
#include<vector>
using namespace std;

class node{
public:
int data;
node* next;
public:
node(int data1,node* next1)
{
    data=data1;
    next=next1;
}

node (int data1)
{
    data=data1;
    next=nullptr;
}
};

node* arr2LL(vector<int>&a)
{
    node *head=new node(a[0]);
    node *temp=head;
    int cnt=1;
    for(int i=1;i<a.size();i++)
    {
     node *newnode=new node(a[i]);
     temp->next=newnode;
     temp=newnode;
     cnt++;
    }
    cout<<"\nLength: "<<cnt<<endl;
   return head;
}

bool searchele(node* head,int val)
{
node *temp=head;
while(temp)
{
    if(temp->data==val)
    {
        return 1;
    }
    temp=temp->next;
}
return 0;
}


int main()
{
  vector<int>a={1,2,3,4,5,24,89};
  node *head=nullptr;
  head=arr2LL(a);
   node *temp=head;
    while(temp)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n"<<searchele(head,30);
    return 0;
}
