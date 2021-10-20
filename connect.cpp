#include <string>
#include <iostream>
using namespace std;
void printBoard(int row, int col, string arr[40][40]);
void insertDisk(int row, int col, int rowNum, string player, string arr[40][40]);
int main()
{
    int r, c, p;
    string board[40][40];
    cout << "Enter no. of rows and columbs:-" << endl;
    cin >> r >> c;
    int maxTurns = r * c;
    int turnCount = 0;
    int insert;
    cout << "Enter win connections required:-" << endl;
    cin >> p;
    //Initializing Row numbers
    for (int i = 1; i <= c; i++)
    {
        board[0][i] = to_string(i);
    }
    //Initializing the 2D array with O
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            board[i][j] = "O";
        }
    }

    printBoard(r, c, board);

    string player1 = "r";
    string player2 = "y";
    //Setting up an Infinite while loop
    while (1)
    {
        if (turnCount % 2 != 0)
        {
            turnCount++;
            cout << endl
                 << "Red's Turn" << endl
                 << "Enter Row No. where you would Like to insert your disk : ";
            cin >> insert;
            insertDisk(r,c,insert, player2,board);
            printBoard(r, c, board);
        }
        else
        {
            turnCount++;
            cout << endl
                 << "Yellow's Turn" << endl
                 << "Enter Row No. where you would Like to insert your disk : ";
            cin >> insert;
            insertDisk(r,c,insert, player2,board);
            printBoard(r, c, board);
        }
        if (turnCount == maxTurns)
        {
            break;
        }
    }
    return 0;
}
//Insert Disk in board Function

void insertDisk(int row, int col, int rowNum, string player, string arr[40][40]){
    arr[2][2] = player;

}

//Print Board Function
void printBoard(int row, int col, string arr[40][40])
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            cout << "|" << arr[i][j] << "|";
        }
        cout << endl;
    }
}