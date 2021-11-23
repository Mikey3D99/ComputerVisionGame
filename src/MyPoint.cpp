#include <iostream>

using namespace std;


class MyPoint{
    private:
        int x;
        int y;

    public:
        explicit MyPoint(int x = 100, int y = 100){
            this->x = x;
            this->y = y;
        }

        void set(int xx, int yy){
            this->x = xx;
            this->y = yy;
        }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void print() const{
            cout << "(" << this->x << ", " << this->y << ")" << endl;
        }

    void setX(int x) {
        MyPoint::x = x;
    }

    void setY(int y) {
        MyPoint::y = y;
    }

};
