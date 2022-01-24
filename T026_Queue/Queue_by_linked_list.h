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
class QueueByLL
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueByLL()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    QueueByLL(QueueByLL const &q)
    {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;

        Node<T> *tmp = q.head;
        while (tmp != NULL)
        {
            this->enqueue(tmp->data);
            tmp = tmp->next;
        }
    }

    void operator=(QueueByLL const &q)
    {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;

        Node<T> *tmp = q.head;
        while (tmp != NULL)
        {
            this->enqueue(tmp->data);
            tmp = tmp->next;
        }
    }

    int getSize() const { return this->size; }
    bool isEmpty() const { return this->size == 0; }

    T front() const
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return this->head->data;
    }

    void enqueue(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (this->head == NULL)
            this->head = this->tail = newNode;
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void dequeue()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T> *tmp = this->head;
        this->head = this->head->next;
        this->size--;
        delete tmp;
        if (this->head == NULL)
            this->tail = NULL;
    }

    void destroy()
    {
        while (!this->isEmpty())
            this->dequeue();
    }
};