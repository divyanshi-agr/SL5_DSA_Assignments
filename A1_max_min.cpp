#include <iostream>
using namespace std;

int isSorted(int arr[], int n)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>arr[i-1] && i>0)
			flag++;
	}
	return flag;
}

void min_max(int a[], int i, int j, int *max, int *min)
{
	int flag = 0;
	if(i==j)
	{
		*max=a[i];
		*min=a[i];
	}	
	else if(i==j-1)
	{
		if(a[i]<a[j])
		{
			*max = a[j];
			*min = a[i];
		}
		else
		{
			*min = a[j];
			*max = a[i];
		}
	}
	else
	{
		int mid = (i+j)/2;
		int max1, min1;
		if(isSorted(a, i+j+1)==0)
		{
			*max = a[i];
			*min = a[j];
		}
		else if(isSorted(a, i+j+1)==i+j)
		{
			*min = a[i];
			*max = a[j];
		}
		else
		{			
			min_max(a, i, mid, max, min);
			min_max(a, mid+1, j, &max1, &min1);
			if(*max<max1)
				*max=max1;
			if(*min>min1)
				*min=min1;
		}
	}
}

int main()
{
	int n, min, max;
	cout<<"Enter size of the array: ";
	cin>>n;
	cout<<"Enter elements of the array: ";
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<"The array is : ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<"\t";
		
	min_max(a, 0, n-1, &max, &min);
	cout<<"\n\nThe maximum element is : "<<max<<endl;
	cout<<"The minimum element is : "<<min<<endl;
	return 0;
}