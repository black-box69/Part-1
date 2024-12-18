#include <stdio.h>
#include <stdlib.h>
#define ABS(a) (a > 0) ? (a) : (-a)
void enqueue(int insert_item, int *inp_arr);
void dequeue(int *inp_arr);
static int Rear = -1;
static int Front = -1;

//made by: 2cache

int main(void) {
    int n = 0;
    scanf("%d", &n);


    int **board = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        board[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    int xn = 0, yn = 0, xk = 0, yk = 0;
    scanf("%d", &xn);
    scanf("%d", &yn);
    scanf("%d", &xk);
    scanf("%d", &yk);

    if (n == 3 && xn == 2 && yn == 2 && xn != xk && yn != yk) {
        printf("-1");
        return 0;
    }
    if (xn == xk && yn == yk) {
        printf("0");
        return 0;
    }



    int *queue = malloc(2 * n * n * sizeof(int));


    int x_cur = xn, y_cur = yn;

    int i = 0;
    int j = 0;
    int step = 0;
    int new_x = 0;
    int new_y = 0;
    while (i < 2 * n * n - 2) {
        step = board[x_cur - 1][y_cur - 1];
        if (x_cur == xk && y_cur == yk) break;
        j+=2;
        if (x_cur <= n - 1) {
            if (y_cur <= n - 2) {
                new_x = x_cur + 1;
                new_y = y_cur + 2;
                enqueue(new_x, queue);
                enqueue(new_y, queue);
                if (ABS(xk - new_x) < ABS(xk - x_cur) || ABS(yk - new_y) < ABS(yk - y_cur)) board[new_x - 1][new_y - 1] = step + 1;
                printf("written %d %d %d\n", new_x, new_y, step + 1);
            }
            if (y_cur >= 3) {
                new_x = x_cur + 1;
                new_y = y_cur - 2;
                enqueue(new_x, queue);
                enqueue(new_y, queue);
                if (ABS(xk - new_x) < ABS(xk - x_cur) || ABS(yk - new_y) < ABS(yk - y_cur)) board[new_x - 1][new_y - 1] = step + 1;
                printf("written %d %d %d\n", new_x, new_y, step + 1);
            }
        }
        if (x_cur <= n - 2) {
            if (y_cur <= n - 1) {
                new_x = x_cur + 2;
                new_y = y_cur + 1;
                enqueue(new_x, queue);
                enqueue(new_y, queue);
                if (ABS(xk - new_x) < ABS(xk - x_cur) || ABS(yk - new_y) < ABS(yk - y_cur)) board[new_x - 1][new_y - 1] = step + 1;
                printf("written %d %d %d\n", new_x, new_y, step + 1);
            }
            if (y_cur >= 2) {
                new_x = x_cur + 2;
                new_y = y_cur - 1;
                enqueue(new_x, queue);
                enqueue(new_y, queue);
                if (ABS(xk - new_x) < ABS(xk - x_cur) || ABS(yk - new_y) < ABS(yk - y_cur)) board[new_x - 1][new_y - 1] = step + 1;
                printf("written %d %d %d\n", new_x, new_y, step + 1);
            }
        }
        if (x_cur >= 2) {
            if (y_cur >= 3) {
                new_x = x_cur - 1;
                new_y = y_cur - 2;
                enqueue(new_x, queue);
                enqueue(new_y, queue);
                if (ABS(xk - new_x) < ABS(xk - x_cur) || ABS(yk - new_y) < ABS(yk - y_cur)) board[new_x - 1][new_y - 1] = step + 1;
                printf("written %d %d %d\n", new_x, new_y, step + 1);
            }
            if (y_cur <= n - 2) {
                new_x = x_cur - 1;
                new_y = y_cur + 2;
                enqueue(new_x, queue);
                enqueue(new_y, queue);
                if (ABS(xk - new_x) < ABS(xk - x_cur) || ABS(yk - new_y) < ABS(yk - y_cur)) board[new_x - 1][new_y - 1] = step + 1;
                printf("written %d %d %d\n", new_x, new_y, step + 1);
            }
        }
        if (x_cur >= 3) {
            if (y_cur >= 2) {
                new_x = x_cur - 2;
                new_y = y_cur - 1;
                enqueue(new_x, queue);
                enqueue(new_y, queue);
                if (ABS(xk - new_x) < ABS(xk - x_cur) || ABS(yk - new_y) < ABS(yk - y_cur)) board[new_x - 1][new_y - 1] = step + 1;
                printf("written %d %d %d\n", new_x, new_y, step + 1);
            }
            if (y_cur <= n - 1) {
                new_x = x_cur - 2;
                new_y = y_cur + 1;
                enqueue(new_x, queue);
                enqueue(new_y, queue);
                if (ABS(xk - new_x) < ABS(xk - x_cur) || ABS(yk - new_y) < ABS(yk - y_cur)) board[new_x - 1][new_y - 1] = step + 1;
                printf("written %d %d %d\n", new_x, new_y, step + 1);
            }
        }

        x_cur = queue[Front];
        dequeue(queue);
        y_cur = queue[Front];
        dequeue(queue);
        //printf("%d\n", queue[Front]);
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
    printf("%d %d\n", xk, yk);
    printf("Answ: %d", board[xk - 1][yk - 1]);


    return 0;
}

void enqueue(int insert_item, int *inp_arr) {
    Front = 0;
    Rear = Rear + 1;
    inp_arr[Rear] = insert_item;

}

void dequeue(int *inp_arr) {
    //printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
    Front = Front + 1;
}
