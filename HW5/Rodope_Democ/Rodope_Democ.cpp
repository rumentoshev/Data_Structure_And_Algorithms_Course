#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
    }
    stack<long long int> burevci;
    queue<long long int> passed;
    queue<long long int> sredechani;
    int j = 0;
    while(j < N)
    {
        if (numbers[j] < 0 && burevci.empty())
        {
            passed.push(numbers[j]);
        }
        else if (numbers[j] > 0 && sredechani.empty())
        {
            burevci.push(numbers[j]);
        }
        else if (numbers[j] < 0 && !burevci.empty())
        {
            int k = j;
            while (numbers[k]<0)
            {
                if (k == N)
                {
                    break;
                }
                sredechani.push(numbers[k]);
                k++;
            }
            while (!burevci.empty() && !sredechani.empty())
            {
                if (burevci.top() == abs(sredechani.front()))
                {
                    burevci.pop();
                    sredechani.pop();
                }
                else if (burevci.top() < abs(sredechani.front()))
                {
                    burevci.pop();
                }
                else if (burevci.top() > abs(sredechani.front()))
                {
                    sredechani.pop();
                }
            }
            while (!sredechani.empty())
            {
                passed.push(sredechani.front());
                sredechani.pop();
            }
            j = k;
            continue;
        }
        j++;
    }
    vector<long long int> temp;
    int i = 0;
    while (!burevci.empty())
    {
        temp.push_back(burevci.top());
        i++;
        burevci.pop();
    }
    for (int l = temp.size() -1; l >= 0; --l)
    {
        passed.push(temp[l]);
    }
    while (!passed.empty())
    {
        cout << passed.front()<<"\n";
        passed.pop();
    }
    return 0;
}