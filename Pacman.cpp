#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
using namespace std;

char getCharAtxy(short int x, short int y);
void printMaze();
void gotoxy(int x, int y);
void erasePacman(int pacmanX, int pacmanY);
void printPacman(int pacmanX, int pacmanY);
void printGhost1();
void printGhost2();
void printGhost3();
void printScore(int score);
void gameOver();
string mainMenu();
void gameInterface();
void moveGhost1();
void moveGhost2();
void moveGhostRandom();
void moveGhostSmart();
void eraseGhost(int x, int y);
float distance(int gx, int gy);
bool pacmanCollisionEnemyLeft();
bool pacmanCollisionEnemyRight();
bool pacmanCollisionEnemyUp();
bool pacmanCollisionEnemyDown();
void lives();
bool setCursor(bool visible);

int score = 0;
int pacmanX = 4;
int pacmanY = 4;
int g1x = 2;
int g1y = 15;
int g2x = 95;
int g2y = 2;
int g3x = 50;
int g3y = 20;
int health = 3;

string directiong1 = "right";
string directiong2 = "down";
char previousChar = ' ';

char pacman[4][6] = {{' ', '.', '-', '-', '.', ' '}, {'/', ' ', '_', '.', '-', '.'}, {'\\', ' ', ' ', '`', '-', '.'}, {' ', '`', '-', '-', '`', ' '}};
char ghost[4][6] = {{' ', ',', '-', '-', ',', ' '}, {'|', ' ', 'o', 'o', ' ', '|'}, {'|', ' ', '~', '~', ' ', '|'}, {'|', '/', '\\', '/', '\\', '|'}};

main()
{
    system("cls");
    setCursor(0);

    bool file = true;
    while (file == true)
    {
        string option;
        option = mainMenu();
        if (option == "1")
        {
            gameInterface();
        }

        else if (option == "2")
        {
            file = false;
        }
    }
}

void printMaze()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 55);
    cout << "##############################################################################################################################" << endl;
    cout << "##                                                                                                                          ## " << endl;
    cout << "##                                                                                                                          ## " << endl;
    cout << "##                   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .                ## " << endl;
    cout << "##                                                                                                                          ## " << endl;
    cout << "##    ..      ##########                #######################################             ############             ..     ## " << endl;
    cout << "##    ..      ##   .                    ##                                   ##                   .   ##             ..     ## " << endl;
    cout << "##    ..      ##   .                    ##     . . . . . . . . . . . . .     ##                   .   ##             ..     ## " << endl;
    cout << "##    ..      ##   .                    ##                                   ##                   .   ##             ..     ## " << endl;
    cout << "##    ..      ##   .                                                                              .   ##             ..     ## " << endl;
    cout << "##    ..                                                  ##                                                         ..     ## " << endl;
    cout << "##                         ##                             ##                              ##                                ## " << endl;
    cout << "##               . . . . . ##                             ##                              ## . . . . .                      ## " << endl;
    cout << "##                         ##                             ##                              ##                                ## " << endl;
    cout << "##               ############                      ################                       ############                      ## " << endl;
    cout << "##                         ##                                                             ##                                ## " << endl;
    cout << "##                         ##                                                             ##                                ## " << endl;
    cout << "##                         ##          ##                                   ##            ##                                ## " << endl;
    cout << "##                                     ##     . . . . . . . . . . . . .     ##                                              ## " << endl;
    cout << "##                                     ##                                   ##                                              ## " << endl;
    cout << "##                                     #######################################                                       ..     ## " << endl;
    cout << "##     ..      ##   .                                                                              .   ##            ..     ## " << endl;
    cout << "##     ..      ##   .                                                                              .   ##            ..     ## " << endl;
    cout << "##     ..      ##   .                                                                              .   ##            ..     ## " << endl;
    cout << "##     ..      ##   .                                                                              .   ##            ..     ## " << endl;
    cout << "##     ..      ##########                                                                    ############            ..     ## " << endl;
    cout << "##     ..                                                                                                                   ## " << endl;
    cout << "##                   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .                ## " << endl;
    cout << "##                                                                                                                          ## " << endl;
    cout << "##                                                                                                                          ## " << endl;
    cout << "##############################################################################################################################" << endl;
}

