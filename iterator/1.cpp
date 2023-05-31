// Truy cập nội dung của đối tượng trong tập hợp mà không cần biết nội dung bên trong nó.
#include <iostream>
#include <vector>
using namespace std;

class Iterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual int currentItem() const = 0;
};

class Collection
{
public:
    virtual Iterator *createIterator() = 0;
    virtual void add(int value) = 0;
};

class ConcreteIterator : public Iterator
{
private:
    vector<int> *m_data;
    int m_current;

public:
    ConcreteIterator(vector<int> *data) : m_data(data), m_current(0) {}
    void first() override
    {
        m_current = 0;
    }
    void next() override
    {
        ++m_current;
    }
    bool isDone() const override
    {
        return m_current >= m_data->size();
    }
    int currentItem() const override
    {
        return m_data->at(m_current);
    }
};

class ConcreteCollection : public Collection
{
private:
    vector<int> m_data;

public:
    Iterator *createIterator() override
    {
        return new ConcreteIterator(&m_data);
    }
    void add(int value)
    {
        m_data.push_back(value);
    }
};
//Lớp ConcreteIterator truy cập nội dung của đối tượng trong tập hợp thông qua con trỏ m_data, mà không cần biết nội dung bên trong của đối tượng.
int main()
{
    Collection *Collection = new ConcreteCollection();
    Collection->add(1);
    Collection->add(2);
    Collection->add(3);
    Iterator *iterator = Collection->createIterator();
    for (iterator->first(); !iterator->isDone(); iterator->next())
    {
        cout << iterator->currentItem() << endl;
    }
    delete iterator;
    delete Collection;
    return 0;
}