#include <stdio.h>
#include <stdlib.h>

void fck();
void output_the_base(int **a, int n);
void input_triangle(int **a, int n);

int main() {
    int n;
    int max = 30;
    if (!scanf("%d", &n) || n < 1 || n > max) {
        fck();
        return 1;
    }
    int **a = (int **)malloc(n * sizeof(int *));
    input_triangle(a, n);
    output_the_base(a, n);
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

void output_the_base(int **a, int n) {
    for (int j = 0; j < n; j++) {
        if (j < n - 1)
            printf("%d ", a[n - 1][j]);
        else
            printf("%d", a[n - 1][j]);
    }
}

void fck() { fprintf(stderr, "Puck you, Verter!"); }