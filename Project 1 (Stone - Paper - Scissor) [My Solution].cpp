#include <iostream> 
#include <cstdlib>              // for rand() and srand()
#include <ctime>                // for time()

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

short HowManyRounds()
{
    short RoundsNumber;

    do {

        cout << "How Many Rounds 1 to 10 ? ";
        cin >> RoundsNumber;

    } while (RoundsNumber < 1 || RoundsNumber > 10);

    return RoundsNumber;
}

enGameChoice ReadPlayerChoice()
{
    short c;

    do {
        cout << "\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissor ? ";
        cin >> c;
    } while (c != 1 && c != 2 && c != 3);

    return (enGameChoice)c;
}

enGameChoice GetComputerChoice()
{
    short c = RandomNumber(1, 3);

    return (enGameChoice)c;
}

string GetChoiceString(enGameChoice GameChoice)
{
    switch (GameChoice)
    {
    case enGameChoice::Stone :
        return "Stone";
    case enGameChoice::Paper:
        return "Paper";
    case enGameChoice::Scissor:
        return "Scissor";
    }
}

string GameRules(enGameChoice PlayerChoice, enGameChoice ComputerChoice)
{
    if (PlayerChoice == ComputerChoice)
    {
        system("color 6F");
        return "[No Winner]";
    }

    switch (PlayerChoice)
    {
    case enGameChoice::Stone:
        if (ComputerChoice == enGameChoice::Paper)
        {
            cout << "\a";
            system("color 4F");
            return "[Computer]";
        }
        else
        {
            system("color 2F");
            return "[Player]";
        }
    case enGameChoice::Paper:
        if (ComputerChoice == enGameChoice::Scissor)
        {
            cout << "\a";
            system("color 4F");
            return "[Computer]";
        }
        else
        {
            system("color 2F");
            return "[Player]";
        }

    case enGameChoice::Scissor:
        if (ComputerChoice == enGameChoice::Stone)
        {
            cout << "\a";
            system("color 4F");
            return "[Computer]";
        }
        else
        {
            system("color 2F");
            return "[Player]";
        }
    }
}

void WonTimes(string RoundWinner, short& PlayerWonTimes, short& ComputerWonTimes, short& DrawTimes)
{
    if (RoundWinner == "[Player]")
        PlayerWonTimes++;
    else
        if (RoundWinner == "[Computer]")
            ComputerWonTimes++;
        else
            DrawTimes++;
}

void OneRoundResults(short RoundsNumber, short& PlayerWonTimes, short& ComputerWonTimes, short& DrawTimes)
{
    for (short i = 1; i <= RoundsNumber; i++)
    {
        cout << endl << "\nRound [" << i << "] begins: " << endl;

        enGameChoice PlayerChoice = ReadPlayerChoice();
        enGameChoice ComputerChoice = GetComputerChoice();

        string RoundWinner = GameRules(PlayerChoice, ComputerChoice);

        WonTimes(RoundWinner, PlayerWonTimes, ComputerWonTimes, DrawTimes);

        cout << "\n___________Round [" << i << "]___________" << endl << endl;
        cout << "Player Choice   : " << GetChoiceString(PlayerChoice) << endl;
        cout << "Computer Choice : " << GetChoiceString(ComputerChoice) << endl;
        cout << "Round Winner    : " << RoundWinner << endl;
        cout << "_______________________________" << endl;    
    }
}

string FinalWinner(short PlayerWonTimes, short ComputerWonTimes)
{
    if (PlayerWonTimes > ComputerWonTimes)
        return "Player";
    else
        if (PlayerWonTimes < ComputerWonTimes)
            return "Computer";
        else
            return "No winner";
}

void EndOfGame(short& PlayerWonTimes, short& ComputerWonTimes, short& DrawTimes, char& ReStartGame)
{
    short RoundsNumber = HowManyRounds();
    
    OneRoundResults(RoundsNumber, PlayerWonTimes, ComputerWonTimes, DrawTimes);

    cout << endl << "\t\t______________________________________________________" << endl << endl;
    cout << "\t\t\t\t+++ G a m e  O v e r +++" << endl;
    cout << "\t\t______________________________________________________" << endl << endl;
    cout << "\t\t____________________[Game Results]____________________" << endl << endl;
    cout << "\t\tGame Rounds        : " << RoundsNumber << endl;
    cout << "\t\tPlayer won times   : " << PlayerWonTimes << endl;
    cout << "\t\tComputer won times : " << ComputerWonTimes << endl;
    cout << "\t\tDraw times         : " << DrawTimes << endl;
    cout << "\t\tFinal Winner       : " << FinalWinner(PlayerWonTimes, ComputerWonTimes) << endl;

    cout << "\t\t______________________________________________________" << endl << endl;
    cout << "\t\tDo you want to play again? Y/N? ";
    cin >> ReStartGame;
}

void ResetGame(short& PlayerWonTimes, short& ComputerWonTimes, short& DrawTimes)
{
    PlayerWonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

    // Optional: clear the screen
    system("cls");

    // Optional: reset color
    system("color 0F"); // Default console color
}

int main() {
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    short PlayerWonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;
    char ReStartGame = 'A';

    do{
        EndOfGame(PlayerWonTimes, ComputerWonTimes, DrawTimes, ReStartGame);
        ResetGame(PlayerWonTimes, ComputerWonTimes, DrawTimes);
    } while (ReStartGame == 'Y' || ReStartGame == 'y');

    return 0;
}