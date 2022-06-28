#include <iostream>
using namespace std;

template<class T>
class node
{
    public:
    T val;
    node*right;
    node(T  data)
    {
        val=data;
        right=NULL;
    }
};

template<class T>
class Queue
{
    public:
    Queue()
    {
      tail=NULL;
      head=NULL;

    }
    void enqueue(T v)
    {
       node<T>* n=new node<T>(v);
      if(head==NULL)
      {
        head=n;
        tail=n;
        return ;
      }
    node<T> *temp=head;
    while(temp->right!=NULL)
    {
       temp = temp->right;
    }
    temp->right=n;
    tail=n;
    }
    T dequeue()
    {
    if(head->right==NULL)
    {
      node<T> *deletednode2;
      deletednode2=head;
      head=NULL;
      return (deletednode2->val);

    }

     node<T> *deletednode1;
     deletednode1=head;
     head=deletednode1->right;
     return (deletednode1->val);
      
    }
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
    bool isEmpty()
    {
      if(head==NULL)
      {
        return true;
      }
      else 
      return false;
      
    }
    private:
    node<T> *head;
    node<T> *tail;

};


template<class T>
class Printer
{
  public:

  class InsufficientInk
  {
    public:
    InsufficientInk(string reason1){cout<<reason1;}
  };
  class NoDocument
  {
    public: 
    NoDocument(string reason2){cout<<reason2;}
  };
  class PrinterBusy
  {
    public:
    PrinterBusy(string reason3){cout<<reason3;}
  };

  Printer(){
    cap=0;
    inker=0;
  }
  
  Printer(int capacity,int ink)
  {
    cap=capacity;
    inker=ink;
    
  }
  void addDocument(T val)
  {
    if(q.size()==cap) throw PrinterBusy("PRINTER_BUSY");
    q.enqueue(val);

  }
  T printDocument()
  {
    if(q.isEmpty()) 
    {
      throw  NoDocument("NO_DOCUMENT");
    }
    if(inker==0)
    {
      throw InsufficientInk("INSUFFICIENT_INK");
    }
    T er=q.dequeue();
    inker--;
    return er;
  }
  void fillink(int newink)
  {
    inker=newink;
  }
  private :
  Queue<T> q;
  int cap,inker;

  

};

int main()
 {
    int m,n;
    cin>>m;
    cin>>n;
    char T;
    cin>>T;
    //for int data type
    int Q;
    if(T=='I')
    {
      Printer<int> p(m,n);
      cin>>Q;
      while(Q--)
      {
        try{
        int a;
        cin>>a;
        if(a==1)
        {
        
          int b;
          cin>>b;
          p.addDocument(b);
          }
        if(a==2)
        {
            int num=p.printDocument();
             cout<<num<<endl;
             }
        if(a==3)
        {
          int c;
          cin>>c;
          p.fillink(c);

        }
    }
    catch(Printer<int>::InsufficientInk){cout<<endl;}
    catch(Printer<int>::NoDocument){cout<<endl;}
    catch(Printer<int>::PrinterBusy){cout<<endl;}

      }
    }
    //for char data type
    if(T=='C')
    {
     Printer<char> p(m,n);
      cin>>Q;
      while(Q--)
      {
        try{
        int a;
        cin>>a;
        if(a==1)
        {
        
          char b;
          cin>>b;
          p.addDocument(b);
          }
        if(a==2)
        {
            char num=p.printDocument();
             cout<<num<<endl;
             }
        if(a==3)
        {
          int c;
          cin>>c;
          p.fillink(c);

        }
    }
    catch(Printer<char>::InsufficientInk){cout<<endl;}
    catch(Printer<char>::NoDocument){cout<<endl;}
    catch(Printer<char>::PrinterBusy){cout<<endl;}

      }

    }
    //for float data type
    if(T=='F')
    {
      Printer<float> p(m,n);
      cin>>Q;
      while(Q--)
      {
        try{
        int a;
        cin>>a;
        if(a==1)
        {
        
          float b;
          cin>>b;
          p.addDocument(b);
          }
        if(a==2)
        {
            float num=p.printDocument();
             cout<<num<<endl;
             }
        if(a==3)
        {
          int c;
          cin>>c;
          p.fillink(c);

        }
    }
    catch(Printer<float>::InsufficientInk){cout<<endl;}
    catch(Printer<float>::NoDocument){cout<<endl;}
    catch(Printer<float>::PrinterBusy){cout<<endl;}

      }
      
    }

    return 0;
}   
