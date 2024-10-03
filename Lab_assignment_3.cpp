#include <iostream>

class queue {
private: 
    int rear, front;
    int queueL[50];
    int max;
    int size;
public:
    queue() {
        size = 0;
        max = 50;
        rear = front = -1; // Initially queue is empty
    }
    int is_empty();
    int is_full();
    void add(int element);
    void del();
    void print();
};

int queue::is_empty() {
    return front == -1; // Check if the queue is empty
}

int queue::is_full() {
    return rear == (max - 1); // Check if the queue is full
}

void queue::add(int element) { // Insertion of an element
    if (!is_full()) {
        if (is_empty()) {
            front = 0; // First element added
        }
        queueL[++rear] = element;
        size++;
    } else {
        std::cout << "Queue is full. Cannot add element " << element << ".\n";
    }
}

void queue::del() { // Deletion of an element
    if (!is_empty()) {
        int element = queueL[front++]; // Remove element from the front
        if (front > rear) { // Reset queue if it becomes empty
            front = rear = -1; // Reset for next operations
        }
        size--;
    } else {
        std::cout << "Queue is empty. Cannot delete element.\n";
    }
}

void queue::print() {
    if (is_empty()) {
        std::cout << "\nQueue is empty.\n";
        return;
    }
    std::cout << "\nElements of queue: ";
    for (int i = front; i <= rear; i++) {
        std::cout << queueL[i] << "\t";
    }
    std::cout << std::endl;
}

int main() {
    queue q;
    q.add(12);
    q.add(3);
    q.add(4);
    q.print();
    
    q.del();
    q.print();
    
    q.del();
    q.print();
    
    q.del(); // This will delete the last element
    q.print(); // Check if the queue is empty after all deletions
    
    return 0;
}



