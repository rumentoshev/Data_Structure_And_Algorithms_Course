#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() { 

    string first, second;
    cin >> first >> second;

    int ans = 0;
    //bool flag = false;
    for (int i = 0; i < first.size(); i++)
    {
        int index = i;
        int counter = 0;
        for (int j = 0; j < second.size(); j++)
        {
            if (index >= second.size())
            {
                break;
            }
            if (first[index] != second[j])
            {
                counter = 0;
                index = i;
            }
            else if (first[index] == second[j])
            {
                counter++;
                index++;
            }

            ans = max(counter, ans);
        }
    }
    cout << ans;
    return 0;
}