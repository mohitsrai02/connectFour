#include <string>
#include <iostream>
#include <conio.h>
using namespace std;
class connect
{
public:
    int r, c, p;
    string board[40][40];
    int maxTurns = r * c;
    int turnCount = 1;
    int temp;
    int insert;
    int count = 0;
    string player1 = "r";
    string player2 = "y";
    string player;
    string winner = "none";
    connect();
    ~connect();
    void printBoard();
    void initialize();
    void startGame();
    void insertDisk(int rowNum, string player);
    string checkVertical(string player);
    string checkH(string player);
};

int main()
{
    connect game;
    game.initialize();
    game.startGame();
    return 0;
}

connect::~connect()
{
}
void connect::startGame()
{
    printBoard();
    //Setting up an Infinite while loop
    while (1)
    {
        if (turnCount % 2 != 0)
        {
            cout << endl
                 << "Red's Turn" << endl
                 << "Enter Row No. where you would Like to insert your disk : ";
            cin >> insert;
            turnCount++;
            insertDisk(insert, player1);
            printBoard();
            if (winner == "r")
            {
                break;
            }
        }
        else
        {
            player = 'y';
            cout << endl
                 << "Yellow's Turn" << endl
                 << "Enter Row No. where you would Like to insert your disk : ";
            cin >> insert;
            turnCount++;
            insertDisk(insert, player2);
            printBoard();
            if (winner == "y")
            {
                break;
            }
        }
        cout << maxTurns - turnCount << " turns remaining" << endl;
        if (turnCount == maxTurns)
        {
            cout << "Game Over" << endl
                 << "Result : Draw" << endl;
            break;
        }
    }
}
//for horizontal
string connect::checkH(string player)
{
    for (int x = 0; x <= r; x++)
    {
        if (board[c][insert+x] == player)
        {
            ++count;
        }
        if (board[c][insert-x] == player)
        {
            ++count;
        }

    }
    --count;
    if (count >= p)
    {
        cout << "Player " << player << " has won the game" << endl;
        return player;
    }
    else
    {
        count = 0;
    }
    return "continue";
}
//for vertical
string connect::checkVertical(string player)
{
    for (int x = 0; x <= r; x++)
    {
        if (board[c - x][insert] == player)
        {
            ++count;
        }
    }
    if (count >= p)
    {
        cout << "Player " << player << " has won the game" << endl;
        return player;
    }
    else
    {
        count = 0;
    }
    return "continue";
}

void connect::insertDisk(int rowNum, string player)
{
    temp = c;
    while (1)
    {
        if (board[temp][rowNum] == "O")
        {
            board[temp][rowNum] = player;

        winner = checkVertical(player);
            if (winner == "r" || winner == "y")
            {}
            else{
                winner = checkH(player);
            }
            
            break;
        }
        --temp;
        if (temp == 0)
        {
            break;
        }
    }
}
connect::connect()
{
    cout << "Enter no. of rows:-" << endl;
    cin >> r;
    cout << "Enter no. of columns:-" << endl;
    cin >> c;
    cout << "Enter win connections required:-" << endl;
    cin >> p;
    maxTurns = r * c;
}
void connect::initialize()
{
    for (int i = 1; i <= c; i++)
    {
        board[0][i] = to_string(i);
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            board[i][j] = "O";
        }
    }
}
void connect::printBoard()
{
    for (int i = 0; i <= r; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            cout << "|" << board[i][j] << "|";
        }
        cout << endl;
    }
}
