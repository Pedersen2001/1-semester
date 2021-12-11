#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int main(void){
    int L[] = {5, 3, 8, 1, 6, 10, 7, 2, 4, 9};
    int L_size = sizeof(L) / sizeof(L[0]);

    printf("Given list \n");
    printList(L, L_size);

    MergeSort(L, 0, L_size - 1);

    printf("The sorted list \n");
    printList(L, L_size);
    return 0;
}

void Merge(int L[], int start, int mid, int end){
    /*Here goes your code*/
    int i, j;
    int L1 = mid - start + 1;
    int L2 = end - mid;
    int Length1[L1], Length2[L2];

    for (i = 0; i < L1; i++)
        Length1[i] = L[start + i];
        
    for (j = 0; j < L2; j++)
        Length2[j] = L[mid + 1 + j];

    i = 0;
    j = 0;

    while (i < L1 && j < L2){
        if (Length1[i] <= Length2[j]){
            L[start] = Length1[i];
            i++;
        }else{
            L[start] = Length2[j];
            j++;
        }
        start++;
    }

    while (i < L1){
        L[start] = Length1[i];
        i++;
        start++;
    }

    while (j < L2){
        L[start] = Length2[j];
        j++;
        start++;
    }
}

void MergeSort(int L[], int start, int end){
    /*Here goes your code as well*/
    if (start < end){
        int mid = ((end + start) / 2);

        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);

        Merge(L, start, mid, end);
    }
}

void printList(int L[], int size){
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", L[i]);
    printf("\n");
}