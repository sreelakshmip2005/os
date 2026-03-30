#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]), f = atoi(argv[2]);
    int ref[n], frame[f], time[f];
    int i,j,k,least,fault=0,found,t=0;

    srand(time(0));

    for(i=0;i<n;i++){
        ref[i]=rand()%10;
        printf("%d ",ref[i]);
    }

    for(i=0;i<f;i++){
        frame[i]=-1;
        time[i]=0;
    }

    for(i=0;i<n;i++){
        found=0;
        for(j=0;j<f;j++){
            if(frame[j]==ref[i]){
                found=1;
                time[j]=++t;
            }
        }

        if(!found){
            least=0;
            for(j=1;j<f;j++)
                if(time[j]<time[least]) least=j;

            frame[least]=ref[i];
            time[least]=++t;
            fault++;
        }
    }

    printf("\nLRU Page Faults: %d",fault);
    return 0;
}
