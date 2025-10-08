#include <iostream>
#include <conio.h>   // for _getch() to detect 'Esc'
#include <cstring>   
using namespace std;

// Function to check if a string is palindrome
bool isPalindrome(const char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

// Function to display result
void checkAndDisplay(const char str[])
{
    if (isPalindrome(str))
        cout << "Result: Palindrome" << endl;
    else
        cout << "Result: Not Palindrome " << endl;
}

int main()
{
    char input[100];

    cout << endl;
    cout << "Palindrome Checker Program\n";
    cout << endl;
    cout << "Press ESC anytime to exit.\n\n";

    while (true)
    {
        cout << "Enter a word: ";

        int i = 0;
        char ch;

        while (true)
        {
            ch = _getch();

            if (ch == 27) // ESC key ASCII code
            {
                cout << "\nExiting program..." << endl;
                return 0;
            }
            else if (ch == '\r') // Enter key
            {
                input[i] = '\0';
                cout << endl;
                break;
            }
            else if (ch == '\b') // Handle backspace
            {
                if (i > 0)
                {
                    cout << "\b \b";
                    i--;
                }
            }
            else if (i < 99) // Normal character input
            {
                input[i++] = ch;
                cout << ch;
            }
        }

        checkAndDisplay(input);
        cout << endl;
    }

    return 0;
}
