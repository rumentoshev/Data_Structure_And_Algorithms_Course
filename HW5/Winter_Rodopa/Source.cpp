#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Coordinates
{
    int x;
    int y;

    Coordinates(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

};

int main() {

    int N, M, T;
    cin >> N >> M >> T;
    int x, y;
    int count = 0;
    bool** matrix = new bool* [M];
    for (int i = 0; i < M; ++i)
    {
        matrix[i] = new bool[N];
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = false;
        }
    }
    queue<Coordinates> bad;
    while (cin >> y >> x)
    {
        matrix[x - 1][y - 1] = true;
        bad.push(Coordinates(x - 1, y - 1));
        count++;
    }
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] == false)
            {
                cout << "0" << " ";
            }
            else
            {
                cout << "1" << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < T; i++)
    {
        int size = bad.size();
        for (int j = 0; j < size; j++)
        {
            Coordinates place = bad.front();
            if ((place.x - 1) >= 0)
            {
              if (matrix[place.x - 1][place.y] == false)
                {
                  matrix[place.x - 1][place.y] = true;
                  bad.push(Coordinates(place.x - 1, place.y));
                  count++;
                }
            }
            if ((place.x + 1) < M)
            {
                if (matrix[place.x + 1][place.y] == false)
                {
                    matrix[place.x + 1][place.y] = true;
                    bad.push(Coordinates(place.x + 1, place.y));
                    count++;
                }
            }
            if ((place.y - 1) >= 0)
            {
                if (matrix[place.x][place.y - 1] == false)
                {
                    matrix[place.x][place.y - 1] = true;
                    bad.push(Coordinates(place.x, place.y - 1));
                    count++;
                }
            }
            if ((place.y + 1) < N)
            {
                if(matrix[place.x][place.y + 1] == false)
                {
                    matrix[place.x][place.y + 1] = true;
                    bad.push(Coordinates(place.x, place.y + 1));
                    count++;
                }
            }
            for (int i = 0; i < M; ++i)
            {
                for (int j = 0; j < N; j++)
                {
                    if (matrix[i][j] == false)
                    {
                        cout << "0" << " ";
                    }
                    else
                    {
                        cout << "1" << " ";
                    }
                }
                cout << "\n";
            }
            cout << "\n";
            bad.pop();
        }
    }
    for (int i = 0; i < M; ++i)
        delete[] matrix[i];
    delete[] matrix;
    cout << M * N - count;
    return 0;
}