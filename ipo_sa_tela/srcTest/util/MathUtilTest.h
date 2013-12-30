#ifndef MATHUTILTEST_H
#define MATHUTILTEST_H

#include <src/util/MathUtil.h>
#include <cassert>

void expZero(){
    assert( MathUtil::potenciaBaseNeperianda( 0 ) == 1 );
}

#endif // MATHUTILTEST_H
