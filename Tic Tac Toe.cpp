#include <iostream>
#include <windows.h>
using namespace std;

bool checkDiagonals(char character);
bool checkRows(char character);
bool checkColumns(char character);
bool isWinner(char character);
void maze();
void gotoxy(int x, int y);
bool setCursor(bool visible);

const int gridSize = 3;
char grid[gridSize][gridSize] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

main()
{
    bool outerFlag;
    setCursor(0);
    while (outerFlag != 0)
    {
        char char1, char2;
        bool flag = false;
        int count = 1;
        system("cls");
        cout << "Character for Player 1(X or O): ";
        cin >> char1;
        if (char1 == 'X')
        {
            char2 = 'O';
        }

        else if (char1 == 'O')
        {
            char2 = 'X';
        }
        gotoxy(50, 10);

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);

        maze();
        gotoxy(53, 5);
        SetConsoleTextAttribute(hConsole, 1);
        gotoxy(53, 5);
        cout << grid[0][0];
        gotoxy(59, 5);
        SetConsoleTextAttribute(hConsole, 2);
        cout << grid[0][1];
        gotoxy(65, 5);
        SetConsoleTextAttribute(hConsole, 3);
        cout << grid[0][2];
        gotoxy(53, 8);
        SetConsoleTextAttribute(hConsole, 4);
        cout << grid[1][0];
        gotoxy(59, 8);
        SetConsoleTextAttribute(hConsole, 5);
        cout << grid[1][1];
        gotoxy(65, 8);
        SetConsoleTextAttribute(hConsole, 6);
        cout << grid[1][2];
        gotoxy(53, 11);
        SetConsoleTextAttribute(hConsole, 8);
        cout << grid[2][0];
        gotoxy(59, 11);
        SetConsoleTextAttribute(hConsole, 9);
        cout << grid[2][1];
        gotoxy(65, 11);
        SetConsoleTextAttribute(hConsole, 10);
        cout << grid[2][2];
        int num;
        while (num != 0)
        {
            gotoxy(3, 11);
            SetConsoleTextAttribute(hConsole, 13);
            cout << "Enter Number: ";
            cin >> num;
            char character;
            if (count % 2 == 1)
            {
                character = char1;
            }
            if (count % 2 == 0)
            {
                character = char2;
            }
            if (num == 1)
            {
                if ((grid[0][0] == 'X'))
                {
                }
                else if (grid[0][0] == 'O')
                {
                }
                else
                {
                    grid[0][0] = character;
                    count++;
                }
            }
            else if (num == 2)
            {
                if ((grid[0][1] == 'X'))
                {
                }
                else if (grid[0][1] == 'O')
                {
                }
                else
                {
                    grid[0][1] = character;
                    count++;
                }
            }
            else if (num == 3)
            {
                if ((grid[0][2] == 'X'))
                {
                }
                else if (grid[0][2] == 'O')
                {
                }
                else
                {
                    grid[0][2] = character;
                    count++;
                }
            }
            else if (num == 4)
            {
                if ((grid[1][0] == 'X'))
                {
                }
                else if (grid[1][0] == 'O')
                {
                }
                else
                {
                    grid[1][0] = character;
                    count++;
                }
            }
            else if (num == 5)
            {
                if ((grid[1][1] == 'X'))
                {
                }
                else if (grid[1][1] == 'O')
                {
                }
                else
                {
                    grid[1][1] = character;
                    count++;
                }
            }
            else if (num == 6)
            {
                if ((grid[1][2] == 'X'))
                {
                }
                else if (grid[1][2] == 'O')
                {
                }
                else
                {
                    grid[1][2] = character;
                    count++;
                }
            }
            else if (num == 7)
            {
                if ((grid[2][0] == 'X'))
                {
                }
                else if (grid[2][0] == 'O')
                {
                }
                else
                {
                    grid[2][0] = character;
                    count++;
                }
            }
            else if (num == 8)
            {
                if ((grid[2][1] == 'X'))
                {
                }
                else if (grid[2][1] == 'O')
                {
                }
                else
                {
                    grid[2][1] = character;
                    count++;
                }
            }
            else if (num == 9)
            {
                if ((grid[2][2] == 'X'))
                {
                }
                else if (grid[2][2] == 'O')
                {
                }
                else
                {
                    grid[2][2] = character;
                    count++;
                }
            }
            system("cls");
            cout << "Enter 0 to exit" << endl;
            SetConsoleTextAttribute(hConsole, 12);
            maze();
            SetConsoleTextAttribute(hConsole, 1);
            gotoxy(53, 5);
            cout << grid[0][0];
            gotoxy(59, 5);
            SetConsoleTextAttribute(hConsole, 2);
            cout << grid[0][1];
            gotoxy(65, 5);
            SetConsoleTextAttribute(hConsole, 3);
            cout << grid[0][2];
            gotoxy(53, 8);
            SetConsoleTextAttribute(hConsole, 4);
            cout << grid[1][0];
            gotoxy(59, 8);
            SetConsoleTextAttribute(hConsole, 5);
            cout << grid[1][1];
            gotoxy(65, 8);
            SetConsoleTextAttribute(hConsole, 6);
            cout << grid[1][2];
            gotoxy(53, 11);
            SetConsoleTextAttribute(hConsole, 8);
            cout << grid[2][0];
            gotoxy(59, 11);
            SetConsoleTextAttribute(hConsole, 9);
            cout << grid[2][1];
            gotoxy(65, 11);
            SetConsoleTextAttribute(hConsole, 10);
            cout << grid[2][2];

            flag = isWinner(character);
            if (flag == true)
            {
                gotoxy(3, 10);
                if (character == char1)
                {
                    cout << "Player 1 has won the game." << endl;
                }
                if (character == char2)
                {
                    cout << "Player 2 has won the game." << endl;
                }
                string any;
                getline(cin, any);
                getline(cin, any);
                break;
            }

            if (count == 10 && flag == false)
            {
                gotoxy(3, 10);
                cout << "It is a tie" << endl;
                string any;
                getline(cin, any);
                getline(cin, any);
                break;
            }
        }
    }
    cout << "Do you want to continue...?";
    string a;
    getline(cin, a);
    if ((a == "No") || (a == "no") || (a == "nO") || (a == "NO"))
    {
        outerFlag = 0;
    }
}

