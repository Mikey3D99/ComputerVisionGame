#ifndef TEST_MYPOINT_H
#define TEST_MYPOINT_H

#include <iostream>

class MyPoint {
private:
    int x;
    int y;

public:
    explicit MyPoint(int x, int y);
    void set(int xx, int yy);
    int getX() const;
    int getY() const;
    void print() const;
    void setX(int x);
    void setY(int y);
};

#endif
