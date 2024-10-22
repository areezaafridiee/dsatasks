#include<iostream>
using namespace std;
int main()
{
	int arr[5]={1,2,3,4,5},n,val;
	cout<<"Original Array! : ";
	for(int i=0;i<=4;i++)
	{
		cout<<arr[i]<<" ";
	}
    cout<<endl;
    cout<<"Enter the index you want to update! : ";
    cin>>n;
    if(n<0||n>=5)
    {
    	cout<<"Invalid Index!";
    	return 1;
	}
	cout<<"Enter the updated value : ";
	cin>>val;
	arr[n]=val;
	cout<<"Updated Array! "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	}

