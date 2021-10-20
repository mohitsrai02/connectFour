#include <string>
#include <iostream>
using namespace std;
void printBoard(int row, int col, string arr[40][40]);

int main()
{
    int r, c, p;
    string board[40][40];
    cout << "Enter no. of rows and columbs:-" << endl;
    cin >> r >> c;
    int maxTurns = r*c;
    int turnCount = 1;
    cout << "Enter win connections required:-" << endl;
    cin >> p;
    //Initializing Row numbers
    for (int i = 1; i <= c; i++)
    {
             board[0][i]= to_string(i);
    }
    //Initializing the 2D array with O
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
             board[i][j]="O";
        }
    }

    printBoard(r,c,board);

    string player1 = "red";
    string player2 = "yellow";

    while(1){
        if (turnCount % 2 != 0)
        {
            cout<<"Red's Turn"<<endl;
        }

        break;

    }
    return 0;
}
void printBoard(int row, int col, string arr[40][40])
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            cout << "|" << arr[i][j] << "|";
        }
        cout <<endl;
    }
}