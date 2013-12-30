#ifndef MATHUTIL_H
#define MATHUTIL_H

class MathUtil
{
public:
    MathUtil();
    static double randomEntre0e1();
    // numero neperiano elevado a expoente
    static double potenciaBaseNeperianda( double expoente );

private:
    static void seed();
};

#endif // MATHUTIL_H
