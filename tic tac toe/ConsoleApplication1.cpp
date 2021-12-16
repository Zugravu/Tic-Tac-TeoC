#include <iostream>
#include <windows.h>
#include <conio.h>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

using namespace std;

void DrawBoard(char m[4][4])
{
	cout << "\t\t" << m[0][0] << "|" << " " << m[0][1] << " " << "|" << " " << m[0][2] << "\n";
	cout << "\t\t---------\n";
	cout << "\t\t" << m[1][0] << "|" << " " << m[1][1] << " " << "|" << " " << m[1][2] << "\n";
	cout << "\t\t---------\n";
	cout << "\t\t" << m[2][0] << "|" << " " << m[2][1] << " " << "|" << " " << m[2][2] << "\n";
	cout << "\t\t---------\n";
}
void MatInt(char m[4][4])
{
	char x = '1';
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m[i][j] = x, x++;
}
bool Winner(char m[4][4])
{
	int i, j;
	for (int i = 0; i < 3; i++)
		if (m[i][0] == m[i][1] && m[i][0] == m[i][2])
		{
			if (m[i][0] == 'X')
				{cout << "X wins \n"; return 1;}
			else if (m[i][0] == 'O')
				{cout << "O wins \n"; return 1;}
		}
		else if (m[0][i] == m[1][i] && m[0][i] == m[2][i])
		{ 
			if (m[i][0] == 'X')
				{cout << "X wins \n"; return 1;}
			else if (m[i][0] == 'O')
				{cout << "O wins \n"; return 1;}
		}

	if (m[0][0] == m[1][1] && m[0][0] == m[2][2])
	{
		if (m[0][0] == 'X')
			{cout << "X wins \n"; return 1;}
		else if (m[0][0] == 'O')
			{cout << "O wins \n"; return 1;}
	}

	else if (m[0][2] == m[1][1] && m[0][0] == m[2][0])
	{
		if (m[0][2] == 'X')
			{cout << "X wins \n"; return 1;}
		else if (m[0][2] == 'O')
			{cout << "O wins \n"; return 1;}
	}
	return 0;
}
void X_Place(char m[4][4], char x)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (x == m[i][j])
				m[i][j] = 'X';
	
}
void O_Place(char m[4][4],char x)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (x == m[i][j])
				m[i][j] = 'O';
}

void cls()
{
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		// TODO: Handle failure!
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	// Flood-fill the console with spaces to clear it
	//FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(hOut, topLeft);
}

void Game()
{
	char m[4][4];
	MatInt(m);
	bool game_over = false;
	char turn = 'X';
	while (game_over == false)
	{
		DrawBoard(m);
		if (_kbhit())
		{
			switch (_getch())
			{	
				case '1': if (turn == 'X') X_Place(m, '1'), turn = 'O'; else O_Place(m, '1'), turn = 'X'; break;
				case '2': if (turn == 'X') X_Place(m, '2'), turn = 'O'; else O_Place(m, '2'), turn = 'X'; break;
				case '3': if (turn == 'X') X_Place(m, '3'), turn = 'O'; else O_Place(m, '3'), turn = 'X'; break;
				case '4': if (turn == 'X') X_Place(m, '4'), turn = 'O'; else O_Place(m, '4'), turn = 'X'; break;
				case '5': if (turn == 'X') X_Place(m, '5'), turn = 'O'; else O_Place(m, '5'), turn = 'X'; break;
				case '6': if (turn == 'X') X_Place(m, '6'), turn = 'O'; else O_Place(m, '6'), turn = 'X'; break;
				case '7': if (turn == 'X') X_Place(m, '7'), turn = 'O'; else O_Place(m, '7'), turn = 'X'; break;
				case '8': if (turn == 'X') X_Place(m, '8'), turn = 'O'; else O_Place(m, '8'), turn = 'X'; break;
				case '9': if (turn == 'X') X_Place(m, '9'), turn = 'O'; else O_Place(m, '9'), turn = 'X'; break;
			}
		}
		if (Winner(m) == 1)
			game_over = true;
		cls();
	}

}
int main()
{	
	Game();
	return 0;
}
