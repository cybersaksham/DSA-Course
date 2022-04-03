#include <vector>
using namespace std;

class MinPQueue {
    vector<int> data;

    void upHeapify(int childIndex) {
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if(this->data[parentIndex] > this->data[childIndex]) {
                int tmp = this->data[parentIndex];
                this->data[parentIndex] = this->data[childIndex];
                this->data[childIndex] = tmp;
            }
            else break;
            childIndex = parentIndex;
        }
    }

    void downHeapify(int parentIndex) {
        while(parentIndex >=0 && parentIndex < this->size()) {
            int minIndex = parentIndex;
            int leftChildIndex = parentIndex * 2 + 1;
            int rightChildIndex = parentIndex * 2 + 2;

            if(leftChildIndex < this->size() && this->data[leftChildIndex] < this->data[minIndex]) minIndex = leftChildIndex;
            if(rightChildIndex < this->size() && this->data[rightChildIndex] < this->data[minIndex]) minIndex = rightChildIndex;

            if(minIndex == parentIndex) break;

            int tmp = this->data[parentIndex];
            this->data[parentIndex] = this->data[minIndex];
            this->data[minIndex] = tmp;

            parentIndex = minIndex;
        }
    }

public:
    MinPQueue() {}

    // Get Size
    int size() const { return this->data.size(); }

    // Check Empty
    bool empty() const { return this->size() == 0; }

    // Minimum Priority Element
    int top() const {
        if(this->empty()) return 0;
        return this->data[0];
    }

    // Push New Element
    void push(int val) {
        this->data.push_back(val);
        this->upHeapify(this->size() - 1);
    }

    // Pop New Element
    void pop() {
        if(this->empty()) return;
        this->data[0] = this->data[this->size() - 1];
        this->data.pop_back();
        this->downHeapify(0);
    }
};