#ifndef TEST_COLORHSV_H
#define TEST_COLORHSV_H


class ColorHsv {
private:
    int hmin;
    int smin;
    int vmin;
    int hmax;
    int smax;
    int vmax;

public:
    ColorHsv();

    int getHmin() const;
    int getSmin() const;
    int getVmin() const;
    int getHmax() const;
    int getSmax() const;
    int getVmax() const;

    void setHmin(int hmin);
    void setSmin(int smin);
    void setVmin(int vmin);
    void setHmax(int hmax);
    void setSmax(int smax);
    void setVmax(int vmax);
};


#endif
