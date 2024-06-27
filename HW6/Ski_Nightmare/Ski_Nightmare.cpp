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
    Node* create(vector<infoForElement>& arr,Node* root, long long int x, long long int index)
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
    
    void printInorder(struct Node* node)
    {
        if (node == NULL)
            return;

        /* first recur on left child */
        printInorder(node->left);

        /* then print the data of node */
        cout << node->x << " ";

        /* now recur on right child */
        printInorder(node->right);
    }
    Node* get_root()
    {
        return root;
    }
    long long int left_Num(Node* root)
    {
        Node* temp = root;
        long long int size = 0;
        while (temp != nullptr)
        {
            size++;
            temp = temp->left;
        }
        return size;

    }

    long long int right_Num(Node* root)
    {
        Node* temp = root;
        long long int size = 0;
        while (temp != nullptr)
        {
            size++;
            temp = temp->right;
        }
        return size;
    }
};
void sumInorder(struct Node* node, vector<long long int>& arr, long long int middle)
{
    if (node == NULL)
        return;

    sumInorder(node->left, arr, middle);

    arr[middle + node->x] += node->value;

    sumInorder(node->right, arr, middle);
}
int main() {
    
    int N;
    cin >> N;
    vector<infoForElement> arr;
    for (int i = 0; i < N; i++)
    {
        long int new_element,index_of_left, index_of_right;
        cin >> new_element >> index_of_left >> index_of_right;
        infoForElement temp(new_element,index_of_left,index_of_right);
        arr.push_back(temp);
    }
    Tree tr;
    tr.root = tr.create(arr,tr.root,0, 0);
    tr.printInorder(tr.root);
    long long int num_of_lines = tr.left_Num(tr.get_root()) + tr.right_Num(tr.get_root()) - 1;
    vector<long long int> sums(num_of_lines, 0);
    long long int middle = tr.left_Num(tr.get_root()) - 1;
    sumInorder(tr.get_root(), sums, middle);
    for (int i = 0; i < num_of_lines; i++)
    {
        if (sums[i] != 0)
        {
            cout << sums[i] << " ";
        }
    }

    return 0;
}
