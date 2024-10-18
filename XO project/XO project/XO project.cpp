#include <iostream>
#include <string>
#include <iomanip>
#include<cstdlib>
using namespace std;
bool win = true;
string nameO, nameX;
char order[3][3] = { {'1', '2', '3'}, { '4','5','6' }, { '7','8','9' } };

void resetboard()
{
	char order[3][3] = { {'1', '2', '3'}, { '4','5','6' }, { '7','8','9' } };
}
void players(string& name1, string& name2)
{
	cout << "enter the name of the first player \'O\' player \n";
	cin >> name1;
	cout << "enter the name of the second player \'X\' player \n";
	cin >> name2;
	nameO = name1;
	nameX = name2;
}

bool winerO()
{

	if (order[0][0] == 'O' && order[0][1] == 'O' && order[0][2] == 'O' ||
		order[0][0] == 'O' && order[1][0] == 'O' && order[2][0] == 'O' ||
		order[1][0] == 'O' && order[1][1] == 'O' && order[1][2] == 'O' ||
		order[2][0] == 'O' && order[2][1] == 'O' && order[2][2] == 'O' ||
		order[0][1] == 'O' && order[1][1] == 'O' && order[2][1] == 'O' ||
		order[0][2] == 'O' && order[1][2] == 'O' && order[2][2] == 'O' ||
		order[0][0] == 'O' && order[1][1] == 'O' && order[2][2] == 'O' ||
		order[0][2] == 'O' && order[1][1] == 'O' && order[2][0] == 'O')
		return true;
	else
		return false;
}
bool winerX()
{
	if (order[0][0] == 'X' && order[0][1] == 'X' && order[0][2] == 'X' ||
		order[0][0] == 'X' && order[1][0] == 'X' && order[2][0] == 'X' ||
		order[1][0] == 'X' && order[1][1] == 'X' && order[1][2] == 'X' ||
		order[2][0] == 'X' && order[2][1] == 'X' && order[2][2] == 'X' ||
		order[0][1] == 'X' && order[1][1] == 'X' && order[2][1] == 'X' ||
		order[0][2] == 'X' && order[1][2] == 'X' && order[2][2] == 'X' ||
		order[0][0] == 'X' && order[1][1] == 'X' && order[2][2] == 'X' ||
		order[0][2] == 'X' && order[1][1] == 'X' && order[2][0] == 'X')
		return true;
	else
		return false;
}

void playero()
{
	int num;
	bool valid = false;
	cout << "player " << nameO << " enter a number \n";
	cin >> num;
	while (!valid) {
		resetboard();
		if (num >= 1 && num <= 9 && order[(num - 1) / 3][(num - 1) % 3] != 'O' && order[(num - 1) / 3][(num - 1) % 3] != 'X')
		{
			switch (num)
			{
			case 1:order[0][0] = 'O'; break;
			case 2:order[0][1] = 'O'; break;
			case 3:order[0][2] = 'O'; break;
			case 4:order[1][0] = 'O'; break;
			case 5:order[1][1] = 'O'; break;
			case 6:order[1][2] = 'O'; break;
			case 7:order[2][0] = 'O'; break;
			case 8:order[2][1] = 'O'; break;
			case 9:order[2][2] = 'O'; break;

			}
			valid = true;
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			valid = false;
			cout << "invalid value please enter a number from 1 to 9 hasn't been used yet \n";
			cin >> num;
		}
		else
		{
			valid = false;
			cout << "invalid value please enter a number from 1 to 9 hasn't been used yet \n";
			cin >> num;
		}
	}
}
void playerx()
{
	int num;
	bool valid = false;
	cout << "player " << nameX << " enter a number \n ";
	cin >> num;
	while (!valid)
	{
		if (num >= 1 && num <= 9 && order[(num - 1) / 3][(num - 1) % 3] != 'O' && order[(num - 1) / 3][(num - 1) % 3] != 'X')
		{
			switch (num)
			{
			case 1:order[0][0] = 'X'; break;
			case 2:order[0][1] = 'X'; break;
			case 3:order[0][2] = 'X'; break;
			case 4:order[1][0] = 'X'; break;
			case 5:order[1][1] = 'X'; break;
			case 6:order[1][2] = 'X'; break;
			case 7:order[2][0] = 'X'; break;
			case 8:order[2][1] = 'X'; break;
			case 9:order[2][2] = 'X'; break;
			}
			valid = true;
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			valid = false;
			cout << "invalid value please enter a number from 1 to 9 hasn't been used yet \n";
			cin >> num;
		}
		else
		{
			valid = false;
			cout << "invalid value please enter a number from 1 to 9 hasn't been used yet \n";
			cin >> num;
		}
	}
}

void tic()
{

	cout << "   " << order[0][0] << setw(3) << "|" << "   " << order[0][1] << setw(3) << "|" << "   " << order[0][2] << setw(3) << "\n";
	cout << "--------------------\n";
	cout << "   " << order[1][0] << setw(3) << "|" << "   " << order[1][1] << setw(3) << "|" << "   " << order[1][2] << setw(3) << "\n";
	cout << "--------------------\n";
	cout << "   " << order[2][0] << setw(3) << "|" << "   " << order[2][1] << setw(3) << "|" << "   " << order[2][2] << setw(3) << "\n";
}


bool boardFull()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (order[i][j] != 'O' && order[i][j] != 'X')
				return false;
		}
	}
	return true;
}

int main()
{
	system("color B5");
	int n;
	bool yet = true,contineu=true;
	int num = 0;
	while (contineu) {
		players(nameO, nameX);
		system("cls");
		while (!winerO() && !winerX())
		{
			tic();
			playero();

			if (winerO())
			{
				system("cls");

				tic();
				cout << "||---------------------------||\n||---------------------------||\n";
				cout << "||     player " << nameO << " wins     ||" << "\n";
				cout << "||wineer winner chiken dinner||\n";
				cout << "||---------------------------||\n||---------------------------||";
				cout << "\n Do you want to play again? \n";
				cout << "if yes press 1 otherwise press 0";
				cin >> n;
				if (n == 1)
					contineu = true;
				else
					contineu = false;
				system("cls");

				break;
			}
			if (boardFull())
			{
				tic();
				cout << "It's a draw!\n";
				cout << "\n Do you want to play again? \n";
				cout << "if yes press 1 otherwise press 0";
				cin >> n;
				if (n == 1)
					contineu = true;
				else
					contineu = false;
				system("cls");
				break;
			}

			system("cls");
			tic();
			playerx();
			if (winerX())
			{
				system("cls");

				tic();
				cout << "||---------------------------||\n||---------------------------||\n";
				cout << "||     player " << nameX << " wins     ||" << "\n";
				cout << "||wineer winner chiken dinner||\n";
				cout << "||---------------------------||\n||---------------------------||";
				cout << "\n Do you want to play again? \n";
				cout << "if yes press 1 otherwise press 0";
				cin >> n;
				if (n == 1)
					contineu = true;
				else
					contineu = false;
				system("cls");
				break;
			}

			if (boardFull())
			{
				tic();
				cout << "It's a draw!\n";
				cout << "\n Do you want to play again? \n";
				cout << "if yes press 1 otherwise press 0";
				cin >> n;
				if (n == 1)
					contineu = true;
				else
					contineu = false;
				system("cls");
				break;
			}

			system("cls");

		}
		
	}
	cout << "thank you! <3";
}