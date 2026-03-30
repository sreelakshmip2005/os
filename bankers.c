#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter processes and resources: ");
    scanf("%d %d", &n, &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int finish[n], safe[n], work[m];

    printf("Enter Allocation:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Max:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available:\n");
    for(j=0;j<m;j++)
        scanf("%d",&avail[j]);

    // Need = Max - Allocation
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(j=0;j<m;j++) work[j] = avail[j];
    for(i=0;i<n;i++) finish[i] = 0;

    int count = 0;

    while(count < n) {
        for(i=0;i<n;i++) {
            if(!finish[i]) {
                for(j=0;j<m;j++)
                    if(need[i][j] > work[j]) break;

                if(j == m) {
                    for(k=0;k<m;k++)
                        work[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    if(count == n) {
        printf("Safe Sequence: ");
        for(i=0;i<n;i++)
            printf("P%d ", safe[i]);
    } else {
        printf("Deadlock (Unsafe)");
    }

    return 0;
}
