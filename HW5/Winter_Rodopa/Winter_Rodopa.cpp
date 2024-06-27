#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int NumOfCols, NumOfRows;
    cin >> NumOfCols >> NumOfRows;
    bool** matrix = new bool* [NumOfRows];
    for (int i = 0; i < NumOfCols; i++)
    {
        matrix[i] = new bool[NumOfCols];
        for (int j = 0; j < NumOfCols; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < NumOfCols; i++)
    {
        for (int j = 0; j < NumOfCols; j++)
        {
            cout<<matrix[i][j];
        }
    }
    

    return 0;
}