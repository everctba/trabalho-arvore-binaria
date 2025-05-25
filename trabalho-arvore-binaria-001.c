#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define TRUE 1
#define FALSE 0
struct No
{
    int num;
    struct No *esq;
    struct No *dir;
};
struct No *raiz, *paux, *pnovo;
void incluir();
void excluir();
void preordem(struct No *node);
void emordem(struct No *node);
void posordem(struct No *node);
void pesquisar(struct No *node);
int incluirNo(struct No* p, int c);
int excluirNo(struct No* p, int c);
int pesquisarNo(struct No *node, int c);
int main()
{
    int op;
    setlocale(NULL, "Portuguese");
    raiz = NULL;
    do
    {
        system("cls");
        printf("\n+===================================+");
        printf("\n| M E N U P R I N C I P A L |");
        printf("\n+===================================+");
        printf("\n| 1. Incluir |");
        printf("\n| 2. Excluir |");
        printf("\n| 3. Pré-Ordem (R-E-D) |");
        printf("\n| 4. Em-Ordem (E-R-D) |");
        printf("\n| 5. Pós-Ordem (E-D-R) |");
        printf("\n| 6. Pesquisar |");
        printf("\n| 9. Finalizar |");
        printf("\n+===================================+");
        printf("\nDigite a opção....: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            incluir();
            break;
        case 2:
            excluir();
            break;
        case 3:
            preordem(raiz);
            getch();
            break;
        case 4:
            emordem(raiz);
            getch();
            break;
        case 5:
            posordem(raiz);
            getch();
            break;
        case 6:
            pesquisar(raiz);
            getch();
            break;
        case 9:
            ;
            break;
        default:
            ;
            break;
        }
    }
    while(op != 9);
    printf("\n\n\n\n\n\n");
    return 0;
}
void incluir()
{
    int c;
    system("cls");
    printf("\n+--------------------------+");
    printf("\n| PROCEDIMENTO DE INCLUSÃO |");
    printf("\n+--------------------------+");
    pnovo = (struct No *)(malloc(sizeof(struct No)));
    printf("\nDigite o número a incluir.....: ");
    scanf("%d", &c);
    pnovo->num = c;
    if (raiz == NULL)
    {
        pnovo->esq = NULL;
        pnovo->dir = NULL;
        raiz = pnovo;
    }
    else
    {
        incluirNo(raiz, c);
    }
    printf("\n\n Elemento incluído\n\n");
    getch();
}
int incluirNo(struct No* p, int c)
{
}
void excluir()
{
    int c;
    system("cls");
    printf("\n+--------------------------+");
    printf("\n| PROCEDIMENTO DE EXCLUSÃO |");
    printf("\n+--------------------------+");
    if (raiz == NULL)
    {
        printf("\n\n ÁRVORE VAZIA");
        getch();
        return;
    }
    printf("\nDigite o número a excluir....: ");
    scanf("%d", &c);
    getch();

}
//int incluirNo(struct No* p, int c)
//{
//}
void preordem(struct No *node)
{
// raiz - esquerda - direita
    if (node == NULL)
    {
        return;
    }
    printf("\n%d", node->num);
    preordem(node->esq);
    preordem(node->dir);
}
void emordem(struct No *node)
{
// esquerda - raiz - direita
    if (node == NULL)
    {
        return;
    }
    emordem(node->esq);
    printf("\n%2d no: %p esq: %p dir: %p", node->num, node, node->esq, node->dir);
    emordem(node->dir);
}
void posordem(struct No *node)
{
// esquerda - direita - raiz
    if (node == NULL)
    {
        return;
    }
    posordem(node->esq);
    posordem(node->dir);
    printf("\n%d", node->num);
}
int pesquisarNo(struct No *node, int c)
{
}
void pesquisar(struct No *node)
{
    int c;
    system("cls");
    printf("\n+--------------------------+");
    printf("\n| PROCEDIMENTO DE PESQUISA |");
    printf("\n+--------------------------+");
    if (raiz == NULL)
    {
        printf("\n\n ÁRVORE VAZIA");
        getch();
        return;
    }
    printf("\nDigite o número a pesquisar...: ");
    scanf("%d", &c);
    if (pesquisarNo(raiz, c) == TRUE)
    {
        printf("\nNúmero encontrado");
    }
    else
    {
        printf("\nNúmero Não encontrado");
    }
}
