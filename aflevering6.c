#include <stdio.h>
#include <stdlib.h>

#define STOR 6
#define LILLE 3
#define MAX 12

int sammenfletning(double[], double[], double[], int, int);
void udskriv(double[], double[], double[], int, int, int);

int main (void) {
    double MAX_arr[MAX],
           arr1[STOR] = {1.2, 3.6, 4.2, 5.6, 6.7, 8.3},
           arr2[LILLE] = {3.6, 4.3, 4.9};

    int flet;

    flet = sammenfletning(arr1, arr2, MAX_arr, STOR, LILLE);
           udskriv(arr1, arr2, MAX_arr, STOR, LILLE, flet);

    return 0;
    
}

int sammenfletning(double array1[], double array2[], double MAX_arr[], int str1, int str2) {
    int i1, i2, i3;

    for (i1 = 0, i2 = 0, i3 = 0; str1 > i2 || str2 > i2; i1++) {
        if (str1 == i2) {
            MAX_arr[i1] = array2[i3];
            i3++;
        }else if (str2 == i3) {
            MAX_arr[i1] = array1[i2];
            i2++;
        }else {
            if (array1[i2] < array2[i3]) {
                MAX_arr[i1] = array1[i2];
                i2++;
            }else if (array1[i2] > array2[i3]) {
                MAX_arr[i1] = array2[i3];
                i3++;
            }else {
                MAX_arr[i1] = array1[i2];
                i2++, i3++;
            }
        }        
    }
    return i1;   
}

void udskriv(double array1[], double array2[], double MAX_arr[], int size1, int size2, int slut) {
    int a;

    printf("Array nr 1. er:\n");
    for (a = 0; a < size1; a++) {
        printf("%.1lf ", array1[a]);
    }

    printf("\n\nArray nr 2. er: \n");
    for (a = 0; a < size2; a++) {
        printf("%.1lf ", array2[a]);
    }

    printf("\n\nDet sammenflettede array er: \n");
    for (a = 0; a < slut; a++) {
        printf("%.1lf ", MAX_arr[a]);
    }
    printf("\n\n");
}