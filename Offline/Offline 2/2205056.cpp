#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
class Rectangle
{
private:
    int length;
    int width;
    char *color;

public:
    Rectangle()
    {
        length = 0;
        width = 0;
        color = nullptr;
    }
    Rectangle(int length, int width, const char *color)
    {
        this->length = length;
        this->width = width;
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
    }
    Rectangle(const Rectangle &r)
    {
        length = r.length;
        width = r.width;
        if (r.color != nullptr)
        {
            color = (char *)malloc(sizeof(char) * (strlen(r.color) + 1));
            strcpy(color, r.color);
        }
        else
        {
            color = nullptr;
        }
    }
    Rectangle *clone()
    {
        Rectangle *Clone = new Rectangle(*this);
        return Clone;
    }
    ~Rectangle()
    {
        if (color != nullptr)
        {
            delete[] color;
        }
    }
    int getPerimeter()
    {
        return 2 * (length + width);
    }
    int getArea()
    {
        return length * width;
    }
    const char *getColor()
    {
        return color ? color : "";
    }
    void setColor(const char *color)
    {
        if (this->color != nullptr)
        {
            free(this->color);
        }
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
    }
    int getLength()
    {
        return length;
    }
    void setLength(int length)
    {
        this->length = length;
    }
    int getWidth()
    {
        return width;
    }
    void setWidth(int width)
    {
        this->width = width;
    }
};
class Triangle
{
private:
    int a;
    int b;
    int c;
    char *color;

public:
    Triangle()
    {
        a = 0;
        b = 0;
        c = 0;
        color = nullptr;
    }
    Triangle(int a, int b, int c, const char *color)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
    }
    Triangle(const Triangle &t)
    {
        a = t.a;
        b = t.b;
        c = t.c;
        if (t.color != nullptr)
        {
            color = (char *)malloc(sizeof(char) * (strlen(t.color) + 1));
            strcpy(color, t.color);
        }
        else
        {
            color = nullptr;
        }
    }
    Triangle *clone()
    {
        Triangle *Clone = new Triangle(*this);
        return Clone;
    }
    ~Triangle()
    {
        if (color != nullptr)
        {
            free(color);
        }
    }
    int getPerimeter()
    {
        return a + b + c;
    }
    double getArea()
    {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    int get_a()
    {
        return a;
    }
    void set_a(int a)
    {
        this->a = a;
    }
    int get_b()
    {
        return b;
    }
    void set_b(int b)
    {
        this->b = b;
    }
    int get_c()
    {
        return c;
    }
    void set_c(int c)
    {
        this->c = c;
    }
    const char *getColor()
    {
        return color ? color : "";
    }
    void setColor(const char *color)
    {
        if (this->color != nullptr)
        {
            free(this->color);
        }
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
    }
};
class Circle
{
private:
    int radius;
    char *color;

public:
    Circle()
    {
        radius = 0;
        color = nullptr;
    }
    Circle(int radius, const char *color)
    {
        this->radius = radius;
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
    }
    Circle(const Circle &c)
    {
        radius = c.radius;
        if (c.color != nullptr)
        {
            color = (char *)malloc(sizeof(char) * (strlen(c.color) + 1));
            strcpy(color, c.color);
        }
        else
        {
            color = nullptr;
        }
    }
    Circle *clone()
    {
        Circle *Clone = new Circle(*this);
        return Clone;
    }
    ~Circle()
    {
        if (color != nullptr)
        {
            free(color);
        }
    }
    double getPerimeter()
    {
        return 2 * 3.14 * radius;
    }
    double getArea()
    {
        return 3.14 * radius * radius;
    }
    const char *getColor()
    {
        return color ? color : "";
    }
    void setColor(const char *color)
    {
        if (this->color != nullptr)
        {
            free(this->color);
        }
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
    }
    int getRadius()
    {
        return radius;
    }
    void setRadius(int radius)
    {
        this->radius = radius;
    }
};
class ShapeCollection
{
private:
    Rectangle **Rectangles;
    Circle **Circles;
    Triangle **Triangles;

    int Rectangle_Count;
    int Rectangle_Capacity;
    int Triangle_Count;

