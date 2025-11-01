#include <iostream>
using namespace std;

//  QUEUE CLASS
class Queue {
private:
    int arr[1000];        // Array to store elements
    int frontIndex;       // Points to front of queue
    int rearIndex;        // Points to rear of queue

public:
    // Constructor — initializes an empty queue
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    // Add (enqueue) a value at the end of the queue
    void enqueue(int value) {
        if (rearIndex == 999) {      // If queue is full
            cout << "Queue is full!" << endl;
            return;
        }
        rearIndex++;
        arr[rearIndex] = value;      // Add new element
    }

    // Remove (dequeue) and return the front value
    int dequeue() {
        if (isEmpty()) {             // Check if queue is empty
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int value = arr[frontIndex]; // Get front element
        frontIndex++;                // Move front pointer
        return value;
    }

    // Check if the queue is empty
    bool isEmpty() {
        if (frontIndex > rearIndex)
            return true;
        else
            return false;
    }

    // Return number of elements in queue
    int size() {
        if (isEmpty()) return 0;
        return (rearIndex - frontIndex + 1);
    }
};

//  SORTING FUNCTION
// Simple bubble sort to sort the array in ascending order
void sortArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap values if they are out of order
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


int main() {
    int n;
    cout << "Enter number of cards: ";
    cin >> n;

    int deck[1000];
    cout << "Enter the card values: ";
    for (int i = 0; i < n; i++) {
        cin >> deck[i];
    }

    // Step 1: Sort the card values
    sortArray(deck, n);

    // Step 2: Fill queue with positions (0, 1, 2, ..., n-1)
    Queue q;
    for (int i = 0; i < n; i++) {
        q.enqueue(i);
    }

    int result[1000];       // To store the final deck order
    int currentCard = 0;    // Index for current card in sorted deck

    // Step 3: Simulate the revealing process
    while (!q.isEmpty()) {
        // Take the top index from queue and place the next card there
        int index = q.dequeue();
        result[index] = deck[currentCard];
        currentCard++;

        // Move next index to back (like rotating the deck)
        if (!q.isEmpty()) {
            int nextIndex = q.dequeue();
            q.enqueue(nextIndex);
        }
    }

    // Step 4: Print the arranged deck
    cout << "Deck order to reveal cards in increasing order: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
