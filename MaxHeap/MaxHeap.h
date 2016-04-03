#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
	vector<int> data;
	void BubbleDown(int index);
	void BubbleUp(int index);
	void Heapify();

public:
	MaxHeap() {}
	MaxHeap(const vector<int>& vvector);
	~MaxHeap() {}

	void Insert(int newValue);
	int GetMax();
	void DeleteMax();
};