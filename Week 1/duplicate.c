#include <stdio.h>

void main() {
    int size, duplicates = 0;


    printf("\nEnter size of array: ");
    scanf("%d", &size);


    int arr[size];


    printf("\nEnter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                duplicates++;
                break;
            }
        }
    }


    printf("\nNumber of duplicates: %d\n", duplicates);
}
