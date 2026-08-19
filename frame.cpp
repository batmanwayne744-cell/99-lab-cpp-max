#include<iostream>
using namespace std;

int main()
{
     int n,a[100],b[200];
     int i=0,j=0,count=0;

     cout<<"Enter frame length:";
     cin>>n;

     cout<<"Enter frame bits:";
     for(i=0;i<n;i++)
      cin>>a[i];
     i=0;
     
     while (i<n)
     {
          b[j]=a[i];

          if(a[i]==1)
           count++;
          else
           count=0;
           
          if(count==5)
          {
               j++;
               b[j]=0;
               count=0;
          } 
          i++;
          j++;
     }
     cout<<"Frame after bit stuffing:";
     for(i=0;i<j;i++)
      cout<<b[i];

      return 0;
}  