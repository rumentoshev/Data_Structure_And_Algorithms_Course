#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    size_t Q;
    cin >> Q;
    vector <vector <char>> arr;
    for (size_t i = 0; i < Q; i++)
    {
        size_t sizeOfTheString = 0;
        cin >> sizeOfTheString;
        vector<char> temp;
        for (size_t j = 0; j < sizeOfTheString; j++)
        {
            char symbol;
            cin >> symbol;
            temp.push_back(symbol);
        }
        arr.push_back(temp);
    }

    for (size_t i = 0; i < Q; i++)
    {
        size_t currSymbolIndex = 0;
        size_t counter = 0;
        for (size_t j = 1; j < arr[i].size(); j++)
        {
            if (arr[i][currSymbolIndex] == arr[i][j])
            {
                counter++;
            }
            else
            {
                currSymbolIndex = j;
            }
        }
        cout << counter;
        cout << endl;
    }
    return 0;
}