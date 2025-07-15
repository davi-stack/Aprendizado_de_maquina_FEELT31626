#ifndef NN_H
#define NN_H

#include <vector>

class nn {
public:
    std::vector<int> w;
    int b, t;

    nn();
    void reset();
    int value(const std::vector<int>& x);
    void train(const std::vector<int>& in, int out);
};

#endif
