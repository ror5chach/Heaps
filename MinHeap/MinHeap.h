#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
	vector<int> data;
	void BubbleDown(int index);
	void BubbleUp(int index);
	void Heapify();

public:
	MinHeap() {}
	MinHeap(const vector<int>& vvector);
	~MinHeap() {}

	void Insert(int newValue);
	int GetMin();
	void DeleteMin();
};
