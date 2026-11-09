#include <stdio.h>

int main() {
    float urunTutari, odenenPara;
    int paraUstu;
    int toplamKupur = 0;

    int kupurler[] = {
        20000, 10000, 5000, 2000, 1000, 500,
        100, 50, 25, 10, 5, 1
    };

    int i, adet;

    printf("Urun tutarini giriniz: ");
    scanf("%f", &urunTutari);

    printf("Odenen parayi giriniz: ");
    scanf("%f", &odenenPara);

    // Para ustunu kurusa cevirme
    paraUstu = (int)((odenenPara - urunTutari) * 100 + 0.5);

    printf("\nPara ustu: %.2f TL\n", paraUstu / 100.0);       


    // Rapor:yuvarlama yapmadan donusum
    int yuvarlamasiz = (int)((odenenPara - urunTutari) * 100);
    printf("Yuvarlamasiz kurus: %d\n", yuvarlamasiz);
    printf("\nVerilecek kupurler:\n");

    for(i = 0; i < 12; i++) {

        adet = paraUstu / kupurler[i];

        if(adet > 0) {

            if(kupurler[i] >= 100) {
                printf("%d TL: %d adet\n",
                       kupurler[i] / 100, adet);
            }
            else {
                printf("%d kurus: %d adet\n",
                       kupurler[i], adet);
            }

            paraUstu = paraUstu % kupurler[i];

            toplamKupur += adet;
        }
    }

    printf("\nToplam kupur sayisi: %d\n", toplamKupur);

    return 0;
}
