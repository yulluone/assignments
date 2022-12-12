// In this program, 
// the cin statement is used for input, 
// and the cout statements are used for output. 
// The if statement is used to control the flow of the program based on 
// whether the input number is positive or not. 
// An array of type string with 10 elements is defined and
 // initialized with the English words for the numbers from 0 to 9. 
// The intToString() function is defined and called to convert an integer to a string,
// so that each digit can be looked up in the array of words and spelled out.

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert an integer to a string
string intToString(int n)
{
    string result;
    while (n > 0)
    {
        int digit = n % 10;
        result += char(digit + '0');
        n /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    // Input and output
    cout << "Enter a positive integer: ";
    int number;
    cin >> number;

    // Flow of control
    if (number <= 0)
    {
        cout << "Error: the number must be positive." << endl;
        return 1;
    }

    // Array
    array<string, 10> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Function
    string str = intToString(number);
    cout << "The number spelled out is: ";
    for (char ch : str)
    {
        int index = ch - '0';
        cout << words[index] << " ";
    }
    cout << endl;

    return 0;
}