#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {

    long long int Q;
    cin >> Q;
    //Q - num of requests

    vector<long long int> ans;
    for (int i = 0; i < Q; ++i)
    {
        long long int N;
        cin >> N;
        //N - number of sweets
        vector<long long int> sweets;
        map<long long int, int> arr;
        //First int - num
        //Second int - index
        for (long long int j = 0; j < N; ++j)
        {
            long long int temp;
            cin >> temp;
            //temp - number of the sweet
            sweets.push_back(temp);
        }

        int start = 1;
        int currMaxSubArr = 1;
        for (long long int k = 0; k < N; k++)
        {
            if (arr.count(sweets[k]) == 1)
            {
                auto itr1 = arr.find(sweets[k]);
                long long int firstIndex = itr1->second;
                if (firstIndex < start)
                {
                    itr1->second = k + 1;
                    currMaxSubArr = max(itr1->second - start + 1, currMaxSubArr);
                }
                else if(firstIndex >= start)
                {
                    start = firstIndex + 1;
                    itr1->second = k + 1;
                }
            }
            else
            {
                arr.insert({ sweets[k],k + 1 });
                auto itr = arr.find(sweets[k]);
                currMaxSubArr = max(itr->second - start + 1, currMaxSubArr);
            }
        }
        ans.push_back(currMaxSubArr);
        
    }

    for (long long int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]<<"\n";
    }
    return 0;
}
