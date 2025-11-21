#ifndef POLYGON_HPP
#define POLYGON_HPP

struct Point {
    double x, y;
};

class Polygon {
private:
    int numVertices;
    Point* vertices;

public:
    Polygon();
    Polygon(int n);
    Polygon(int n, const double* coords);
    Polygon(int n, double radius);
    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);
    ~Polygon();

    int getNumVertices() const { return numVertices; }
    void setVertex(int index, double x, double y);
    Point getVertex(int index) const;
    double calculateArea() const;
    void print() const;
};

#endif
