#include "MaxHeap.h"

MaxHeap::MaxHeap(const vector<int>& vvector) : data(vvector)
{
	Heapify();
}

void MaxHeap::Heapify()
{
	for (int i = data.size(); i >= 0; --i)
		BubbleDown(i);
}

void MaxHeap::BubbleDown(int index)
{
	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;

	if (leftChildIndex >= (int)data.size())
		return;				// this is a leaf node

	int maxIndex = index;

	//find the largest among this node and left/right child nodes
	if (data[index] < data[leftChildIndex])
		maxIndex = leftChildIndex;

	if ((rightChildIndex < (int)data.size()) && (data[maxIndex] < data[rightChildIndex]))
		maxIndex = rightChildIndex;

	if (maxIndex != index)
	{
		// swap with the maxIndex and bubble it down to correct location
		data[index] = data[index] ^ data[maxIndex];
		data[maxIndex] = data[index] ^ data[maxIndex];
		data[index] = data[index] ^ data[maxIndex];
		BubbleDown(maxIndex);
	}
}

void MaxHeap::BubbleUp(int index)
{
	if (index == 0)
		return;

	int parentIndex = (index - 1) / 2;

	if (data[parentIndex] < data[index])
	{
		// swap with parentIndex
		data[index] = data[index] ^ data[parentIndex];
		data[parentIndex] = data[index] ^ data[parentIndex];
		data[index] = data[index] ^ data[parentIndex];
		BubbleUp(parentIndex);
	}
}

void MaxHeap::Insert(int newValue)
{
	data.push_back(newValue);
	BubbleUp(data.size()-1);
}

int MaxHeap::GetMax()
{
	return data[0];
}

void MaxHeap::DeleteMax()
{
	if (data.size() == 0)
		return;

	// move last element to first element and remove the last element
	data[0] = data[data.size()-1];
	data.pop_back();
	
	// now bubble it down to its correct location
	BubbleDown(0);
}

int main()
{
	vector<int> input;
	input.push_back(20);
	input.push_back(30);
	input.push_back(10);
	input.push_back(40);
	input.push_back(70);
	input.push_back(50);
	input.push_back(60);

	MaxHeap maxHeap(input);

	int k = 3;
	//find the kth smallest
	// remove the k-1 smallest first
	for (int i = 0; i < k-1; ++i)
		maxHeap.DeleteMax();

	// get the kth smallest at GetMin()
	cout << maxHeap.GetMax() << endl;

	return 0;

}