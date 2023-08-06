#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Space.h"

void printTableau(bool **tab, int cols, int rows)
{
    int i = 0;

    while (i < cols)
    {
        int j = 0;
        printf("|");
        while (j < rows)
        {
            if (tab[i][j])
            {
                printf("#|");
            }
            else
            {
                printf(".|");
            }
            j++;
        }
        printf("\n");
        i++;
    }
printf("\n");
}
bool **tableaux(int cals, int rows)
{
    bool **tableaux = malloc(sizeof(bool *) * cals); // comment on fais pour tout
    int i = 0;
    while (i < cals)
    {
        tableaux[i] = malloc(sizeof(bool) * rows);
        i++;
    }
    i = 0;
    int t;
    while (i < cals)
    {
        t = 0;
        while (t < rows)
        {
            tableaux[i][t] = false;
            t++;
        }
        i++;
    }
    return tableaux;
}
