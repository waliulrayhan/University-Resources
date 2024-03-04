#include<bits/stdc++.h>
#include<time.h>\

using namespace std;

 
int
getmax (int a[], int n) 
{
  
int mx = a[0];
  
for (int i = 0; i < n; i++)
    
    {
      
mx = max (a[i], mx);
    
} 
return mx;

}


 
void
counting (int a[], int n, int div) 
{
  
int output[n];
  
int cnt[10] = { 0 };
  
for (int i = 0; i < n; i++)
    
    {
      
cnt[(a[i] / div) % 10]++;
  
} 
for (int i = 1; i < 10; i++)
    
    {
      
cnt[i] += cnt[i - 1];
  
} 
for (int i = n - 1; i >= 0; i--)
    
    {
      
output[cnt[(a[i] / div) % 10] - 1] = a[i];
      
cnt[(a[i] / div) % 10]--;
  
} 
for (int i = 0; i < n; i++)
    
    {
      
a[i] = output[i];

} 
} 
 
void

radix_sort (int a[], int n) 
{
  
int m = getmax (a, n);
  
int x = 0;
  
for (int div = 1; m / div > 0; div *= 10)
    
    {
      
counting (a, n, div);
      
x++;
      
	//cout<<"After pass-"<<x<<":"<<endl;
	
for (int i = 0; i < n; i++)
	
	{
	  
	    //cout<<a[i]<<" ";
	} 
	//cout<<endl;
} 
} 
 
int

main () 
{
  
int n;
  
cout << "Enter the size of the array :";
  
cin >> n;
  
int a[n];
  
for (int i = 0; i < n; i++)
    
    {
      
a[i] = 10000 + rand () % 1000;
    
} 
cout << "Before sort :" << endl;
  
for (int i = 0; i < n; i++)
    
    {
      
	cout<<a[i]<<" ";
    } 
    cout<<endl;
    
 
clock_t t;
  
t = clock ();
  
 
radix_sort (a, n);
  
 
t = clock () - t;
  
double time_taken = ((double) t) / CLOCKS_PER_SEC;
  
 
printf ("\n\nradix_sort() took %f seconds to execute. \n", time_taken);
  
 
 
 
cout << "\nAfter sort :" << endl;
  
for (int i = 0; i < n; i++)
    
    {
      
	cout<<a[i]<<" ";
} 
} 
