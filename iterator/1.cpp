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
//Lớp Iterator đại diện cho một lớp duyệt các phần tử trong tập hợp
class collection
{
public:
    virtual Iterator *createIterator() = 0;
    virtual void add(int value) = 0;
    virtual int size() const = 0;
    virtual int at(int index) const = 0;
};
//Lớp collection đại diện cho một tập hợp các phần tử
class ConcreteIterator : public Iterator
{
private:
    collection *m_collection;
    int m_current;

public:
    ConcreteIterator(collection *collection) : m_collection(collection), m_current(0) {}
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
        return m_current >= m_collection->size();
    }
    int currentItem() const override
    {
        return m_collection->at(m_current);
    }
};

class ConcreteCollection : public collection
{
private:
    vector<int> m_data;

public:
    Iterator *createIterator() override
    {
        return new ConcreteIterator(this);
    }
    void add(int value) override
    {
        m_data.push_back(value);
    }
    int size() const override
    {
        return m_data.size();
    }
    int at(int index) const override
    {
        return m_data.at(index);
    }
};
//Lớp ConcreteIterator và ConcreteCollection là các lớp cụ thể thực hiện các phương thức của lớp Iterator và Collection.
int main()
{
    collection *collection = new ConcreteCollection();
    collection->add(1);
    collection->add(2);
    collection->add(3);
    Iterator *iterator = collection->createIterator();
    for (iterator->first(); !iterator->isDone(); iterator->next())
    {
        cout << iterator->currentItem() << endl;
    }
    delete iterator;
    delete collection;
    return 0;
}