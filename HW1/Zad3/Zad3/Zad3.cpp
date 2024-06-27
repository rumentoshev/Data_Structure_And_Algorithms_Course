#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    bool flag = false;
    int indexOfFirstPosNum = -1;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] > 0)
        {
            indexOfFirstPosNum = i;
            if (arr[indexOfFirstPosNum] > 1)
            {
                cout << 1;
                return 0;
            }
            break;
        }
    }
    if (indexOfFirstPosNum == -1)
    {
        cout << 1;
        return 0;
    }
     for (int i = indexOfFirstPosNum; i < N; i++)
    {
            if ((i + 1) == N)
            {
                cout << arr[N - 1] + 1;
            }
            else
            {   
                if (arr[i] + 1 == arr[i + 1] || arr[i] == arr[i + 1])
                {
                    continue;
                }
                else
                {
                    cout << arr[i] + 1;
                    break;
                }
            }
      }
   
    
    return 0;
}
//int N;
//cin >> N;
//int* arr = new int[N];
//for (int i = 0; i < N; i++)
//{
//    cin >> arr[i];
//}
////Bubble Sort
//for (int i = 0; i < N; i++)
//{
//    for (int j = i + 1; j < N; j++)
//    {
//        if (arr[j] < arr[i])
//        {
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//
//        }
//    }
//}
//int index = 0;
//for (int i = 0; i < N; i++)
//{
//    if (arr[i] >= 0)
//    {
//        index = i;
//        break;
//    }
//}
//for (int i = index + 1; i < N; i++)
//{
//    if (arr[i - 1] + 1 == arr[i] || arr[i - 1] == arr[i])
//    {
//        if (i + 1 == N)
//        {
//            cout << arr[N - 1] + 1;
//        }
//        continue;
//    }
//    else
//    {
//        cout << arr[i - 1] + 1;
//        break;
//    }
//}
//delete[] arr;