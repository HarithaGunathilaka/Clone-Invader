#include <iostream>
#include "windows.h"
#include "time.h"
#include <cwchar>

using namespace std;
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
void fontsize(int, int);


char Map[11][41] = {

	"########################################",
	"#                                      #",
	"# @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @  #",
	"#  @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ #",
	"#   @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @  #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                  W                   #",
	"########################################",

};


bool endgame = false;
int gamespeed = 100;
int randomNumberOne, randomNumberTwo, randomNumberThree, randomNumberFour, randomNumberFive;
int randomNumberSix, randomNumberSeven, randomNumberEight, randomNumberNine,randomNumberTen;
int MaxHealth = 200;
int YourHealth = MaxHealth;
int GamePoints=0;

//initializing font size
void fontsize(int a, int b) {
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

VOID WINAPI SetConsoleColors(WORD attribs) {
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX cbi;
	cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hOutput, &cbi);
	cbi.wAttributes = attribs;
	SetConsoleScreenBufferInfoEx(hOutput, &cbi);
}

int main()
{
	fontsize(125, 55); //calling fontsize
	//system("color 0c");
	SetConsoleColors(BACKGROUND_BLUE | FOREGROUND_RED| FOREGROUND_INTENSITY);
	while (endgame == false&&GamePoints<=350) {
		
			srand(time(0));
			system("cls");
			for (int y = 0; y < 11; y++) {
				cout << Map[y] << endl;

			}
			
			cout << "Total Points " << GamePoints << " / 130" << endl;
			cout << "Health" << YourHealth << " / " << MaxHealth;
			for (int y = 0; y < 11; y++) {
				for (int x = 0; x < 41; x++) {

					switch (Map[y][x]) {

					case 'W':

						if (GetAsyncKeyState(VK_LEFT) != 0) {

							int newX = x - 1;

							switch (Map[y][newX]) {

							case ' ':
								Map[y][x] = ' ';
								x--;
								Map[y][newX] = 'W';

								break;

							}

						}

						if (GetAsyncKeyState(VK_RIGHT) != 0) {

							int newX = x + 1;

							switch (Map[y][newX]) {

							case ' ':
								Map[y][x] = ' ';
								x++;
								Map[y][newX] = 'W';
								break;

							}

						}

						if (GetAsyncKeyState(VK_SPACE) != 0) {

							y--;
							Map[y][x] = '`';

						}

						break;

					case '`':


						Map[y][x] = ' ';
						y--;

						if (Map[y][x] != '#' && Map[y][x] != '@') {

							Map[y][x] = '`';

						}
						else if (Map[y][x] == '@') {

							Map[y][x] = ' ';

							GamePoints = GamePoints + 10;

						}

						break;

					case '@':

						randomNumberOne = rand() % 15 + 1;
						randomNumberTwo = rand() % 25 + 1;
						randomNumberThree = rand() % 35+ 1;
						randomNumberFour = rand() % 45 + 1;
						randomNumberFive = rand() % 50 + 1;
						randomNumberSix = rand() % 55 + 1;
						randomNumberSeven = rand() % 65 + 1;
						randomNumberEight = rand() % 75 + 1;
						randomNumberNine = rand() % 85 + 1;
						randomNumberTen = rand() % 90 + 1;
						

						if (randomNumberOne == 1|| randomNumberTwo==1|| randomNumberThree==1|| randomNumberFour==1|| randomNumberFive==1||randomNumberSix==1||randomNumberSeven==1||randomNumberEight==1||randomNumberNine==1||randomNumberTen==1) {

							y++;
							Map[y][x] = '^';

						}

						break;

					case '^':

						Map[y][x] = ' ';
						y++;

						if (Map[y][x] != '#' && Map[y][x] != 'W') {
							Map[y][x] = '^';
						}
						else if (Map[y][x] == 'W') {

							YourHealth -= 20;
						}
						break;


					}
				}
			}
		
		if (YourHealth <= 0) {
			endgame = true;

		}
		Sleep(gamespeed);

	}
	system("cls");
	cout << "You Lost" << endl;

	system("PAUSE");




	return 0;
}
