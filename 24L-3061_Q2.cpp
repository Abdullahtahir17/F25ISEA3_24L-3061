#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

string chooseRandomWord(const char filename[]);
void displayWord(const char word[], const bool guessed[], int length);
bool updateGuessedLetters(char guess, const char word[], bool guessed[], int length);
bool allLettersGuessed(const bool guessed[], int length);

int main()
{
    srand(static_cast<unsigned>(time(0)));// can use s rand here 

    const char filename[] = "words.txt";
    string wordStr = chooseRandomWord(filename);

    if (wordStr.empty())
    {
        cout << "Error: Could not read words from file." << endl;
        return 1;
    }

    int length = wordStr.length();
    char word[50];
    strcpy_s(word, wordStr.c_str());

    bool guessed[50] = { false };
    int remainingMistakes = 7;
    char guess;
    bool found;

    cout << "----------------------------------------\n";
    cout << "         HANGMAN GAME              \n";
    cout << "----------------------------------------\n";
    cout << "Word has " << length << " letters.\n";
    cout << "You can make 7 mistakes.\n\n";

    while (remainingMistakes > 0)
    {
        displayWord(word, guessed, length);

        cout << "\nEnter your guess (a-z): ";
        cin >> guess;
        guess = tolower(guess);

        found = updateGuessedLetters(guess, word, guessed, length);

        if (!found)
        {
            remainingMistakes--;
            cout << "Wrong guess!  Remaining mistakes: " << remainingMistakes << endl;
        }
        else
        {
            cout << "Good guess! " << endl;
        }

        if (allLettersGuessed(guessed, length))
        {
            cout << "\n Congratulations! You guessed the word: " << word << endl;
            return 0;
        }
    }

    cout <<endl<< " You lost! The word was: " << word << endl;
    return 0;
}


// Reads all words from file and picks one randomly
string chooseRandomWord(const char filename[])
{
    ifstream file(filename);
    if (!file)
        return "";

    string words[100];
    int count = 0;

    while (file >> words[count] && count < 100)
        count++;

    file.close();

    if (count == 0)
        return "";

    int index = rand() % count;
    return words[index];
}

// Displays the current guessed word
void displayWord(const char word[], const bool guessed[], int length)
{
    cout << "Word: ";
    for (int i = 0; i < length; i++)
    {
        if (guessed[i])
            cout << word[i] << ' ';
        else
            cout << "_ ";
    }
    cout << endl;
}

// Updates guessed letters, returns true if found
bool updateGuessedLetters(char guess, const char word[], bool guessed[], int length)
{
    bool found = false;
    for (int i = 0; i < length; i++)
    {
        if (tolower(word[i]) == guess && !guessed[i])
        {
            guessed[i] = true;
            found = true;
        }
    }
    return found;
}

// Checks if all letters are guessed
bool allLettersGuessed(const bool guessed[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!guessed[i])
            return false;
    }
    return true;
}
