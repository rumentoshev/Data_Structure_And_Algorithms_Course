#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    int score = 0;
    string name;
};
bool compare(Student x1, Student x2)
{
    return x1.score > x2.score || x1.score == x2.score && x1.name < x2.name;
}
int main() {
    
    int N;
    cin >> N;
    vector<Student> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].name;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].score;
    }
    
    std::sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].name << " " << arr[i].score << '\n';
    }
    return 0;
}