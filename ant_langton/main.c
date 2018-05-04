#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ABSC 380
#define ORDO 160

void initializeTab(int** pArray) {

    int** pTab = pArray;

    for(int y = 0;y < ORDO;y++) {
        for(int x = 0;x < ABSC;x++) {
            pTab[y][x] = 0;
        }
    }
}

void printTab(int** pArray) {
    int** pTab = pArray;

    //system("color 1");

    for (int y = 0;y < ORDO;y++) {
        for (int x = 0;x < ABSC;x++) {
            if (pTab[y][x] == 1) {
                printf(" ");
            } else {
                printf("%d ", pTab[y][x]);
            }
        }
        printf("\n");
    }
}

void updateTab(int** pArray, int abscisse, int ordonnee) {
    int** pTab = pArray;
    int x = abscisse;
    int y = ordonnee;

    //Sleep(1);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole, 4);
    CONSOLE_SCREEN_BUFFER_INFO csbi = {0};
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD coordCur = csbi.dwCursorPosition;

    // now you can change position of the cursor
    coordCur.X = x * 2;
    coordCur.Y = y;
    //printf("x = %d y = %d",coordCur.X,coordCur.Y);
    SetConsoleCursorPosition(hConsole, coordCur);

    // and print any information from the new position
    if (pTab[y][x] == 1) {
        printf(" ");
    } else {
        printf("%d", pTab[y][x]);
    }
}

void infiniteLoop(int** pArray) {
    int** pTab = pArray;

    srand( time(NULL) );

    int orientation = -1;

    /*
    S = 1
    E = 0
    N = -1
    W = -2
    */

    int move = -1;

    /*
    Right = 1
    Left = -1
    */

    int y = rand() % ORDO;
    int x = rand() % ABSC;

    printTab(pTab);

    while (1) {
        if (pTab[y][x] == 1) {
            move = 1;
            orientation+=move;

            pTab[y][x] = 0;

            if (orientation == 2) {
                orientation = -2;
            }
        } else if (pTab[y][x] == 0){

            move = -1;
            orientation+=move;

            pTab[y][x] = 1;

            if (orientation == -3) {
                orientation = 1;
            }
        }

        updateTab(pTab, x, y);

        if (orientation == 0) {
            x += 1;
        } else if (orientation == -2) {
            x -= 1;
        } else if (orientation == 1) {
            y += 1;
        } else if (orientation == -1) {
            y -= 1;
        }

        if (x == ABSC) {
            x = 0;
        } else if (x == -1) {
            x = ABSC - 1;
        } else if (y == ORDO) {
            y = 0;
        } else if (y == -1) {
            y = ORDO - 1;
        }
    }
}

int main()
{
    int** pTab ;
    pTab = (int**) malloc(ORDO*sizeof(int*));

    for(int i=0;i<ORDO;i++)
        pTab[i]=(int*) malloc(ABSC*sizeof(int));

    initializeTab(pTab);

    infiniteLoop(pTab);

    free(pTab);
    return 0;
}
