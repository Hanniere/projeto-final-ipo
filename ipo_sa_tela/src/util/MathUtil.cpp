#include "MathUtil.h"

#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>

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
