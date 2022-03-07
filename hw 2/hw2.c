#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    fp=fopen("lotto.txt","w+");
    int n;
    scanf("%d",&n);
    int a[6];
    int b[70];
    int c;
    for (int i=1; i<70; i++){
        b[i]=i;
    }
    time_t curtime;
    time(&curtime);
    fprintf(fp,"\n======== lotto649 =========\n");
    fprintf(fp,"= %s", ctime(&curtime));
    srand(time(NULL));
    for (int x=1; x<=5; x++) {
        if ( x <= n) {
            fprintf(fp,"[%d]:",x);
            for (int i=0; i<6; i++) {
                a[i]=rand() % 70;
                for(;b[a[i]]==0;) {
                    a[i]=rand() % 70;
                }
                b[a[i]]=0;
            }
            for (int i=1; i<70; i++){
                if ( b[i] == 0) {
                    if ( i < 10) {
                        fprintf(fp,"0");
                    }
                    fprintf(fp,"%d ",i);
                }
            }
            c=(rand() % 10)+1;
            if ( c < 10) {
                fprintf(fp,"0");
            }
            fprintf(fp,"%d", c);
        }else {
            fprintf(fp,"[%d]: -- -- -- -- -- -- --", x);
        }
        fprintf(fp,"\n");
        for (int i=1; i<70; i++) {
            b[i]=i;
        }
    }
    fprintf(fp,"======== csie@CGU =========");
    fclose(fp);
    return 0;
}