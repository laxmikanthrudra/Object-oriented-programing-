#include <bits/stdc++.h>
using namespace std;

class Matrix  /*class named Matrix having 3 private member*/
{
  private:
     int  rows;
     int columns;
     int **mat;
  public:
     Matrix() /*default constructor of the class */
     {
       rows=0; 
       columns=0; 
       mat=NULL;
       }
     Matrix(int row,int column)/*initialize Matrix's rows and columns with 0's*/
     {
        rows=row;
        columns=column;
        mat=NULL;
     }
     Matrix(int row,int column,int**matrix)/*initialize Matrix's rows and columns with corresponding values*/
     {
        rows=row;
        columns=column;
        mat=matrix;
     }
      void setValue(int row,int col,int val)
      {
        mat[row][col]=val;/*to set a paticular value to matrix*/
      }
      int getValue(int row,int col)
      {
        return mat[row][col];/*to get the value in arry*/
      }
      int getNoRows()
      {
        return rows;
      }
      int getNoColumns() 
      {
        return columns;
      }

      /*printing in spiral way*/
      

      void printSpiral()
      {
         
         int i, k = 0, l = 0,m=rows-1,n=columns-1,direction=0;
 
        while (k <= m && l <= n) {
            
          if(direction==0){
          for (i = l; i <= n; ++i) {
            cout << mat[k][i] << " ";
         }
         k++;
        }
         else if(direction==1){
         for (i = k; i <= m; ++i) {
             cout << mat[i][n] << " ";
         }
         n--;
        }
        else if(direction==2){
        for(i=n;i>=l; i--){
          cout<<mat[m][i]<<" ";
        }
        m--;
        }
        
        else if(direction==3){
        for(i = m;i>=k;i--){
          cout<<mat[i][l]<<" ";
         }
         l++;
        }
        direction = (direction + 1)%4;

    }
         cout<<endl;
       }

    /*finding the trace of a matrix*/
    long long int trace()
    {
      long long int summend=0;
       
       if(rows!=columns) return -1;
        else{
            for(int i=0;i<rows;i++){
                summend+=mat[i][i];
            }
            return summend;
        }
       }

  /*if the sum of rows and column are equal then it is special matrix*/
      bool isSpecialMatrix()
      {
         
         int colsum=0,rowsum=0;
         
         for(int i=0;i<rows;i++){
             colsum+=mat[i][0];
         }
         for(int i=0;i<columns;i++){
             rowsum+=mat[0][i];
         }
         
         if(rowsum!=colsum){return false;}
         
         else{
             for(int i=0;i<columns;i++)
          {
            int columnsums=0;
            for(int j=0;j<rows;j++)
            {
                columnsums=columnsums+mat[j][i];
                
            }
            if(columnsums!=colsum)
            {
                return false;
                
            }
          }
          
          for(int i=0;i<rows;i++)
          {
            int rowsums=0;
            for(int j=0;j<columns;j++)
            {
                rowsums=rowsums+mat[i][j];
                
            }
            if(rowsums!=rowsum)
            {
                return false;
                
            }
          }
         return true;
         }
         
         
         
         
         
       }
       /*check for a triangle(upper or lower)*/
   bool checkTriangular()
      {
       if(rows!=columns)return false;
       
        int luck=0, flag=0;
        for(int i=1;i<rows;i++)
        {
          for (int j=0;j<i;j++)
            {
              if(mat[i][j]!=0)
              {
                luck=1; break;
                }
            }
        }
        for(int i=0;i<rows;i++)
        {
          for (int j=i+1;j<columns;j++)
            {
              if (mat[i][j]!= 0)
              {
                flag=1; break;
                }
            }
        }
        if(luck==0 || flag==0)return true;
        else return false;
    }

};

int main()
{
   int N,M;/*N and M are rows and columns respectivily*/
   cin>>N>>M;
   //Matrix R(N,M);/*class matrix R*/
   int **L;
     L = new int *[N];
    for(int i=0;i<N;i++){
        L[i]=new int[M];
    }
   for(int i=0;i<N;i++)
   {
     for(int j=0;j<M;j++)
     {
         cin>>L[i][j];
     }
   }
   Matrix R(N,M,L);
   int Q;
   cin>>Q;
   int opcode; 
   while(Q--)
   {
       cin>>opcode;
       switch(opcode)
       {
           case 1:R.printSpiral(); break;
           
           case 2:cout<<R.trace()<<endl; break;
           
           case 3:
                   if(R.checkTriangular()!=true)cout<<"false"<<endl;
                   else cout<<"true"<<endl; 
                   break;
           
           case 4: 
                  if(R.isSpecialMatrix()!=true)
                  cout<<"false"<<endl;
                  else cout<<"true"<<endl;
                  break;
       }
   }
     
   return 0;
}