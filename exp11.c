
#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Function to insert an item
void insert(int item) {
    int i, temp;

    if (size == MAX) {
        printf("Heap is full\n");
        return;
    }

    i = size;
    heap[i] = item;
    size++;

    // Adjust heap upwards
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }

    printf("Item inserted successfully\n");
}

// Function to delete maximum item
void deleteMax() {
    int i, left, right, largest, temp;

    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted item: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    // Adjust heap downwards
    i = 0;

    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }
}

// Function to display heap
void display() {
    int i;

    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap elements: ");

    for (i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

// Main function
int main() {
    int choice, item;

    while (1) {
        printf("\n--- MAX HEAP PRIORITY QUEUE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                deleteMax();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}