void gotoxy(int pacmanX, int pacmanY)
{
    COORD coordinates;
    coordinates.X = pacmanX;
    coordinates.Y = pacmanY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void erasePacman(int pacmanX, int pacmanY)
{
    gotoxy(pacmanX, pacmanY);
    cout << "      ";
    gotoxy(pacmanX, pacmanY + 1);
    cout << "      ";
    gotoxy(pacmanX, pacmanY + 2);
    cout << "      ";
    gotoxy(pacmanX, pacmanY + 3);
    cout << "      ";
    gotoxy(pacmanX, pacmanY + 4);
}

void printPacman(int pacmanX, int pacmanY)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 48);
    for (int i = 0; i < 4; i++)
    {
        gotoxy(pacmanX, pacmanY + i);
        for (int j = 0; j < 6; j++)
        {
            cout << pacman[i][j];
        }
    }
}

void printGhost1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 52);
    for (int i = 0; i < 4; i++)
    {
        gotoxy(g1x, g1y + i);
        for (int j = 0; j < 6; j++)
        {
            cout << ghost[i][j];
        }
    }
}

bool setCursor(bool visible)
{
 CONSOLE_CURSOR_INFO info;
 info.dwSize = 100;
 info.bVisible = visible;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void printGhost2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 53);
    for (int i = 0; i < 4; i++)
    {
        gotoxy(g2x, g2y + i);
        for (int j = 0; j < 6; j++)
        {
            cout << ghost[i][j];
        }
    }
}

void printGhost3()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 61);
    for (int i = 0; i < 4; i++)
    {
        gotoxy(g3x, g3y + i);
        for (int j = 0; j < 6; j++)
        {
            cout << ghost[i][j];
        }
    }
}

void printScore(int score)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 62);
    gotoxy(81, 31);
    cout << "Score: " << score;
}

string mainMenu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 63);
    string option;
    system("cls");
    cout << "PACMAN" << endl;
    cout << "1. Start" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your option...";
    getline(cin, option);
    return option;
}

