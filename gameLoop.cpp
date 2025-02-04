//
// Created by Nick Palceski on 2/4/25.
//
#include <iostream>
#include <Player.h>

void playGame(){    //game is put in a void function which is run in main
    std::string prevWords[10];       //array that holds all the words guessed throughout the game.
    int x=0;        //increment for adding words to array.
    bool keepPlaying = true;    //if user decides to keep playing when asked.
    while (keepPlaying) {
        std::cout<<"First player enters a word, the second one guesses."<<std::endl;
        Player p1("test1");
        Player p2("test2");
        std::string word;
        std::cout << "Enter a word for "<<p2.playerName<<" to guess: ";
        std::cin >> word;
        prevWords[x]=word;      //puts the word into previous words array.
        x++;
        std::string blanks = word;   //copies word to another variable which changes word to "_" given blanks.
        for (char &c: blanks) {
            c = '_';
        }
        system("clear");
        std::cout << p1.playerName<<" picked a word " << blanks.size() << " characters long." << std::endl;

        int guesses = 5;
        char letter;
        bool endGame = false;   //bool variable so we can keep running until game has ended.
        while (!endGame) {
            std::cout << std::endl << blanks << std::endl;
            std::cout << guesses << " Guesses left. " << std::endl;
            std::cout << "Enter a letter: ";
            std::cin >> letter;

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
                std::cout << word << std::endl;
                std::cout<<std::endl;
                std::cout << "Nice one "<<p2.playerName<<"! You guessed the word correctly!" << std::endl;
                std::cout << "You had "<<guesses<< " guesses remaining."<<std::endl;
                std::cout<<std::endl;
            }
            if (guesses == 0) {     //run out of guesses.
                endGame = true;
                std::cout << std::endl;
                std::cout << "You are out of guesses! Game Over." << std::endl;
                std::cout << "The word was: " << word << std::endl;
            }
        }
        //ask user to play again.
        char playAgain;
        std::cout << "Would you like to play again? (y/n): " << std::endl;
        std::cin >> playAgain;

        switch(playAgain){
            case 'n': keepPlaying = false;{         //jumps out of loop.
            std::cout<<std::endl;
            std::cout<<"Words guessed this session: "<<std::endl;
            for (int j=0;j<x;j++){
                std::cout<<prevWords[j]<<" | ";
            }
            std::cout<<std::endl<<"Thanks for playing! Bye!"<<std::endl;
            break;
        }
            default:
                system("clear");
                continue;           //loops back to keepPlaying
        }
    }
}