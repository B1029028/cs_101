#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define counter_file "counter.bin"
void init_file() {
    int write_array[1] = {0};
    FILE* fp = fopen(counter_file,"r");
    if (fp == NULL) {
        FILE* tmpfp = fopen(counter_file, "wb+");
        fwrite(write_array, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    }else {
        fclose(fp);
    }
}
int get_counter() {
    int read_array[1];
    FILE* tmpfp = fopen(counter_file, "rb");
    fread(read_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
    return read_array[0];
}
void set_counter(int counter) {
    int write_array[1];
    write_array[0] = counter;
    FILE* tmpfp = fopen(counter_file, "wb");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}
void dolotto(char lotto_file[], int counter) {
    FILE *fp;
    fp=fopen(lotto_file,"w+");
    int n;
    printf("請問你要買幾組樂透彩");
    scanf("%d",&n);
    int a[6];
    int b[70];
    int c;
    for (int i=1; i<70; i++){
        b[i]=i;
    }
    time_t curtime;
    time(&curtime);
    fprintf(fp,"======== lotto649 =========\n");
    fprintf(fp,"=======+ No.%05d +========\n", counter);
    fprintf(fp,"= %.*s\n", 24, ctime(&curtime));
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
}
int main() {
    int counter;
    init_file();
    counter = get_counter();
    counter++;
    char lotto_file[32];
    snprintf(lotto_file, 32, "lotto[%05d].txt", counter);
    dolotto(lotto_file, counter);
    set_counter(counter);
    return 0;
}