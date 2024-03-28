#ifndef CLEAR_H
#define CLEAR_H
#include "Weather.h"

class Clear : public Weather {
private:
    std::string weatherName;
public:
    Clear();
    ~Clear() = default;
};

#endif // CLEAR_H