void gameInterface()
{
    bool gameRunning = true;
    system("cls");
    printMaze();
    //printGhost1();
    //printGhost2();
    printPacman(pacmanX, pacmanY);
    int timer = 0;
    health = 3;
    while (gameRunning)
    {
        lives();
        //moveGhost1();
        //moveGhost2();
        moveGhostRandom();
        if (timer == 3)
        {
            moveGhostSmart();
            timer = 0;
        }
        timer++;

        if (GetAsyncKeyState(VK_LEFT))
        {
            char nextLocation = getCharAtxy(pacmanX - 1, pacmanY);
            char nextLocation1 = getCharAtxy(pacmanX - 1, pacmanY + 1);
            char nextLocation2 = getCharAtxy(pacmanX - 1, pacmanY + 2);
            char nextLocation3 = getCharAtxy(pacmanX - 1, pacmanY + 3);
            if ((nextLocation == ' ') && (nextLocation1 == ' ') && (nextLocation2 == ' ') && (nextLocation3 == ' '))
            {
                erasePacman(pacmanX, pacmanY);
                pacmanX = pacmanX - 1;
                printPacman(pacmanX, pacmanY);
            }
            else if ((nextLocation == '.') || (nextLocation1 == '.') || (nextLocation2 == '.') || (nextLocation3 == '.'))
            {
                erasePacman(pacmanX, pacmanY);
                pacmanX = pacmanX - 1;
                printPacman(pacmanX, pacmanY);
                score = score + 1;
                printScore(score);
            }

        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            char nextLocation = getCharAtxy(pacmanX + 6, pacmanY);
            char nextLocation1 = getCharAtxy(pacmanX + 6, pacmanY + 1);
            char nextLocation2 = getCharAtxy(pacmanX + 6, pacmanY + 2);
            char nextLocation3 = getCharAtxy(pacmanX + 6, pacmanY + 3);
            if ((nextLocation == ' ') && (nextLocation1 == ' ') && (nextLocation2 == ' ') && (nextLocation3 == ' '))
            {
                erasePacman(pacmanX, pacmanY);
                pacmanX = pacmanX + 1;
                printPacman(pacmanX, pacmanY);
            }
            else if ((nextLocation == '.') || (nextLocation1 == '.') || (nextLocation2 == '.') || (nextLocation3 == '.'))
            {
                erasePacman(pacmanX, pacmanY);
                pacmanX = pacmanX + 1;
                printPacman(pacmanX, pacmanY);
                score = score + 1;
                printScore(score);
            }

        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            char nextLocation = getCharAtxy(pacmanX + 1, pacmanY - 1);
            char nextLocation1 = getCharAtxy(pacmanX + 2, pacmanY - 1);
            char nextLocation2 = getCharAtxy(pacmanX + 3, pacmanY - 1);
            char nextLocation3 = getCharAtxy(pacmanX + 4, pacmanY - 1);
            char nextLocation4 = getCharAtxy(pacmanX, pacmanY - 1);
            char nextLocation5 = getCharAtxy(pacmanX + 5, pacmanY - 1);
            if ((nextLocation == ' ') && (nextLocation1 == ' ') && (nextLocation2 == ' ') && (nextLocation3 == ' ') && (nextLocation4 == ' ') && (nextLocation5 == ' '))
            {
                erasePacman(pacmanX, pacmanY);
                pacmanY = pacmanY - 1;
                printPacman(pacmanX, pacmanY);
            }

            else if ((nextLocation == '.') || (nextLocation1 == '.') || (nextLocation2 == '.') || (nextLocation3 == '.') || (nextLocation4 == '.') || (nextLocation5 == '.'))
            {
                erasePacman(pacmanX, pacmanY);
                pacmanY = pacmanY - 1;
                printPacman(pacmanX, pacmanY);
                score = score + 1;
                printScore(score);
            }

        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            char nextLocation = getCharAtxy(pacmanX + 1, pacmanY + 4);
            char nextLocation1 = getCharAtxy(pacmanX + 2, pacmanY + 4);
            char nextLocation2 = getCharAtxy(pacmanX + 3, pacmanY + 4);
            char nextLocation3 = getCharAtxy(pacmanX + 4, pacmanY + 4);
            char nextLocation4 = getCharAtxy(pacmanX + 5, pacmanY + 4);
            char nextLocation5 = getCharAtxy(pacmanX, pacmanY + 4);
            if ((nextLocation == ' ') && (nextLocation1 == ' ') && (nextLocation2 == ' ') && (nextLocation3 == ' ') && (nextLocation4 == ' ') && (nextLocation5 == ' '))
            {
                erasePacman(pacmanX, pacmanY);
                pacmanY = pacmanY + 1;
                printPacman(pacmanX, pacmanY);
            }

            else if ((nextLocation == '.') || (nextLocation1 == '.') || (nextLocation2 == '.') || (nextLocation3 == '.') || (nextLocation4 == '.') || (nextLocation5 == '.'))
            {
                erasePacman(pacmanX, pacmanY);
                pacmanY = pacmanY + 1;
                printPacman(pacmanX, pacmanY);
                score = score + 1;
                printScore(score);
            }

        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameRunning = false;
        }

        if(health < 0)
        {
            gameOver();
            gameRunning = false;
        }
        bool collisionLeft = pacmanCollisionEnemyLeft();
        bool collisionRight = pacmanCollisionEnemyRight();
        bool collisionUp = pacmanCollisionEnemyUp();
        bool collisionDown = pacmanCollisionEnemyDown();
        if((collisionLeft == true) || (collisionRight == true) || (collisionUp == true) || (collisionDown == true))
        {
            health--;
            erasePacman(pacmanX,pacmanY);
            pacmanX = 3;
            pacmanY = 2;
        }

        if(score >= 146)
        {
            system("cls");
            gotoxy(50,10);
            cout << "*   *  *****  *   *"; gotoxy (50,11);
            cout << " * *   *   *  *   *"; gotoxy (50,12);
            cout << "  *    *   *  *   *"; gotoxy (50,13);
            cout << "  *    *****  *****"; gotoxy (50,14);
            gotoxy(50,16);
            cout << "*   *  *****  **   *"; gotoxy (50,11);
            cout << "* * *  *   *  * *  *"; gotoxy (50,12);
            cout << "* * *  *   *  *  * *"; gotoxy (50,13);
            cout << " * *   *****  *   **"; gotoxy (50,14);
            getch();
        }

        Sleep(30);
    }
}

