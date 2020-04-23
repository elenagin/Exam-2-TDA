#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model.h"
#include "view.h"


void binary(unsigned n)
{
    if (n > 1)
        binary(n / 2);

    printf("%d", n % 2);
}

int main()
{
    unsigned data;

    initial_menu();
    printf("%d data\n", get_data());
    binary(get_data());
    printf("\n");
    print_data();
    print_coding();
    print_error_bit();
    print_error_process();
    print_message();
    final_menu();

    return 0;
}