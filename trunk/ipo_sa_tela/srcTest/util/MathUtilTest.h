#ifndef MATHUTILTEST_H
#define MATHUTILTEST_H

#include <src/util/MathUtil.h>
#include <cassert>

void expZero(){
    assert( MathUtil::potenciaBaseNeperianda( 0 ) == 1 );
}

void randomMaiorZeroMenorUm(){
    double rand = MathUtil::randomEntre0e1();
    assert( rand >= 0.0 );
    assert( rand < 1.0 );
}

#endif // MATHUTILTEST_H
