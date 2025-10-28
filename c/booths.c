#include <stdio.h>
#include <stdlib.h>

void arithmeticRightShift(int *A, int *Q, int *Q_1, int n) {
    int last_A = A[0];
    for (int i = n - 1; i > 0; i--) {
        A[i] = A[i - 1];
    }
    A[0] = last_A;
    Q[*Q_1] = Q[n - 1];
    for (int i = n - 1; i > 0; i--) {
        Q[i] = Q[i - 1];
    }
    Q[0] = A[n - 1];
}

void addBinary(int *A, int *M, int n) {
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int sum = A[i] + M[i] + carry;
        A[i] = sum % 2;
        carry = sum / 2;
    }
}

void twosComplement(int *M, int n) {
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        M[i] = M[i] ^ 1;
        if (carry == 1) {
            if (M[i] == 0) {
                M[i] = 1;
                carry = 0;
            } else {
                M[i] = 0;
            }
        }
    }
}

void boothMultiplication(int *M, int *Q, int n) {
    int A[n];
    int Q_1 = 0;
    for (int i = 0; i < n; i++) {
        A[i] = 0;
    }
    int negM[n];
    for (int i = 0; i < n; i++) {
        negM[i] = M[i];
    }
    twosComplement(negM, n);
    printf("Steps:\n");
    for (int i = 0; i < n; i++) {
        printf("Step %d: ", i + 1);
        for (int j = 0; j < n; j++) printf("%d", A[j]);
        printf(" ");
        for (int j = 0; j < n; j++) printf("%d", Q[j]);
        printf(" %d\n", Q_1);
        if (Q[n - 1] == 1 && Q_1 == 0) {
            addBinary(A, negM, n);
        } else if (Q[n - 1] == 0 && Q_1 == 1) {
            addBinary(A, M, n);
        }
        arithmeticRightShift(A, Q, &Q_1, n);
    }
    printf("Final result: ");
    for (int i = 0; i < n; i++) printf("%d", A[i]);
    printf(" ");
    for (int i = 0; i < n; i++) printf("%d", Q[i]);
    printf("\n");
}

int main() {
    int n = 4;
    int M[4] = {0, 1, 1, 0};
    int Q[4] = {1, 0, 0, 1};
    boothMultiplication(M, Q, n);
    return 0;
}
