class MyQueue
{
    stack<int> in, out;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        temp();
        int x = out.top();
        out.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        temp();
        return out.top();
    }

    void temp()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */