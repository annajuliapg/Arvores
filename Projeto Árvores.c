#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

enum Balance {E,C,D}; // esquerda, centro, direita

typedef enum Balance Balance;

struct no
{
    int chave;
    Balance bal;
    struct no *esq, *dir;
};

typedef struct no no;

void insere(no **, int, int *);

int main ()
{
    setlocale(LC_ALL,"portuguese");

    int menu, num;

    no *raiz = NULL;
    no *inicio;

    int h; /* Flag para verificar se a altura da árvore fo alterada */


    do
    {
        system("cls");
        printf("\n\n\t-----------");
        printf("\n\t| Árvores |");
        printf("\n\t-----------");

        printf("\n\n\tMENU\n\n");

        printf("\n\t1.Inserção Balanceada");
        printf("\n\n\t2.Remoção Balanceada");
        printf("\n\n\t3.Percursos em profundidade (em ordem, preordem e posordem)");
        printf("\n\n\t4.Percurso em largura");
        printf("\n\n\t5.Contagens (número total de nós, nós folha, nós com um filho, enós com dois filhos)");
        printf("\n\n\t6.Altura da árvore");
        printf("\n\n\t7.Média dos valores armazenados na árvore");
        printf("\n\n\t8.Menor valor armazenado");
        printf("\n\n\t9.Maior valor armazenado");
        printf("\n\n\t10.Verificação se as duas árvores são iguais (mesma estrutura e mesmos valores nas mesmas posições)");
        printf("\n\n\t11.Verificação se duas árvores são semelhantes (mesma estrutura, independentemente dos valores dos nós)");
        printf("\n\n\t12.Verificação se duas árvores são simétricas (uma é a imagem da outra refletida em um espelho)");
        printf("\n\n\t13.Verificação se um elemento de valor x está em alguma ou nas duas árvores");
        printf("\n\n\t14.Verificação de quais valores estão em ambas as árvores (equivalente à intersecção de conjuntos)");
        printf("\n\n\t15.Verificação de todos os elementos que estão em pelo menos uma das árvores (equivalente à união de conjuntos)");
        printf("\n\n\t0.Sair\n");

        printf("\n\n\tDigite a opcão: ");
        scanf("%d",&menu);

        switch (menu)
        {
            case 1:
            system("cls");
            printf("\n\tDigite o némero que deseja inserir: ");
            scanf("%d",&num);
            h=0;
            insere(&raiz, num,&h);
            printf("\n\n\tNúmero inserido!");
            printf("\n\n\n\t");
            system("PAUSE");
            break;

            case 2:
            system("cls");

            break;

            case 3:
            system("cls");

            break;

            case 4:
            system("cls");

            break;

            case 5:
            system("cls");

            break;

            case 6:
            system("cls");

            break;

            case 7:
            system("cls");

            break;

            case 8:
            system("cls");

            break;

            case 9:
            system("cls");

            break;

            case 10:
            system("cls");

            break;

            case 11:
            system("cls");

            break;

            case 12:
            system("cls");

            break;

            case 13:
            system("cls");

            break;

            case 14:
            system("cls");

            break;

            case 15:
            system("cls");

            break;

            case 0:
            exit(1);

            default:
            printf("\n\n\tNúmero Inválido");
            printf("\n\n\n\t");
            system("PAUSE");
            break;
        }

    }while(menu!=0);

    printf("\n\n\n\n\n\t");
    system("pause");
    return 0;
}

void insere(no **raiz, int n, int *h)
{
    struct no *p1, *p2;

    if (*raiz == NULL)
    {
        *raiz = (struct no *) malloc(sizeof(struct no));
        *h=1;
        (*raiz) -> chave = n;
        (*raiz) -> esq = (*raiz) -> dir = NULL;
        (*raiz) -> bal=C;
     }
     else
    {
       if (n < (*raiz)->chave)
       {
            insere (&(*raiz)->esq,n,h);

            if (*h)
            {
                switch ((*raiz)->bal)
                {
                   case D:
                   (*raiz)->bal = C;
                    *h=0;
                    break;

                    case C:
                    (*raiz)->bal = E;
                    break;

                    case E:
                    p1= (*raiz) -> esq;
                    if (p1->bal == E) // rebalanceamento simples
                    {
                        (*raiz) -> esq = p1->dir;
                        p1->dir = (*raiz);
                        (*raiz)->bal= C;
                        (*raiz) = p1;
                    }
                    else //rebalanceamento duplo
                    {
                        p2 = p1->dir;
                        p1->dir = p2->esq;
                        p2->esq = p1;
                        (*raiz)->esq=p2->dir;
                        p2->dir=(*raiz);

                        if (p2->bal==E) (*raiz)->bal = D;
                            else (*raiz)->bal = C;

                        if (p2->bal==D) p1->bal = E;
                            else p1->bal = C;

                         (*raiz) = p2;

                    }
                    (*raiz)->bal = C;
                    *h=0;
                    break;
                }
            }
        }
        else
            if (n > (*raiz)->chave)
            {
                insere (&(*raiz)->dir,n,h);

                if (*h)
                {
                    switch ((*raiz)->bal)
                    {
                        case E:
                        (*raiz)->bal = C;
                        *h=0;
                        break;

                        case C:
                        (*raiz)->bal = D;
                        break;

                        case D:
                        p1= (*raiz) -> dir;

                        if (p1->bal == D) // rebalanceamento simples
                        {
                            (*raiz) -> dir = p1->esq;
                            p1->esq = (*raiz);
                            (*raiz)->bal= C;
                            (*raiz) = p1;
                        }
                        else //rebalanceamento duplo
                        {
                            p2 = p1->esq;
                            p1->esq = p2->dir;
                            p2->dir = p1;
                            (*raiz)->dir=p2->esq;
                            p2->esq=(*raiz);

                            if (p2->bal==D) (*raiz)->bal = E;
                                else (*raiz)->bal = C;

                            if (p2->bal==E) p1->bal = D;
                                else p1->bal = C;

                            (*raiz) = p2;
                        }

                        (*raiz)->bal = C;
                        *h=0;
                        break;
                    }
                }
            }

    }

}
