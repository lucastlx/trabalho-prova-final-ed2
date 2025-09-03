#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor, peso;
    float valorpeso;
} Item;

int main() {
    int i1, i2, i3 = 0, i4, i5;
    float i6 = 0.0;

    printf("quantidade de itens: ");
    scanf("%d", &i1);

    Item *item = (Item*) malloc(sizeof(Item) * i1);

    for(i4 = 0; i4 < i1; i4++) {
        printf("valor%d: ", i4);
        scanf("%d", &item[i4].valor);
        printf("item%d: ", i4);
        scanf("%d", &item[i4].peso);
        if (item[i4].peso == 0) {
            item[i4].valorpeso = 0;
        } else {
            item[i4].valorpeso = (float)item[i4].valor / item[i4].peso;
        }
    }

    for(i4 = 0; i4 < i1-1; i4++) {
        for(i5 = i4+1; i5 < i1; i5++) {
            if(item[i5].valorpeso > item[i4].valorpeso) {
                Item tmp = item[i4];
                item[i4] = item[i5];
                item[i5] = tmp;
            }
        }
    }

    printf("capacidade mochila: ");
    scanf("%d", &i2);

    for(i4 = 0; i4 < i1; i4++) {
        if(i2 == 0) {
            break;
        }
        if(item[i4].peso <= i2) {
            i2 -= item[i4].peso;
            i6 += item[i4].valor;
            i3 += item[i4].peso;
        } else {
            i6 += item[i4].valorpeso * i2;
            i3 += i2;
            i2 = 0;
        }
    }

    printf("valor total: %.2f\n", i6);
    printf("peso usado: %d\n", i3);

    free(item);
    return 0;
}
