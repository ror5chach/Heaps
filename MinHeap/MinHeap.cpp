#include  "MinHeap.h"


MinHeap::MinHeap(const vector<int>& vvector) : data(vvector)
{
	Heapify();
}

void MinHeap::Heapify()
{
	for (int i = data.size() - 1; i >= 0; --i)
		BubbleDown(i);
}

void MinHeap::BubbleDown(int index)
{
	int length = data.size();
	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;

	if (leftChildIndex >= length)
		return;						// this is already a leaf node

	// find the smallest among, node and left/right children
	int minIndex = index;
	if (data[index] > data[leftChildIndex])
		minIndex = leftChildIndex;

	if ((rightChildIndex < length) && (data[minIndex] > data[rightChildIndex]))
		minIndex = rightChildIndex;

	if (minIndex != index)
	{
		// swap this value with minIndex value and bubble it down to correct value
		data[index] = data[index] ^ data[minIndex];
		data[minIndex] = data[index] ^ data[minIndex];;
		data[index] = data[index] ^ data[minIndex];
		BubbleDown(minIndex);
	}
}

void MinHeap::BubbleUp(int index)
{
	if (index == 0)
		return;

	int parentIndex = (index - 1) / 2;

	if (data[parentIndex] > data[index])
	{
		// swap with parentIndex
		data[index] = data[index] ^ data[parentIndex];
		data[parentIndex] = data[index] ^ data[parentIndex];
		data[index] = data[index] ^ data[parentIndex];
		BubbleUp(parentIndex);
	}
}

void MinHeap::Insert(int newValue)
{
	data.push_back(newValue);
	BubbleUp(data.size()-1);
}

int MinHeap::GetMin()
{
	return data[0];
}

void MinHeap::DeleteMin()
{
	if (data.size() == 0)
		return;

	// move last element to first element and remove the last element
	data[0] = data[data.size() - 1];
	data.pop_back();

	// now bubble down the first element, since it was moved here from last place
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

	MinHeap minHeap(input);

	int k = 5;
	//find the kth smallest
	// remove the k-1 smallest first
	for (int i = 0; i < k-1; ++i)
		minHeap.DeleteMin();

	// get the kth smallest at GetMin()
	cout << minHeap.GetMin() << endl;

	return 0;

}
