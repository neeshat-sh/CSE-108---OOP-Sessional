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
    Rectangle() : length(0), width(0), color(nullptr) {}
    Rectangle(int length, int width, const char *color)
    {
        this->length = length;
        this->width = width;
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
    }
    ~Rectangle()
    {
        if (color != nullptr)
        {
            free(color);
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
    Triangle() : a(0), b(0), c(0), color(nullptr) {}
    Triangle(int a, int b, int c, const char *color)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
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
    Circle() : radius(0), color(nullptr) {}
    Circle(int radius, const char *color)
    {
        this->radius = radius;
        this->color = (char *)malloc(sizeof(char) * (strlen(color) + 1));
        if (this->color != nullptr)
            strcpy(this->color, color);
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
    static const int Max_SIZE = 100; //compile time constant because we need fixed-size arrays
    Rectangle Rectangles[Max_SIZE];
    Circle Circles[Max_SIZE];
    Triangle Triangles[Max_SIZE];
    int Rectangle_Count;
    int Triangle_Count;
    int Circle_Count;

public:
    ShapeCollection() : Rectangle_Count(0), Triangle_Count(0), Circle_Count(0) {}
    void addRectangle(Rectangle &r)
    {
        if (Rectangle_Count < Max_SIZE)
        {
            Rectangles[Rectangle_Count].setLength(r.getLength());
            Rectangles[Rectangle_Count].setWidth(r.getWidth());
            Rectangles[Rectangle_Count].setColor(r.getColor());
            Rectangle_Count++;
        }
        else
        {
            cout << "No more rectangles can be added" << endl;
        }
    }
    void addTriangle(Triangle &t)
    {
        if (Triangle_Count < Max_SIZE)
        {
            Triangles[Triangle_Count].set_a(t.get_a());
            Triangles[Triangle_Count].set_b(t.get_b());
            Triangles[Triangle_Count].set_c(t.get_c());
            Triangles[Triangle_Count].setColor(t.getColor());

            Triangle_Count++;
        }
        else
        {
            cout << "No more triangles can be added" << endl;
        }
    }
    void addCircle(Circle &c)
    {
        if (Circle_Count < Max_SIZE)
        {
            Circles[Circle_Count].setRadius(c.getRadius());
            Circles[Circle_Count].setColor(c.getColor());
            Circle_Count++;
        }
        else
        {
            cout << "No more Circles can be added" << endl;
        }
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
            cout << "length: " << Rectangles[i].getLength() << " ";
            cout << "width: " << Rectangles[i].getWidth() << endl;
        }
    }
    void printTriangles()
    {
        for (int i = 0; i < Triangle_Count; i++)
        {
            cout << "Triangle " << i << ": ";
            cout << "a: " << Triangles[i].get_a() << " ";
            cout << "b: " << Triangles[i].get_b() << " ";
            cout << "c: " << Triangles[i].get_c() << endl;
        }
    }
    void printCircles()
    {
        for (int i = 0; i < Circle_Count; i++)
        {
            cout << "Circle " << i << ": ";
            cout << "radius: " << Circles[i].getRadius() << endl;
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

    /// Create triangle with a, b, c, color. (a, b, c are lengths of the sides)
    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    /// Create circle with radius, color
    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    /*
    When constructing the ShapeCollection class, you will create static arrays for 100
    rectangles, triangles and circles. You don’t have to dynamically allocate memory for this.
    */
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by reference to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied, leading to double free errors when things go
    out of scope. Once passed by reference, do not directly store the reference in
    the array. Instead, copy the data from the reference to the array element.
    We will see better ways to handle this in the upcoming sessions.
    */
    shapes.addRectangle(r1);
    shapes.addTriangle(t1);
    shapes.addCircle(c1);

    Rectangle r2(15, 25, "Black");
    shapes.addRectangle(r2);
    Triangle t2(5, 12, 13, "White");
    shapes.addTriangle(t2);

    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;

    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();

    return 0;
}
