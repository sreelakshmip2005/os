#include <stdio.h>

struct P {
    int pid, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, time = 0, q = 3;
    struct P p[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        p[i].pid = i+1;
        printf("\nAT and BT for P%d: ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].rt = p[i].bt;
    }

    int done;
    do {
        done = 1;

        for(int i=0;i<n;i++) {
            if(p[i].rt > 0) {
                done = 0;

                if(p[i].rt > q) {
                    time += q;
                    p[i].rt -= q;
                } else {
                    time += p[i].rt;
                    p[i].ct = time;
                    p[i].rt = 0;

                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                }
            }
        }
    } while(!done);

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    return 0;
}
