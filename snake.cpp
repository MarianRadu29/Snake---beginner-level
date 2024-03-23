#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;
char T[25][60], g;
int i, j, score = 0, fructx[21], fructy[21], coadax[1200], coaday[1200], a, b;
struct Snake
{
    int x, y;
}snake;
void Spatiu_de_joc()
{
    for (i = 1; i <= 60; i++)
        T[1][i] = '#';
    for (int i = 2; i < 20; i++)
        for (int j = 1; j <= 60; j++)
            if (j == 1 || j == 60)
                T[i][j] = '#';
            else
                T[i][j] = ' ';
    for (i = 1; i <= 60; i++)
        T[20][i] = '#';
}
void fructele()
{   
    srand(time(NULL));
    for (i = 1; i <= 20; i++)
        do
        {
            fructx[i] = rand();
            fructy[i] = rand();
        } while (fructx[i] <= 1 || fructx[i] >= 20 || fructy[i] <= 1 || fructy[i] >= 60);
}
void coada_sarpe()
{
    if (score > 0)
        for (i = score; i > 0; i--)
        {
            coadax[i] = coadax[i - 1];
            coaday[i] = coaday[i - 1];
        }
    coadax[0] = snake.x;
    coaday[0] = snake.y;
}
int main()
{
    snake.x = 0;
    snake.y = 0;
    bool game = true;
    srand(time(NULL));
    do
    {
        snake.x = rand() % 19;
        snake.y = rand() % 58;
    } while ((snake.y <= 1 || snake.y >= 60) && (snake.x <= 1 || snake.x >= 20));
    T[snake.x][snake.y] = '0';
    Spatiu_de_joc();
    fructele();
    while (game == true)
    {
        system("cls");
        for (i = 1; i <= 20; i++)
            T[fructx[i]][fructy[i]] = 'F';
        for (i = 1; i <= 20; i++)
        {
            for (j = 1; j <= 60; j++)
                cout << T[i][j];
            cout << endl;
        }
        cout << endl;
        cout << setfill(' ') << setw(20) << "Score: " << score;
        if (_kbhit())
        {
            switch (getch())
            {
            case 'a':
            {
                if (g == 'd' && score > 0)
                    game = false;
                snake.y--;
                if (snake.y == 1)
                    game = false;
                g = 'a';
            }
            break;
            case 'd':
            {
                if (g == 'a' && score > 0)
                    game = false;
                snake.y++;
                if (snake.y == 60)
                    game = false;
                g = 'd';
            }
            break;
            case 'w':
            {
                if (g == 's' && score > 0)
                    game = false;
                snake.x--;
                if (snake.x == 1)
                    game = false;
                g = 'w';
            }
            break;
            case 's':
            {
                if (g == 'w' && score > 0)
                    game = false;
                snake.x++;
                if (snake.x == 20)
                    game = false;
                g = 's';
            }
            break;
            default:
                break;
            }
            if (T[snake.x][snake.y] == 'F')
            {
                score++;
                for (i = 1; i <= 20; i++)
                    if (fructx[i] == snake.x && fructy[i] == snake.y)
                        break;
                do
                {
                    fructx[i] = rand();
                    fructy[i] = rand();
                } while (fructx[i] <= 1 || fructx[i] >= 20 || fructy[i] <= 1 || fructy[i] >= 60 || T[fructx[i]][fructy[i]] == '0');

            }
        }
        else
        {
            switch (g)
            {
            case 'a':
            {
                snake.y--;
                if (snake.y == 1)
                    game = false;
            }
            break;
            case 'd':
            {
                snake.y++;
                if (snake.y == 60)
                    game = false;
            }
            break;
            case 'w':
            {
                snake.x--;
                if (snake.x == 1)
                    game = false;
            }
            break;
            case 's':
            {
                snake.x++;
                if (snake.x == 20)
                    game = false;
            }
            break;
            default:
                break;
            }
            if (T[snake.x][snake.y] == 'F')
            {
                score++;
                for (i = 1; i <= 20; i++)
                    if (fructx[i] == snake.x && fructy[i] == snake.y)
                        break;
                do
                {
                    fructx[i] = rand();
                    fructy[i] = rand();
                } while (fructx[i] <= 1 || fructx[i] >= 20 || fructy[i] <= 1 || fructy[i] >= 60 || T[fructx[i]][fructy[i]] == '0');

            }
        }
        _sleep(50);
        Spatiu_de_joc();
        T[snake.x][snake.y] = '0';
        coada_sarpe();
        for (i = 1; i <= score; i++)
            if (coadax[i] == snake.x && coaday[i] == snake.y && score > 0)
                game = false;
        for (i = 0; i <= score; i++)
            T[coadax[i]][coaday[i]] = '0';
    }
    cin >> i;
    return 0;
}
