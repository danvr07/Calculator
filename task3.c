#include <stdio.h>
#include <math.h>
#define MAX 100

int main() {
    float numere[MAX], out[MAX], out2[MAX], rez = 0;  //  VECTORII PENTRU NUMERE
    char operand[MAX], operand1[MAX], operand2[MAX];  //  VECTORII PENTRU OPERATII
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &numere[i]);
    }
    if (n > 1) {
        scanf("%s", operand);
    }

    int i = 0, j = 0, c = 0, d = 0, x = 0, y = 0, v = 0, q = 0;

    for (j = 0, i = 0; j < n - 1; j++, i++) {
        if (operand[i] == '+' || operand[i] == '-') {
            out[c] = numere[i];
            c++;
        } else if (operand[i] == '#') {
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
        } else if (operand[r] == '#') {
            operand1[d] = operand[r];
            d++;
        }
    }

    for (x = 0, y = 0; x < n - 1; x++, y++) {
        if (operand1[y] == '+' || operand1[y] == '-') {
            out2[v] = out[y];
            v++;
        }
        if (operand1[x] == '#') {
            out2[v] = (out[x] + out[x + 1]) * (out[x] + out[x + 1]);
            out[x + 1] = out2[v];
        }
    }
    if (v > 0) {
        out2[v] = numere[y];
    }

    for (int w = 0; w < n - 1; w++) {
        if (operand1[w] == '+' || operand1[w] == '-') {
            operand2[q] = operand1[w];
            q++;
        }
    }

    int m = 0, a = 0;

    while (m < n - 1) {
        if (m == 0) {
            if (operand2[m] == '+') {
                rez = out2[a] + out2[a + 1];
            }
            if (operand2[m] == '-') {
                rez = out2[a] - out2[a + 1];
            }
            if (operand1[m] != '+' && operand1[m] != '-' && operand1[m] != '#') {
                rez = out[a];
            } else if (operand2[m] != '+' && operand2[m] != '-' && operand2[m] != '*') {
                rez = out2[a];
            }
        } else {
            if (operand2[m] == '+')
                rez += out2[a + 1];
            if (operand2[m] == '-')
                rez -= out2[a + 1];
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
