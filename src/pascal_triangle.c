#include <stdio.h>
#include <stdlib.h>

void fck();
void output_the_base(int **a, int n);
void input_triangle(int **a, int n);
void output_the_matrix(int **a, int n, int counter, int n_matrix);

int main() {
    int n;
    int max;
#ifdef BASE
    max = 30;
#endif
#ifdef MATRIX
    max = 10;
#endif
    if (!scanf("%d", &n) || n < 1 || n > max) {
        fck();
        return 1;
    }
#ifdef MATRIX
    int counter = n * n;
    int n_matrix = n;
    int i = 1;
    for (; counter > i; i++) counter = counter - i;
    counter = n * n;
    n = i;
#endif
    int **a = (int **)malloc(n * sizeof(int *));
    input_triangle(a, n);
#ifdef BASE
    output_the_base(a, n);
#endif
#ifdef MATRIX
    output_the_matrix(a, n, counter, n_matrix);
#endif
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    return 0;
}

void input_triangle(int **a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc((i + 1) * sizeof(int));
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
}

void output_the_matrix(int **a, int n, int counter, int n_matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d", a[i][j]);
            counter--;
            if (!counter) break;
            if (counter % n_matrix == 0)
                printf("\n");
            else
                printf(" ");
        }
    }
}

void output_the_base(int **a, int n) {
    for (int j = 0; j < n; j++) {
        if (j < n - 1)
            printf("%d ", a[n - 1][j]);
        else
            printf("%d", a[n - 1][j]);
    }
}

void fck() { fprintf(stderr, "Puck you, Verter!"); }