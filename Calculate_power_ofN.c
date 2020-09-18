/******************************************************************************

Power Function: Implement a function to calculate X^N. 
Both X and N can be positive or negative. 
You can assume that overflow doesn't happen.
(Try doing it in O(log(N)) time)

*******************************************************************************/

#include <stdio.h>

int positivePower(int num, int power) {
        if(power == 0) {
            return 1;
        }
        if (power == 1) {
            return num;
        }
        
        int halfPower = positivePower(num, power/2);
        if(power%2== 0) {
            return halfPower * halfPower;
        } else {
            return halfPower * halfPower * num;
        }
}

int absNum(int number) {
   return (number > 0 ? number : (-1 * number));    
}

float calculatePower(int num, int power) {
    
    if ((num == 0) && power <=0) {
        return -1;
    }
    
    float result = positivePower(absNum(num),absNum(power));
    
    // handle power is negative
    if (power < 0) {
        return (1/result);
    }
    // handle num is zero for non zero power
    if(num < 0 && power != 0) {
        return (-1 * result);
    }
    return result;
}

int main()
{
    double num,po;
    
    num = 2;
    po = -1;
    
    float result = calculatePower(num,po);
    printf("Result is %f",result);

    return 0;
}
