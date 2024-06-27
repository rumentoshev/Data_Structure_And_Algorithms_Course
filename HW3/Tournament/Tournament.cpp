#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct tournamentsWeightLimits
{
    double minWeightLine = 0;
    double maxWeightLine =0;

    int numberOfStudentsToParticipate = 0;
};
 
int findTheIndexInLeft(vector<int>& arrayWithStudentsWeights, int start, int end,int target)//works
{
    int mid = 0;
    int ans = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arrayWithStudentsWeights[mid] >= target)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int findTheIndexInRight(vector<int>& arrayWithStudentsWeights, int start, int end, int target)//works
{
    int mid;
    int ans;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arrayWithStudentsWeights[mid] <= target)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main() {
    
    int N, Q;
    cin >> N >> Q;
    vector<int> arrWithStudentsWeights(N);
    for (int i = 0; i < N; ++i)//works
    {
        cin >> arrWithStudentsWeights[i];
    }
    sort(arrWithStudentsWeights.begin(), arrWithStudentsWeights.end());//works
    vector<tournamentsWeightLimits> arrWithTournaments(Q);
    for (int i = 0; i < Q; ++i)//works
    {
        cin>>arrWithTournaments[i].minWeightLine;
        cin >> arrWithTournaments[i].maxWeightLine;
    }
    int leftIndex;
    int rightIndex;
    for (int i = 0; i < Q; ++i)
    {
        leftIndex = findTheIndexInLeft(arrWithStudentsWeights, 0, N - 1, arrWithTournaments[i].minWeightLine) + 1;
        rightIndex = findTheIndexInRight(arrWithStudentsWeights, 0, N - 1, arrWithTournaments[i].maxWeightLine) + 1;
        if (leftIndex > rightIndex)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << rightIndex - leftIndex + 1 << "\n";

        }

    }
   /* vector<int> arr(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    cout<<findTheIndexInLeft(arr, 0, 4, 3);
    cout<<findTheIndexInRight(arr, 0, 4, 3);*/
    
    return 0;
}
