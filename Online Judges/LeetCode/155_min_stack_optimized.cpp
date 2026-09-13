#include <stack>

class MinStack {
    std::stack<long long> values;
    long long currentMin = 0;

public:
    void push(int value) {
        const long long value64 = value;

        if (values.empty()) {
            values.push(value64);
            currentMin = value64;
        } else if (value64 < currentMin) {
            // The encoded value marks a new minimum and preserves the old one.
            values.push(2 * value64 - currentMin);
            currentMin = value64;
        } else {
            values.push(value64);
        }
    }

    void pop() {
        const long long value = values.top();
        values.pop();

        if (value < currentMin) {
            currentMin = 2 * currentMin - value;
        }
    }

    int top() const {
        const long long value = values.top();
        return static_cast<int>(value < currentMin ? currentMin : value);
    }

    int getMin() const {
        return static_cast<int>(currentMin);
    }
};
