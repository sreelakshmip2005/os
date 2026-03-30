#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int head = atoi(argv[1]);
    int req[10], done[10]={0};
    int i, j, pos, min, dist, total=0;

    srand(time(0));

    // generate requests
    for(i=0;i<10;i++){
        req[i]=rand()%5000;
        printf("%d ",req[i]);
    }

    // SSTF
    for(i=0;i<10;i++){
        min=9999;
        for(j=0;j<10;j++){
            if(!done[j]){
                dist=abs(head-req[j]);
                if(dist<min){
                    min=dist;
                    pos=j;
                }
            }
        }
        total += min;
        head = req[pos];
        done[pos]=1;
    }

    printf("\nTotal Head Movement: %d", total);
    return 0;
}