void moveGhost1()
{
    if (directiong1 == "right")
    {
        char nextLocation = getCharAtxy(g1x + 6, g1y);
        if ((nextLocation == '#') || (nextLocation == '.') || (nextLocation == '|'))
        {
            directiong1 = "left";
        }

        else if (nextLocation == ' ' || nextLocation == '.')
        {
            eraseGhost(g1x, g1y);
            g1x = g1x + 1;
            if (nextLocation == '.')
            {
                previousChar = nextLocation;
            }
            printGhost1();
        }
    }

    if (directiong1 == "left")
    {
        char nextLocation = getCharAtxy(g1x - 1, g1y);
        if (nextLocation == '#')
        {
            directiong1 = "right";
        }

        else if (nextLocation == ' ' || nextLocation == '.')
        {
            eraseGhost(g1x, g1y);
            g1x = g1x - 1;
            previousChar = nextLocation;
            printGhost1();
        }
    }
}

void moveGhost2()
{
    if (directiong2 == "down")
    {
        char nextLocation = getCharAtxy(g2x, g2y + 4);
        if ((nextLocation == '#') || (nextLocation == '.') || (nextLocation == '|'))
        {
            directiong2 = "up";
        }

        else if (nextLocation == ' ' || nextLocation == '.')
        {
            eraseGhost(g2x, g2y);
            g2y = g2y + 1;
            previousChar = nextLocation;
            printGhost2();
        }
    }

    if (directiong2 == "up")
    {
        char nextLocation = getCharAtxy(g2x, g2y - 1);
        if (nextLocation == '#')
        {
            directiong2 = "down";
        }

        else if (nextLocation == ' ' || nextLocation == '.')
        {
            eraseGhost(g2x, g2y);
            g2y = g2y - 1;
            previousChar = nextLocation;
            printGhost2();
        }
    }
}

void eraseGhost(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 6; j++)
        {
            cout << " ";
        }
    }
}

bool pacmanCollisionEnemyLeft()
{
    bool collision = false;
    char isEnemy1 = getCharAtxy(pacmanX - 1, pacmanY);
    char isEnemy2 = getCharAtxy(pacmanX - 1, pacmanY + 1);
    char isEnemy3 = getCharAtxy(pacmanX - 1, pacmanY + 2);
    char isEnemy4 = getCharAtxy(pacmanX - 1, pacmanY + 3);

    if ((isEnemy1 == '|') || (isEnemy2 == '|') || (isEnemy3 == '|') || (isEnemy4 == '|'))
    {
        collision = true;
    }
    return collision;
}

bool pacmanCollisionEnemyRight()
{
    bool collision = false;
    char isEnemy1 = getCharAtxy(pacmanX + 6, pacmanY);
    char isEnemy2 = getCharAtxy(pacmanX + 6, pacmanY + 1);
    char isEnemy3 = getCharAtxy(pacmanX + 6, pacmanY + 2);
    char isEnemy4 = getCharAtxy(pacmanX + 6, pacmanY + 3);

    if ((isEnemy1 == '|') || (isEnemy2 == '|') || (isEnemy3 == '|') || (isEnemy4 == '|'))
    {
        collision = true;
    }
    return collision;
}

