using namespace std;

template <typename T>
class StackByArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackByArray(int size)
    {
        if (size <= 0)
            throw invalid_argument("Size must be grater than zero");
        this->data = new T[size];
        this->nextIndex = 0;
        this->capacity = size;
    }

    StackByArray(StackByArray const &st)
    {
        this->data = new T[st.capacity];
        this->nextIndex = st.nextIndex;
        this->capacity = st.capacity;

        for (int i = 0; i < this->capacity; i++)
            this->data[i] = st.data[i];
    }

    void operator=(StackByArray const &st)
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
            cout << "Stack is full" << endl;
            return;
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