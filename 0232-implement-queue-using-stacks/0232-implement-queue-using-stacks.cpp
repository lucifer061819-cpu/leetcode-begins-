class MyQueue {
    stack<int> s1, s2;

    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        transfer();
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        transfer();
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};