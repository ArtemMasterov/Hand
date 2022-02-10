#include "Graph.h"
#include <iostream>
#define VERYBIGINT 1000000
using namespace std;

void Graph::find_Min_Dist_Floyd()
{
    int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                if (!are_adj(i, j))
                {
                    weights[i][j] = matrix[i][j];
                }
                else {
                    weights[i][j] = VERYBIGINT;
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // итерации по k
    {
        int ck = vertexes[k]; // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[i][k] + weights[k][j] < weights[i][j]) {
                    // пересчет матрицы путей
                    weights[i][j] = weights[i][k] + weights[k][j];
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++)
    {
        int ck = vertexes[k];
        // вывод всех минимальных путей от вершины '0'
        cout << "V" << ck << ": " << weights[0][vertexes[ck]] << ", ";
    }
}