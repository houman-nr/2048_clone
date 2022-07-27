#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>

using namespace std;
bool closegame = false;
void menupage();
void playGame();
int main() {
	for (;;)
	{
		menupage();
		if (closegame == true)
			break;
		playGame();
		cout << "\nPress any key to get back to menu\n";
		int x = _getch();
	}
}
bool con;
bool invalidcommand;
bool gameOver;
bool win;
bool loose;
bool possibility_of_entering;
int matris[4][4];
int score;
string entering_command;
string player_name;



void setGlobals();
void gameLoop();
void render();
void playGame() {
	setGlobals();
	render();
	while (!gameOver) {
		gameLoop();
	}
	// TODO: end game messages; based on game state
	if (win)
		cout << ">>>>Congratulations.You have beaten the game.<<<<";
	else if (loose)
		cout << " >>>>Unfortunately you have lost the game.Good luck next time.<<<<";
	else if (!win && !loose)
		cout << ">>>>Hope to see you next time.<<<<";
}

void random_generation();
void setGlobals() {
	bool con = false;
	invalidcommand = false;
	closegame = false;
	gameOver = false;
	win = false;
	loose = false;
	possibility_of_entering = true;
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
		{
			matris[i][j] = 0;
		}
	random_generation();
}


void input();
void update();
void render();
void gameLoop() {
	input();
	update();
	render();
	
}

void input() {
	entering_command = _getch();
}

void a() {
	int temp = 4;
	for (int k = 0; k <= 3; k++)
	{
		for (int i = 0; i <= 3;i++)
		{
			for (int j = 1; j <= 3;j++)
				if (matris[i][j] != 0)
				{
					if (matris[i][j - 1] == matris[i][j] && j != temp)
					{
						matris[i][j - 1] += matris[i][j];
						matris[i][j] = 0;
						temp = j - 1;
					}
					else if (matris[i][j - 1] == 0)
					{
						matris[i][j - 1] += matris[i][j];
						matris[i][j] = 0;
					}
				}
		}
	}
}
void d() {
	int temp = 4;
	for (int k = 0; k <= 3; k++)
	{
		for (int i = 0; i <= 3; i++)
		{
			int j = 2;
			while (j >= 0)
			{
				if (matris[i][j] != 0)
				{
					if (matris[i][j + 1] == matris[i][j] && j != temp)
					{
						matris[i][j + 1] += matris[i][j];
						matris[i][j] = 0;
						temp = j + 1;
					}
					else if (matris[i][j + 1] == 0)
					{
						matris[i][j + 1] += matris[i][j];
						matris[i][j] = 0;
					}
				}
				j--;
			}
		}	
	}
}
void w() {
	int temp = 4;
	for (int k = 0; k <= 3; k++)
	{
		for (int j = 0; j <= 3; j++)
		{
			int i = 3;
			while (i >= 1)
			{
				if (matris[i][j] != 0)
				{
					if (matris[i - 1][j] == matris[i][j] && i != temp)
					{
						matris[i - 1][j] += matris[i][j];
						matris[i][j] = 0;
						temp = i - 1;
					}
					else if (matris[i - 1][j] == 0)
					{
						matris[i - 1][j] += matris[i][j];
						matris[i][j] = 0;
					}
				}
				i--;
			}
		}
	}
}
void s() {
	int temp = 4;
	for (int k = 0; k <= 3; k++)
	{
		for (int j = 0; j <= 3;j++)
		{
			for (int i = 0; i <= 2;i++)
				if (matris[i][j] != 0)
				{
					if (matris[i + 1][j] == matris[i][j] && i != temp)
					{
						matris[i + 1][j] += matris[i][j];
						matris[i][j] = 0;
						temp = i + 1;
					}
					else if (matris[i + 1][j] == 0)
					{
						matris[i + 1][j] += matris[i][j];
						matris[i][j] = 0;
					}
				}
		}
	}
}
void possibility() {
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (matris[i][j] == 0)
			{
				possibility_of_entering = true;
				break;
			}
		}
	}
}
void loosing_possibility() {
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
		{
			if (matris[i][j] != matris[i][j + 1] && matris[i + 1][j] != matris[i][j])
				if (possibility_of_entering == false)
				{
					loose = true;
					gameOver = true;
				}
		}
}
void winning_possibility() {
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 0; j++)
		if (matris[i][j] == 2048)
		{
			win = true;
			gameOver = true;
		}
	}
}
void random_generation() {
	//srand(time(0));
	for (;;)
	{
		
		int i = rand() % 4;
		int j = rand() % 4;
		if (matris[i][j] == 0)
		{
			matris[i][j] = 2;
			break;
		}
	}
}
int score_board();
void movement() {
	if (entering_command == "a")
	{
		a();
		possibility();
		if (possibility_of_entering == true)
		{
			random_generation();
		}
	}
	else if (entering_command == "d")
	{
		d();
		possibility();
		if (possibility_of_entering == true)
			random_generation();
	}
	else if (entering_command == "s")
	{
		s();
		possibility();
		if (possibility_of_entering == true)
			random_generation();
	}
	else if (entering_command == "w")
	{
		w();
		possibility();
		if (possibility_of_entering == true)
			random_generation();
	}
	else if (entering_command == "e")
	{
		gameOver = true;
		score_board();
		ofstream record("R.txt", ios::app);
		record << player_name << "==>";
		record << score << "\n";
		record.close();
	}
	else
	{
		invalidcommand = true;
	}
}


