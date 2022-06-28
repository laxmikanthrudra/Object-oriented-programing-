#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//creating class node 
class node
{
  public:
   node *right;
   int val;
    node(int data)
    {
        val=data;
        right=NULL;
    }
};

//creating class Dlist

class Dlist
{
  private:
   node *head=NULL;
   
  public:
  
//pushing element at front into the double linked list
void push_front(int r)
{
  node* n=new node(r);
    if(head==NULL)
    {
      head=n;
      return ;
    }
    n->right=head;
    head=n;
}
//poping the front element and return it
int pop_front()
{
  if(head==NULL)
  {
    return -1 ;
  }
  node *deletednode1;
  deletednode1=head;
  head=deletednode1->right;
  return (deletednode1->val) ;
}

//find weather the linked list is empty or not
int size()
{
  if(head==NULL)
  {
    return 1;
  }
  else return 0;
}


};

//creating class stacka
class stacka
{
  private:
   Dlist L;
  public:
  //pushing element into the stacka
   void push(int k)
   {

     L.push_front(k) ;
   }
   //poping the top element and printing it
   void pop()
   {
     cout<<L.pop_front()<<endl; 
   }
   //finding the sdize of stacka
  int isEmpty()
   {
     return (L.size() );
   }
   
   //returning the top element of the stack
  int Top()
  {
    if(L.size())
    {
      return -1;
    }
    int ele=L.pop_front();
    L.push_front(ele);
    return ele;
  }
  

};


class Graph {
   private:
  int** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int num) {
    numVertices = num;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new int[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void operator += (pair<int,int>p) {
    adjMatrix[p.first][p.second] = true;
    adjMatrix[p.second][p.first] = true;
  }

  // Remove edges
  void operator -= (pair<int,int>p) {
    adjMatrix[p.first][p.second] = false;
    adjMatrix[p.second][p.first] = false;
  }


 // detecting cycle

bool dfs(int vertex, set<int>&visited, int parent) {
   visited.insert(vertex);
   for(int v = 0; v<numVertices; v++) {
      if(adjMatrix[vertex][v]) {
         if(v == parent)    //if v is the parent not move that direction
            continue;
         if(visited.find(v) != visited.end())    //if v is already visited
            return true;
         if(dfs(v, visited, vertex))
            return true;
      }
   }
   return false;
}

bool detectCycle() {
   set<int> visited;       //visited set
   for(int v = 0; v<numVertices; v++) {
      if(visited.find(v) != visited.end())    //when visited holds v, jump to next iteration
         continue;
      if(dfs(v, visited, -1)) {    //-1 as no parent of starting vertex
         return true;
      }
   }
   return false;
    
    
}

//reach u,v
bool reach(int u,int v)
{
      if (adjMatrix[u][v] == 1)
        return true;
    else
        return false;
}
// Print the martix
    
friend ostream& operator <<(ostream &s,Graph G);


};
ostream& operator <<(ostream&s,Graph G){
    for(int i=0;i<G.numVertices;i++){
        for(int j=0;j<G.numVertices;j++){
            s <<G.adjMatrix[i][j]<<" ";
        }
        s<<endl;
    }
    return s;
}



int main() {
  int Q;
  cin>>Q;
  string opcode;
  stacka s;
  while(Q--)
    {
      cin>>opcode;
      if(opcode=="push")
      {
        int a;
        cin>>a;
        s.push(a); 
      }
      else if(opcode=="pop")
      {
        s.pop();
      }
      else if(opcode=="top")
      {
        cout<<s.Top()<<endl;
      }
      else if(opcode=="empty")
      {
        cout<<s.isEmpty()<<endl;
      }
      
    }
  int n,m;
  cin>>n>>m;
  Graph G(n);
  string opcode2;
  while(m--)
    {
      cin>>opcode2;
      if(opcode2=="add")
      {
        int a,b;
          cin>>a>>b;
        G+=std::pair<int,int>(a,b);
      }
      else if(opcode2=="del")
      {
        int a,b;
          cin>>a>>b;
        G-=std::pair<int,int>(a,b);
      }
      else if(opcode2=="print")
      {
        cout<<G;
      }
      else if(opcode2=="cycle")
      {
        cout<<G.detectCycle()<<endl;
      }
      else if(opcode2=="reach")
      {
        int a,b;
        cin>>a>>b;
        cout<<G.reach(a,b)<<endl;
      }
      
    }
  
}