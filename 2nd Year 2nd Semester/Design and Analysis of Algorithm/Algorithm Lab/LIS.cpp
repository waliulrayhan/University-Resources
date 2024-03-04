#include<iostream>
#include<cstring>
using namespace std;
int arr[100];
int dp[100];
int n;

int lis(int i)
{
	int ans=1;
	if(dp[i]!=-1)
		return dp[i];
	for(int j=0;j<i;j++)
	{
		if(arr[j]<arr[i])
		{
			ans = max(ans,1+lis(j));
		}
	}
	return dp[i]=ans;
}

void _LIS()
{
	int list[n+1];
	int prv[n+1];
	int mx=0;
	list[0]=0;
	prv[0]=-1;


	for(int i=1;i<=n;i++)
	{
		list[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i] && list[i]<=list[j]+1)
			{
				list[i]=list[j]+1;
				prv[i]=j;
			}
		}
		mx = max(mx,list[i]);
	}


	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(mx == list[i])
		{
			pos=i;
			break;
		}
	}

	cout<<"Maximum LIS Length is: "<<mx<<endl;
	cout<<"The Maximum Subsequence is: ";


	//increasing order

    int ar[mx];
	int aa=0;

	while(prv[pos]!=-1)
	{
		ar[aa]=arr[pos];
		pos = prv[pos];
		aa++;
	}
	for(int i=mx-1;i>=0;i--)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;




	//decreasing order
	/* while(prv[pos]!=-1)
	{
		cout<<arr[pos]<<" ";
		pos = prv[pos];
	}
	cout<<endl; */
}


int main()
{
	for(int i=0;i<100;i++)
		dp[i]=-1;

	int ans=0;
	cout << "Enter array size: ";
	cin>>n;
	cout << "Enter " << n << " values: ";
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	_LIS();

}

