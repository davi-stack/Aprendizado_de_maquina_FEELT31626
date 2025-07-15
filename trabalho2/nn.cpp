#include "nn.h"
#include <ostream>
#include <iostream>
using namespace std;


nn::nn() {
    w.resize(2);
    w.assign(2, 0);
    b = 0;
    t = 1;
}

void nn::reset() {
    w.assign(2, 0);
    b = 0;
    t = 0;
}

int nn::value(const std::vector<int>& x) {
    int sum = b;
    for (int i = 0; i < w.size(); i++) {
        sum += w[i] * x[i];
    }
    if(sum>=t) return 1;
    return -1;
}

void nn::train(const std::vector<int>& in, int out) {
    // int y = value(in);
    for (int i = 0; i < 2; i++) {
        // cout << "soma in" << in[i] << " e << " << out << std::endl;
        this->w[i] +=  (in[i] * out);
    }
    b += out;
}
