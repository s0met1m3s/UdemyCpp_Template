#include <iostream>

int main()
{
    int age1 = 28;
    int age2 = 56;

    // 1.)
    int older_age1;
    if(age1 > age2)
        older_age1 = age1;
    else
        older_age1 = age2;
    // 2.) Ternary Opertator
    //              BOOL EXPR    ? TRUE : FALSEW
    int older_age1 = age1 > age2 ? age1 : age2;


    return 0;
}
