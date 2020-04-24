/* Controller Functions
 * Manda a llamar model y view cuando se necesite.
 * Programa para implementar codificación de Hamming
 * utilizando bitwise.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model.h"
#include "view.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int limit;
    uint8_t temp = 11, data, mask = 0, parity = 0, n = 0;

    initial_menu();
    printf("Enter data (int): ");
    scanf("%d", &data); //1001
    //printf(" data %d ", data);
    //printf(" mask %d ", mask);
    //printf(" par %d ", par);
    printf("\nData: ");
    binary(data);
    printf("\n");
    //binary(mask);
    //printf("\n");
    //binary(par);
    limit = sizeof(data) * 8;
    //printf("%d", limit);

    mask = 1;
    temp = 1;
    for (int i = 1; i <= limit; i++) //sizeof(data) * 8
    {
        for (int i = 0; i < 8; i++) //numbits(data)
        {
            mask <<= (uint8_t)pow(2, i);
            parity ^= (data & mask);
            //printf("\n\n%d ", i);
            //binary(parity);
            //printf("\n");
            //binary(mask);
        }
        temp |= parity << (uint8_t)pow(2, i);
        //printf("\n\n");
        //binary(temp);
    }
    printf("\npar ");
    binary(parity);
    printf("\nmask ");
    binary(parity);
    printf("\ntemp ");
    binary(temp);
    printf("\n");

    final_menu();
}