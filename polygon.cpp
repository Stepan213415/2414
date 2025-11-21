#include "polygon.hpp"
#include <cmath>
#include <iostream>
#include <algorithm> // для std::abs

const double PI = 3.14159265358979323846;

// Конструктор за замовчуванням
Polygon::Polygon() : numVertices(0), vertices(nullptr) {}

// Конструктор з кількістю вершин
Polygon::Polygon(int n) : numVertices(n) {
    if (n > 0)
        vertices = new Point[n];
    else
        vertices = nullptr;

    for (int i = 0; i < n; i++) {
        vertices[i] = {0.0, 0.0};
    }
}

// Конструктор з масивом координат
Polygon::Polygon(int n, const double* coords) : numVertices(n) {
    if (n > 0)
        vertices = new Point[n];
    else
        vertices = nullptr;

    for (int i = 0; i < n; i++) {
        vertices[i].x = coords[2 * i];
        vertices[i].y = coords[2 * i + 1];
    }
}

// Конструктор правильного багатокутника
Polygon::Polygon(int n, double radius) : numVertices(n) {
    if (n > 0)
        vertices = new Point[n];
    else
        vertices = nullptr;

    for (int i = 0; i < n; i++) {
        double angle = 2 * PI * i / n;
        vertices[i].x = radius * cos(angle);
        vertices[i].y = radius * sin(angle);
    }
}

// Конструктор копіювання (Deep Copy)
Polygon::Polygon(const Polygon& other) : numVertices(other.numVertices) {
    if (other.numVertices > 0) {
        vertices = new Point[other.numVertices];
        for (int i = 0; i < other.numVertices; i++) {
            vertices[i] = other.vertices[i];
        }
    } else {
        vertices = nullptr;
    }
}

// Деструктор
Polygon::~Polygon() {
    if (vertices != nullptr) {
        delete[] vertices;
        vertices = nullptr;
    }
}

// Оператор присвоєння
Polygon& Polygon::operator=(const Polygon& other) {
    if (this == &other) return *this; // захист від самоприсвоєння

    // Очищення старої пам'яті
    delete[] vertices;

    numVertices = other.numVertices;
    if (other.numVertices > 0) {
        vertices = new Point[other.numVertices];
        for (int i = 0; i < numVertices; i++) {
            vertices[i] = other.vertices[i];
        }
    } else {
        vertices = nullptr;
    }

    return *this;
}

void Polygon::setVertex(int index, double x, double y) {
    if (index >= 0 && index < numVertices) {
        vertices[index].x = x;
        vertices[index].y = y;
    }
}

Point Polygon::getVertex(int index) const {
    if (index >= 0 && index < numVertices) return vertices[index];
    return {0.0, 0.0};
}

// Формула площі Гаусса (шнурівки)
double Polygon::calculateArea() const {
    if (numVertices < 3) return 0.0;

    double area = 0.0;
    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices; // наступна вершина (замикається на 0)
        area += (vertices[i].x * vertices[j].y) - (vertices[j].x * vertices[i].y);
    }
    return std::abs(area) / 2.0;
}

void Polygon::print() const {
    std::cout << "----------------------------------\n";
    std::cout << "Багатокутник з " << numVertices << " вершинами:\n";
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Вершина " << i + 1 << ": ("
                  << vertices[i].x << ", " << vertices[i].y << ")\n";
    }
    std::cout << "Площа = " << calculateArea() << std::endl;
    std::cout << "----------------------------------\n";
}
