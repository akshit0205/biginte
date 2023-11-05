#include <stdio.h>
#include <stdlib.h>
#include "bigint.c"

int main()
{
	b* num1 = input();
    b* num2 = input();

    b* sum = polyadd(num1, num2);
    b* diff = polysub(num1, num2); 
    b* product = polymulti(num1, num2);
    
    printf("Sum: ");
    print(sum);
   printf("\nDifference: ");
    print(diff); 
   printf("Product: ");
    print(product) ;
        return 0;
}