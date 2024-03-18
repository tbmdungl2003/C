#include <stdio.h>

#define maxn 20

int n, m;
int c = 0;
int a[maxn];
int x[maxn];
int lonnhat = 0;

void Try(int k, int curr) {
    if (k == n + 1) {
        if (curr == m) {
            if (lonnhat < x[1] * x[2] * x[3]) {
                lonnhat = x[1] * x[2] * x[3];
            }
        }
        return;
    }
    for (int i = 1; i <= m - curr; i++) {
        x[k] = i;
        Try(k + 1, i * a[k] + curr);
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    Try(1, 0);
    printf("%d\n", lonnhat);
    return 0;
}