    int Triangle_Capacity;
    int Circle_Count;
    int Circle_Capacity;

public:
    ShapeCollection()
    {
        Rectangles = new Rectangle *[1];
        Circles = new Circle *[1];
        Triangles = new Triangle *[1];

        Rectangle_Count = 0;
        Triangle_Count = 0;
        Circle_Count = 0;

        Rectangle_Capacity = 1;
        Triangle_Capacity = 1;
        Circle_Capacity = 1;
    }
    void add(Rectangle r)
    {
        if (Rectangle_Count >= Rectangle_Capacity)
        {
            cout << "Increasing capacity of Rectangles from " << Rectangle_Capacity << " to " << Rectangle_Capacity * 2 << endl;
            Rectangle **new_Rectangles = new Rectangle *[Rectangle_Capacity * 2];

            for (int i = 0; i < Rectangle_Capacity; i++)
            {
                new_Rectangles[i] = Rectangles[i]->clone();
            }
            for (int i = 0; i < Rectangle_Capacity; i++)
            {
                delete Rectangles[i];
            }
            delete[] Rectangles;
            Rectangles = new_Rectangles;
            Rectangle_Capacity *= 2;
        }
        Rectangles[Rectangle_Count++] = r.clone();
    }
    void add(Triangle t)
    {
        if (Triangle_Count >= Triangle_Capacity)
        {
            cout << "Increasing capacity of Triangles from " << Triangle_Capacity << " to " << Triangle_Capacity * 2 << endl;

            Triangle **new_Triangles = new Triangle *[Triangle_Capacity * 2];
            for (int i = 0; i < Triangle_Capacity; i++)
            {
                new_Triangles[i] = Triangles[i]->clone();
            }
            for (int i = 0; i < Triangle_Capacity; i++)
            {
                delete Triangles[i];
            }
            delete[] Triangles;
            Triangles = new_Triangles;
            Triangle_Capacity *= 2;
        }
        Triangles[Triangle_Count++] = t.clone();
    }
    void add(Circle c)
    {
        if (Circle_Count >= Circle_Capacity)
        {
            cout << "Increasing capacity of Circles from " << Circle_Capacity << " to " << Circle_Capacity * 2 << endl;
            Circle **new_Circles = new Circle *[Circle_Capacity * 2];

            for (int i = 0; i < Circle_Capacity; i++)
            {
                new_Circles[i] = Circles[i]->clone();
            }
            for (int i = 0; i < Circle_Capacity; i++)
            {
                delete Circles[i];
            }
            delete[] Circles;
            Circles = new_Circles;
            Circle_Capacity *= 2;
        }
        Circles[Circle_Count++] = c.clone();
    }
    int getRectCount()
    {
        return Rectangle_Count;
    }
    int getTriCount()
    {
        return Triangle_Count;
    }
    int getCircCount()
    {
        return Circle_Count;
    }
    void printRectangles()
    {
        for (int i = 0; i < Rectangle_Count; i++)
        {
            cout << "Rectangle " << i << ": ";
            cout << "length: " << Rectangles[i]->getLength() << " ";
            cout << "width: " << Rectangles[i]->getWidth() << endl;
        }
    }
    void printTriangles()
    {
        for (int i = 0; i < Triangle_Count; i++)
        {
            cout << "Triangle " << i << ": ";
            cout << "a: " << Triangles[i]->get_a() << " ";
            cout << "b: " << Triangles[i]->get_b() << " ";
            cout << "c: " << Triangles[i]->get_c() << endl;
        }
    }
    void printCircles()
    {
        for (int i = 0; i < Circle_Count; i++)
        {
            cout << "Circle " << i << ": ";
            cout << "radius: " << Circles[i]->getRadius() << endl;
        }
    }
};

int main()
{
    // Create rectangle with length, width, color
    Rectangle r1(10, 20, "Red");
    // The Color is stored using malloc, which will be freed during destruction
    cout << "Rectangle Perimeter: " << r1.getPerimeter() << endl;
    cout << "Rectangle Area: " << r1.getArea() << endl;
    cout << "Rectangle Color: " << r1.getColor() << endl;
    // When changing the color, you need to free the memory of the old color
    // and allocate new memory for the new color
    r1.setColor("Yellow");
    cout << "Rectangle Color: " << r1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    // Create triangle with a, b, c, color. (a, b, c are lengths of the sides)
    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    // Create circle with radius, color
    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    /*
    When constructing the ShapeCollection class, you will create dynamic for
    rectangles, triangles and circles. You have to dynamically allocate memory for this.
    */
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by value to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied. So, you have to write copy contructor so that
    memory allocation is properly done and no double free error occurs.
    */

    shapes.add(r1);
    shapes.add(t1);
    shapes.add(c1);

    Rectangle r2(15, 25, "Black");
    Rectangle r3(150, 225, "Green");
    shapes.add(r2);
    shapes.add(r3);
    Triangle t2(5, 12, 13, "White");
    shapes.add(t2);

    cout << endl;

    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;

    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();

    return 0;
}