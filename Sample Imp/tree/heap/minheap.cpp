#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
   private:
    vector<int> array;

    void heapify(int i);

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

   public:
    MinHeap() = default;
    void insert(int key);
    int extractMin();
    int getMin() const;
    void deleteKey(int i);
    void printHeap() const;
};

// Helper function to maintain the heap property
void MinHeap::heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int size = array.size();

    if (left < size && array[left] < array[smallest]) smallest = left;
    if (right < size && array[right] < array[smallest]) smallest = right;

    if (smallest != i) {
        swap(array[i], array[smallest]);
        heapify(smallest);
    }
}

void MinHeap::insert(int key) {
    this->array.push_back(key);
    int pos = array.size() - 1;

    // parrent (pos-1) /2
    while (pos != 0 && array[(pos - 1) / 2] > array[pos]) {
        swap(array[pos], array[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}

int MinHeap::extractMin() {
    if (array.empty()) throw underflow_error("Heapp underflow");
    if (array.size() == 1) {
        int tmp = array[0];
        array.pop_back();
        return tmp;
    }

    int res = array[0];

    // array[0] = array[array.size() - 1];
    array[0] = array.back();
    array.pop_back();
    heapify(0);
    return res;
}

int MinHeap::getMin() const {
    if (array.empty()) throw underflow_error("Heapp underflow");
    return array[0];
}

void MinHeap::deleteKey(int i) {
    if (i < 0 || i >= array.size()) {
        throw out_of_range("Invalid index");
    }

    array[i] = array.back();
    array.pop_back();
    heapify(i);
}

void MinHeap::printHeap() const {
    for (auto i : array) cout << i << " ";
    cout << endl;
}