bool pacmanCollisionEnemyUp()
{
    bool collision = false;
    char isEnemy1 = getCharAtxy(pacmanX, pacmanY);
    char isEnemy2 = getCharAtxy(pacmanX + 1, pacmanY);
    char isEnemy3 = getCharAtxy(pacmanX + 2, pacmanY);
    char isEnemy4 = getCharAtxy(pacmanX + 3, pacmanY);
    char isEnemy5 = getCharAtxy(pacmanX + 4, pacmanY);
    char isEnemy6 = getCharAtxy(pacmanX + 5, pacmanY);

    if ((isEnemy1 == '|') || (isEnemy2 == '|') || (isEnemy3 == '|') || (isEnemy4 == '|') || (isEnemy5 == '|') || (isEnemy6 == '|'))
    {
        collision = true;
    }

    else if ((isEnemy1 == '/') || (isEnemy2 == '/') || (isEnemy3 == '/') || (isEnemy4 == '/') || (isEnemy5 == '/') || (isEnemy6 == '/'))
    {
        collision = true;
    }

    else if ((isEnemy1 == '\\') || (isEnemy2 == '\\') || (isEnemy3 == '\\') || (isEnemy4 == '\\') || (isEnemy5 == '\\') || (isEnemy6 == '\\'))
    {
        collision = true;
    }
    return collision;
}

bool pacmanCollisionEnemyDown()
{
    bool collision = false;
    char isEnemy2 = getCharAtxy(pacmanX + 1, pacmanY + 4);
    char isEnemy3 = getCharAtxy(pacmanX + 2, pacmanY + 4);
    char isEnemy4 = getCharAtxy(pacmanX + 3, pacmanY + 4);
    char isEnemy5 = getCharAtxy(pacmanX + 4, pacmanY + 4);

    if ((isEnemy2 == ',') || (isEnemy3 == ',') || (isEnemy4 == ',') || (isEnemy5 == ','))
    {
        collision = true;
    }

    else if ((isEnemy2 == '-') || (isEnemy3 == '-') || (isEnemy4 == '-') || (isEnemy5 == '-'))
    {
        collision = true;
    }

    return collision;
}

void lives()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 54);
    char heart = 3;
    if(health == 3)
    {
        gotoxy(81,32);
        cout << heart << heart << heart;
    }

    else if(health == 2)
    {
        gotoxy(81,32);
        cout << heart << heart << " ";
    }

    else if(health == 1)
    {
        gotoxy(81,32);
        cout << heart << " " << " ";
    }

    else if(health <= 0)
    {
        gotoxy(81,32);
        cout << " " << " " << " ";
    }
}

