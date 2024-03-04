//Lab task, protita step e dekhabo je p, q, r er value gulo koto hocche.

#include <stdio.h>
#include<time.h>

int partition(int p, int r);
void quickSort(int left, int right);
int A[1000000], N;

int main()
{
    int i, j;
    printf("Enter number of elements in array: ");
    scanf("%d", &N);

    srand(time(NULL));

    for(i=1; i<=N; i++)
    {
        A[i] = (rand()%100);
    }

    clock_t t;
    t = clock();

    quickSort(1, N);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("quickSort() took %f seconds to execute \n", time_taken);

    //printf("Sorted array: ");
    for (i = 1; i <= N; i++)
    {
        //printf("%d ", A[i]);
    }
}

int partition(int p, int r)
{
    int x, i, j, k, temp;
    x = A[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    for (k = 1; k <= N; k++)
    {
        //printf("%d ", A[k]);
    }

    //printf("\n");

    return i + 1;
}

void quickSort(int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(p, r);
        //printf("%d\n", q);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}
