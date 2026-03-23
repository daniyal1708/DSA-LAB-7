#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Term {
    double coeff;
    int degree;
    Term* next;

    Term(double c, int d);
};

class Polynomial {
private:
    Term* head;

    void insertTerm(double coeff, int degree);
    double power(double base, int exp) const;

public:
    Polynomial();
    ~Polynomial();

    bool readFromFile(const string& filename);
    void print() const;

    Polynomial add(const Polynomial& other) const;
    Polynomial multiply(const Polynomial& other) const;

    double evaluate(double x) const;
};
