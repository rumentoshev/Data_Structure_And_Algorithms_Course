#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> numbers;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    vector<int> negative(N);
    vector<int> positive(N);
    int i = 0,j1 = 0,j2 = 0;
    while (i < N)
    {
        if (numbers[i] % 2 == 1)
        {
            int temp = numbers[i];
            negative[j1] = temp;
            j1++;
            i++;
            continue;
        }
        else
        {
            int temp = numbers[i];
            positive[j2] = temp;
            j2++;
            i++;
            continue;
        }
        
    }
    for (int i = 0; i < j2; i++)
    {
        cout << positive[i] << "\n";
    }
    for (int i = 0; i < j1; i++)
    {
        cout << negative[i] << "\n";
    }
    
    return 0;
}