#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int N;
vector<string> dictionary;
unordered_map<char, unordered_set<char>> Graph;
unordered_map<char, bool> Visited;
vector<char> ans;

void fillTheDict()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        dictionary.push_back(word);
        for (char t : word)
        {
            Graph[t];
        }
    }
}
void fillTheGraph()
{
    for (int i = 1; i < N; i++)
    {
        string word1 = dictionary[i - 1];
        string word2 = dictionary[i];

        int lenOfTheShortestWord = min(word1.length(), word2.length());
        for (int i = 0; i < lenOfTheShortestWord; i++)
        {
            if (word1[i] != word2[i])
            {
                Graph[word1[i]].insert(word2[i]);
                break;
            }
        }
    }
}
void DFS(char x)
{
    Visited[x] = true;
    for (char t : Graph[x])
    {
        if (Visited[t] == false)
        {
            DFS(t);
        }
    }
    ans.push_back(x);
}
void fillAns()
{
    for (auto el : Graph)
    {
        if (Visited[el.first] == false)
        {
            DFS(el.first);
        }
    }
}
void printAns()
{
    for (int i = ans.size() - 1; i >= 0; --i)
    {
        cout << ans[i] << " ";
    }
}
int main() 
{
    fillTheDict();
    fillTheGraph();
    fillAns();
    printAns();
    return 0;
}
