#include "complex.h"

ComplexNumber TwiddleFactor(int power)
{
    ComplexNumber result = {cos(-TAU*power/LENGTH),sin(-TAU*power/LENGTH)};
    return result;
}

ComplexNumber ComplexAdd(ComplexNumber a,ComplexNumber b)
{
    ComplexNumber result;
    result.real      = a.real+b.real;
    result.imaginary = a.imaginary+b.imaginary;
    return result;
}

ComplexNumber ComplexReduce(ComplexNumber a,ComplexNumber b)
{
    ComplexNumber result;
    result.real      = a.real-b.real;
    result.imaginary = a.imaginary-b.imaginary;
    return result;
}

ComplexNumber ComplexMultiply(ComplexNumber a,ComplexNumber b)
{
    ComplexNumber result;
    result.real      = a.real*b.real-a.imaginary*b.imaginary;
    result.imaginary = a.real*b.imaginary+a.imaginary*b.real;
    return result;
}
