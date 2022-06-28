#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Node{

friend class Trie;
private:

vector<Node *> next ;
bool isEnd ;
Node()
{
  next.resize(26,NULL);
  isEnd=false ;
}
};

class Trie {
private:
    Node* root=NULL;
    
public:
Trie()
  {
    root=new Node;
  }
  Node* updatednode()
  {
    Node* Newn=new Node;
    return Newn;
  }

    //insert prefix
void insert( string key)
{
    Node *temp = root;
 
    for (int i = 0; i < key.size(); i++)
    {
        int ind ;
        ind= key[i] - 'a';
        if (!temp->next[ind])
            temp->next[ind] =updatednode();
 
        temp= temp->next[ind];
    }
    temp->isEnd = true;
}
//search and print prefix
void search(string key)
{
        Node *temp=root;
        string shortl="",longl="";
        int flag=0;
        int num=key.size();
         
        for(int i=0;i<num;i++)
        {
          int ind ;
          ind= key[i] - 'a';
            if(!temp->next[ind])
            {
                if(temp->isEnd)
                {
                    cout<<shortl<<" ";
                    return;
                }
                else break;
            }
            else
            {
                if(temp->isEnd)
                {
                    flag=1;
                    longl=shortl;
                }
                shortl=shortl+key[i];
                temp=temp->next[ind];
            }
        }
        if(flag){
           cout<<longl<<" ";
            return ;
        }
        else if(temp->isEnd){
          cout<<shortl<<" ";
            return ;
        }
        cout<<key<<" ";
        return ;
    }
};


int main() {
    int p;
  cin>>p;
  string sam;
  Trie T;
  for(int i=0;i<p;i++)
    {
      cin>>sam;
      T.insert(sam);
    }
  
  int n;
  cin>>n;
  string kan;
  for(int j=0;j<n;j++)
    {
      cin>>kan;
      T.search(kan);
    }
    cout<<endl;
  }