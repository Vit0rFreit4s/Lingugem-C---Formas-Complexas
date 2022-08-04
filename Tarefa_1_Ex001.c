#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define NUM 10

/*

Pretende-se criar um programa em C que faça a gestão de uma fila de espera. Para o efeito vamos ter um array com 10 elementos do tipo inteiro.
Notas:

Para realizar a marcação é solicitado ao utilizador o nº do utente (entre 1 e 999) e colocado na 1ª posição livre (igual a zero).
A marcação de urgência coloca o utente na posição que o utilizador indicar.
A eliminação retira da lista o número do utente.
Utilize funções.
O registo das marcações deve estar sempre visível e passa a ter as seguintes opções:

Crie um menu com as seguintes opções:
- Realizar Marcação.
- Marcação de Urgência.
- Eliminar Marcação.
- Terminar o programa.
Possível Layout:
------------------------------------------------------------------------------------------------------------------------
Clínica Quebra-Ossos
Registo de Marcações
0   1   2   3   4   5   6   7   8   9
0   0   0   0   0   0   0   0   0   0
------------------------------------------------------------------------------------------------------------------------
Menu
------------------------------------------------------------------------------------------------------------------------
1 – Realizar Marcação.
2 – Marcação de Urgência.
3 – Eliminar Marcação.
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
        puts("1 - Realizar Marcação.\n");
        puts("2 - Marcação de Urgência.\n");
        puts("3 - Eliminar Marcação.\n");
        puts("9 - Terminar o Programa.\n");
        puts("*********************************************************************************\n");

        printf("Digite a opção desejada: ");
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
            puts("Opção inválida, tente novamente!!\n");
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
    puts("\t\t\tClínica Entra Sem Mão e Sai Sem Pé!!!\n");
    puts("\t\t\t\tREGISTRO DE MARCAÇÕES\n");
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
    puts("\t\t\t\tMARCAÇÕES\n");
    puts("*********************************************************************************\n");

    do
    {
        printf("Digite o seu número de utente (entre 1 e 999): \n");
        scanf("%i", &utente);
    }
    while(utente < 1 || utente > 999);

    for(i = 0; i < NUM; i++)
    {
        if(array[i] == 0)
        {
            array[i] = utente;
            printf("Marcação realizada com sucesso!\n");
            system("pause");
            system("cls");
            Menu(array);
        }
    }
    printf("Não existem mais vagas! Aguarde até alguma senha estar livre ou procure uma outra unidade...\n");
    system("pause");
    system("cls");
    Menu(array);
}

Urgencia(int array [])
{
    int i = 0, j = 0, utente = 0, posicao = 0, temp = 0, troca = 0;

    system("cls");



    puts("**********************************************************************************\n");
    puts("\t\t\t\tURGÊNGIA\n");
    puts("**********************************************************************************\n");
    do
    {
        printf("Digite o seu número de utente (entre 1 e 999): \n");
        scanf("%i", &utente);
    }
    while(utente < 1 || utente > 999);
    do
    {
        printf("Digite a posição em que quer marcar (entre 1 e 10): \n");
        scanf("%i", &posicao);
    }
    while(posicao < 1 || posicao >10);


    if(array[posicao-1] == 0)
    {
        array[posicao-1] = utente;
        printf("Marcação realizada com sucesso!\n");
        system("pause");
        system("cls");
        Menu(array);
    }
    else if(array[posicao-1] != 0 && array[posicao] == 0)
    {
        temp = array[posicao-1];
        array[posicao-1] = utente;
        array[posicao] = temp;
        printf("Marcação realizada com sucesso!\n");
        system("pause");
        system("cls");
        Menu(array);
    }
    else if(array[posicao-1] != 0 && array[posicao-2] == 0)
    {
        temp = array[posicao-1];
        array[posicao-1] = utente;
        array[posicao-2] = temp;
        printf("Marcação realizada com sucesso!\n");
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
                printf("Marcação realizada com sucesso!\n");
                system("pause");
                system("cls");
                Menu(array);

            }



        }
        printf("Não existem mais vagas! Aguarde até alguma senha estar livre ou procure uma outra unidade...\n");
        system("pause");
        system("cls");
        Menu(array);



}
    Eliminar(int array [])
    {
        int i = 0, utente = 0;

        system("cls");

        puts("*********************************************************************************\n");
        puts("\t\t\t\tELIMINAR MARCAÇÕES\n");
        puts("*********************************************************************************\n");
        do
        {
            printf("Digite o seu número de utente (entre 1 e 999): \n");
            scanf("%i", &utente);
        }
        while(utente < 1 || utente > 999);

        for(i = 0; i < NUM; i++)
        {
            if(array[i] == utente)
            {
                array[i] = 0;
                printf("Eliminação realizada com sucesso!\n");
                system("pause");
                system("cls");
                Menu(array);
            }
        }

        printf("Número de utente não encontrado!\n");
        system("pause");
        Menu(array);

    }

    void main()
    {
        setlocale(LC_ALL, "Portuguese");
        int array [NUM] = {0};

        Menu(array);
    }
