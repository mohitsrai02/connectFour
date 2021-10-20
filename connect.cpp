#include <string>
#include <iostream>
using namespace std;
int main()
{
    int r, c, p;
    string board[40][40];
    cout << "Enter no. of rows and columbs:-" << endl;
    cin >> r >> c;
    int maxTurns = r*c;
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

    for (int i = 0; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout <<"|"<< board[i][j] << "|";
        }
        cout << "\n";
    }

    string player1 = "red";
    string player2 = "yellow";

    while(1){
        if ()
        {
            /* code */
        }
        
        cout<<"hello";
        break;

    }
    return 0;
}