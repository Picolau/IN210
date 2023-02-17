#include "age.h"

static const float Price = 1.5;

float computePrice(int age)
{
    int limitAge;
    recupAge(&limitAge);
    if (age>limitAge)
        return Price;
    else
        return Price/2;
}
