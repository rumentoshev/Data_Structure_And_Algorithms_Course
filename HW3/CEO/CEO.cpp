#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int checkIfTheNumIsAnswer(vector<int>& arr, long long int numToCheck)
{
    int counterOfCreatedtTeams = 0;
    int i = 0;
    long long int tempSum = 0;
    while (i < arr.size())
    {
        tempSum = tempSum + arr[i];
        if (tempSum > numToCheck)
        {
            tempSum = 0;
            ++counterOfCreatedtTeams;
            continue;
        }
        else
        {
            i++;
            continue;
        }
    }
    ++counterOfCreatedtTeams;
    return counterOfCreatedtTeams;
}
int findTheAnswer(vector<int>& arr, int start, int end, int numOfTeams)
{
    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        int possibleTeamsWithSumCloseToMid = checkIfTheNumIsAnswer(arr, mid);
        if (possibleTeamsWithSumCloseToMid > numOfTeams)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}


int main() {

    int numberOfDevs;
    int numberOfTeams;
    cin >> numberOfDevs >> numberOfTeams;
    vector<int> arrOfDevs(numberOfDevs);
    for (int i = 0; i < numberOfDevs; i++)
    {
        cin >> arrOfDevs[i];
    }
    int smallestPossSol = *max_element(arrOfDevs.begin(), arrOfDevs.end());
    int biggestPossSol = 0;
    for (int i = 0; i < numberOfDevs; ++i)
    {
        biggestPossSol += arrOfDevs[i];
    }
    cout << findTheAnswer(arrOfDevs, smallestPossSol, biggestPossSol, numberOfTeams);

    return 0;
}