using namespace std;

template <typename T>
class StackByDynamicArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackByDynamicArray()
    {
        this->data = new T[4];
        this->nextIndex = 0;
        this->capacity = 4;
    }

    StackByDynamicArray(StackByDynamicArray const &st)
    {
        this->data = new T[st.capacity];
        this->nextIndex = st.nextIndex;
        this->capacity = st.capacity;

        for (int i = 0; i < this->capacity; i++)
            this->data[i] = st.data[i];
    }

    void operator=(StackByDynamicArray const &st)
    {
        this->data = new T[st.capacity];
        this->nextIndex = st.nextIndex;
        this->capacity = st.capacity;

        for (int i = 0; i < this->capacity; i++)
            this->data[i] = st.data[i];
    }

    int size() const { return this->nextIndex; }
    bool isEmpty() const { return this->nextIndex == 0; }

    T top() const
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return this->data[this->nextIndex - 1];
    }

    void push(T val)
    {
        if (this->nextIndex == this->capacity)
        {
            T *newData = new T[2 * this->capacity];
            for (int i = 0; i < this->capacity; i++)
                newData[i] = this->data[i];
            delete[] this->data;
            this->data = newData;
            this->capacity *= 2;
        }
        this->data[this->nextIndex++] = val;
    }

    void pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        this->nextIndex--;
    }

    void destroy() { delete[] this->data; }
};