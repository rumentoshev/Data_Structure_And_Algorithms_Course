#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

typedef unsigned long long ull;

int main() {

    size_t n, r;
    cin >> n >> r;

    vector<ull> weights(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    unordered_map<ull, ull> singleNumberOccurences;
    unordered_map<ull, unordered_map<ull, ull>> pairOccurences;

    ull counter = 0, x;
    while (n-- > 0)
    {
        x = weights[n];

        counter += pairOccurences[r * x][r * r * x];
        pairOccurences[x][r * x] += singleNumberOccurences[r * x];
        ++singleNumberOccurences[x];
    }

    cout << counter;

    return 0;
}
//int  main()
//{
//	int N, M;
//	cin >> N >> M;
//
//	return 0;
//}
//int main()
//{
//	long long int N, M;
//	cin >> N >> M;
//	vector<long long int> nums;
//	unordered_multiset<long long int> set;
//	long long int ans = 0;
//	for (long long int i = 0; i < N; i++)
//	{
//		long long int temp;
//		cin >> temp;
//		long long int twice = temp / M;
//		long long int triple = twice / M;
//		if (i < 2)
//		{
//			set.insert(temp);
//			continue;
//		}
//		else
//		{
//			if (set.count(twice) != 0 && set.count(triple) != 0)
//			{
//				ans += set.count(twice) * set.count(triple);
//				set.insert(temp);
//			}
//			else
//			{
//				set.insert(temp);
//			}
//		}
//	}
//	
//	cout << ans;
//	return 0;
//}


using namespace std;

// Complete the countTriplets function below.
//typedef long long ll;
//
//int main()
//{
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//
//    long n, r;
//    cin >> n >> r;
//
//    unordered_map<int, long> mp2, mp3;
//    //mp2 to hold count of needed values after this one to complete 
//    //2nd part of triplet
//    //mp3 to hold count of needed values to complete triplet
//
//    int val;
//    long long res = 0;
//    while (n--)
//    {
//        cin >> val;
//        if (mp3.count(val))        //This value completes mp3[val] triplets
//            res += mp3[val];
//        if (mp2.count(val))        //This value is valid as 2° part of mp2[val] triplets
//            mp3[val * r] += mp2[val];
//        mp2[val * r]++;            //"Push-up" this value as possible triplet start
//    }
//
//    cout << res << endl;
//
//    return 0;
//}
//




//int main() 
//{
//    int N, M;
//    cin >> N >> M;
//    vector<long long int> nums; 
//    for (long long int i = 0; i < N; i++)
//    {
//        long long int temp;
//        cin >> temp;
//        nums.push_back(temp);
//    }
//    
//    unordered_map<long long int, long long int> counter;
//    set<int> setOfNums (nums.begin(), nums.end());
//
//    for (long long int num : nums)
//    {
//        counter[num]++;
//    }
//
//    long long int ans = 0;
//
//    for (auto itr = setOfNums.begin(); itr != setOfNums.end(); itr++)
//    {
//        if (counter.find(*itr*M) != counter.end() && counter.find(*itr * M * M) != counter.end())
//        {
//            long long int tempAns = counter[*itr] * counter[*itr * M] * counter[*itr * M * M];
//            ans += tempAns;
//        }
//    }
//    cout << ans;
//    return 0;
//}
