#include <iostream>

using namespace std;

void board();
void startGame();
int playerTurn();
string defineMark(int);
int isGameOver();
void returnBoard();
bool playAgain(char);
int check();
void invalidMove();
string putMark(int, char[], char, int&);
int main();


char location[10] = { 'o','1','2','3','4','5','6','7','8','9' };
char play = 'y';
string player1, player2, turn;
int counter1 = 0, counter2 = 0;
int player = 1;


int main()
{
    char mark;
    int choice;
    

    startGame();

    while (playAgain)
    {
        do
        {
            board();
            playerTurn();

            cout << turn << ", enter a number:  ";
            cin >> choice;
           

            // define which mark will display
            mark = char(defineMark(player)[0]);

            putMark(choice, location, mark, player);

            check();
            player++;
            board();

        } while (check() == -1);


        if (check() == 1)
        {
            --player;
            if (player == 1)
                counter1++;
            else if (player == 2)
                counter2++;
            cout << "\a" << turn << " win";
        }
        else
            cout << "\a Game draw";

        cin.ignore();
        cin.get();

        cout << "Do you want to play again.\nTo play again enter 'y', to close the game enter 'n'" << endl;
        cin >> play;

        if (playAgain(play))
            returnBoard();
        else
        {
            cout << endl << "See You Later :)" << endl;
            exit(1);
        }
    }
    return 0;
}

void board()
{
    //using {system("cls")} to refresh the board in every step without print board again
    system("cls");

    cout << endl << player1 << " : " << counter1 << "       " << player2 << " : " << counter2 << endl;
    cout << endl << player1 << " (X) - " << player2 << " (O)" << endl << endl;

    cout << "\t _______________________" << endl;
    cout << "\t|       |       |       |" << endl;
    cout << "\t|   " << location[7] << "   |   " << location[8] << "   |   " << location[9] << "   |" << endl;
    cout << "\t|_______|_______|_______|" << endl;
    cout << "\t|       |       |       |" << endl;
    cout << "\t|   " << location[4] << "   |   " << location[5] << "   |   " << location[6] << "   |" << endl;
    cout << "\t|_______|_______|_______|" << endl;
    cout << "\t|       |       |       |" << endl;
    cout << "\t|   " << location[1] << "   |   " << location[2] << "   |   " << location[3] << "   |" << endl;
    cout << "\t|_______|_______|_______|" << endl;
    cout << endl;
}


void startGame()
{
    cout << "                                  ---------------------------------------------" << endl;
    cout << "                                  -------- Welcome to tic tac toe game --------" << endl;
    cout << "                                  ---------------------------------------------" << endl << endl;

    cout << "Player 1, What is your name? ";
    cin >> player1;
    player1[0] = toupper(player1[0]);

    cout << "Player 2, What is your name? ";
    cin >> player2;
    player2[0] = toupper(player2[0]);
}


int playerTurn()
{
    //define which player will play
    if (player % 2) {
        player = 1;
    }
    else {
        player = 2;
    }

    if (player == 1) {
        turn = player1;
    }
    else if (player == 2) {
        turn = player2;
    }
    return player;
}


void returnBoard()
{
    location[1] = '1';
    location[2] = '2';
    location[3] = '3';
    location[4] = '4';
    location[5] = '5';
    location[6] = '6';
    location[7] = '7';
    location[8] = '8';
    location[9] = '9';
    board();
}


bool playAgain(char choice)
{
    if (choice == 'y')
        return true;
    return false;
}


string defineMark(int player)
{
    if (player == 1)
        return "X";
    return "O";
}


int check()
{
    if (isGameOver() == 1)
        return 1;
    else if (isGameOver() == 0)
        return 0;

    return -1;
}


void invalidMove()
{
    cout << "Invalid move" << endl;
}


string putMark(int choice, char location[], char mark, int& player)
{
    if (choice == 1 && location[1] == '1')
        location[1] = mark;
    else if (choice == 2 && location[2] == '2')
        location[2] = mark;
    else if (choice == 3 && location[3] == '3')
        location[3] = mark;
    else if (choice == 4 && location[4] == '4')
        location[4] = mark;
    else if (choice == 5 && location[5] == '5')
        location[5] = mark;
    else if (choice == 6 && location[6] == '6')
        location[6] = mark;
    else if (choice == 7 && location[7] == '7')
        location[7] = mark;
    else if (choice == 8 && location[8] == '8')
        location[8] = mark;
    else if (choice == 9 && location[9] == '9')
        location[9] = mark;
    else
    {
        --player;
        invalidMove();
        cin.ignore();
        cin.get();
        return location;
    }
    return location;
}


int isGameOver()
{
    /*
        this function return:
        1 for game is over with result
        -1 for game is in progress
        0 game is over (Game draw)
    */
    if (location[1] == location[2] && location[2] == location[3])

        return 1;
    else if (location[4] == location[5] && location[5] == location[6])

        return 1;
    else if (location[7] == location[8] && location[8] == location[9])

        return 1;
    else if (location[1] == location[4] && location[4] == location[7])

        return 1;
    else if (location[2] == location[5] && location[5] == location[8])

        return 1;
    else if (location[3] == location[6] && location[6] == location[9])

        return 1;
    else if (location[1] == location[5] && location[5] == location[9])

        return 1;
    else if (location[3] == location[5] && location[5] == location[7])

        return 1;

    else if (location[1] != '1' && location[2] != '2' && location[3] != '3'
        && location[4] != '4' && location[5] != '5' && location[6] != '6'
        && location[7] != '7' && location[8] != '8' && location[9] != '9')

        return 0;

    else
        return -1;
}