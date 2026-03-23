#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    Polynomial poly;
    string filename;

    cout << "Enter the name of the polynomial file => ";
    cin >> filename;

    if (!poly.readFromFile(filename)) {
        cout << "Error reading file: " << filename << "\n";
        return 1;
    }

    poly.print();
    cout << "\n";

    while (true) {
        cout << "1. ADD polynomial\n";
        cout << "2. MULTIPLY polynomial\n";
        cout << "3. EVALUATE polynomial\n";
        cout << "4. QUIT\n";
        cout << "Enter choice # => ";

        int choice;
        cin >> choice;

        if (choice == 4) break;

        if (choice == 1) {
            string f;
            cout << "Enter the file containing the polynomial to add => ";
            cin >> f;

            Polynomial p;
            if (!p.readFromFile(f)) {
                cout << "Error reading file: " << f << "\n";
                continue;
            }

            p.print();
            cout << "\n";

            Polynomial sum = poly.add(p);
            cout << "Sum: ";
            sum.print();
            cout << "\n";
        }
        else if (choice == 2) {
            string f;
            cout << "Enter the file containing the polynomial to multiply => ";
            cin >> f;

            Polynomial p;
            if (!p.readFromFile(f)) {
                cout << "Error reading file: " << f << "\n";
                continue;
            }

            p.print();
            cout << "\n";

            Polynomial product = poly.multiply(p);
            cout << "Product: ";
            product.print();
            cout << "\n";
        }
        else if (choice == 3) {
            double x;
            cout << "Enter the value at which to evaluate => ";
            cin >> x;

            double r = poly.evaluate(x);
            cout << "Value at " << x << " = " << r << "\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
