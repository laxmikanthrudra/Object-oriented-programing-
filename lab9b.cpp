#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Thanos(int a,int b)
{
    if(a < b ) 
    {
        cout<<a<<endl;
        cout<<"NO";
    }
    else{
        cout<<a<<endl;
        cout<<"YES";
    }
}

int Power(int N,int* arr)
{
    int thanos[N][N],j;
    for(int i=0;i<N;i++)
    for(int p=0;p<N;p++)
    thanos[i][p] = 0;
    
    for(int size = 1;size<=N;size++)
    {
        for(int i=0;i+size<=N;i++)
        {
            j = i+size-1;
            if( j == i+1)thanos[i][j] =arr[i]*arr[j] + max(arr[i],arr[j]);
            else if(i == j) thanos[i][j] = arr[i]; 
            for(int k = i+1;k<j;k++)
            {
                int right=max(thanos[i][j],thanos[i][k]+thanos[k][j] + arr[i]*arr[k]*arr[j]                +arr[i]*arr[j]+max(arr[i],arr[j])  -max(arr[k],arr[j])- arr[i]*arr[k] - max(arr[i],arr[k]) - arr[k]*arr[j]);
                thanos[i][j] = right ;
            }
        }
    }
    return thanos[0][N-1];
}
    

    



int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
        
    int true_power=Power(N,arr);
    int power;
    cin>>power;
    
    Thanos(true_power,power);
    
    return 0;
}