void moveGhostRandom()
{
    int randomValue = rand() % 4;
    if (randomValue == 0) // 0 for moving Left
    {
        char next = getCharAtxy(g3x - 1, g3y);
        char next1 = getCharAtxy(g3x - 1, g3y + 1);
        char next2 = getCharAtxy(g3x - 1, g3y + 2);
        char next3 = getCharAtxy(g3x - 1, g3y + 3);
        if (((next == ' ') && (next != '#') && (next != '.')) && ((next1 == ' ') && (next1 != '#') && (next1 != '.')) && ((next2 == ' ') && (next2 != '#') && (next2 != '.')) && ((next3 == ' ') && (next3 != '#') && (next3 != '.')))
        {
            eraseGhost(g3x, g3y);
            g3x = g3x - 1;
            gotoxy(g3x, g3y);
            printGhost3();
        }
    }
    if (randomValue == 1) // 1 for moving Right
    {
        char next = getCharAtxy(g3x + 6, g3y);
        char next1 = getCharAtxy(g3x + 6, g3y + 1);
        char next2 = getCharAtxy(g3x + 6, g3y + 2);
        char next3 = getCharAtxy(g3x + 6, g3y + 3);
        if (((next == ' ') && (next != '#') && (next != '.')) && ((next1 == ' ') && (next1 != '#') && (next1 != '.')) && ((next2 == ' ') && (next2 != '#') && (next2 != '.')) && ((next3 == ' ') && (next3 != '#') && (next3 != '.')))
        {
            eraseGhost(g3x, g3y);
            g3x = g3x + 1;
            gotoxy(g3x, g3y);
            printGhost3();
        }
    }
    if (randomValue == 2) // 2 for moving Up
    {
        char next = getCharAtxy(g3x, g3y - 1);
        char next1 = getCharAtxy(g3x + 1, g3y - 1);
        char next2 = getCharAtxy(g3x + 2, g3y - 1);
        char next3 = getCharAtxy(g3x + 3, g3y - 1);
        char next4 = getCharAtxy(g3x + 4, g3y - 1);
        char next5 = getCharAtxy(g3x + 5, g3y - 1);
        if (((next == ' ') && (next != '#') && (next != '.')) && ((next1 == ' ') && (next1 != '#') && (next1 != '.')) && ((next2 == ' ') && (next2 != '#') && (next2 != '.')) && ((next3 == ' ') && (next3 != '#') && (next3 != '.')) && ((next4 == ' ') && (next4 != '#') && (next4 != '.')) && ((next5 == ' ') && (next5 != '#') && (next5 != '.')))
        {
            eraseGhost(g3x, g3y);
            g3y = g3y - 1;
            gotoxy(g3x, g3y);
            printGhost3();
        }
    }
    if (randomValue == 3) // 2 for moving Down
    {
        char next = getCharAtxy(g3x, g3y + 4);
        char next1 = getCharAtxy(g3x + 1, g3y + 4);
        char next2 = getCharAtxy(g3x + 2, g3y + 4);
        char next3 = getCharAtxy(g3x + 3, g3y + 4);
        char next4 = getCharAtxy(g3x + 4, g3y + 4);
        char next5 = getCharAtxy(g3x + 5, g3y + 4);
        if (((next == ' ') && (next != '#') && (next != '.')) && ((next1 == ' ') && (next1 != '#') && (next1 != '.')) && ((next2 == ' ') && (next2 != '#') && (next2 != '.')) && ((next3 == ' ') && (next3 != '#') && (next3 != '.')) && ((next4 == ' ') && (next4 != '#') && (next4 != '.')) && ((next5 == ' ') && (next5 != '#') && (next5 != '.')))
        {
            eraseGhost(g3x, g3y);
            g3y = g3y + 1;
            gotoxy(g3x, g3y);
            printGhost3();
        }
    }
}

float distance(int gx, int gy)
{
    return sqrt(pow(pacmanX - gx, 2) + pow(pacmanY - gy, 2));
}

