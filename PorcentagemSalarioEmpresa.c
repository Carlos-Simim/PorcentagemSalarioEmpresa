#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

int main()
{
    setlocale (LC_ALL, "Portuguese");

    int funcionarios;
    int i;
    int salarios [500000]; /*N�o vi necessidade para manter esse vetor como uma vari�vel, pois n�meros de funcion�rios maiores
    que esse s�o impratic�veis de serem inseridos manualmente. Mesmo assim, 500 mil j� � maior do que a quantidade de funcion�rios
    da grande maioria das companhias existentes no mundo (apenas 12 empresas superam esse n�mero), ent�o esse tamanho supriria
    virtualmente qualquer demanda.*/
    int soma;
    int media;
    int AcimaDaMedia, AbaixoDaMedia;
    float PorcentagemAcima, PorcentagemAbaixo;
    PorcentagemAbaixo = 0;
    PorcentagemAcima = 0;
    AbaixoDaMedia = 0;
    AcimaDaMedia = 0;
    soma = 0;
//Prefiro declarar cada vari�vel individualmente porque acho melhor de visualizar.

    //Coleta de informa��es (Quantidade de funcion�rios e sal�rio dos funcion�rios)
    printf("\nQuantos funcion�rios deseja incluir? (Favor inserir um n�mero inteiro maior que 0) ");
    scanf("%d",&funcionarios);



    for(i=0; i<funcionarios; i++)
    {
        printf("\nInforme o sal�rio do funcion�rio n� %d: ",i+1);
        scanf("%d",&salarios[i]);
    }

    for(i=0; i<funcionarios; i++)
    {
        soma = soma + salarios[i];
    }

    //C�lculo de m�dia e atribui��o de caracter�stica referente.
    media = soma/funcionarios;

    for (i=0; i<funcionarios; i++)
    {
        if (salarios[i]>media)
        {
            AcimaDaMedia = AcimaDaMedia+1;
        }
        if (salarios[i]<=media)
        {
            AbaixoDaMedia = AbaixoDaMedia+1;
        }
    }

    //C�lculo da porcentagem.
    PorcentagemAcima = (float)AcimaDaMedia/funcionarios*100;
    PorcentagemAbaixo = 100 - PorcentagemAcima;

    //Retorno desejado.
    printf("\n%.2f%% dos funcion�rios recebem um sal�rio acima da m�dia.",PorcentagemAcima);
    printf("\n%.2f%% dos funcion�rios recebem um sal�rio abaixo da m�dia.",PorcentagemAbaixo);

    Sleep(5000);
    return 0;
}
