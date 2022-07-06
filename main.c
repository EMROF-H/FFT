#include <stdio.h>

#include "fft.c"

int main()
{
    int i;
    
    int           x[LENGTH]={1,2,3,4,5,6,7,8};
    ComplexNumber X[LENGTH];
    RFFT(x,X);
    for(i=0;i<LENGTH;i++)printf("%lf %lf\n",X[i].real,X[i].imaginary);
    
    return 0;
}