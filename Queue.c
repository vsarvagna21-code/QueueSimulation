#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int queue[MAX];
int front = -1;
int rear = -1;


void enqueue(int value);
void dequeue();
void peek();
void visualize_queue();
int isFull();
int isEmpty();

int main() {
    int choice, value;

    printf("\n==========================================\n");
    printf("    QUEUE SIMULATION (Array Based)\n");
    printf("==========================================\n");
    printf("Capacity: %d elements\n", MAX);

    while (1) {
        printf("\n------------------------------------------\n");
        printf(" 1. Enqueue (Insert)\n");
        printf(" 2. Dequeue (Delete)\n");
        printf(" 3. Peek (Front Element)\n");
        printf(" 4. Visualize Internal State\n");
        printf(" 5. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                visualize_queue();
                break;
            case 5:
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Check if queue is full
int isFull() {
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if queue is empty
int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

// Add an element to the rear
void enqueue(int value) {
    if (isFull()) {
        printf("\n[ERROR] Queue OVERFLOW! Cannot insert %d.\n", value);
        printf("(Rear has reached index %d)\n", MAX - 1);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("\n[SUCCESS] Inserted %d at Index %d.\n", value, rear);
        visualize_queue(); 
}
}

// Remove an element from the front
void dequeue() {
    if (isEmpty()) {
        printf("\n[ERROR] Queue UNDERFLOW! Nothing to delete.\n");
    } else {
        int deletedValue = queue[front];
        printf("\n[SUCCESS] Deleted %d from Index %d.\n", deletedValue, front);
        
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
            printf("(Queue is now completely empty, pointers reset to -1)\n");
        }
        visualize_queue();
    }
}

// View the front element
void peek() {
    if (isEmpty()) {
        printf("\n[INFO] Queue is Empty. No front element.\n");
    } else {
        printf("\n[PEEK] Front element is: %d (at Index %d)\n", queue[front], front);
    }
}

// The core simulation function: Draws the array and pointers
void visualize_queue() {
    printf("\n    INTERNAL MEMORY STATE:\n");
    
    // 1. Print Indices
    printf("    Index:  ");
    for (int i = 0; i < MAX; i++) {
        printf("  [%d]  ", i);
    }
    printf("\n");

    // 2. Print Data Container
    printf("    Data:   | ");
    for (int i = 0; i < MAX; i++) {
        if (i >= front && i <= rear && front != -1) {
            printf("%-4d | ", queue[i]); // Show Value
        } else {
            printf("     | "); // Show Empty Space
        }
    }
    printf("\n");

    // 3. Print Pointers (Front and Rear)
    printf("    Ptrs:     ");
    for (int i = 0; i < MAX; i++) {
        int printed = 0;
        if (i == front && front != -1) {
            printf("^F    ");
            printed = 1;
        }
        if (i == rear && rear != -1) {
            // Adjust spacing if Front and Rear are at the same index
            if (printed) printf("\b\b\b^F/R  "); 
            else printf("^R    ");
            printed = 1;
        }
        
        if (!printed) printf("       ");
    }
    printf("\n");
    printf("    (F = Front, R = Rear)\n");
}
