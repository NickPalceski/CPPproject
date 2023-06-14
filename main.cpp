#include <iostream>
using namespace std;

class Player {  //class that holds the players name (object).
public:
    Player(){       //constructor
        cout<<"Enter player name: "; cin>>name;
    }
    string name;
    ~Player()= default;      //destructor
};

void playGame(){    //game is put in a void function which is run in main
    string prevWords[10];       //array that holds all the words guessed throughout the game.
    int x=0;        //increment for adding words to array.
    bool keepPlaying = true;    //if user decides to keep playing when asked.
    while (keepPlaying) {
        cout<<"First player enters a word, the second one guesses."<<endl;
        Player p1;
        Player p2;
        string word;
        cout << "Enter a word for "<<p2.name<<" to guess: ";
        cin >> word;
        prevWords[x]=word;      //puts the word into previous words array.
        x++;
        string blanks = word;   //copies word to another variable which changes word to "_" given blanks.
        for (char &c: blanks) {
            c = '_';
        }
        system("clear");
        cout << p1.name<<" picked a word " << ::size(blanks) << " characters long." << endl;

        int guesses = 5;
        char letter;
        bool endGame = false;   //bool variable so we can keep running until game has ended.
        while (!endGame) {
            cout << blanks << endl;
            cout << guesses << " Guesses left. " << endl;
            cout << "Enter a letter: ";
            cin >> letter;

            bool correct = false;   //set to false first because we still have to check.
            int i = 0;      //increment for each _ in blanks.
            for (char c: word) {
                if (letter == c) {
                    blanks[i] = letter;
                    correct = true; //letter is in the word.
                }
                i++;
            }
            if (!correct) {     //letter is not in the word, subtract a guess.
                guesses--;
            }
            if (blanks == word) {   //the word is guessed completely.
                endGame = true;
                cout << word << endl;
                cout << "Nice one "<<p2.name<<"! You guessed the word correctly!" << endl;
                cout << "You had "<<guesses<< " guesses remaining."<<endl;
            }
            if (guesses == 0) {     //run out of guesses.
                endGame = true;
                cout << "You are out of guesses! Game Over." << endl;
                cout << "The word was: " << word << endl;
            }
        }
             //ask user to play again.
        char playAgain;
        cout << "Would you like to play again? (y/n): " << endl;
        cin >> playAgain;
        switch(playAgain){
            case 'n': keepPlaying = false;{         //jumps out of loop.
            cout<<endl;
            cout<<"Words guessed this session: "<<endl;
            for (int j=0;j<x;j++){
                cout<<prevWords[j]<<" | ";
            }
            cout<<endl<<"Thanks for playing! Bye!"<<endl;
        }
            default:
                system("clear");
                continue;           //loops back to keepPlaying
        }
    }
}
int main() {
    playGame();     //void function is run in main.
    return 0;
}