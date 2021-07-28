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
    int salarios [500000]; /*Não vi necessidade para manter esse vetor como uma variável, pois números de funcionários maiores
    que esse são impraticáveis de serem inseridos manualmente. Mesmo assim, 500 mil já é maior do que a quantidade de funcionários
    da grande maioria das companhias existentes no mundo (apenas 12 empresas superam esse número), então esse tamanho supriria
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
//Prefiro declarar cada variável individualmente porque acho melhor de visualizar.

    //Coleta de informações (Quantidade de funcionários e salário dos funcionários)
    printf("\nQuantos funcionários deseja incluir? (Favor inserir um número inteiro maior que 0) ");
    scanf("%d",&funcionarios);



    for(i=0; i<funcionarios; i++)
    {
        printf("\nInforme o salário do funcionário n° %d: ",i+1);
        scanf("%d",&salarios[i]);
    }

    for(i=0; i<funcionarios; i++)
    {
        soma = soma + salarios[i];
    }

    //Cálculo de média e atribuição de característica referente.
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

    //Cálculo da porcentagem.
    PorcentagemAcima = (float)AcimaDaMedia/funcionarios*100;
    PorcentagemAbaixo = 100 - PorcentagemAcima;

    //Retorno desejado.
    printf("\n%.2f%% dos funcionários recebem um salário acima da média.",PorcentagemAcima);
    printf("\n%.2f%% dos funcionários recebem um salário abaixo da média.",PorcentagemAbaixo);

    Sleep(5000);
    return 0;
}
