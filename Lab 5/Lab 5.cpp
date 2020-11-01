/*
Preston Derrig
c++ Fall 2020
Due: November 2nd 2020
Lab #5 Number Guessing Game
Create a game for the user to guess a random number from 1 to 100 and they only have 20 attempts to guess
correctly
*/

#include <iostream>      //library and namespaces
#include <time.h>
using namespace std;

void WelcomeMessage();  //a simple message displayed at the start of the program

void GenerateNumber(int& GeneratedValue); // a function that just create the random number the user is trying to guess

void GuessingNumbers(int RandomNumber_, int& TimesWon, int& TimesLost, int& RoundsPlayed);
// the function where the gameplay takes place. The user will input values in this function and the function will say
// if the guess was correct or wrong. This function is where the wins, loses, and rounds played are kept track off

void IncorrectGuesses(); //this function is just where a random incorrect guess message is made to tell the user their guess was incorrect

void WinningGuesses(); // this function has all the messages for the user when they win a round

void LossingMessages();//  this function holds the messages for when the user loses a round

void PlayAgainMessages(bool& playagain); // this has a the messages asking the player for a new round, and this function is 
// where the variable that keeps the game going gets turned off if the user wants to stop playing. 

void ClosingProgram(int Wins_, int Losses_, int TimesPlayed);// This function prints out some message for the player like 
// a thank you message, and messages about the amount of wins and losses they have





int main()
{
    bool playing = true; //these are the variables that get used in multiple functions
    int RandomNumber = 0;
    int Wins = 0;
    int Losses = 0;
    int Rounds = 0;

    WelcomeMessage();

    do //this loop is the game play loop that when shut off ends the program
    {
        GenerateNumber(RandomNumber);
        GuessingNumbers(RandomNumber, Wins, Losses, Rounds);
        PlayAgainMessages(playing);
    } while (playing == true);

    ClosingProgram(Wins, Losses, Rounds);

    return 0;
}


void WelcomeMessage()
{
    cout << "Hello, welcome to the random number guessing game." << endl <<
        "A random number between 1 and 100 has been generated" << endl
        << "You will have twenty guesses to try and get the right number." << endl;
}

void GenerateNumber(int& GeneratedValue)
{
    srand(time(NULL));
    GeneratedValue = rand() % 100 + 1;
}

void GuessingNumbers(int RandomNumber_, int& TimesWon, int& TimesLost, int& RoundsPlayed)
{
    int guess;
    int attempts;
    int incorrectguesscounter = 0;
    cout << endl << endl << endl << endl;

    for (attempts = 1; attempts < 21; attempts++) // this loop is what lets the user have 20 guesses at the real value
    {
        if (attempts == 1)
        {
            cout << "Please enter your first guess: ";
            cin >> guess; cout << endl << endl;
        }
        else
        {
            cout << "Please enter your next guess:  ";
            cin >> guess; cout << endl << endl;
        }

        if (guess > 100 || guess < 1) // this statement helps keep the values entered in the range where the actual value is
        {
            cout << "The guess you just put in is invalid" << endl <<
                "This guess doesn't count as one of your guess" << endl << endl;
            attempts--;
        }
        else
        {
            if (guess == RandomNumber_)// this if else statement is where the guess is checked and either the win or loss message is diplayed
            {                          // this statement also helps to track the amount of wins and losses
                attempts = 21;
                WinningGuesses();
                TimesWon++;
                TimesLost--;
            }
            else
                IncorrectGuesses();
            incorrectguesscounter++;
        }

    }
    if (incorrectguesscounter == 20)
        LossingMessages();

    TimesLost++;
    RoundsPlayed++;

    incorrectguesscounter = 0;
}

void IncorrectGuesses()
{
    int incorrectMessage;
    incorrectMessage = rand() % 10 + 1;

    switch (incorrectMessage)
    {
    case 1: cout << "Unlucky" << endl << endl;
        break;
    case 2: cout << "Better Luck Next Guess" << endl << endl;
        break;
    case 3: cout << "Try Again" << endl << endl;
        break;
    case 4: cout << "You'll get it next guess" << endl << endl;
        break;
    case 5: cout << "Uh Oh" << endl << endl;
        break;
    case 6: cout << "Wrong" << endl << endl;
        break;
    case 7: cout << "Maybe just guess the right number next time" << endl << endl;
        break;
    case 8: cout << "So close or So far, even I don't know the number" << endl << endl;
        break;
    case 9: cout << "Is it really this hard to guess the right number" << endl << endl;
        break;
    case 10: cout << "All Trick, and No Treat" << endl << endl;
        break;
    default: cout << "Error, please exit the program" << endl << endl;
        break;

    }

}


