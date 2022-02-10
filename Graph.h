#pragma once
#define SIZE 10
#include <iostream>
using namespace std;

class Graph 
{
    public:
    Graph();
    void addVertex(int vnumber);
    void addEdge(int v1, int v2, int weight);
    void find_Min_Dist_Floyd();

    private:
    bool are_adj(int v1, int v2);
    int matrix[SIZE][SIZE]; // матрица 

    int vertexes[SIZE]; // хранилище 
    int vertexCount;

};

