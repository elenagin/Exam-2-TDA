void initial_menu(){
    system("clear");
    printf("Bienvenido al sistema\n");
    printf("----------------------------\n");
    printf("\tElena Ginebra\n");
    printf("----------------------------\n");
    printf("Presione enter para comenzar...\n");
    getchar();
    system("clear");
}

unsigned get_data()
{
    int input;

    system("clear");
    printf("Ingresar dato: ");
    scanf("%d", &input);

    return input;
}

void print_data()
{
    printf("Data: ");
}

void print_coding()
{
    printf("Coding: ");
}

void print_error_bit()
{
    printf("Error in bit: ");
}

void print_error_process()
{
    printf("Error in bit: ");
    printf("Code: 1001000\nC[2:0]: 011\nError in bit 3");
}

void print_message()
{
    printf("Message: ");
}

void final_menu(){
    printf("Presione enter para salir...\n");
    getchar();
    getchar();
}
