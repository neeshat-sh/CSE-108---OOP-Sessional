#include <iostream>
#include <cstring>
using namespace std;

class Point {
   public:
    int x, y;
    char* dummy;
    Point(int x, int y) {
        cout << "Contrusctor called for " << this << endl;
        this->x = x;
        this->y = y;
        dummy = (char*)malloc(sizeof(char)*7);
        strcpy(dummy, "CSE108");
    }
    ~Point() {
        cout << "Destructor called for " << this << endl;
        free(dummy);
    }
};

void printPoint(Point& p) {
    cout << "Point: (" << p.x << ", " << p.y << ")" << endl;
}

void setZero(Point p) {
    /*
    Point p will not change the original object. This is because p is a copy of the original object.
    If the original object has a dynamically allocated memory, then the destructor will be called twice.
    Once for this local copy and once for the original object.
    To avoid this, we can pass the object by reference like this: Point& p
    */
    p.x = 0;
    p.y = 0;
}

int main() {
    Point p1(10, 20);
    printPoint(p1);
    setZero(p1);
    printPoint(p1);
    return 0;
}
