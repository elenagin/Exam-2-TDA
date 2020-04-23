#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model.h"
#include "view.h"

int main()
{
    int data[10];
    int receivedData[10], c, c1, c2, c3, i;

    printf("Enter 6 bits of data one by one\n");
    scanf("%d", &data[9]);
    scanf("%d", &data[8]);
    scanf("%d", &data[6]);
    scanf("%d", &data[5]);
    scanf("%d", &data[4]);
    scanf("%d", &data[2]);

    //Calculation of even parity
    data[0] = data[2] ^ data[4] ^ data[6] ^ data[8]; //p1
    data[1] = data[2] ^ data[5] ^ data[6] ^ data[9]; //p2
    data[3] = data[4] ^ data[5] ^ data[6]; //p4
    data[7] = data[8] ^ data[9]; //p8

    printf("\nEncoded data is\n");
    for (i = 9; i >= 0; i--)
        printf("%d", data[i]);

    printf("\n\nEnter received data bits one by one\n");
    for (i = 9; i >= 0; i--)
        scanf("%d", &receivedData[i]);

    c0 = receivedData[2] ^ receivedData[4] ^ receivedData[6] ^ receivedData[8];
    c1 = receivedData[2] ^ receivedData[5] ^ receivedData[6] ^ receivedData[9];
    c3 = receivedData[4] ^ receivedData[5] ^ receivedData[6];
    c7 = receivedData[7] = receivedData[8] ^ receivedData[9]; 
    c = c3 * 4 + c2 * 2 + c1;

    if (c == 0)
    {
        printf("\nNo error while transmission of data\n");
    }
    else
    {
        printf("\nError on position %d", c);

        printf("\nData sent : ");
        for (i = 0; i < 7; i++)
            printf("%d", data[i]);

        printf("\nData received : ");
        for (i = 0; i < 7; i++)
            printf("%d", receivedData[i]);

        printf("\nCorrect message is\n");

        //if errorneous bit is 0 we complement it else vice versa
        if (receivedData[7 - c] == 0)
            receivedData[7 - c] = 1;
        else
            receivedData[7 - c] = 0;

        for (i = 0; i < 7; i++)
        {
            printf("%d", receivedData[i]);
        }

        printf("\n");
    }
}