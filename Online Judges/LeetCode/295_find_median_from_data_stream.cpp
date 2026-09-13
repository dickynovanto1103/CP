#include <cassert>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
    MedianFinder() = default;

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        rebalance();
    }

    double findMedian() {
        assert(!maxHeap.empty());

        if (maxHeap.size() > minHeap.size()) {
            return static_cast<double>(maxHeap.top());
        }

        return (static_cast<double>(maxHeap.top()) + minHeap.top()) / 2.0;
    }

private:
    // maxHeap stores the lower half; minHeap stores the upper half.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void rebalance() {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        assert(maxHeap.size() >= minHeap.size());
        assert(maxHeap.size() - minHeap.size() <= 1);
    }
};
