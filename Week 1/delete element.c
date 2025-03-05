#include<stdio.h>

void main() {
    int size, n;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];  // Variable Length Array (VLA)

    printf("Enter elements: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position where value has to be deleted: ");
    scanf("%d", &n);

    // Check for invalid position
    if (n < 1 || n > size) {
        printf("Invalid position.\n");
        return;
    }

    n--; // Convert position to 0-based index

    // Shift elements left to delete the element at position n
    for(int i = n; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print the array after deletion
    printf("Array after deletion: ");
    for(int i = 0; i < size - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
