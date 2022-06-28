#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int leastcommon(string st1, string st2, int a, int b,vector<vector<int> >& vec)
{
    if (a==0 || b==0) return 0;
    
    if (st1[a-1] == st2[b-1])
    {
        return vec[a][b] = 1 + leastcommon(st1, st2, a-1, b-1, vec);
    }
 
    if (vec[a][b] != -1) 
    {
        return vec[a][b];
    }
    
    return vec[a][b] = max(leastcommon(st1, st2, a, b-1, vec),leastcommon(st1, st2, a-1, b, vec));
}


 
int minimum_operations(string st1, string st2, int a, int b)
{
    int arr[a+1][b+1];
    for (int i=0; i<=a; i++) 
    {
        for (int j=0; j <= b; j++) 
        {
            if (j==0) arr[i][j]=i;
            else if (i==0) arr[i][j]=j;
            else if (st1[i-1] != st2[j-1])
            {
                arr[i][j]= 1 + min(min(arr[i][j-1], arr[i-1][j]), arr[i-1][j-1]);
            }
            else
            {
                arr[i][j] = arr[i-1][j-1];
                
            }
        }
    }
 
    return arr[a][b];
}






string LCS(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1];
 
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    int index = L[m][n];

    char lcs[index + 1];
    lcs[index] = '\0'; 
    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
       
        if (X[i - 1] == Y[j - 1]) 
        {
            lcs[index - 1]
                = X[i - 1]; 
            i--;
            j--;
            index--; 
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    return lcs;
}

vector<string> closest(vector<string> vec,string st)
{
    vector<string> temp1;
    int n;
    n= vec.size();
    
    vector<vector<int>> dp(st.length() + 1, vector<int>(vec[0].length() + 1, -1));
    int mg = leastcommon(st,vec[0],st.length(),vec[0].length(),dp);
    
    for(int i=1;i<n;i++)
    {
        vector<vector<int>> dp(st.length() + 1, vector<int>(vec[i].length() + 1, -1));
        int gg; 
        gg= leastcommon(st,vec[i],st.length(),vec[i].length(),dp);
        if(mg < gg)
        {
            mg = gg;
        }
    }
    for(int i=0;i<n;i++)
    {
        vector<vector<int>> dp(st.length() + 1, vector<int>(vec[i].length() + 1, -1));
        int ag;
        ag= leastcommon(st,vec[i],st.length(),vec[i].length(),dp); 
        if(mg ==ag)
        {
            temp1.push_back(vec[i]);
        }       
    }
    return temp1;
}


int main() 
{
    int N;
    cin>>N;
    string temp1;
    vector<string>S,D;
    for(int i=0;i<N;i++)
    {
        cin>>temp1;
        S.push_back(temp1);
    } 
    
    int d;
    cin>>d;
    for(int i=0;i<d;i++)
    {
        cin>>temp1;
        D.push_back(temp1);
    }
    
    
    vector<string> str;
    int k=S.size();
    int i,j,min_operat;
    for(i=0;i<k;i++)
    {
        min_operat = minimum_operations(S[i],D[0],S[i].length(),D[0].length());
        for(j=1;j<D.size();j++)
        {
            int op ;
            op= minimum_operations(S[i],D[j],S[i].length(),D[j].length());
            if(min_operat > op)
            {
                min_operat = op;
            }
        }
        for(j=0;j<D.size();j++)
        {
            int op; 
            op= minimum_operations(S[i],D[j],S[i].length(),D[j].length());
            if(min_operat == op)
            {
                str.push_back(D[j]);
            }
        }
        
        if(str.size() > 1)
        {
            vector<string> tempclose = closest(str,S[i]);
            int n;
            n= tempclose.size();
            for(int k=0;k<n;k++)
            {
                cout<<S[i]<<endl;
                cout<<tempclose[k]<<endl;
                string sam;
                sam= LCS(S[i],tempclose[k],S[i].length(),tempclose[k].length());
                if(sam != "")
                {
                    cout<<sam<<endl;
                }
                else 
                {
                    cout<<"EMPTY"<<endl;
                }
                cout<<min_operat<<endl;
            }
        }
        
        else if(str.size() == 1)
        {
            cout<<S[i]<<endl;
            cout<<str[0]<<endl;
            string lcastring ;
            lcastring = LCS(S[i],str[0],S[i].length(),str[0].length());
            if(lcastring != "")
            {
                cout<<lcastring<<endl;
            }
            else 
            {
                cout<<"EMPTY"<<endl;
            }
            cout<<min_operat<<endl;
        }
        
        str.clear();
    }
    return 0;
}