void LossingMessages()
{
    int LossingMessage;
    LossingMessage = rand() % 10 + 1;

    cout << "****************************************************" << endl;
    switch (LossingMessage)
    {
    case 1: cout << "Sorry, but you have lost this round of the number guessing game" << endl << endl;
        break;
    case 2: cout << "You had a 20% chance to guess the number, but you couldn't" << endl << endl;
        break;
    case 3: cout << "You have lost, but that's okay, statistically you were supposed to lose" << endl << endl;
        break;
    case 4: cout << "You have lost this round, my strategy for the next round, would be to guess the right number" << endl << endl;
        break;
    case 5: cout << "Unfortunately, you have not guessed the correct number this round" << endl << endl;
        break;
    case 6: cout << "Wow, you were wrong 20 times in a row!" << endl << endl;
        break;
    case 7: cout << "You have lost, but we both know your next guess was totally the right number" << endl << endl;
        break;
    case 8: cout << "With your number guessing skill, I would suggest not buying any lottery tickets" << endl << endl;
        break;
    case 9: cout << "You have lost this round, do I need to remind you that the goal is to guess the right number early, not leave it to the last guess" << endl << endl;
        break;
    case 10: cout << "This round ends as a loss for you" << endl << endl;
        break;
    default: cout << "Error, please exit the program" << endl << endl;
        break;
    }

}

void WinningGuesses()
{
    int WinMessage;
    WinMessage = rand() % 10 + 1;

    cout << "*************************************" << endl <<
        "You guessed correctly and win this round!" << endl << endl;
    switch (WinMessage)
    {
    case 1: cout << "Good job, I guess, this doesn't take an actual skill" << endl << endl;
        break;
    case 2: cout << "Great work" << endl << endl;
        break;
    case 3: cout << "Awesome Guess" << endl << endl;
        break;
    case 4: cout << "Amazing, this is your 1 in 5 chance of wining" << endl << endl;
        break;
    case 5: cout << "Spectacular" << endl << endl;
        break;
    case 6: cout << "Unbelieveable,a random guess was miracously correct, it's not like literal infants could do that" << endl << endl;
        break;
    case 7: cout << "Awe Inspiring" << endl << endl;
        break;
    case 8: cout << "You are the man at games of luck that take 0 skill to win" << endl << endl;
        break;
    case 9: cout << "Cool, you randomly guessed 1 number out of 100" << endl << endl;
        break;
    case 10: cout << "Impressive" << endl << endl;
        break;
    default: cout << "Error, please exit the program" << endl << endl;
        break;

    }

}

void PlayAgainMessages(bool& playagain)
{
    int PAMessage;
    PAMessage = rand() % 10 + 1;
    int answer;

    switch (PAMessage)
    {
    case 1: cout << endl << "That was fun!" << endl << endl;
        break;
    case 2: cout << endl << "Let's play again!" << endl << endl;
        break;
    case 3: cout << endl << "Who's up for another round?" << endl << endl;
        break;
    case 4: cout << endl << "My mom said it's okay for you to play another round." << endl << endl;
        break;
    case 5: cout << endl << "Come on you have time to play one more round." << endl << endl;
        break;
    case 6: cout << endl << "Play Again, It's Literally Free to Play" << endl << endl;
        break;
    case 7: cout << endl << "You Can't Be Bored Yet, Can You?" << endl << endl;
        break;
    case 8: cout << endl << "Play Again, It's even easier than 123, You just push 1" << endl << endl;
        break;
    case 9: cout << endl << "If you play again and win, the reward is ... well, nothing, but a sense of pride" << endl << endl;
        break;
    case 10: cout << endl << "You know You want to play again." << endl << endl;
        break;
    default: cout << endl << "Error, please exit the program";
        break;

    }


    cout << "If you would like to play again, enter 1." << endl <<
        "If you wish to finish playing , enter 2:   ";

    cin >> answer; // these statements help to check that the number put in is valid and to then either finish the game or run the game again
    if (answer > 2 || answer < 0)
    {
        cout << "The number you input is not valid." << endl << "Please enter either the numbers 1 or 2:   ";
        cin >> answer;
    }
    if (answer == 1)
        playagain = true;
    else
        playagain = false;

    cout << endl << endl;

}

void ClosingProgram(int Wins_, int Losses_, int TimesPlayed)
{

    cout << endl << endl << "Thank you so much for playing!" << endl << endl
        << "At the end you played " << TimesPlayed;
    if (TimesPlayed == 1)
        cout << " round.";
    else
        cout << " rounds.";

    cout << endl << endl << "In that time you won " << Wins_;
    if (Wins_ == 1)
        cout << " round.";
    else
        cout << " rounds.";

    cout << endl << endl << "And, you also lost " << Losses_;
    if (Losses_ == 1)
        cout << " round.";
    else
        cout << " rounds.";

    cout << endl << endl << endl << endl;

}
