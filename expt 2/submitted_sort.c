// quick + merge sort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// to get total number of swaps --> pass pointre (pass by ref)
// pass by value --> creates new .. dosent update

void quickSort(int a[], int low, int high , int *swaps);
int partition(int a[], int low, int high , int * swaps);
void swap(int *a, int *b);
void printArray(int a[], int size);
void mergeSort(int a[], int low, int high, int size);
void merge(int a[], int low, int mid, int high, int size);

int main()
{
    int blocks = 1000;
    // int blocks = 1;
    srand(42);
    double merge_timer[blocks];
    double quick_timer[blocks];
    int swap_arr[blocks] ;

    {
        int offset = 0;
        for (int k = 0; k < blocks; k++)
        {

            int swaps = 0 ;
            offset = offset + 100;
            int to_be_sort_quick[offset];
            int to_be_sort_merge[offset];

            clock_t start_t, end_t;
            double total_t;

            // taking rand nos
            for (int i = 0; i < offset; i++)
            {
                to_be_sort_merge[i] = rand() % offset;
                to_be_sort_quick[i] = to_be_sort_merge[i];
            }

            start_t = clock();
            mergeSort(to_be_sort_merge, 0, offset - 1, offset);
            end_t = clock();
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            merge_timer[k] = total_t;

            // quicksort
            start_t = clock();
            quickSort(to_be_sort_quick, 0, offset - 1 ,&swaps);
            end_t = clock();
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            quick_timer[k] = total_t;
            
            // printf("SWAPS OF BLOCK [%d] : %d\n" , k, (swaps)) ;
            swap_arr[k] = swaps ;

        }
    }

    // putting output of swaps in csv 
    FILE *textfile;
    textfile = fopen("swaps_store.csv", "w");
    for (int i = 0; i < blocks; i++)
    {
        fprintf(textfile, "%d ", swap_arr[i]);
        fprintf(textfile, "\n");
    }
    fclose(textfile);

    //get time complexity
    printf("BLOCK \t\t TIME TO MERGE SORT \t TIME TO QUICK SORT\n") ;
        for (int i = 0 ; i < blocks ; i ++){
            printf("1 TO %d\t\t %f \t\t\t %f\n", (i + 1), merge_timer[i] , quick_timer[i] );
    }
    return 0;
}

void quickSort(int a[], int low, int high , int *swaps)
{
    // means only divided till one elemet remains
    if (low < high)
    {
        int pivotIndex = partition(a, low, high , swaps);
        quickSort(a, low, pivotIndex - 1 , swaps);
        quickSort(a, pivotIndex + 1, high , swaps);

    }
}
int partition(int a[], int low, int high , int *swaps)
{
    int begin = low;
    int end = high;
    // pivot = fisrt element
    int pivotIndex = begin;
    int pivot = a[pivotIndex];


    while (begin < end)
    {
        // moves fwd until first element > than pivot found
        while (a[begin] <= pivot)
        {
            begin++;
        }
        // moves bwd until first element < than pivot found
        while (a[end] > pivot)
        {
            end--;
        }
        if (begin < end)
        {
            // swap end and begin
            swap(&a[begin], &a[end]);
            // count number of successsful swaps
            (*swaps)++ ;
        }
    }

    // swap end and pivot
    swap(&a[pivotIndex], &a[end]);
    (*swaps)++ ;
    return end;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// void printArray(int a[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d\t ", a[i]);
//     }
//     printf("\n");
// }

void mergeSort(int a[], int low, int high, int size)
{

    // when 1 elemnt remains , low == high
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid, size);
        mergeSort(a, mid + 1, high, size);
        merge(a, low, mid, high, size);
    }
}
void merge(int a[], int low, int mid, int high, int size)
{
    int b[size];
    int sublist1_pointer = low;
    int sublist2_pointer = mid + 1;
    // this is for new array
    int new_array_pointer = low;

    while (sublist1_pointer <= mid && sublist2_pointer <= high)
    {
        if (a[sublist1_pointer] < a[sublist2_pointer])
        {
            b[new_array_pointer] = a[sublist1_pointer];
            sublist1_pointer++;
        }
        else
        {
            b[new_array_pointer] = a[sublist2_pointer];
            sublist2_pointer++;
        }
        new_array_pointer++;

    }
    while (sublist1_pointer <= mid)
    {
        b[new_array_pointer] = a[sublist1_pointer];
        new_array_pointer++;
        sublist1_pointer++;
    }
    while (sublist2_pointer <= high)
    {
        b[new_array_pointer] = a[sublist2_pointer];
        new_array_pointer++;
        sublist2_pointer++;
    }

    //  copying contents  of b back to a -- from low to high --> therby refers the sublist currently working on
    // if 0 to size ---> refers to original list in first step -- kachra prog
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}