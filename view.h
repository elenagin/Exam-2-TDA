/* View Functions
*/

/* Imprime un menú de inicio para el usuario
* No recibe ni regresa datos.
*/
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

/* Imprime un mensaje al usuario para terminar programa
* No recibe ni regresa datos.
*/
void final_menu(){
    printf("Presione enter para salir...\n");
    getchar();
    getchar();
}
