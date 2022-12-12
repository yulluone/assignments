#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // maximum size of the array that will store the sequence

// Function prototypes
void print_fibonacci_sequence(int sequence[], int size);

int main() {
  int fibonacci_sequence[MAX_SIZE]; // array that will store the sequence
  int num; // variable to store the number up to which the sequence will be calculated
  
  // Ask the user to input a number
  cout << "Enter a number: ";
  cin >> num;

  // Initialize the first two numbers in the sequence
  fibonacci_sequence[0] = 0;
  fibonacci_sequence[1] = 1;

  // Calculate the next numbers in the sequence using a loop
  for (int i = 2; i < num; i++) {
    fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
  }

  // Print the sequence to the screen
  print_fibonacci_sequence(fibonacci_sequence, num);
  
  return 0;
}

// Function to print the Fibonacci sequence
void print_fibonacci_sequence(int sequence[], int size) {
  for (int i = 0; i < size; i++) {
    cout << sequence[i] << " ";
  }
  cout << endl;
}