
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void player_color(char (*Tj)[8])     {
    int i;
        for (i = 0; i < 5; i++) {
            printf("\n the color number %d \t", i + 1);
            fflush(stdout);
            fgets(Tj[i], sizeof(Tj[i]), stdin);
            Tj[i][strcspn(Tj[i], "\n")] = '\0';
        }
}
        void random_number(int *C) {
        int i, j;
        srand(time(NULL));
        for (i = 0; i < 5; i++) {
            do {
                C[i] = (rand() % 8 + 1);
                for (j = 0; j < i; j++) {
                    if (C[i] == C[j]) {
                        break;
                    }
                }
            } while (j < i);
        }
    }
        void pc_color(int C[5], char(*Tc)[8]) {
            int i;
        for (i = 0; i < 5; i++) {
            switch (C[i]) {
            case 1:
                strcpy(Tc[i], "red");
                break;
            case 2:
                strcpy(Tc[i], "blue");
                break;
            case 3:
                strcpy(Tc[i], "green");
                break;
            case 4:
                strcpy(Tc[i], "black");
                break;
            case 5:
                strcpy(Tc[i], "white");
                break;
            case 6:
                strcpy(Tc[i], "pink");
                break;
            case 7:
                strcpy(Tc[i], "yellow");
                break;
            case 8:
                strcpy(Tc[i], "brown");
                break;
            }
        }
    }
        void test(char Tj[][8], char Tc[][8], int* p, int* d) {
            int i, j;
            for (i = 0; i < 5; i++) {
                if (strcmp(Tj[i], Tc[i]) == 0) {
                    (*p) = (*p) + 1;
                    printf("\nthe color number %d is in the right place\t", i + 1);
                }
                else {
                    for (j = 0; j < 5; j++) {
                        if (i != j && strcmp(Tj[i], Tc[j]) == 0) {
                            (*d) = (*d) + 1;
                            printf("\n the color number %d is in the wrong place\t", i + 1);
                        }
                    }
                }
            }
        }
        void end(int x){
            if (x == 5) {
                printf("\n you won!\t");
            }
            else { printf("\n GAME OVER\t"); }
        }
int main()
{
    char Tj[5][8];
    char Tc[5][8];
    int C[5];
    int i, j, p = 0, d = 0, cmp = 8;
    printf("\t the colors are : green black yellow pink white blue red brown \n");
    random_number(C);
    pc_color(C, Tc);
    while (cmp > 0) {
        d = 0;
        p = 0;
        player_color(Tj);
        test(Tj, Tc,&p,&d);
        if (p == 5) {
            break;
        }
        else {
            cmp = cmp - 1;
            if (cmp > 0) {
                printf("\n you have %d try left \t ", cmp);
                printf("\n try again.\t");
            }
        }
    }
    end(p);
    return 0;
}