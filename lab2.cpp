#include <bits/stdc++.h>

using namespace std;
int flag=0;

class Book
{
  public:
  string title;
  string author;
  int year;
  int price;
  Book* right=NULL;
  Book* left=NULL;
};

class Bookshelf
{
   public:
   // void list();
   // void findCheap();
   // void addbook(Book B);
   // void removebook(int n);
   // //void reverseUnique();
   int checkEmpty(Book* head)
   {
       if(head!=NULL)return 0;
       else return 1;
   }
};

class HorizontalBookshelf:public Bookshelf
{
  public:
  
   Book *head;
    Book *head1;
    
   HorizontalBookshelf()
   {
     head= NULL; head1=NULL;
   }
    void addbook(Book B)
    {
        //cout<<'t'<<endl;
       Book*Node=new Book;
       Node->author=B.author;
       Node->price=B.price; 
       Node->year=B.year;
       Node->title=B.title;
      
       if(head==NULL)
       {
        head=Node; 
        head1=Node;
        head1->right=NULL;
       }
      
      else {
        head1->right=Node;
        head1=Node;
        head1->right=NULL;
      }
       
    }
    void removebook(int n)
    {
      while(n--)
      { 
          //cout<<"test"<<endl;
          if(head==NULL) cout<<"e"<<endl;
          else{
              head=head->right;
          }
      }
    }
    void list()
    {
      if(head!=NULL)
      {
        Book*newpoint=head;
        while(newpoint!=NULL)
        {
          cout<<newpoint->title<<","<<newpoint->author<<
          ","<<newpoint->year<<","<<newpoint->price<<endl;
          newpoint=newpoint->right;
        }
      }
      else
      {
        cout<<"e"<<endl;
      }
    }
    void findCheap(){
            if(checkEmpty(head)){cout<<"e";}
      else
      {
        Book*ptr1=head;
        int minprice=head->price;
        while(ptr1!=nullptr)
        {
          if(minprice>=ptr1->price){cout<<"-1"; minprice=ptr1->price;}
          else{cout<<minprice;}
          ptr1=ptr1->right;  
          if(ptr1!=NULL){cout<<",";}
        }
        
      }  
      cout<<endl;
            }
    
    void reverseUnique()
    {
        if(head==NULL) return;
      Book* ptr1=head; 
      Book* ptr2;
      Book *extra;
      while (ptr1!=nullptr && ptr1->right!=nullptr)
      {
        ptr2=ptr1;
        while(ptr2->right!=NULL)
        {
          if( (ptr1->year==ptr2->right->year) && (ptr1->price==ptr2->right->price )&&(ptr1->title==ptr2->right->title) && (ptr1->author==ptr2->right->author) )
          {
            extra=ptr2->right;
              ptr2->right=ptr2->right->right;
            delete(extra);
       }
           else{
               ptr2=ptr2->right;
         }
       }
       ptr1=ptr1->right;
      }

      Book *temp = NULL;
      Book *prev = NULL;
      Book *current = head;
      while(current != NULL) 
      {
          temp = current->right;
          current->right = prev;
          prev = current;
          current = temp;
        
      }
       head = prev; Book *duck=head;
       while(duck->right!=nullptr){duck=duck->right;}
       head1=duck;
    }
};


class VerticalBookshelf:public Bookshelf
{
  public:
       Book *head;
       
    VerticalBookshelf(){head = NULL;}
   void addbook(Book B)
    {
      Book*Node=new Book;
       Node->author=B.author;
       Node->price=B.price; 
       Node->year=B.year;
       Node->title=B.title;

      if(head==NULL){
          head=Node;
          head->right=NULL;
          head->left=NULL;
      }
      else 
      {
        head->right=Node; 
        Node->left=head; 
        head=Node;
        }
    }
    void removebook(int n)
    {
      while(n--)
      {
        if(head==NULL) cout<<'e'<<endl;
        else{
            head=head->left;
        }
      }
    }
    void list()
    {
      if(head==NULL){cout<<"e"<<endl;}
      else
      {
        Book*ptr=head;
        while(ptr!=NULL)
        {
          cout<<ptr->title<<","<<ptr->author<<","<<ptr->year<<","<<ptr->price<<endl;
          ptr=ptr->left;
        }
      }
    }
    void findCheap(){
            if(checkEmpty(head)){cout<<"e";}
      else
      {
        Book*ptr1=head;
        int minprice=head->price;
        while(ptr1!=nullptr)
        {
          if(minprice>=ptr1->price){cout<<"-1"; minprice=ptr1->price;}
          else{cout<<minprice;}
          ptr1=ptr1->left;  
          if(ptr1!=NULL){cout<<",";}
        }
        
      }  
      cout<<endl;
            }
        

    void reverseUnique()
    {
      Book* ptr1=head; 
      Book* ptr2;
      Book *extra;
      while (ptr1!=nullptr && ptr1->left!=nullptr)
      {
        ptr2=ptr1;
        while(ptr2->left!=NULL)
        {
          if( (ptr1->year==ptr2->left->year)&& (ptr1->price==ptr2->left->price )&&(ptr1->title==ptr2->left->title) && (ptr1->author==ptr2->left->author))
          {
            extra=ptr2->left;
            ptr2->left=ptr2->left->left;
            delete(extra);
          }
           else ptr2=ptr2->left;
         }
        ptr1=ptr1->left;
      }

      Book *temp = NULL;
      Book *prev = NULL;
      Book *current = head;
      while(current != NULL) 
      {
          temp = current->left;
          current->left = prev;
          prev = current;
          current = temp;
        
      }
       head = prev;
      
    }

  
};
int main()
{
  int Q;
  cin>>Q;
  HorizontalBookshelf h;
  VerticalBookshelf v;
  string opcode;
  for(int i=0;i<Q;i++)
  {
     cin>>opcode; 
     char type;
     if(opcode=="LIST")
     {
        cin>>type;
        if(type=='v')v.list();
        else if(type=='h')h.list();
     }
     if(opcode=="FINDC")
     {
       cin>>type;
        if(type=='v')v.findCheap();
        else if(type=='h')h.findCheap();
     }
     if(opcode=="ADD")
     {
        cin>>type;
        if(type=='v')
        {
          Book B;
          cin>>B.title;
          cin>>B.author;
          cin>>B.year;
          cin>>B.price;
          v.addbook(B);
        }
        else if(type=='h')
        {
          Book B;
          cin>>B.title;
          cin>>B.author;
          cin>>B.year;
          cin>>B.price;
          h.addbook(B);
        }

     }
     if(opcode=="REMOVE")
     {
         int n; 
         cin>>n; 
         cin>>type;
         if(type=='v') v.removebook(n);
         else if(type=='h') h.removebook(n);
           
     }    

     if(opcode=="REVUNI")
     { 
         cin>>type;
         if(type=='v') v.reverseUnique();
         else if(type=='h') h.reverseUnique();
           
     }     
  }
  return 0;
}