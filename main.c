#include <stdio.h>

typedef enum {
    add, sub, mul, //div
} Calculator;

typedef struct {
    Calculator calculator;
    double var1;
    double var2;
} Calc;

double Add (double a,double b) {
    return a + b;
}

double Sub (double a,double b) {
    return a - b;
}

double Mul (double a, double b) {
    return a * b;
}

//div -> nanti kalo dibagi 0 error aja  (kalo var2 = 0 error)

double hasil (Calc k) {
    switch (k.calculator) {
    case add: return Add(k.var1,k.var2);
    case sub: return Sub(k.var1,k.var2);
    case mul: return Mul(k.var1,k.var2);
    //div
    }
}

int main () {
    int pilihan;
    Calc kalkulator;
    double Hasil;

    printf("=== Program Kalkulator Sederhana untuk 2 Angka ===\n");

    do {
        printf("\n\nSilahkan pilih Opsi dibawah ini\n\n");
        printf("0. Addition\n");
        printf("1. Subtraction\n");
        printf("2. Multiplication\n");
        printf("3. Division\n");
        printf("4. Stop\n\n");

        printf("Pilihan anda : ");
        scanf("%d", &pilihan);

        if (pilihan == 4) {
            break;
        }

        kalkulator.calculator = (Calculator)pilihan;

        printf("\nMasukkan angka pertama : ");
        scanf("%lf", &kalkulator.var1);

        printf("Masukkan angka kedua : ");
        scanf("%lf", &kalkulator.var2);      
        
        Hasil = hasil(kalkulator);

        printf("\nHasilnya adalah : %.2f", Hasil);

    } while (pilihan != 4);

    return 0;
}
