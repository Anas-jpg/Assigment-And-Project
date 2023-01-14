#include <iostream>
using namespace std;

struct Connect4
{
     connect4(string Names[]){
        re_init(Names);
    }
    connect4(){
        string N[2] = {"P1", "P2"};
        re_init(N);
    }
    void re_init(string Names[]){
        for(int i = 0; i< 7; i++){
            ColumnMoves[i] = 6;
            for(int j = 0; j< 6; j++)
                Data[j][i] = 32;
        }
        Result = 0;
        GameOver = 0;
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'o';
        PlayerChar[1] = 'x';
        PlayerWinningChar[0] = 'O';
        PlayerWinningChar[1] = 'X';
    }
    char playerName[81];
	char playerID;

int MakeMove(int Columns,Connect4 &activePlayer)
{
    char Data[9][Columns];
	int Move;
	do
	{
		cout << activePlayer.playerName << "'s turn ";
		cout << "Please Insert a Number Between 1 and 7 : ";
		cin >> Move;
            if(Move>7 || Move<1)
                cout<<"Number Out of Range "<<endl<<endl;
        while (Data[1][Move] == 'x' || Data[1][Move] == 'o')
		{
			cout << "That Row is Full, Please Enter New Row: ";
			cin >> Move;
		}
		if(Data[1][Move] == 'x')
        return -1;
	}
        while (Move < 1 || Move > 7);
	return Move;

}
void ShowGame(char Data[][10])
{
	int r = 6, c = 7, i, ix;

	for (i = 1; i <= r; i++)
	{
		cout << "|";
		for (ix = 1; ix <= c; ix++)
		{
			if (Data[i][ix] != 'x' && Data[i][ix] != 'o')
				Data[i][ix] = '-';

			cout << Data[i][ix] << " ";
		}
		cout << "|" << endl;
	}
}
int Restart()
{
    char Data[9][10];
	int Restart;

	cout << "Would you like to Restart? Yes(1) No(2): ";
	cin >> Restart;
	if (Restart == 1)
	{
		for (int i = 1; i <= 6; i++)
		{
			for (int ix = 1; ix <= 7; ix++)
			{
				Data[i][ix] = '-';
			}
		}
	}
	else
		cout << "END!- Hope you Enjoy" << endl;
	return Restart;
}
void bottomcheck(char Data[][10], Connect4 &activePlayer, int Move)
{
	int x, turn;
	x = 6;
	turn = 0;

	do
	{
		if (Data[x][Move] != 'x' && Data[x][Move] != 'o')
		{
			Data[x][Move] = activePlayer.playerID;
			turn = 1;
		}
		else
			--x;
	}
	 while (turn != 1);
}
void isWinner(Connect4 &activePlayer)
{
	cout << endl << activePlayer.playerName << " , Congratulations! You Win!\n Game Over" << endl;
}
void Start()
	{
    Connect4 playerOne, playerTwo;
	int Move, win, full, again;

	cout << "Enter the Name of Player 1 : ";
	cin >> playerOne.playerName;
	playerOne.playerID = 'x';
	cout << "Enter the Name of Player 2 : ";
	cin >> playerTwo.playerName;
	playerTwo.playerID = 'o';
	win = 0;
	again = 0;
        char Data[9][10];
	    ShowGame(Data);
	    do
            {
		Move = MakeMove(10,playerOne);
		bottomcheck(Data, playerOne, Move);
		ShowGame(Data);
		win = CheckIfGameOver(Data, playerOne);
		if (win == 1)
		{
			isWinner(playerOne);
			again = Restart();
			if (again == 2)
			{
				break;
			}
		}

		Move = MakeMove(10,playerTwo);
		bottomcheck(Data, playerTwo, Move);
		ShowGame(Data);
		win = CheckIfGameOver(Data, playerTwo);
		if (win == 1)
		{
			isWinner(playerTwo);
			again = Restart();
			if (again == 2)
			{
				break;
			}
		}
	}
	 while (again != 2);
}
private:
    int CheckIfGameOver(char Data[][10], Connect4 &activePlayer)
{
	char XO;
	int countr;

	XO = activePlayer.playerID;
	countr = 0;

	for (int i = 8; i >= 1; --i)
	{

		for (int IX = 9; IX >= 1; --IX)
		{

			if (Data[i][IX] == XO &&
				Data[i - 1][IX - 1] == XO &&
				Data[i - 2][IX - 2] == XO &&
				Data[i - 3][IX - 3] == XO)
			{
				countr = 1;
			}
			if (Data[i][IX] == XO &&
				Data[i][IX - 1] == XO &&
				Data[i][IX - 2] == XO &&
				Data[i][IX - 3] == XO)
			{
				countr = 1;
			}

			if (Data[i][IX] == XO &&
				Data[i - 1][IX] == XO &&
				Data[i - 2][IX] == XO &&
				Data[i - 3][IX] == XO)
			{
				countr = 1;
			}

			if (Data[i][IX] == XO &&
				Data[i - 1][IX + 1] == XO &&
				Data[i - 2][IX + 2] == XO &&
				Data[i - 3][IX + 3] == XO)
			{
				countr = 1;
			}
			if (Data[i][IX] == XO &&
				Data[i][IX + 1] == XO &&
				Data[i][IX + 2] == XO &&
				Data[i][IX + 3] == XO)
			{
				countr = 1;
			}
		}
	}
	return countr;
}
string PlayerNames[2];
    int TurningPlayer;
    char PlayerChar[2];
    char PlayerWinningChar[2];
    int  ColumnMoves[7];
    char Data[6][7];
    bool GameOver;
    int Result;
};
int main()
{
    cout << "*-----------------------------------------------------------------------------------------|" << endl;
	cout << "\t\t\t\tWELCOME TO Connect4 Game  " << endl;
	cout << "*-----------------------------------------------------------------------------------------|" << endl << endl << endl;
    Connect4 New;
	New.Start();
	return 0;
}
