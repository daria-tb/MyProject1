#include <iostream>
#include <vector>
using namespace std;

/* Граф — это нелинейная структура данных, состоящая из вершин и ребер. Вершины иногда также называют узлами, а ребра — это линии или дуги, соединяющие любые два узла в графе. Более формально граф состоит из набора вершин ( V ) и набора ребер ( E ). Граф обозначается как G(V, E) . 
Матрица смежности — это способ представления графа в виде матрицы булевых значений (0 и 1).*/


/* Представление неориентированного графа в виде матрицы смежности:

На рисунке ниже показан неориентированный граф. Изначально вся матрица инициализируется значением 0. Если есть ребро от источника к месту назначения, мы вставляем 1 в оба случая ( adjMat[source][destination] и adjMat [ destination][source]), поскольку мы можем пойти в любом направлении. */
void addEdge(vector<vector<int>>& mat, int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void displayMatrix(vector<vector<int>>& mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int V = 4;
    vector<vector<int>> mat(V, vector<int>(V, 0));

    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(mat);

    return 0;
}