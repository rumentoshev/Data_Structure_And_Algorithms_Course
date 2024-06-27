#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void enqueue(long long int* arr,int& front,int& rear,const int size,long long int x)
{
	if (front == -1 && rear == -1)
	{
		front = rear = 0;
	}
	else
	{
		rear = (rear + 1) % size;
	}
	arr[rear] = x;
}
void dequeue(long long int* arr, int& front, int& rear, const int size)
{
     if (front == rear)
	{
		rear = front = -1;
	}
	else
	{
		front = (front + 1) % size;
	}
}
int findMin(long long int* arr, int size)
{
	long long int min = 1000000002;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
int main() {
    int N, sizeOfGroup;
    cin >> N >> sizeOfGroup;
    long long int* arr = new long long int[sizeOfGroup];
	int front = -1;
	int rear = -1;
	int long long sum = 0;
	long long int firstMinEl;
	long long int lastMinEl;
	bool flag = false;
	for (int i = 0; i < N; ++i)
	{
		long long int temp;
		cin >> temp;
		if (i < sizeOfGroup)
		{
			enqueue(arr, front, rear, sizeOfGroup, temp);
		}
		else
		{
			if (i == sizeOfGroup)
			{
				firstMinEl = findMin(arr, sizeOfGroup);
				sum += firstMinEl;
				cout << firstMinEl << "\n";
				lastMinEl = firstMinEl;
				dequeue(arr, front, rear, sizeOfGroup);
				enqueue(arr, front, rear, sizeOfGroup, temp);
				lastMinEl = findMin(arr, sizeOfGroup);
				cout << lastMinEl << "\n";
				sum += lastMinEl;
				continue;
			}
			if (arr[front] == lastMinEl)
			{
				flag = true;
			}
			dequeue(arr, front, rear, sizeOfGroup);
			enqueue(arr, front, rear, sizeOfGroup, temp);
			if (flag == true)
			{
				lastMinEl = findMin(arr, sizeOfGroup);
				sum += lastMinEl;
				flag = false;
				continue;
			}
			if (lastMinEl <= temp)
			{
				cout << lastMinEl;
				sum += lastMinEl;
			}
			else 
			{
				lastMinEl = temp;
				sum += lastMinEl;
				cout << lastMinEl;
			}
		}
	}
	cout << sum;
    delete[] arr;

    return 0;
}