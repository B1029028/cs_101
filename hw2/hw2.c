#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define counter_file "counter.bin"
#define operate_id_file "operate_id.bin"
#define records_file "records.bin"
#define operator_id_file "operator_id.bin"
typedef struct lotto_record_t {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[32];
    char lotto_time[32];
} typelotto_record;
typedef struct emp_record_t{
    int emp_id;
    char emp_name[32];
    int emp_salary;
} emp_record;
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
void init_file2() {
    int write_array[1] = {0};
    FILE* tmpfp = fopen(operate_id_file, "r");
    if(tmpfp == NULL){
        FILE* fp = fopen(operate_id_file, "wb+");
        fwrite(write_array, sizeof(int), 1, fp);
        fclose(fp);
    }else  {
        fclose(tmpfp);
    }
}
int get_op_id(int id) {
    int write_array[1];
    write_array[0] = id;
    FILE* tmpfp = fopen(operate_id_file, "wb+");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
    return(write_array[0]);
}
void set_op_id(int id) {
    int write_array[1];
    write_array[0] = id;
    FILE* tmpfp = fopen(operate_id_file, "wb");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}
int make_struct(int counter, int n, int id) {
    if( id == 0) {
        int new_id;
        char new_name[32];
        int new_salary;
        printf("請輸入要新增的操作人員(ID):");
        scanf("%d", &new_id);
        printf("請輸入要新增的操作人員(Name):");
        scanf("%s", &new_name[32]);
        printf("請輸入要新增的操作人員(salary):");
        scanf("%d", &new_salary);
        emp_record records;
        records.emp_id = new_id;
        strcpy(records.emp_name, new_name);
        records.emp_salary = new_salary;
        FILE* fp = fopen(operator_id_file, "ab");
        fwrite(&records, sizeof(records), 1, fp);
        fclose(fp);
        //printf("%d", records.emp_id);
        //printf("%s", records.emp_name);
        //printf("%d", records.emp_salary);
        id = new_id;
    }
    char Date[32];
    char Time[32];
    time_t now = time(0);
    strftime(Date, 100, "%Y%m%d", localtime(&now));
    strftime(Time, 100, "%H:%M:%S", localtime(&now));
    typelotto_record lotto;
    lotto.lotto_no = counter;
    lotto.lotto_receipt = n*50*(1.1);
    lotto.emp_id = id;
    strcpy(lotto.lotto_date, Date);
    strcpy(lotto.lotto_time, Time);
    FILE* fp = fopen(records_file, "ab");
    fwrite(&lotto, sizeof(lotto), 1, fp);
    fclose(fp);
    return(id);
}
void dolotto(char lotto_file[], int counter, int id) {
    FILE *fp;
    fp=fopen(lotto_file,"w+");
    int n;
    make_struct(counter, n, id);
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
    fprintf(fp,"=======* Op.%05d *========\n", id);
    fprintf(fp,"======== csie@CGU =========");
    fclose(fp);
}
int main() {
    int counter;
    init_file();
    init_file2();
    counter = get_counter();
    counter++;
    char lotto_file[32];
    snprintf(lotto_file, 32, "lotto[%05d].txt", counter);
    int id;
    printf("請輸入操作人員ID:");
    scanf("%d", &id);
    id = get_op_id(id);
    dolotto(lotto_file, counter, id);
    set_counter(counter);
    set_op_id(id);
    return 0;
}