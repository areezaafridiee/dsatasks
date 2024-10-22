#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
 int temp;
 temp=*x;
 *x=*y;
 temp=*y;	
}
int main()
{
int k=20, s=30;
cout<<"Before Swapping : "<<endl;
cout<<" K= "<<k<<" S= "<<s;
swap(k,s);
cout<<endl;
cout<<"After Swapping : "<<endl;	
cout<<" K= "<<k<<" S= "<<s;
}
