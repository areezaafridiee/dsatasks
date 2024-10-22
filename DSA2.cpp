#include<iostream>
using namespace std;
int main()
{ 
	int max;
	int n;
	int min;
	int arr[5];
	cout<<"Enter Values : "<<endl;
    cin>>n;
    if(n<=0)
	{
		cout<<"Invalid No. of Elements";
    }
    int num[n];
	cout<<"Enter "<<n<<"  Numbers: ";
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
    }
	max=num[0];
    min=num[0];
	for (int j= 1;j<n;j++)
	{
		if(num[j]>max)
		{
			max=num[j];
		}
		else if(num[j]<min)
		{
			min=num[j];
		}
	}
	cout<<"Maximum Value : "<<max<<endl;
	cout<<"Minimum Value : "<<min<<endl;
	return 0;
}
