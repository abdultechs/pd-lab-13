#include <iostream>
#include <fstream>
using namespace std;

void findMissingAlphabets(string inputAlphabets) 
{
    bool presentLetters[26] = {false};
    
    // Marking present letters
    for (int i = 0; i < inputAlphabets.size(); i++) 
    {
        char currentChar = inputAlphabets[i];
        if (currentChar >= 'a' && currentChar <= 'z') 
        {
            presentLetters[currentChar - 'a'] = true;
        }
    }
    
    // Finding missing letters
    string missingAlphabets = "";
    for (int i = 0; i < 26; i++) 
    {
        if (!presentLetters[i]) 
        {
            missingAlphabets += char(i + 'a');
        }
    }

    // Writing missing alphabets to file
    fstream alphabetFile;
    alphabetFile.open("alphabets.txt", ios::app);
    if (!missingAlphabets.empty()) 
    {
        alphabetFile << "\n" << missingAlphabets;
    } 
    else 
    {
        alphabetFile << "\n";
    }
    alphabetFile.close();
}

int main() 
{
    string inputAlphabets;
    cout << "Enter alphabets (a-z): ";
    cin >> inputAlphabets;
    
    // Writing input alphabets to file
    fstream alphabetFile;
    alphabetFile.open("alphabets.txt", ios::out); 
    alphabetFile << inputAlphabets;
    alphabetFile.close();
    
    // Checking for missing alphabets
    findMissingAlphabets(inputAlphabets);
    
    return 0;
}
