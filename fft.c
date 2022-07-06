#include "fft.h"

void BinaryReverse(int array[]);

void RFFT(int input[],ComplexNumber output[])
{
    ComplexNumber temp;
    int level,buttterflyInsideIndex,butterflyIndex,index;
    int butterflyWidth,butterflyCount;

	BinaryReverse(input);

    for(index=0;index<LENGTH;index++)
    {
        output[index].real = input[index];
        output[index].imaginary = 0;
    }

    for(level=1;level<=ORDER;level++)
    {
        butterflyWidth = 1<<(level-1);
        for(buttterflyInsideIndex=0;buttterflyInsideIndex<butterflyWidth;buttterflyInsideIndex++)
        {
            butterflyCount = 1<<(ORDER-level);
            for(butterflyIndex=0;butterflyIndex<butterflyCount;butterflyIndex++)
            {
                index = buttterflyInsideIndex+2*butterflyWidth*butterflyIndex;
                temp = ComplexMultiply(output[index+butterflyWidth],TwiddleFactor(buttterflyInsideIndex*butterflyCount));
                output[index+butterflyWidth] = ComplexReduce(output[index],temp);
                output[index]                = ComplexAdd   (output[index],temp);
            }
        }
    }
}

void BinaryReverse(int array[])
{
    int index,bitIndex;
    int indexReverse,lowOperator,highOperator,low,high;
    int temp;

	for(index=0;index<LENGTH;index++)
	{
		indexReverse = index;
		for(bitIndex=0;bitIndex<ORDER/2;bitIndex++)
		{
			lowOperator  = 1 << bitIndex;
			highOperator = 1 << (ORDER-1-bitIndex);

			low  = index & lowOperator;
			high = index & highOperator;

			if(low)
            {
                indexReverse |=  highOperator;
            }
            else
            {
                indexReverse &= ~highOperator;
            }
			if(high)
            {
                indexReverse |=  lowOperator;
            }
            else
            {
                indexReverse &= ~lowOperator;
            }
		}

		if(index < indexReverse)
		{
            array[index]        = array[index] ^ array[indexReverse];
            array[indexReverse] = array[index] ^ array[indexReverse];
            array[index]        = array[index] ^ array[indexReverse];
		}                                
	}
}
