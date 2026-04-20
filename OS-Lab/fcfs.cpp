#include <stdio.h>

int main() {
    int n, i, bt[10], wt[10], tt[10];
    float totwt = 0, tottt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("BT for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i < n; i++) {
        tt[i] = wt[i] + bt[i];
        totwt += wt[i];
        tottt += tt[i];
    }

    printf("\nPID\tBT\tWT\tTT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tt[i]);

    printf("\nAvg WT = %.2f\nAvg TT = %.2f\n", totwt / n, tottt / n);

    return 0;
}
