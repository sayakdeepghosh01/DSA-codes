#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Traversing the array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
//Explain-
// Array traversal involves accessing each element of the array exactly once.
// We can use a loop to iterate over the elements of the array and perform some operation on each element.