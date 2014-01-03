#ifndef MATHUTIL_H
#define MATHUTIL_H

class MathUtil
{
public:
    MathUtil();
    virtual ~MathUtil();

    static double randomEntre0e1();
    // numero neperiano elevado a expoente
    static double potenciaBaseNeperianda( double expoente );
    static int random();
    static int randomLimitado( int limite );
private:
    static void seed();
};

#endif // MATHUTIL_H
