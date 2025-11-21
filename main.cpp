#include <iostream>
#include <vector>
#include <cstdlib>

#define NOGDI

#include <windows.h>
#include "polygon.hpp"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Polygon current;
    char choice;

    do {
        clearScreen();
        current.print();

        cout << "Меню:\n";
        cout << "1. Створити пустий (задати кількість вершин)\n";
        cout << "2. Створити правильний багатокутник (n та радіус)\n";
        cout << "3. Створити за координатами\n";
        cout << "4. Змінити конкретну вершину\n";
        cout << "q. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == '1') {
            int n;
            cout << "Введіть кількість вершин: ";
            cin >> n;
            current = Polygon(n);
        }
        else if (choice == '2') {
            int n;
            double radius;
            cout << "Введіть кількість вершин та радіус: ";
            cin >> n >> radius;
            current = Polygon(n, radius);
        }
        else if (choice == '3') {
            int n;
            cout << "Введіть кількість вершин: ";
            cin >> n;

            double* coords = new double[n * 2];
            cout << "Введіть координати (x1 y1 x2 y2 ...): ";
            for (int i = 0; i < n; i++) {
                cout << "Вершина " << i + 1 << ": ";
                cin >> coords[2 * i] >> coords[2 * i + 1];
            }
            current = Polygon(n, coords);
            delete[] coords;
        }
        else if (choice == '4') {
            int idx;
            double x, y;
            cout << "Номер вершини (1-" << current.getNumVertices() << "), нові X та Y: ";
            cin >> idx >> x >> y;
            current.setVertex(idx - 1, x, y);
        }
        else if (choice == 'q') {
            break;
        }

    } while (choice != 'q');

    return 0;
}
