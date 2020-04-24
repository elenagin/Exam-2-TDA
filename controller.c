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
    int data[7];
    int receivedData[7], c, c1, c2, c4, i;
    int errorBit;
    uint8_t num = 3;

    //printf("Enter data\n");
    //scanf("%s", &num);
    //binary(num);
    initial_menu();
    printf("Enter 4 bits one by one (big to small)\n");
    scanf("%d", &data[6]);
    scanf("%d", &data[5]);
    scanf("%d", &data[4]);
    scanf("%d", &data[2]);

    data[0] = data[2] ^ data[4] ^ data[6]; //p1
    data[1] = data[2] ^ data[5] ^ data[6]; //p2
    data[3] = data[4] ^ data[5] ^ data[6]; //p4

    printf("\nEncoded: ");
    for (i = 6; i >= 0; i--)
        printf("%d", data[i]);

    printf("\n\nWhich bit will you assign the error to? [6:0].\n");
    scanf("%d", &errorBit);

    for (i = 6; i >= 0; i--)
        receivedData[i] = data[i];

    if (receivedData[errorBit] == 1)
    {
        receivedData[errorBit] = 0;
    }
    else
    {
        receivedData[errorBit] = 1;
    }

    c1 = receivedData[2] ^ receivedData[4] ^ receivedData[6]; //p1
    c2 = receivedData[2] ^ receivedData[5] ^ receivedData[6]; //p2
    c4 = receivedData[4] ^ receivedData[5] ^ receivedData[6]; //p4
    c = c4 * 4 + c2 * 2 + c1;

    if (c == 0)
    {
        printf("\nThe same, no mistake\n");
    }
    else
    {
        printf("\nError in bit: %d", c);

        printf("\nReceived: ");
        for (i = 6; i >= 0; i--)
            printf("%d", receivedData[i]);

        printf("\nCorrected is: ");

        if (receivedData[errorBit] == 0)
            receivedData[errorBit] = 1;
        else
            receivedData[errorBit] = 0;

        for (i = 6; i >= 0; i--)
            printf("%d", receivedData[i]);

        printf("\n");
    }
    final_menu();
}