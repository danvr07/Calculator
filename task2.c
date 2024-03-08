#include <stdio.h>
#define MAX 100

int main() {
    float numere[MAX], out[MAX], rez = 0;  //  VECTORII PENTRU NUMERE
    char operand[MAX], operand1[MAX];  //  VECTORII PENTRU OPERATII
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &numere[i]);
    }
    if (n > 1) {
        scanf("%s", operand);
    }

    int i = 0, j = 0, c = 0, d = 0;

    for (j = 0, i = 0; j < n - 1; j++, i++) {
        if (operand[i] == '+' || operand[i] == '-') {
            out[c] = numere[i];
            c++;
        }
        if (operand[j] == '*') {
            out[c] = numere[j] * numere[j + 1];
            numere[j + 1] = out[c];
        } else if (operand[j] == '/') {
            out[c] = numere[j] / numere[j + 1];
            numere[j + 1] = out[c];
        }
    }
    out[c] = numere[i];

    for (int r = 0; r < n - 1; r++) {
        if (operand[r] == '+' || operand[r] == '-') {
            operand1[d] = operand[r];
            d++;
        }
    }
    int m = 0, a = 0;

    while (m < n - 1) {
        if (m == 0) {
            if (operand1[m] == '+') {
                rez = out[a] + out[a + 1];
            }
            if (operand1[m] == '-') {
                rez = out[a] - out[a + 1];
            } else if (operand1[m] != '+' && operand1[m] != '-')  {
                rez = out[a];
            }
        } else {
            if (operand1[m] == '+')
                rez += out[a + 1];
            if (operand1[m] == '-')
                rez -= out[a + 1];
        }
        m++;
        a++;
    }
    if (n == 1) {
        rez = numere[i];
    }
    printf("%f\n", rez);
    return 0;
}
