#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    unordered_map < string, set<string>> system;
    string pathToCurrLocation = "/";

    for (int i = 0; i < N; ++i)
    {
        string t;
        getline(cin, t);
        
        if (t[0] == 'p')
        {
            cout << pathToCurrLocation << "\n";
        }
        else if(t[0] == 'l')
        {
            for (auto dir : system[pathToCurrLocation])
            {
                cout << dir << " ";
            }
            cout << "\n";
        }
        else if (t[0] == 'm')
        {
            t.erase(0, 6);
            if (system[pathToCurrLocation].find(t) == system[pathToCurrLocation].end())
            {
                system[pathToCurrLocation].insert(t);
            }
            else
            {
                cout << "Directory already exists\n";
            }
        }
        else if (t[0] == 'c')
        {
            t.erase(0, 3);
            if (t == "..")
            {
                if (pathToCurrLocation == "/")
                {
                    cout << "No such directory\n";
                }
                else
                {
                    pathToCurrLocation.pop_back();
                    while (pathToCurrLocation.back() != '/')
                    {
                        pathToCurrLocation.pop_back();
                    }
                }
            }
            else
            {
                if (system[pathToCurrLocation].find(t) != system[pathToCurrLocation].end())
                {
                    pathToCurrLocation.append(t);
                    pathToCurrLocation.append("/");
                }
                else
                {
                    cout << "No such directory\n";
                }
            }
        }
    }
    return 0;
}

//int main() {
//
//    int N;
//    cin >> N;
//    cin.ignore();
//    unordered_map<string,set<string>> system;
//    string path = "/";
//    vector<string> Path;
//    string currentDirectory = "/";
//    Path.push_back(currentDirectory);
//    pair<string,set<string>> current;
//    current.first = path;
//    system.insert(current);
// 
//    for (int i = 0; i <N; ++i)
//    {
//        string x;
//        getline(cin, x);
//        if (x[0] == 'l')
//        {
//            for (auto s : current.second)
//            {
//                cout << s << " ";
//            }
//            cout << "\n";
//        }
//        else if (x[0] == 'c')
//        {
//            x.erase(0, 3);
//            if (x == "..")
//            {
//                if (path == "/")
//                {
//                    cout << "No such directory\n";
//                    continue;
//                }
//                else
//                {
//                    for (int i = 0; i < currentDirectory.size(); i++)
//                    {
//                        path.pop_back();
//                    }
//
//                    current.first = currentDirectory;
//                    current.second = system[path];
//                    Path.pop_back();
//                    currentDirectory = Path.back();
//                    
//                    continue;
//                }
//            }
//            if (current.second.find(x) != current.second.end())
//            {
//                path.append(x);
//                path.append("/");
//                currentDirectory = x + "/";
//                Path.push_back(currentDirectory);
//                current.first = path;
//                current.second.clear();
//                system.insert(current);
//            }
//            else
//            {
//                cout << "No such directory\n";
//            }
//        }
//        else if (x[0] == 'p')
//        {
//            cout << path << "\n";
//        }
//        else if (x[0] == 'm')
//        {
//            x.erase(0, 6);
//            if (current.second.find(x) == current.second.end())
//            {
//                current.second.insert(x);
//                system[current.first] = current.second;
//            }
//            else
//            {
//                cout << "Directory already exists\n";
//            }
//        }
//
//    }
//    return 0;
//}