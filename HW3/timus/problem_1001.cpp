#include <cmath>
#include <cstdio>

#define SIZE (256 * 1024) / sizeof(double)
double n[SIZE + 1];

int main() {
    int s = 0;

    while (scanf("%lf", &(n[s])) != EOF) {
        s++;
    }

    s -= 2;
    for (; s >= 0; s--) printf("%.4f\n", sqrt(n[s]));
}
