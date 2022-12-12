/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cpplite/CPPTemplate.cpp to edit this template
 */

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

// Function to reverse a string
string reverseString(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    // Input and output
    cout << "Enter a sentence: ";
    string line;
    getline(cin, line);

    // Flow of control
    if (line.empty())
    {
        cout << "Error: no sentence was entered." << endl;
        return 1;
    }

    // Array
    array<string, 100> words;
    int wordCount = 0;

    // Function
    string word;
    for (char ch : line)
    {
        if (isspace(ch))
        {
            if (!word.empty())
            {
                words[wordCount++] = word;
                word.clear();
            }
        }
        else
        {
            word += ch;
        }
    }
    if (!word.empty())
    {
        words[wordCount++] = word;
    }

    // Reverse each word and output the result
    cout << "The reversed sentence is: ";
    for (int i = 0; i < wordCount; i++)
    {
        cout << reverseString(words[i]) << " ";
    }
    cout << endl;

    return 0;
}