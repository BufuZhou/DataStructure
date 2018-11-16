#include "varincludes.h"

clock_t start, stop;
double duration1, duration2;

int main(void)
{
    int ii = 30000;

    start = clock();
    PrintN(ii);
    stop = clock();
    duration1 = ((double) (stop - start))  / CLK_TCK;
    
    start = clock();
    PrintN_1(ii);
    stop = clock();
    duration2 = ((double) (stop - start)) / CLK_TCK;
    
    printf("%.2f\n", duration1);
    printf("%.2f\n", duration2);


    return 0;
}