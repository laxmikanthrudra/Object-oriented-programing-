#include <iostream>

using namespace std;

class base
{
  public:
    virtual int Knapsack(int a,int n,int val[],int wt[])=0;

};

class derived:
public base
{
  public:
    int Knapsack(int kan,int n,int wt[],int rev[])
    {
       int i,j,kanth[kan+1];
       int m=0;
       
       while(m<kan+1)
       {
          kanth[m]=0;
          m++;
       }
        // intialising temp arry to 0
       
       for(i=0;i<=kan;i++)
       {
           for(j=0;j<n;j++)
           {
              if(!(wt[j]>i))
               {
                 kanth[i] = max(kanth[i],kanth[i-wt[j]]+rev[j]);
               }
           }
       }
      return kanth[kan];
    } 
};

int main()
{
    
    int W,n;
    cin>>W;
    cin>>n;
    int revenue[n],weight[n];
    for(int i=0;i<n;i++)
    {
        cin>>revenue[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    base *bp =new derived();
    cout<<(*bp).Knapsack(W,n,weight,revenue);
 
  }