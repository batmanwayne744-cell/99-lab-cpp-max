#include<iostream> 
using namespace std;
class Shape 
{
    public:
int area(int s) 
{ 
return(s*s); 
} 
int area(int l,int b) 
{ 
return(l*b); 
} 
float area(float r) 
{ 
return(3.14*r*r); 
} 
float area(float bs,float ht) 
{ 
return((bs*ht)/2); 
}
    
}; 
int area(int); 
int area(int,int); 
float area(float); 
float area(float,float); 

int main() 
{ 
int s,l,b; 
float r,bs,ht; 
Shape s1;
cout<<"Enter side of a square: "; 
cin>>s; 
cout<<"Enter length and breadth of rectangle: "; 
cin>>l>>b; 
cout<<"Enter radius of circle: "; 
cin>>r; 
cout<<"Enter base and height of triangle: "; 
cin>>bs>>ht; 
cout<<"Area of square is "<<area(s); 
cout<<"\nArea of rectangle is "<<area(l,b); 
cout<<"\nArea of circle is "<<area(r); 
cout<<"\nArea of triangle is "<<area(bs,ht); 
cout <<"\n";

cout<<"Area of object square is "<<s1.area(10); 
cout<<"\nArea of object rectangle is "<<s1.area(10,12); 
cout<<"\nArea of object circle is "<<s1.area(5.25f); 
cout<<"\nArea of object triangle is "<<s1.area(6.5f,7.5f); 
cout <<"\n";
} 
int area(int s) 
{ 
return(s*s); 
} 
int area(int l,int b) 
{ 
return(l*b); 
} 
float area(float r) 
{ 
return(3.14*r*r); 
} 
float area(float bs,float ht) 
{ 
return((bs*ht)/2); 
}