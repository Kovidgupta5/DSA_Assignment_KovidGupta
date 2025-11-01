#include <iostream>
#include <string>
using namespace std;

// Stack structure to store letters from the license plate
struct Stack {
    char arr[50];
    int top;
    Stack() {
        top = -1;
    }
    void push(char c) {
        if (top < 49) {
            top++;
            arr[top] = c;
        }
    }
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string licensePlate;
    cout << "Enter license plate: ";
    getline(cin, licensePlate);  // read full line including spaces

    int n;
    cout << "Enter number of words: ";
    cin >> n;

    string words[1000];
    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // Put only letters from license plate into stack (ignore numbers and spaces)
    Stack s;
    for (int i = 0; i < licensePlate.length(); i++) {
        char c = licensePlate[i];
        if (isalpha(c)) {
            c = tolower(c); // make lowercase
            s.push(c);
        }
    }

    string answer = "";
    int minLength = 1000;

    // Check each word from the list
    for (int i = 0; i < n; i++) {
        string w = words[i];

        // Count needed letters from license plate
        int need[26] = {0};
        for (int j = 0; j <= s.top; j++) {
            need[s.arr[j] - 'a']++;
        }

        // Count letters present in the current word
        int have[26] = {0};
        for (int j = 0; j < w.length(); j++) {
            char c = w[j];
            have[c - 'a']++;
        }

        // Check if the word has all required letters
        bool ok = true;
        for (int j = 0; j < 26; j++) {
            if (need[j] > have[j]) {
                ok = false;
                break;
            }
        }

        // If the word is valid and shorter than the previous one, keep it
        if (ok && w.length() < minLength) {
            answer = w;
            minLength = w.length();
        }
    }

    cout << "Shortest completing word: " << answer << endl;
    return 0;
}
