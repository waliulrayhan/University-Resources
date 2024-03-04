#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int left(int i)
{
	return i*2;
}
int right(int i)
{
	return i*2+1;
}

void MAX_HEAPIFY(int a[], int i, int n)
{
  int l,r,largest,loc;
  l=left(i);
  r=right(i);
  if((l<=n)&&a[l]>a[i])
    largest=l;
  else
    largest=i;
  if((r<=n)&&(a[r]>a[largest]))
    largest=r;
  if(largest!=i)
    {
      loc=a[i];
      a[i]=a[largest];
      a[largest]=loc;
      MAX_HEAPIFY(a, largest,n);
    }
}

void BUILD_MAX_HEAP(int a[], int n)
{
  for(int k = n/2; k >= 1; k--)
    {
      MAX_HEAPIFY(a, k, n);
    }
}

void HEAPSORT(int a[], int n)
{

  BUILD_MAX_HEAP(a,n);
  int i, temp;
  for (i = n; i >= 2; i--)
    {
      temp = a[i];
      a[i] = a[1];
      a[1] = temp;
      MAX_HEAPIFY(a, 1, i - 1);
    }
}

int main()
{
  int n;
  time_t b,e;
  cin>>n;
  int a[n+1];

  srand(time(0));
  for(int i=1;i<=n;i++)
    a[i]=rand()%100+1;

  b = clock();
  HEAPSORT(a, n);
  e = clock();


  cout<<"SORTED FORM: "<<endl;
  for (int i = 1; i <= n; i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;

  double ts = (double)(e-b)/CLOCKS_PER_SEC;
  cout<<"Time taking :"<<ts<<"s"<<endl;

}
