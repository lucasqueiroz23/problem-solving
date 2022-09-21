#include <stdio.h>
#include <stdlib.h>
#define MAIORIA 0.51
#define hash(v,m) (v%m)

typedef struct dadosSenadorDeputado
{
    int posicao,quantidadeVotos;

} dadosSenadorDeputado;

int htPres[100];
dadosSenadorDeputado htSen[1000];
dadosSenadorDeputado htDepFed[10000];
dadosSenadorDeputado htDepEst[100000];

typedef struct votacaoPresidencial
{
    int pos,quantidade;

} votacaoPresidencial;

void solvePresidente(int num,votacaoPresidencial *v)
{

    int x = hash(num,100);
    htPres[x] += 1;
    if( htPres[x] > v->quantidade)
    {
        v->quantidade = htPres[x];
        v->pos = x;
    }

}

void solveDepEst(int voto)
{
	int x = hash(voto,100000);
	htDepEst[x].quantidadeVotos+=1;

}
void solveDepFed(int voto)
{
    int x = hash(voto,10000);
	htDepFed[x].quantidadeVotos+=1;

}
void solveSenador(int voto)
{
    int x = hash(voto,1000);
	htSen[x].quantidadeVotos+=1;

}

int devolveQuantidadeDigitos(int x)
{
    int val = 0;
    while(x!=0)
    {
        val++;
        x = x/10;
    }
    return val;
}

void inicializaPosicoes()
{
	for(int i = 0;i<1000;i++)
		htSen[i].posicao = i;
	for(int i = 0;i<10000;i++)
		htDepFed[i].posicao = i;
	for(int i = 0;i<100000;i++)
		htDepEst[i].posicao = i;

}


void merge(dadosSenadorDeputado *v, int l, int m, int r)
{
    dadosSenadorDeputado *v2 = malloc(sizeof(dadosSenadorDeputado)*(r-l+1));
    int k=0;
    int i = l;
    int j = m+1;
    while(i<=m && j<=r)
    {
        if(v[i].quantidadeVotos<=v[j].quantidadeVotos)
        {
            v2[k].quantidadeVotos = v[i].quantidadeVotos;
            v2[k].posicao = v[i].posicao;
            i++;
            k++;
        }
        else
        {
            v2[k].quantidadeVotos = v[j].quantidadeVotos;
            v2[k].posicao = v[j].posicao;
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        v2[k].quantidadeVotos = v[i].quantidadeVotos;
        v2[k].posicao = v[i].posicao;
        i++;
        k++;
    }
    while(j<=r)
    {
        v2[k].quantidadeVotos = v[j].quantidadeVotos;
        v2[k].posicao = v[j].posicao;
        j++;
        k++;
    }
    k=0;
    for(i = l; i<=r; i++)
    {
        v[i].quantidadeVotos= v2[k].quantidadeVotos;
        v[i].posicao = v2[k].posicao;
        k++;
    }


    free(v2);

}

void mergeSort(dadosSenadorDeputado *v, int l, int r)
{
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSort(v,l,m);
    mergeSort(v,m+1,r);
    merge(v,l,m,r);

}

int main()
{
    int quantidadeSenadores=0,quantidadeDepFed=0,quantidadeDepEst=0;
    scanf("%d %d %d",&quantidadeSenadores,&quantidadeDepFed,&quantidadeDepEst);
    int voto=0,quantidadeVotosValidos=0,quantidadeVotosInvalidos=0;

    votacaoPresidencial vPresidente;
    vPresidente.pos=-1;
    vPresidente.quantidade=-1;
    int votosPresidente=0;

	inicializaPosicoes();

    while(scanf("%d",&voto)!=EOF)
    {
        int qtdDigitos = 0;
        if(voto>0)
        {
            quantidadeVotosValidos++;
            qtdDigitos = devolveQuantidadeDigitos(voto);
        }
        else
        {
            quantidadeVotosInvalidos++;
            continue;
        }

        switch(qtdDigitos)
        {
        case 2:
            solvePresidente(voto,&vPresidente);
            votosPresidente++;
            break;
        case 3:
            solveSenador(voto);
            break;
        case 4:
            solveDepFed(voto);
            break;
        case 5:
            solveDepEst(voto);
            break;

        }

    }
    printf("%d %d\n",quantidadeVotosValidos,quantidadeVotosInvalidos);
    double x = (double)vPresidente.quantidade/(double)votosPresidente;

    if(x>=MAIORIA) printf("%d\n",vPresidente.pos);
    else printf("Segundo turno\n");


	mergeSort(htSen,0,999);
	mergeSort(htDepFed,0,9999);
	mergeSort(htDepEst,0,99999);

	int i;
	i = 999;
	while(quantidadeSenadores!=0)
	{
		printf("%d ",htSen[i].posicao);

		i--;
		quantidadeSenadores--;
	}
	printf("\n");

	i = 9999;
	while(quantidadeDepFed!=0)
	{
		printf("%d ",htDepFed[i].posicao);

		i--;
		quantidadeDepFed--;
	}
	printf("\n");

	i = 99999;
	while(quantidadeDepEst!=0)
	{
		printf("%d ",htDepEst[i].posicao);

		i--;
		quantidadeDepEst--;
	}
	printf("\n");

    return 0;
}
