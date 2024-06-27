#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct infoForElement
{
    long int element;
    long int index_of_left;
    long int index_of_right;

    infoForElement(long int first, long int second, long int third)
    {
        this->element = first;
        this->index_of_left = second;
        this->index_of_right = third;
    }

};
struct Node
{
    int value;
    int x;
    Node* left;
    Node* right;

    Node(int value, int x)
    {
        this->value = value;
        this->x = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree {
public:
    Node* root;
    Tree()
    {
        root = nullptr;
    }
    Node* create(vector<infoForElement>& arr, Node* root, long long int x, long long int index)
    {
        root = new Node(arr[index].element, x);
        if (arr[index].index_of_left != -1)
        {
            root->left = create(arr, root->left, x - 1, arr[index].index_of_left);
        }
        else
        {
            root->left = nullptr;
        }
        if (arr[index].index_of_right != -1)
        {
            root->right = create(arr, root->right, x + 1, arr[index].index_of_right);
        }
        else
        {
            root->right = nullptr;
        }

        return root;
    }


    Node* get_root()
    {
        return root;
    }

};


bool validate(Node* root, long int min, long int max)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->value <= min || root->value >= max) return false;

    return validate(root->left, min, root->value) && validate(root->right, root->value, max);
}
bool isValidBST(Node* root)
{
    long int min = -2147483647;
    long int max = 2147483647;
    return validate(root, min, max);
}


int main() {

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<infoForElement> arr;
        for (int i = 0; i < N; i++)
        {
            long int new_element, index_of_left, index_of_right;
            cin >> new_element >> index_of_left >> index_of_right;
            infoForElement temp(new_element, index_of_left, index_of_right);
            arr.push_back(temp);
        }
        Tree tr;
        tr.root = tr.create(arr, tr.get_root(), 0, 0);
        if (isValidBST(tr.get_root()))
        {
            cout << "1" << "\n";
        }
        else
        {
            cout << "0" << "\n";
        }


    }

    return 0;
}