bool checkDiagonals(char character)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][i] == character)
        {
            count = count + 1;
        }
    }

    if (count == gridSize)
    {
        return true;
    }

    if ((grid[2][0] == character) && (grid[1][1] == character) && (grid[0][2] == character))
    {
        return true;
    }

    return false;
}

bool checkRows(char character)
{
    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        count = 0;
        for (int j = 0; j < gridSize; j++)
        {
            if (grid[i][j] == character)
            {
                count = count + 1;
            }
            if (count == gridSize)
            {
                return true;
            }
        }
    }
    return false;
}

bool checkColumns(char character)
{
    int count = 0;

    for (int i = 0; i < gridSize; i++)
    {
        count = 0;
        for (int j = 0; j < gridSize; j++)
        {
            if (grid[j][i] == character)
            {
                count = count + 1;
            }
            if (count == gridSize)
            {
                return true;
            }
        }
    }
    return false;
}

bool isWinner(char character)
{
    if ((checkRows(character) == true) || (checkColumns(character) == true) || (checkDiagonals(character) == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void maze()
{
    gotoxy(50, 3);
    cout << " _________________" << endl;
    gotoxy(50, 4);
    cout << "|     |     |     |" << endl;
    gotoxy(50, 5);
    cout << "|     |     |     |" << endl;
    gotoxy(50, 6);
    cout << "|_____|_____|_____|" << endl;
    gotoxy(50, 7);
    cout << "|     |     |     |" << endl;
    gotoxy(50, 8);
    cout << "|     |     |     |" << endl;
    gotoxy(50, 9);
    cout << "|_____|_____|_____|" << endl;
    gotoxy(50, 10);
    cout << "|     |     |     |" << endl;
    gotoxy(50, 11);
    cout << "|     |     |     |" << endl;
    gotoxy(50, 12);
    cout << "|_____|_____|_____|" << endl;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

bool setCursor(bool visible)
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}