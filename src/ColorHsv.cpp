#include "ColorHsv.h"

ColorHsv::ColorHsv() {
    this->hmin = 94;
    this->smin = 182;
    this->vmin = 70;
    this->hmax = 200;
    this->smax = 255;
    this->vmax = 243;
}

int ColorHsv::getHmin() const {
    return hmin;
}

int ColorHsv::getSmin() const {
    return smin;
}

int ColorHsv::getVmin() const {
    return vmin;
}

int ColorHsv::getHmax() const {
    return hmax;
}

int ColorHsv::getSmax() const {
    return smax;
}

int ColorHsv::getVmax() const {
    return vmax;
}

void ColorHsv::setHmin(int hmin) {
    ColorHsv::hmin = hmin;
}

void ColorHsv::setSmin(int smin) {
    ColorHsv::smin = smin;
}

void ColorHsv::setVmin(int vmin) {
    ColorHsv::vmin = vmin;
}

void ColorHsv::setHmax(int hmax) {
    ColorHsv::hmax = hmax;
}

void ColorHsv::setSmax(int smax) {
    ColorHsv::smax = smax;
}

void ColorHsv::setVmax(int vmax) {
    ColorHsv::vmax = vmax;
}
