#include <stdio.h>
#include <math.h>

//made by: 2cache

typedef struct XY {
    int x;
    int y;
};

//4
//0 2
//-2 -3
//0 3
//2 -3
/*
int is_sym(int n, int total, struct XY *last_point) {
    int x = 0;
    int y = 0;
    scanf("%d", &x);
    scanf("%d", &y);
    struct XY new_last_point = {x, y};
    if (x == 0) return 0;
    else {
        if (n < total / 2 + 1) {
            int last_func_call = is_sym(n + 1, total, &new_last_point);
            int pair_cord = is_sym(2 * (total / 2 + 1) - n, total, &new_last_point);
            if (((*pair_cord).x == -x) && ((*pair_cord).y == y) && (last_func_call == 0)) return 0;
            else return 1;
            //return is_sym(n + 1, total) + ((x<<16) + is_sym(2 * (total / 2 + 1) - n, total) - y);
        }
        else {
            return &last_point;
        }
    }
}*/

int main(void){
    int n = 0;
    scanf("%d", &n);

    int x = 0, y = 0;

    scanf("%d", &x);
    scanf("%d", &y);
    struct XY first_point = {x, y};
    struct XY *adr = &first_point;
    struct XY new_point = *adr;
    printf("%d %d", adr, new_point.x);
    //int res = is_sym(2, n, &first_point);
    //if (res == 0) printf("Yes");
    //else printf("No");
    return 0;
}




int is_sym(n, total, struct XY prev_cord) {
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);
    struct XY last_cord = {x, y};
    if (!x) return 0;
    int zero_call = is_sym(n + 1, total, last_cord);
    int find_pair = is_sym(2 * (total / 2 + 1) - n, total, last_cord);
    if (!zero_call && )


    return 1;
}*/












