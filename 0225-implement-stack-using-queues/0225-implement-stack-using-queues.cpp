 class MyStack {
private:
    queue<int> q;
    
public:
    MyStack() {
    }

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

// Usage:
// MyStack* obj = new MyStack();
// obj->push(x);
// int param_2 = obj->pop();
// int param_3 = obj->top();
// bool param_4 = obj->empty();