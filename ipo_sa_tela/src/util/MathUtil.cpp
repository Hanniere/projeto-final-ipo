#include "MathUtil.h"

#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
//#include <random>

MathUtil::MathUtil()
{
}

MathUtil::~MathUtil()
{
}

void MathUtil::seed()
{
    srand(time(0));
}

double MathUtil::randomEntre0e1()
{
    seed();
    return (double)rand() / double(RAND_MAX);
    // precisa do c++11
//    std::default_random_engine generator;
//    std::uniform_real_distribution<double> distribution(0.0,1.0);
//    return distribution(generator);
}

double MathUtil::potenciaBaseNeperianda(double expoente)
{
    return exp( expoente );
}

int MathUtil::random()
{
    seed();
    return rand();
}


int MathUtil::randomLimitado( int limite )
{
    seed();
    return rand() % limite;
}
