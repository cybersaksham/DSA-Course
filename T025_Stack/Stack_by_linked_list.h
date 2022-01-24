using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data) : data(data), next(NULL) {}
    Node(T data, Node *next) : data(data), next(next) {}
};

template <typename T>
class StackByLL
{
    Node<T> *head;
    int size;

public:
    StackByLL()
    {
        this->head = NULL;
        this->size = 0;
    }

    StackByLL(StackByLL const &st)
    {
        this->size = 0;
        this->head = NULL;

        Node<T> *tmp = st.head;

        StackByLL<T> newSt;
        while (tmp != NULL)
        {
            newSt.push(tmp->data);
            tmp = tmp->next;
        }

        while (!newSt.isEmpty())
        {
            this->push(newSt.top());
            newSt.pop();
        }
    }

    void operator=(StackByLL const &st)
    {
        this->size = 0;
        this->head = NULL;

        Node<T> *tmp = st.head;

        StackByLL<T> newSt;
        while (tmp != NULL)
        {
            newSt.push(tmp->data);
            tmp = tmp->next;
        }

        while (!newSt.isEmpty())
        {
            this->push(newSt.top());
            newSt.pop();
        }
    }

    int getSize() const { return this->size; }
    bool isEmpty() const { return this->size == 0; }

    T top() const
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return this->head->data;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val, this->head);
        this->head = newNode;
        this->size++;
    }

    void pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node<T> *tmp = this->head;
        this->head = this->head->next;
        this->size--;
        delete tmp;
    }

    void destroy()
    {
        while (!this->isEmpty())
            this->pop();
    }
};