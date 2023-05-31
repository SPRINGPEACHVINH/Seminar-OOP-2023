//Cho phép có nhiều hơn một cách thức duyệt đối với một tập hợp tại một thời điểm. 

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

class collection
{
public:
    virtual Iterator *createIterator() = 0;
};

class ConcreteIterator : public Iterator
{
private:
    vector<int> *m_data;
    int m_current;
    int m_step;

public:
    ConcreteIterator(vector<int> *data, int step) : m_data(data), m_current(0), m_step(step) {}
    void first() override
    {
        m_current = 0;
    }
    void next() override
    {
        m_current += m_step;
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

class ConcreteCollection : public collection
{
private:
    vector<int> m_data;
    int m_step = 1;

public:
    Iterator *createIterator() override
    {
        return new ConcreteIterator(&m_data, m_step);
    }
    void add(int value)
    {
        m_data.push_back(value);
    }
    void setStep(int step)
    {
        m_step = step;
    }
};

int main()
{
    ConcreteCollection collection;
    collection.add(1);
    collection.add(2);
    collection.add(3);
    collection.add(4);
    collection.add(5);
    Iterator *iterator1 = collection.createIterator();
    for (iterator1->first(); !iterator1->isDone(); iterator1->next())
    {
        cout << iterator1->currentItem() << endl;
    }
    cout<<"----"<<'\n';
    collection.setStep(2);
    Iterator *iterator2 = collection.createIterator();
    for (iterator2->first(); !iterator2->isDone(); iterator2->next())
    {
        cout << iterator2->currentItem() << endl;
    }
    delete iterator1;
    delete iterator2;
    return 0;
}