#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <iomanip>

using namespace std;
/*
// Wrote a working maxHeap implementation
// Just for practice, the actual question is solved using C++ priorityQueues (built in heap containers)

class Heap {
    private:
        vector <int> heap;
        int size;
        int capacity;
    public:
        // Constructor
        Heap(int capacity);
    
        // Helper functions
        void printHeap();
        void swap(int idx1, int idx2);
        bool hasParent(int index);
        bool hasLeftChild(int index);
        bool hasRightChild(int index);
        int getParentIndex(int index);
        int getLeftChildIndex(int index);
        int getRightChildIndex(int index);
        
        // Heap functions
        int peek();
        void add(int element);
        void poll();
        void heapifyUp();
        void heapifyDown();
        float getMedian();
};

Heap::Heap(int length)
{
    capacity = length;
    size = 0;
    heap.resize(capacity);
}

void Heap::printHeap()
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void Heap::swap(int aIdx, int bIdx)
{
    int temp = heap[aIdx];
    heap[aIdx] = heap[bIdx];
    heap[bIdx] = temp;
}

bool Heap::hasParent(int index)
{
    int parent = (index - 1) / 2;
    return (parent >= 0 && parent <= size);
}

bool Heap::hasLeftChild(int index)
{
    int left_child = index*2 + 1;
    return (left_child >= 0 && left_child <= size);
}

bool Heap::hasRightChild(int index)
{
    int right_child = index*2 + 2;
    return (right_child >= 0 && right_child <= size);
}

int Heap::getParentIndex(int index)
{
    return ((index - 1) / 2);
}

int Heap::getLeftChildIndex(int index)
{
    int output = 2*index + 1;
    if (output >= size)
        return -1;
    return output;
}

int Heap::getRightChildIndex(int index)
{
    int output = 2*index + 2;
    if (output >= size)
        return -1;
    return output;
}

int Heap::peek()
{
    if (size != 0)
        return heap[0];
    return -1;
}

void Heap::add(int element)
{
    if (size == capacity)
        heap.resize(capacity*2);
    
    heap[size] = element;
    size++;
    heapifyUp();
}

void Heap::poll()
{
    if (size > 0)
    {
        swap(0, size - 1);
        heap.erase(heap.end());
        size--;
        heapifyDown();
    }
}

void Heap::heapifyUp()
{
    int index = size - 1;
    while (hasParent(index) && heap[getParentIndex(index)] > heap[index])
    {
        swap(getParentIndex(index), index);
    }
}

void Heap::heapifyDown()
{
    int index = 0;
    int element = heap[0];
    while (hasLeftChild(index) && heap[getLeftChildIndex(index) < heap[index]])
    {
        int smallestChildIndex = getLeftChildIndex(index);
        if (hasRightChild(index) && heap[getRightChildIndex(index)] < heap[getLeftChildIndex(index)])
            smallestChildIndex = getRightChildIndex(index);
        swap(smallestChildIndex, index);
    }
}

float Heap::getMedian()
{
    if (size == 0)
        return 0;
    else
    {
        int middle_idx = size / 2;
        if (size % 2 == 0)
            return (heap[middle_idx] + heap[middle_idx - 1]) / 2.0;
        return heap[middle_idx];
    }
}
*/


// Print maxHeap values
void print_maxHeap(priority_queue <int> maxHeap)
{
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}

// Print minHeap values
void print_minHeap(priority_queue <int, vector<int>, greater<int> > minHeap)
{
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

// Rebalances the heaps in order to keep lower half of values in maxHeap, and higher half of values in minHeap
void rebalanceHeaps(priority_queue <float> &maxHeap, priority_queue <float, vector<float>, greater<float> > &minHeap)
{
    if (!maxHeap.empty() && !minHeap.empty() && minHeap.top() < maxHeap.top())
    {
        // Top of the minHeap
        int minHeapVal = minHeap.top();
        minHeap.pop();
        
        // Top of the maxHeap
        int maxHeapVal = maxHeap.top();
        maxHeap.pop();
        
        // Swap
        minHeap.push(maxHeapVal);
        maxHeap.push(minHeapVal);
    }
}

int main(){
    int n;
    cin >> n;
    
    priority_queue <float> maxHeap;
    priority_queue <float, vector<float>, greater<float> > minHeap;

    for(int a_i = 0;a_i < n;a_i++)
    {
        // Read in input
        int value;
        cin >> value;
        
        // Add to respective heaps
        if (maxHeap.size() <= minHeap.size())
            maxHeap.push(value);
        else
            minHeap.push(value);
        
        // Rebalance the heap to maintain the property (top(minHeap) > top(maxHeap))
        rebalanceHeaps(maxHeap, minHeap);
        
        // Output Median
        if ((minHeap.size() + maxHeap.size()) % 2 == 0)
            cout << fixed << setprecision(1) << ((maxHeap.top() + minHeap.top()) / 2.0) << endl;
        else
            cout << fixed << setprecision(1) << maxHeap.top() << endl;
    }
    return 0;
}