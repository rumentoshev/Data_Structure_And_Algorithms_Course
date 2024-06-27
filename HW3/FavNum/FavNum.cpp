#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long int findTheValue(long long int start, long long int end, long long int target, int P)
{
    int long long counter = 0;
    while (start < end)
    {
        ++counter;
        long long mid1 = start + (end - start) / 3 + 1;
        long long mid2 = end - (end - start) / 3 - 1;
        if (mid1 == mid2 && mid1 == target)
        {
            return P;
        }
        else if (mid1 == mid2 && mid1 != target)
        {
            return P + 1;
        }
        if (target >= mid1 && target <= mid2)
        {
            return counter;
        }
        else if (target < mid1)
        {
            end = mid1 - 1;
        }
        else if (target > mid2)
        {
            start = mid2 + 1;
        }

    }
    return counter;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, P;
    cin >> P >> N;
    long long int nums = pow(3, P);
    vector<long long int> arr(N);
    long long int start = 0;


    for (int i = 0; i < N ; i++)
    {
        long long int temp;
        cin >> temp;
        arr[i] = temp;
    }
    for (int i = 0; i < N; i++)
    {
        cout << findTheValue(start, nums - 1, arr[i] -1, P)<<"\n";
    }
    
    return 0;

}
