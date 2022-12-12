#include <iostream>
#include <array>
using namespace std;

// Function to calculate the sum of an array of integers
int sum(array<int, 2> arr)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        total += arr[i];
    }
    return total;
}

int main()
{
    // Input and output
    int x, y;
				cout << "This program will calculate the sum of an array of 2 integers.";
				cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "You entered: " << x << " and " << y << endl;

    // Flow of control
    if (x > y)
    {
        cout << "The first number is greater than the second number." << endl;
    }
    else if(x < y)
				{
								cout << "The second number is greater than the first number." << endl;
				}
				else
				{
								cout << "The numbers are equal." << endl;
				}
				

    // Array
				array<int, 2> numbers;
				numbers[0] = x;
				numbers[1] = y;

    // Function
    int total = sum(numbers);
    cout << "The sum of the numbers in the array is: " << total << endl;

    return 0;
}