void update() {
	invalidcommand = false;
	movement();
	loosing_possibility();
	winning_possibility();
}

int score_board() {
	score = 0;
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
		{
			score += matris[i][j];
		}	
	return score;
}

void andaze_khone_ha(int matris) {
	if (matris > 1000)
		cout << "[" << matris << "]";
	else if (matris < 1000 && matris > 100)
		cout << "[ " << matris << "]";
	else if (matris < 100 && matris > 10)
		cout << "[ " << matris << " ]";
	else if (matris < 10 && matris > 0)
		cout << "[  " << matris << " ]";
}
void jadval_bazi() {
	for (int i = 0; i <= 3;i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (matris[i][j] != 0)
				andaze_khone_ha(matris[i][j]);
			else
				cout << "[    ]";
		}
		cout << "\n";
	}
}
void menupage();
void menuCommander(int menucommand) {
	if (menucommand == 1)
	{
		system("CLS");
		cout << "please enter your name\n";
		cin >> player_name;
	}
	else if (menucommand == 2)
	{
		score_board();
		system("ClS");
		ifstream record("R.txt");
		record.is_open();
		cout << record.rdbuf();
		int x = _getch();
		menupage();
	}
	else if (menucommand == 3)
	{
		system("CLS");
		cout << "my name is mohammad norsteh\n my student number is 990122680070.\n";
		int x = _getch();
		menupage();
	}
	else if (menucommand == 4)
	{
		gameOver = true;
		closegame = true;
	}
	else {
		cout << "*INVALID COMMAND*";
		int x = _getch();
		menupage();
	}
}
void menupage() {
	system("CLS");
	cout << "1. start the game\n";
	cout << "2. records\n";
	cout << "3. credits\n";
	cout << "4. exit\n";
	int menucommand = 0;
	cin >> menucommand;
	menuCommander(menucommand);
}

void render() {
	system("CLS");
	// TODO
	cout << "[2048 clone, "<< player_name <<"] \n";
	if (invalidcommand == true)
		cout << "*INVALID COMMAND*\n";
	else
		cout << "\n";
	jadval_bazi();
	cout << endl << "score:";
	score_board();
	cout << score;
	cout << "\n[Movement : W,A,S,D]\n[Press  E  to  Exit]\n";
}
