#include <iostream>
#include "MyPoint.h"
using namespace std;

MyPoint::MyPoint(int x, int y) {
    this->x = x;
    this->y = y;
}

void MyPoint::set(int xx, int yy) {
    this->x = xx;
    this->y = yy;
}

int MyPoint::getX() const {
    return x;
}

int MyPoint::getY() const {
    return y;
}

void MyPoint::print() const{
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }

void MyPoint::setX(int x) {
    this->x = x;
}

void MyPoint::setY(int y) {
    this->y = y;
}