void moveGhostSmart()
{
    float left = distance(g3x - 1, g3y);
    float right = distance(g3x + 6, g3y);
    float up = distance(g3x, g3y - 1);
    float down = distance(g3x, g3y + 4);
    if (left <= down && left <= right && left <= up)
    {
        char next = getCharAtxy(g3x - 1, g3y);
        char next1 = getCharAtxy(g3x - 1, g3y + 1);
        char next2 = getCharAtxy(g3x - 1, g3y + 2);
        char next3 = getCharAtxy(g3x - 1, g3y + 3);
        if (((next == ' ') && (next != '#') && (next != '.')) && ((next1 == ' ') && (next1 != '#') && (next1 != '.')) && ((next2 == ' ') && (next2 != '#') && (next2 != '.')) && ((next3 == ' ') && (next3 != '#') && (next3 != '.')))
        {
            gotoxy(g3x, g3y);
            eraseGhost(g3x, g3y);
            g3x = g3x - 1;
            gotoxy(g3x, g3y);
            printGhost3();
        }
    }
    else if (right <= down && right <= left && right <= up)
    {
        char next = getCharAtxy(g3x + 6, g3y);
        char next1 = getCharAtxy(g3x + 6, g3y + 1);
        char next2 = getCharAtxy(g3x + 6, g3y + 2);
        char next3 = getCharAtxy(g3x + 6, g3y + 3);
        if (((next == ' ') && (next != '#') && (next != '.')) && ((next1 == ' ') && (next1 != '#') && (next1 != '.')) && ((next2 == ' ') && (next2 != '#') && (next2 != '.')) && ((next3 == ' ') && (next3 != '#') && (next3 != '.')))
        {
            gotoxy(g3x, g3y);
            eraseGhost(g3x, g3y);
            g3x = g3x + 1;
            gotoxy(g3x, g3y);
            printGhost3();
        }
    }
    else if (down <= left && down <= right && down <= up)
    {
        char next = getCharAtxy(g3x, g3y + 4);
        char next1 = getCharAtxy(g3x + 1, g3y + 4);
        char next2 = getCharAtxy(g3x + 2, g3y + 4);
        char next3 = getCharAtxy(g3x + 3, g3y + 4);
        char next4 = getCharAtxy(g3x + 4, g3y + 4);
        char next5 = getCharAtxy(g3x + 5, g3y + 4);
        if (((next == ' ') && (next != '#') && (next != '.')) && ((next1 == ' ') && (next1 != '#') && (next1 != '.')) && ((next2 == ' ') && (next2 != '#') && (next2 != '.')) && ((next3 == ' ') && (next3 != '#') && (next3 != '.')) && ((next4 == ' ') && (next4 != '#') && (next4 != '.')) && ((next5 == ' ') && (next5 != '#') && (next5 != '.')))
        {
            gotoxy(g3x, g3y);
            eraseGhost(g3x, g3y);
            g3y = g3y + 1;
            gotoxy(g3x, g3y);
            printGhost3();
        }
    }
    else
    {
        char next = getCharAtxy(g3x, g3y - 1);
        char next1 = getCharAtxy(g3x + 1, g3y - 1);
        char next2 = getCharAtxy(g3x + 2, g3y - 1);
        char next3 = getCharAtxy(g3x + 3, g3y - 1);
        char next4 = getCharAtxy(g3x + 4, g3y - 1);
        char next5 = getCharAtxy(g3x + 5, g3y - 1);
        if (((next == ' ') && (next != '#') && (next != '.')) && ((next1 == ' ') && (next1 != '#') && (next1 != '.')) && ((next2 == ' ') && (next2 != '#') && (next2 != '.')) && ((next3 == ' ') && (next3 != '#') && (next3 != '.')) && ((next4 == ' ') && (next4 != '#') && (next4 != '.')) && ((next5 == ' ') && (next5 != '#') && (next5 != '.')))
        {
            gotoxy(g3x, g3y);
            eraseGhost(g3x, g3y);
            g3y = g3y - 1;
            gotoxy(g3x, g3y);
            printGhost3();
        }
    }
}

void gameOver()
{
    system("cls");
    gotoxy(40,9);
   cout << "  ______     ______     __    __     ______   "     ;                  gotoxy(40,10);  
   cout <<  "/\\  ___\\   /\\  __ \\   /\\ '-./  \\   /\\  ___\\      ";           gotoxy(40,11);    
   cout <<  "\\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\-./\\ \\  \\ \\  __\\      ";    gotoxy(40,12);           
   cout << " \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\    ";    gotoxy(40,13);           
   cout << "  \\/_____/   \\/_/\\/_/   \\/_/  \\/_/   \\/_____/    ";               gotoxy(40,14);     
   cout << endl;                                                                   gotoxy(40,15);                            
   cout << "  ______     __   __   ______     ______    ";                         gotoxy(40,16);                    
   cout << " /\\  __ \\   /\\ \\ / /  /\\  ___\\   /\\  == \\   ";                 gotoxy(40,17);                            
   cout << " \\ \\ \\/\\ \\  \\ \\ \\'/   \\ \\  __\\   \\ \\  __<_   ";             gotoxy(40,18);                      
   cout << "  \\ \\_____\\  \\ \\__|    \\ \\_____\\  \\ \\_\\ \\_\\ ";            gotoxy(40,19);                            
   cout << "   \\/_____/   \\/_/      \\/_____/   \\/_/ /_/ ";                     gotoxy(40,20);       
   getch();                 
}