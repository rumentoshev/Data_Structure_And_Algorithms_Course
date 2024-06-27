#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
using namespace std;

#define endl '\n'



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numeberOfBalls;
    cin >> numeberOfBalls;
    vector<int> lineOfBalls(numeberOfBalls);
    for (int i = 0; i < numeberOfBalls; ++i)
    {
        cin >> lineOfBalls[i];
    }
    int numberOfRequests;
    cin >> numberOfRequests;
    for (int i = 0; i <= numberOfRequests; ++i)
    {
        if (i == numberOfRequests)
        {
            if (lineOfBalls.size() != 0)
            {
                for (int i = 0; i < lineOfBalls.size(); ++i)
                {
                    cout << lineOfBalls[i];
                }
            }
            else
            {
                cout <<"-1";
            }
        }
        if (lineOfBalls.size() == 0)
        {
            cout << "Game Over" << "\n";
            continue;
        }
        int position, color;
        cin >> position >> color;
        int nextPosition = position + 1;
        int prevPosition = position - 1;
        int counterOfBalls = 0;
        int flag1 = false, flag2 = false;
        if (lineOfBalls[position] == color)
        {
            if (nextPosition < numeberOfBalls)
            {
                while (lineOfBalls[position] == lineOfBalls[nextPosition])
                {
                    ++counterOfBalls;
                    ++nextPosition;
                    if (nextPosition == numeberOfBalls)
                    {
                        flag1 = true;
                        --nextPosition;
                        break;
                    }
                }
            }
            if (flag1 == false)
            {
                nextPosition--;
            }
            if (prevPosition > -1)
            {
                while (lineOfBalls[position] == lineOfBalls[prevPosition])
                {
                    ++counterOfBalls;
                    --prevPosition;
                    if (nextPosition == -1)
                    {
                        flag2 = true;
                        ++nextPosition;
                        break;
                    }
                }
            }
            if (flag2 == false)
            {
                prevPosition++;
            }
            if (counterOfBalls + 1 > 1)
            {
                lineOfBalls.erase(lineOfBalls.begin() + prevPosition, lineOfBalls.begin() + prevPosition + counterOfBalls + 1);
            }
            cout << counterOfBalls + 2<<"\n";
        }
        else
        {
            lineOfBalls.insert(lineOfBalls.begin() + position + 1, color);
            cout << "0" << "\n";
        }

    }


    return 0;
}