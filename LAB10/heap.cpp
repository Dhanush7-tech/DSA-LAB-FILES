#include <cstdio>
#define MAX 100

// Class to implement Priority Queue using Max Heap
class PriorityQueue {
private:
    int heap[MAX]; // Array to store heap elements
    int size;      // Current size of the heap

    // Helper functions
    void heapifyUp(int index);   // Maintain heap after insertion
    void heapifyDown(int index); // Maintain heap after deletion

public:
    PriorityQueue(); // Constructor

    // Function declarations
    void insert(int value);     // Insert an element into the heap
    void deleteMax();           // Delete the maximum element (root)
    void display();             // Display all heap elements
    void search(int value);     // Search for an element in the heap
    void heapSort();            // Sort heap using Heap Sort
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (1) {
        printf("\n--- Priority Queue using Max Heap ---\n");
        printf("1. Insert\n");
        printf("2. Delete Max\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Sort (Heap Sort)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pq.search(value);
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Constructor initializes heap size to 0
PriorityQueue::PriorityQueue() {
    size = 0;
}

// Maintain max heap property after insertion
void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

// Maintain max heap property after deletion
void PriorityQueue::heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        heapifyDown(largest);
    }
}

// Insert value into heap
void PriorityQueue::insert(int value) {
    if (size >= MAX) {
        printf("Heap is full! Cannot insert more elements.\n");
        return;
    }
    heap[size] = value;
    heapifyUp(size);
    size++;
    printf("%d inserted successfully.\n", value);
}

// Delete the root (maximum value)
void PriorityQueue::deleteMax() {
    if (size == 0) {
        printf("Heap is empty! Nothing to delete.\n");
        return;
    }
    printf("Deleted max element: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Display heap contents
void PriorityQueue::display() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Heap elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Search for a value in heap
void PriorityQueue::search(int value) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            printf("Value %d found at index %d.\n", value, i);
            return;
        }
    }
    printf("Value %d not found in the heap.\n", value);
}

// Heap sort: display elements in descending order
void PriorityQueue::heapSort() {
    if (size == 0) {
        printf("Heap is empty! Nothing to sort.\n");
        return;
    }

    int tempHeap[MAX];
    int tempSize = size;

    // Copy original heap to a temporary array
    for (int i = 0; i < size; i++) {
        tempHeap[i] = heap[i];
    }

    printf("Sorted elements (Descending): ");
    while (size > 0) {
        printf("%d ", heap[0]);
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }
    printf("\n");

    // Restore original heap
    for (int i = 0; i < tempSize; i++) {
        heap[i] = tempHeap[i];
    }
    size = tempSize;
}
