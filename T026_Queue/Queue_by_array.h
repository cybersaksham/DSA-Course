using namespace std;

template <typename T>
class QueueByArray
{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

    void copyInNew(QueueByArray const &q, int finalCapacity)
    {
        if (finalCapacity < q.capacity)
            finalCapacity = 2 * q.capacity;

        T *tmp = new T[finalCapacity];

        int j = 0;
        for (int i = q.firstIndex; i < q.capacity; i++)
            tmp[j++] = q->data[i];
        for (int i = 0; i < q.firstIndex; i++)
            tmp[j++] = q->data[i];

        delete[] this->data;
        this->data = tmp;
        this->reset();
        this->size = q.size;
        this->capacity = finalCapacity;
    }

    void reset()
    {
        this->firstIndex = -1;
        this->nextIndex = 0;
    }

public:
    QueueByArray(int size)
    {
        if (size <= 0)
            throw invalid_argument("Size must be grater than zero");
        this->data = new T[size];
        this->firstIndex = -1;
        this->nextIndex = 0;
        this->size = 0;
        this->capacity = size;
    }

    QueueByArray(QueueByArray const &q) { this->copyInNew(q, q.capacity); }

    void operator=(QueueByArray const &q) { this->copyInNew(q, q.capacity); }

    int getSize() const { return this->size; }
    bool isEmpty() const { return this->size == 0; }

    T front() const
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return this->data[this->firstIndex];
    }

    void enqueue(T val)
    {
        if (this->size == this->capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }
        this->data[this->nextIndex] = val;
        this->nextIndex = (this->nextIndex + 1) % this->capacity;
        this->firstIndex = this->firstIndex == -1 ? 0 : this->firstIndex;
        this->size++;
    }

    void dequeue()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        this->firstIndex = (this->firstIndex + 1) % this->capacity;
        this->size--;
        if (this->isEmpty())
            this->reset();
    }

    void destroy() { delete[] this->data; }
};