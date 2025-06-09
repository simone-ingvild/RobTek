#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
    Rectangle(double w, double h);
    double getArea() const;
    double getPerimeter() const;

private:
    double width, height;
};

#endif // RECTANGLE_H
