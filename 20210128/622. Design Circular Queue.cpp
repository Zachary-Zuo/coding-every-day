class MyCircularQueue
{
    int *vec;
    int head = 0;
    int tail = 1;
    int len = 0;
    int size = 0;

public:
    MyCircularQueue(int k)
    {
        vec = new int[k];
        head = 0;
        tail = 0;
        len = k;
    }

    bool enQueue(int value)
    {
        if (!isFull())
        {
            vec[tail] = value;
            tail++;
            tail = tail % len;
            size++;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool deQueue()
    {
        if (!isEmpty())
        {
            head++;
            size--;
            if (head == len)
                head = 0;
            return true;
        }
        else
        {
            return false;
        }
    }

    int Front()
    {
        if (!isEmpty())
        {
            return vec[head];
        }
        else
        {
            return -1;
        }
    }

    int Rear()
    {
        if (!isEmpty())
        {
            int t = tail - 1;
            if (t < 0)
                t += len;
            return vec[t];
        }
        else
        {
            return -1;
        }
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (size == len)
            return true;
        else
            return false;
    }
};