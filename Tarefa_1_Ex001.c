#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define NUM 10

/*

Pretende-se criar um programa em C que fa�a a gest�o de uma fila de espera. Para o efeito vamos ter um array com 10 elementos do tipo inteiro.
Notas:

Para realizar a marca��o � solicitado ao utilizador o n� do utente (entre 1 e 999) e colocado na 1� posi��o livre (igual a zero).
A marca��o de urg�ncia coloca o utente na posi��o que o utilizador indicar.
A elimina��o retira da lista o n�mero do utente.
Utilize fun��es.
O registo das marca��es deve estar sempre vis�vel e passa a ter as seguintes op��es:

Crie um menu com as seguintes op��es:
- Realizar Marca��o.
- Marca��o de Urg�ncia.
- Eliminar Marca��o.
- Terminar o programa.
Poss�vel Layout:
------------------------------------------------------------------------------------------------------------------------
Cl�nica Quebra-Ossos
Registo de Marca��es
0   1   2   3   4   5   6   7   8   9
0   0   0   0   0   0   0   0   0   0
------------------------------------------------------------------------------------------------------------------------
Menu
------------------------------------------------------------------------------------------------------------------------
1 � Realizar Marca��o.
2 � Marca��o de Urg�ncia.
3 � Eliminar Marca��o.
9 - Terminar o programa.
---------------------------------------------------------------------------------------------------------------

*/

void Menu(int array[])
{
    int opcao = 0, verdade = 0;

    do
    {
        Senhas();
        puts("*********************************************************************************\n");
        puts("\t\t\t\tMENU\n");
        puts("*********************************************************************************\n");
        puts("1 - Realizar Marca��o.\n");
        puts("2 - Marca��o de Urg�ncia.\n");
        puts("3 - Eliminar Marca��o.\n");
        puts("9 - Terminar o Programa.\n");
        puts("*********************************************************************************\n");

        printf("Digite a op��o desejada: ");
        scanf("%i", &opcao);


        switch(opcao)
        {
        case 1:
            Marcacoes(array);
            break;
        case 2:
            Urgencia(array);
            break;
        case 3:
            Eliminar(array);
            break;
        case 9:
            exit(0);
            break;
        default:
            puts("Op��o inv�lida, tente novamente!!\n");
            system("pause");
            system("cls");
            main();
        }
    }
    while(verdade == 0);
}



Senhas(int array [])
{
    int i = 0, j = 0;

    puts("*********************************************************************************\n");
    puts("\t\t\tCl�nica Entra Sem M�o e Sai Sem P�!!!\n");
    puts("\t\t\t\tREGISTRO DE MARCA��ES\n");
    puts("---------------------------------------------------------------------------------\n");
    puts("\t\t\t\tSENHAS\n\n");
    for(j=0; j<NUM; j++)
    {
        printf("[%3i]\t", j+1);
    }
    putchar('\n');
    for(i=0; i<NUM; i++)
    {
        printf("[%3i]\t", array[i]);
    }

    putchar('\n');
}

Marcacoes(int array [])
{
    int i = 0, utente = 0;

    system("cls");

    puts("*********************************************************************************\n");
    puts("\t\t\t\tMARCA��ES\n");
    puts("*********************************************************************************\n");

    do
    {
        printf("Digite o seu n�mero de utente (entre 1 e 999): \n");
        scanf("%i", &utente);
    }
    while(utente < 1 || utente > 999);

    for(i = 0; i < NUM; i++)
    {
        if(array[i] == 0)
        {
            array[i] = utente;
            printf("Marca��o realizada com sucesso!\n");
            system("pause");
            system("cls");
            Menu(array);
        }
    }
    printf("N�o existem mais vagas! Aguarde at� alguma senha estar livre ou procure uma outra unidade...\n");
    system("pause");
    system("cls");
    Menu(array);
}

Urgencia(int array [])
{
    int i = 0, j = 0, utente = 0, posicao = 0, temp = 0, troca = 0;

    system("cls");



    puts("**********************************************************************************\n");
    puts("\t\t\t\tURG�NGIA\n");
    puts("**********************************************************************************\n");
    do
    {
        printf("Digite o seu n�mero de utente (entre 1 e 999): \n");
        scanf("%i", &utente);
    }
    while(utente < 1 || utente > 999);
    do
    {
        printf("Digite a posi��o em que quer marcar (entre 1 e 10): \n");
        scanf("%i", &posicao);
    }
    while(posicao < 1 || posicao >10);


    if(array[posicao-1] == 0)
    {
        array[posicao-1] = utente;
        printf("Marca��o realizada com sucesso!\n");
        system("pause");
        system("cls");
        Menu(array);
    }
    else if(array[posicao-1] != 0 && array[posicao] == 0)
    {
        temp = array[posicao-1];
        array[posicao-1] = utente;
        array[posicao] = temp;
        printf("Marca��o realizada com sucesso!\n");
        system("pause");
        system("cls");
        Menu(array);
    }
    else if(array[posicao-1] != 0 && array[posicao-2] == 0)
    {
        temp = array[posicao-1];
        array[posicao-1] = utente;
        array[posicao-2] = temp;
        printf("Marca��o realizada com sucesso!\n");
        system("pause");
        system("cls");
        Menu(array);
    }
    else if(array[posicao-1] != 0 && array[posicao] != 0 && array[posicao-2] != 0)
        for(i = 0; i < NUM; i++)
        {
            if(array[i] == 0)
            {
                if(i < (posicao-1)){
                    for(i; i < posicao-1; i++){
                        troca = array[i];
                        array[i] = array[i+1];
                        array[i+1]=troca;
                    }
                    array[posicao-1]=utente;
                }
                else{
                    for(i; i > posicao-1; i--){
                        troca = array[i];
                        array[i] = array[i-1];
                        array[i-1]=troca;
                    }
                    array[posicao-1]=utente;

                }
                printf("Marca��o realizada com sucesso!\n");
                system("pause");
                system("cls");
                Menu(array);

            }



        }
        printf("N�o existem mais vagas! Aguarde at� alguma senha estar livre ou procure uma outra unidade...\n");
        system("pause");
        system("cls");
        Menu(array);



}
    Eliminar(int array [])
    {
        int i = 0, utente = 0;

        system("cls");

        puts("*********************************************************************************\n");
        puts("\t\t\t\tELIMINAR MARCA��ES\n");
        puts("*********************************************************************************\n");
        do
        {
            printf("Digite o seu n�mero de utente (entre 1 e 999): \n");
            scanf("%i", &utente);
        }
        while(utente < 1 || utente > 999);

        for(i = 0; i < NUM; i++)
        {
            if(array[i] == utente)
            {
                array[i] = 0;
                printf("Elimina��o realizada com sucesso!\n");
                system("pause");
                system("cls");
                Menu(array);
            }
        }

        printf("N�mero de utente n�o encontrado!\n");
        system("pause");
        Menu(array);

    }

    void main()
    {
        setlocale(LC_ALL, "Portuguese");
        int array [NUM] = {0};

        Menu(array);
    }
