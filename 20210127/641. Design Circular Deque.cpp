class MyCircularDeque
{
    struct Node
    {
        int value;
        Node *next;
        Node *front;
    };
    int num;
    int maxnum;
    Node *head;
    Node *tail;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        maxnum = k;
        num = 0;
        head = nullptr;
        tail = nullptr;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }
        Node *p = new Node;
        p->value = value;
        p->next = head;
        if (num == 0)
        {
            tail = p;
        }
        else
        {
            head->front = p;
        }
        head = p;
        p->front = nullptr;
        num++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }
        Node *p = new Node;
        p->value = value;
        p->front = tail;

        if (num == 0)
        {
            head = p;
        }
        else
        {
            tail->next = p;
        }
        tail = p;
        p->next = nullptr;
        num++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (num == 0)
        {
            return false;
        }
        else
        {
            Node *p = head;
            head = head->next;
            if (head != nullptr)
            {
                head->front = nullptr;
            }
            if (num == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            delete p;
            num--;
            return true;
        }
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (num == 0)
        {
            return false;
        }
        else
        {
            Node *p = tail;
            tail = tail->front;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            if (num == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            delete p;
            num--;
            return true;
        }
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (num == 0)
        {
            return -1;
        }
        else
        {
            return head->value;
        }
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (num == 0)
        {
            return -1;
        }
        else
        {
            return tail->value;
        }
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        if (num == 0)
            return true;
        else
            return false;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        if (num == maxnum)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

/*Note:
动态分配的内存注意回收
在回收之后，任何指向原动态分配内存的指针都应该被清空
*/