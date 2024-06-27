#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node* parent;

    Node(int value)
    {
        this->val = value;
        this->parent = nullptr;
    }
};

bool isTrue(Node* node, int parentValue)
{
    Node* temp = node;
    while (temp->parent != nullptr)
    {
        if (temp->parent->val == parentValue)
        {
            return true;
        }
        temp = temp->parent;
    }
    /*if (node->parent == nullptr)
    {
        return false;
    }

    if (node->parent->val == parentValue)
    {
        return true;
    }

    return isTrue(node->parent, parentValue);*/
    return false;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<Node*> arr(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int parent, kid;
        cin >> parent >> kid;

        if (i == 0)
        {
            arr[parent] = new Node(parent);
            arr[parent]->parent = nullptr;
            arr[kid] = new Node(kid);
            arr[kid]->parent = arr[parent];

        }
        
        arr[kid] = new Node(kid);
        arr[kid]->parent = arr[parent];
    }

    for (int i = N - 1; i > 0; --i)
    {
        cout << arr[i]->val << " " << arr[i]->parent->val << "\n";
    }
    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int first, second;
        cin >> first >> second;

        if (isTrue(arr[second],first))
        {
            cout<<"YES"<<"\n";
        }
        else
        {
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}
