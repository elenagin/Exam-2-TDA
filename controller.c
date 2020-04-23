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
    int data[10];
    int receivedData[10], c, c1, c2, c3, i;


    printf("Enter 4 bits one by one (big to small)\n");
    scanf("%d", &data[6]);
    scanf("%d", &data[5]);
    scanf("%d", &data[4]);
    scanf("%d", &data[2]);

    data[0] = data[2] ^ data[4] ^ data[6]; //p1
    data[1] = data[2] ^ data[5] ^ data[6]; //p2
    data[3] = data[4] ^ data[5] ^ data[6]; //p4

    printf("\nEncoded : ");
    for (i = 6; i >= 0; i--)
        printf("%d", data[i]);

    printf("\n\nEnter received bits one by one (big to small)\n");
    for (i = 6; i >= 0; i--)
        scanf("%d", &receivedData[i]);

    c1 = receivedData[2] ^ receivedData[4] ^ receivedData[6]; //p1
    c2 = receivedData[2] ^ receivedData[5] ^ receivedData[6]; //p2
    c3 = receivedData[4] ^ receivedData[5] ^ receivedData[6]; //p4
    c = c3 * 4 + c2 * 2 + c1;

    if (c == 0)
    {
        printf("\nThe same, no mistake\n");
    }
    else
    {
        printf("\nError in bit: %d", c);

        printf("\nSent: ");
        for (i = 6; i >= 0; i--)
            printf("%d", data[i]);

        printf("\nReceived: ");
        for (i = 6; i >= 0; i--)
            printf("%d", receivedData[i]);

        printf("\nCorrect is: \n");

        if (receivedData[7 - c] == 0)
            receivedData[7 - c] = 1;
        else
            receivedData[7 - c] = 0;

        for (i = 6; i >= 0; i--)
        {
            printf("%d", receivedData[i]);
        }

        printf("\n");
    }
}