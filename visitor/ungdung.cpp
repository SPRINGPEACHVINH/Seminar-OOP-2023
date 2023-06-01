/*
Sử dụng Visitor pattern để thực hiện các thao tác trên một cấu trúc đối tượng phức tạp,
trong đó các đối tượng có các giao diện khác nhau và ta muốn thực hiện các thao tác trên chúng
mà không làm hỏng các lớp đối tượng.
*/
#include <bits/stdc++.h>
using namespace std;

class Circle;
class Rectangle;
class Triangle;

class Visitor
{
public:
    virtual void visit(Circle &) = 0;
    virtual void visit(Rectangle &) = 0;
    virtual void visit(Triangle &) = 0;
};

class Shape
{
public:
    virtual void accept(Visitor &) = 0;
};
//Các class con của shape
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius)
    {
        this->radius = radius;
    }
    double getradius()
    {
        return radius;
    }
    void accept(Visitor &v) override
    {
        v.visit(*this);
    }
};

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    int getwidth()
    {
        return width;
    }
    int getheight()
    {
        return height;
    }
    void accept(Visitor &v) override
    {
        v.visit(*this);
    }
};

class Triangle : public Shape
{
private:
    int base;
    int height;

public:
    Triangle(int base, int height)
    {
        this->base = base;
        this->height = height;
    }
    int getbase()
    {
        return base;
    }
    int getheight()
    {
        return height;
    }
    void accept(Visitor &v) override
    {
        v.visit(*this);
    }
};
//Định nghĩa 2 lớp visitor để tính chu vi và diện tích
class AreaVisitor : public Visitor
{
public:
    void visit(Circle &c) override
    {
        double area = 3.14 * c.getradius() * c.getradius();
        cout << "Area of circle: " << area << endl;
    }

    void visit(Rectangle &r) override
    {
        double area = r.getwidth() * r.getheight();
        cout << "Area of rectangle: " << area << endl;
    }

    void visit(Triangle &t) override
    {
        double area = 0.5 * t.getbase() * t.getheight();
        cout << "Area of triangle: " << area << endl;
    }
};

class PerimeterVisitor : public Visitor
{
public:
    void visit(Circle &c) override
    {
        double perimeter = 2 * 3.14 * c.getradius();
        cout << "Perimeter of circle: " << perimeter << endl;
    }

    void visit(Rectangle &r) override
    {
        double perimeter = 2 * (r.getwidth() + r.getheight());
        cout << "Perimeter of rectangle: " << perimeter << endl;
    }

    void visit(Triangle &t) override
    {
        double perimeter = t.getbase() + t.getheight() + sqrt(t.getbase() * t.getbase() + t.getheight() * t.getheight());
        cout << "Perimeter of triangle: " << perimeter << endl;
    }
};
int main()
{
    Circle c{2};
    Rectangle r{3, 4};
    Triangle t{3, 4};

    AreaVisitor areaVisitor;
    PerimeterVisitor perimeterVisitor;

    c.accept(areaVisitor);
    c.accept(perimeterVisitor);

    r.accept(areaVisitor);
    r.accept(perimeterVisitor);

    t.accept(areaVisitor);
    t.accept(perimeterVisitor);

    return 0;
}
/*Như vậy, thông qua việc sử dụng Visitor pattern, 
chúng ta đã thực hiện các thao tác tìm diện tích và chu vi trên các đối tượng trong cấu trúc đối tượng phức tạp
mà không cần thêm phương thức vào các lớp đối tượng hiện có, 
đồng thời giảm thiểu các ảnh hưởng đến các lớp đối tượng khi thêm các thao tác mới.*/