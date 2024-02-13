#include <stdio.h>

// Function to insert an element at a specific index
void insertElement(int arr[], int *size, int index, int value) {
    if (*size >= index) {
        for (int i = *size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        (*size)++;
    }
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    int index = 2;
    int value = 10;

    insertElement(arr, &size, index, value);

    // Traversing the array after insertion
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Explain:

// Array insertion involves adding an element at a specific position in the array.
// To insert an element, we need to shift elements to the right to make space for the new element.