#include <stdio.h>

// Function to delete an element at a specific index
void deleteElement(int arr[], int *size, int index) {
    if (index < *size) {
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    }
}

int main() {
    int arr[] = {1, 2, 10, 3, 4, 5};
    int size = 6;
    int index = 2;

    deleteElement(arr, &size, index);

    // Traversing the array after deletion
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}



// Explain:

// Array deletion involves removing an element from a specific position in the array.
// To delete an element, we need to shift elements to the left to fill the gap left by the deleted element.