#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// Function to sort a string in alphabetical order
string sortString(string str)
{
    sort(str.begin(), str.end());
    return str;
}

int main()
{
    // Input and output
    cout << "Enter a list of words, separated by spaces: ";
    string line;
    getline(cin, line);

    // Flow of control
    if (line.empty())
    {
        cout << "Error: no words were entered." << endl;
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

    // Use a map to count the number of occurrences of each sorted word
    map<string, int> wordCounts;
    for (int i = 0; i < wordCount; i++)
    {
        string sortedWord = sortString(words[i]);
        wordCounts[sortedWord]++;
    }

    // Output the results
    cout << "Number of anagrams: " << wordCounts.size() << endl;
    for (auto pair : wordCounts)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}