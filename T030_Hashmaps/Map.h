#include <string>
using namespace std;

template <typename V>
class Map;

template <typename K, typename V>
class MapNode
{
    K key;
    V value;
    MapNode *next;

    friend class Map<V>;

public:
    MapNode(K key, V value) : key(key), value(value), next(NULL) {}
    MapNode(K key, V value, MapNode *next) : key(key), value(value), next(next) {}

    static void destroy(MapNode *head)
    {
        if (head == NULL)
            return;

        destroy(head->next);
        delete head;
    }
};

template <typename V>
class Map
{
    MapNode<string, V> **bucket;
    int count;
    int numBuckets;
    double loadFactor;
    double maxLoadFactor;

    void setInitials(int numBuckets = 5)
    {
        this->count = 0;
        this->numBuckets = numBuckets;
        this->loadFactor = 0;
        this->maxLoadFactor = 0.7;

        this->bucket = new MapNode<string, V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
            this->bucket[i] = NULL;
    }

    int getBucketIndexHash(string const &key) const
    {
        int n = key.size();
        int hash = 0;

        for (int i = 0; i < n; i++)
        {
            hash = (hash * 10) % this->numBuckets;
            hash = (hash + key[i]) % this->numBuckets;
        }

        return hash % this->numBuckets;
    }

    void updateLoadFactor()
    {
        this->loadFactor = (double)this->count / this->numBuckets;
    }

    void rehash()
    {
        MapNode<string, V> **tmp = this->bucket;
        this->bucket = new MapNode<string, V> *[2 * numBuckets];

        int oldBuckets = this->numBuckets;
        this->count = 0;
        this->numBuckets *= 2;

        for (int i = 0; i < oldBuckets; i++)
        {
            MapNode<string, V> *head = tmp[i];
            while (head != NULL)
            {
                this->insert(head->key, head->value);
                head = head->next;
            }
        }

        this->updateLoadFactor();
    }

public:
    Map() { this->setInitials(); }
    Map(int n) { this->setInitials(n); }

    int size() const { return this->count; }
    double getLoadFactor() const { return this->loadFactor; }

    V getValue(string const &key) const
    {
        int index = this->getBucketIndexHash(key);
        MapNode<string, V> *head = this->bucket[index];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }

        return 0;
    }

    void insert(string const &key, V const &value)
    {
        int index = this->getBucketIndexHash(key);
        MapNode<string, V> *head = this->bucket[index];

        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = this->bucket[index];
        MapNode<string, V> *newNode = new MapNode<string, V>(key, value, head);
        this->bucket[index] = newNode;
        count++;

        this->updateLoadFactor();
        if (this->loadFactor > this->maxLoadFactor)
            rehash();
    }

    V remove(string const &key)
    {
        int index = this->getBucketIndexHash(key);
        MapNode<string, V> *head = this->bucket[index];
        MapNode<string, V> *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                    this->bucket[index] = head->next;
                else
                    prev->next = head->next;
                V value = head->value;
                delete head;
                count--;
                this->updateLoadFactor();
                return value;
            }
            prev = head;
            head = head->next;
        }

        return 0;
    }

    void destroy()
    {
        for (int i = 0; i < this->numBuckets; i++)
        {
            MapNode<string, V> *head = this->bucket[i];
            head->destroy(head);
        }

        delete[] this->bucket;
    }
};