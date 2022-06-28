#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;


template<typename T> 
class Node
{
   public:
   
   T key, value;
   Node<T>*top;
   Node<T>*bottom;
   Node<T>*left;
   Node<T>*right;
   
   Node()
   {
       left=NULL;
       right=NULL;
       top=NULL;
       bottom=NULL;
   }
   Node(T k,T v)
   {
      key=k;
      value=v;
   }
};

template<typename T> 
class skiplist
{
   private:
   
      Node<T>* head;
      Node<T>* tail;
      int maxi=10;
      int size=0;
      
   public:
     int resize()
     {
        return size;
     }
    
    
    void kskiplist(T mino,T maxo)
      {

        int n=maxi-1; 
        Node<T>*ptr =new Node<T>(mino,mino);
        Node<T>*ktr =new Node<T>(maxo,maxo);
        head=ptr;
        ktr->left=ptr;
        ptr->right=ktr; 
        
        while(n--)
        {
         Node<T>*ptr1=new Node<T>(mino,mino);
         Node<T>*ktr1=new Node<T>(maxo,maxo);
         ptr1->top=ptr; 
         ktr1->top=ktr;
         ptr1->right=ktr1;
         ktr1->left=ptr1;
         ptr->bottom=ptr1; 
         ktr->bottom=ktr1;
         ptr=ptr1; 
         ktr=ktr1; 
        }
        tail=ptr;
      }
      
     Node<T>* searched(T k,Node<T>* found)
     {
      Node<T>* temp=found; 
      while(!(k<temp->right->key))
      {
        temp=temp->right;
      }
      return temp;
     }
     
     Node<T>* search(T k)
     {
         

            Node<T>* ptr=head;
            while (ptr->bottom!=NULL)
            {
                ptr=ptr->bottom;
            
             if(ptr->right->right!=NULL)
             {
                while (k>=ptr->right->key)
                {
                    if(ptr->right->right!=NULL) ptr=ptr->right;
              
                   else break;
                }
             }
           }
           return ptr;
     }
     
     void insert(T k,T v)
     {
      Node<T>* current =searched(k,tail);  
      int count=maxi-1; 
      if(current->key==k)
      {
       return;
      }  
      else
      {
                 size++;
                Node<T> *addNode = new Node<T>(k,v);
                Node<T> *addr = current->right;
                current->right = addNode;
                addNode->left = current;
                addNode->right = addr;
                addr->left = addNode;
                while(rand()%2!=1 && count!=0)
                {
                    Node<T> *temp = new Node<T>(k,v);
                    
                    temp->bottom = addNode;
                    addNode->top = temp;
                    addNode = temp;
                    
                    while(current->top == NULL)
                    {
                        current = current->left;
                    }
                    
                    current = current->top;
                    Node<T> *addr = current->right;
                    current->right = temp;
                    addr->left = temp;
                    temp->right = addr;
                    temp->left = current;
                
                    count--;
         }
      }
      
     }
     void deletednode(T k)
     {
      Node<T>*p=search(k);
      if(p!=NULL)
      {
          if(p->key==k)
          {
        while(p!=NULL)
       {
        p->left->right=p->right; p->right->left=p->left;
        p=p->top;
       }
       size--; 
          }
          
      }
      
    }
         
};

template<typename T>
class Dictionary
{
   public:
    skiplist<T> K;
    Dictionary<T>(T a,T b){
        K.kskiplist(a,b);
    }
  void insert(T k,T v)
   {
     K.insert(k,v);
   }
   void deleteb(T k)
   {
      K.deletednode(k);
   }
   void find(T k)
   {
      if(K.search(k)->right==NULL||K.search(k)->left==NULL)
      {
          cout<<"NOT FOUND"<<endl;
          return;
          
      }
      else if(k==K.search(k)->key)
      {
          cout<<K.search(k)->value<<endl;
          
      }
       else cout<<"NOT FOUND"<<endl;
       return;
   }
   
   bool empty()
   {
      if(K.resize()==0)return true;
      else return false;
   }
   void size()
   {
      cout<<K.resize()<<endl;
   }
};

int main()
{
   string str;
   cin>>str;
    
   if(str=="INTEGERDICT")
   {
     
   int Q; 
   cin>>Q;
   string opcode; 
   Dictionary<int> D(INT_MIN,INT_MAX);
   while(Q--)
   {
      cin>>opcode;
     if(opcode=="SIZE")
     {
       D.size();
     }
     else if(opcode=="FIND")
     {
       int k; cin>>k; 
       D.find(k);
     }
     else if(opcode=="DELETE")
     {
       int k; cin>>k;
       D.deleteb(k);
     }
     else if(opcode=="ISEMPTY")
      {
        if(D.empty()==true)
        {
         cout<<"True"<<endl;
        }
        else
        {
         cout<<"False"<<endl;
        }
      }
     else if(opcode=="INSERT")
     {
       int v,k; 
       cin>>k>>v; 
       D.insert(k,v);
     }
     
    }
   
   }
   
   else if(str=="STRINGDICT")
   {
     
   int Q; 
   cin>>Q;
   string opcode; 
   Dictionary<string> D("A","}");
   while(Q--)
   {
      cin>>opcode;
     if(opcode=="SIZE")
     {
       D.size();
     }
     else if(opcode=="FIND")
     {
       string k; cin>>k; 
       D.find(k);
     }
     else if(opcode=="DELETE")
     {
       string k; cin>>k;
       D.deleteb(k);
     }
     else if(opcode=="ISEMPTY")
      {
        if(D.empty()==true)
        {
         cout<<"True"<<endl;
        }
        else
        {
         cout<<"False"<<endl;
        }
      }
     else if(opcode=="INSERT")
     {
       string v,k; 
       cin>>k>>v; 
       D.insert(k,v);
     }
     
    }
   
   }
}