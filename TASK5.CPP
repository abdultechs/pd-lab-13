#include <iostream>
#include <fstream>
using namespace std;

string alphabetSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
string morseCodeSet[100] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-.-"
};

// Function to convert a single character to Morse code
string convertToMorse(char inputChar) 
{
    if(inputChar >= 'a' && inputChar <= 'z') 
    {
        inputChar -= 32; // Convert to uppercase
    }
    for(int i = 0; i < alphabetSet.length(); i++) 
    {
        if(alphabetSet[i] == inputChar) 
        {
            return morseCodeSet[i];
        }
    }
    return "";
}

// Function to encrypt a message into Morse code
void encryptMessage(string inputMessage) 
{
    fstream morseOutputFile;
    morseOutputFile.open("MorseOutput.txt", ios::out);
    
    string morseEncodedMessage = "";
    for(int i = 0; i < inputMessage.length(); i++) 
    {
        string morseChar = convertToMorse(inputMessage[i]);
        if(!morseChar.empty()) 
        {
            morseEncodedMessage += morseChar + " ";
        }
    }
    
    morseOutputFile << "Original message: " << inputMessage << endl;
    morseOutputFile << "Morse code: " << morseEncodedMessage << endl;
    morseOutputFile.close();
}

int main() 
{
    string userMessage;
    cout << "Enter the message to encrypt: ";
    getline(cin, userMessage);
    
    encryptMessage(userMessage);
    
    return 0;
}
