#include <stdio.h>

//made by: CDECL

int main(void){
    long n;
    int ost;
    long weight=1;/*вес текущей гири*/
    long total = 0;/*вес гирь на той чаше, где нет груза*/
    int result = 0;/*суммарное количество гирь*/
    scanf("%ld",&n);
    /*перевод в троичную систему, используя цифры -1,0,1*/
    while (n>0){
        ost = n % 3;
        n = n / 3;
        /*если в разряде должно получиться 1, то добавляем массу гири к счетчику и увеличиваем количество гирь на 1*/
        if (ost == 1){
            result +=1;
            total+=weight;
        }
        /*если в разряде должно получиться 2, то добавляем 1 к целой части деления n на 3 и как бы записываем -1, то есть добавляем гирю, но на другую чашу*/
        if (ost == 2){
            result += 1;
            n+=1;
        }
        /*увеличиваем вес текущей гири*/
        weight*=3;
    }
    /*если вес на чаше превысил 1 тонну, то выводим -1*/
    if (total > 1000000){
        printf("%d",-1);
    }
    /*если нет, то выводим количество гирь*/
    else{
        printf("%d",result);
    }

}
