#include <stdio.h>
#define MAX 100

int main() {
    float numere[MAX], rez = 0;  //  VECTOR PENTRU NUMERE
    char oper[MAX];  // VECTOR PENTRU OPERATII
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &numere[i]);
    }
    if (n > 1) {
        scanf("%s", oper);
    }

    int i = 0, j = 0;

    while (j < n - 1) {
        if (j == 0) {
            if (oper[j] == '*')
                rez = numere[i] * numere[i+1];
            if (oper[j] == '+')
                rez = numere[i] + numere[i+1];
            if (oper[j] == '-')
                rez = numere[i] - numere[i+1];
            if (oper[j] == '/')
                rez = numere[i] / numere[i+1];
        } else {
            if (oper[j] == '*')
                rez *= numere[i+1];
            if (oper[j] == '+')
                rez += numere[i+1];
            if (oper[j] == '-')
                rez -= numere[i+1];
            if (oper[j] == '/')
                rez /= numere[i+1];
        }
        j++;
        i++;
    }
    if (n == 1) {
        rez = numere[i];
    }
    printf("%f\n", rez);
    return 0;
}
