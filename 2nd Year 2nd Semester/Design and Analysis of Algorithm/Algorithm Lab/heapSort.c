#include<stdio.h>
int A[1000]; // array for storing data elements
int N; // heap size
int Parent(int i);
int Left(int i);
int Right(int i);
void maxHeapify(int i);
void buildMaxheap();

int main()
{
    int i;
    printf("Size of heap: ");
    scanf("%d",&N);
    printf(" Elements of Heap: ");
    for(i =1;i<=N;i++)
    {
        scanf("%d",&A[i]);
    }

    buildMaxheap();

    printf("\nAfter Maxheapify: ");

    for(i=1;i<=N;i++)
    {
        printf("%d ",A[i]);
    }


}

void buildMaxheap()
{
    int i;
    for(i=N/2;i>=1;i--)
    {
        maxHeapify(i);
    }
}

void maxHeapify(int i)
{
    int l,r, largest, temp;
    l=Left(i);
    r=Right(i);

    if(l<=N && A[l]>A[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }

    if(r<=N && A[r]>A[largest])
    {
        largest=r;
    }

    if(largest!=i)
    {
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        maxHeapify(largest);
    }

}

int Parent(int i)
{
    return (i/2);
}
int Left(int i)
{
    return 2*i;
}
int Right(int i)
{
    return 2*i+1;
}
