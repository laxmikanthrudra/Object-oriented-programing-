#include <cmath>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//creating class node 
template<class T>
class node
{
  public:
   node *left;
   node *right;
   T val;
    node(T data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};

//creating class Dlist
template<class T>
class Dlist
{
  private:
   node<T> *head=NULL;
   node<T> *tail=NULL;
   
  public:
//pushing element at end into the double linked list
  void push_end(T r)
  {
    node<T>* n=new node<T>(r);
    if(head==NULL)
    {
      head=n;
      tail=n;
      return ;
    }
    node<T>* temp=head;
    while(temp->right!=NULL)
    {
       temp = temp->right;
    }
    temp->right=n;
    n->left=temp;
    tail=n;
  }
//pushing element at front into the double linked list
void push_front(T r)
{
  node<T>* n=new node<T>(r);
    if(head==NULL)
    {
      head=n;
      tail=n;
      return ;
    }
    head->left=n;
    n->right=head;
    head=n;
}
//poping the front element and return it
T pop_front()
{
  if(head==NULL)
  {
    return 0 ;
  }
  node<T> *deletednode1;
  deletednode1=head;
  head=deletednode1->right;
  return (deletednode1->val) ;
}
//poping the end element and return it
T pop_end()
{
  if(tail==NULL)
  {
    return 0 ;
  }
  node<T> *deletednode2;
  deletednode2=tail;
  tail=deletednode2->left;
 return (deletednode2->val) ;
}
//find the size of the linked list
int size()
{
  int number=0;
  node<T> *current=head;
  while(current!=NULL)
  {
    current=current->right;
    number++;
  }
  return number;
}


};

//creating class stacka
template<class T>
class stacka
{
  private:
   Dlist<T> L;
  public:
  //pushing element into the stacka
   void push(T k)
   {

     L.push_front(k) ;
   }
   //poping the top element and printing it
   void pop()
   {
     cout<<L.pop_front(); 
   }
   //finding the sdize of stacka
  int sizeofstack()
   {
     return (L.size() );
   }
   
   //returning the top element in the stacka
  T returntop()
  {
    T ele=L.pop_front();
    L.push_front(ele);
    return ele;
  }
  //comparing the top element and the element the should push
  bool compare(T On)
  {
    T coparator=returntop();
    if(On>coparator)return true;
    else return false;

  }

};



int main() {
    int n;
    cin>>n;
    char q;
    cin>>q;
    //for int data type
    if(q=='I')
    {
      stacka<int> s;
      int arr[n];
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      for(int i=0;i<n;i++)
      {
        if(s.sizeofstack()==0)
        {
          s.push(arr[i]);
        }
        else
        {
          if(s.compare(arr[i]))
          {
            s.push(arr[i]);
          }
          else
          {
            while(!s.compare(arr[i]))
            {
              s.pop();
            }
            s.push(arr[i]);
          }
        }
      }
      int sizes=s.sizeofstack();
      while(sizes--&&sizes!=0)
      {
        s.pop();
      }
    }
    //for char data type
    if(q=='C')
    {
      stacka<char> s;
      char arr[n];
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      for(int i=0;i<n;i++)
      {
        if(s.sizeofstack()==0)
        {
          s.push(arr[i]);
        }
        else
        {
          if(s.compare(arr[i]))
          {
            s.push(arr[i]);
          }
          else
          {
            while(!s.compare(arr[i]))
            {
              s.pop();
            }
            s.push(arr[i]);
          }
        }
      }
      int sizes=s.sizeofstack();
      while(sizes--&&sizes!=0)
      {
        s.pop();
      }
    }
    //for float data type
    if(q=='F')
    {
      stacka<float> s;
      float arr[n];
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      for(int i=0;i<n;i++)
      {
        if(s.sizeofstack()==0)
        {
          s.push(arr[i]);
        }
        else
        {
          if(s.compare(arr[i]))
          {
            s.push(arr[i]);
          }
          else
          {
            while(!s.compare(arr[i]))
            {
              s.pop();
            }
            s.push(arr[i]);
          }
        }
      }
      int sizes=s.sizeofstack();
      while(sizes--&&sizes!=0)
      {
        s.pop();
      }
    }


    return 0;
}   
