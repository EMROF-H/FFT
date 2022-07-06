#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <math.h>

#include "define.h"

#define PI  3.14159265358979323846264338328
#define TAU 6.28318530717958647692528676656

typedef struct
{
    float real;
    float imaginary;
}
ComplexNumber;

ComplexNumber TwiddleFactor(int power);
ComplexNumber ComplexAdd(ComplexNumber a,ComplexNumber b);
ComplexNumber ComplexReduce(ComplexNumber a,ComplexNumber b);
ComplexNumber ComplexMultiply(ComplexNumber a,ComplexNumber b);

#endif
