#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void doMerge(int p, int q, int r);
void doMergeSort(int p, int r);
int A[1000000];
int main()
{
    int n, i;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    srand(time(NULL));

    for(i=1; i<=n; i++)
    {
        A[i] = (rand()%100);
    }

    //Random number printing

    /*printf("\nGenerating random number:\n");

    for(i=1; i<=n; i++)
    {
        printf("\t%d ", A[i]);
    }*/

    clock_t t;
    t = clock();

    doMergeSort(1, n); // p=1, r=n;

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("doMergeSort() took %f seconds to execute. \n", time_taken);

    //printf("\nSorted elements:\n");

    for(i=1; i<=n; i++)
    {
        //printf("%d ", A[i]);
    }

    return 0;

}

void doMerge(int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = q-p+1;
    n2 = r-q;
    int L[n1+1], R[n2+1];

    for(i=1; i<=n1; i++)
    {
        L[i] = A[p+i-1];
    }
    for(j=1; j<=n2; j++)
    {
        R[j] = A[q+j];
    }
    L[n1+1] = 9999;
    R[n2+1] = 9999;
    i = 1;
    j = 1;
    for(k=p; k<=r; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i = i+1;
        }
        else
        {
            A[k] = R[j];
            j = j+1;
        }
    }

}

void doMergeSort(int p, int r)
{
    int q, i;
    if(p<r)
    {
        q = (p+r)/2;
        doMergeSort(p, q);
        doMergeSort(q+1, r);
        doMerge(p, q, r);
    }
}
