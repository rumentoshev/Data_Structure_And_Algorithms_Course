#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    
    string S;
    cin >> S;
    int count[74] = {};
    for (int i = 0; i < S.length(); ++i)
    {
        count[S[i] - '0']++;
    }
    for (int i = 0; i < S.length(); i++)
    {
        if (count[S[i] - '0'] == 1)
        {
            cout << i<<" ";
        }
    }


    return 0;
}