#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SQUARE_LEN 4

#define MOVE_UP    1
#define MOVE_DOWN  2
#define MOVE_LEFT  3
#define MOVE_RIGHT 4

static int matrix[SQUARE_LEN][SQUARE_LEN];


/* return 0 ~~~ max-1 */
int get_random_num(int max)
{
    return rand() % max;
}

void print_matrix()
{
    int i, j;

    for(i = 0; i < SQUARE_LEN; i++)
    {
        printf("\n");

        for(j = 0; j < SQUARE_LEN; j++)
        {
            printf("%4d ", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void fill_random_with_up()
{
    while(1)
    {
        int is_full = 1;
        int i;
        for(i=0; i<SQUARE_LEN; i++)
        {
            if(matrix[SQUARE_LEN-1][i] == 0)
            {
                is_full = 0;
                break;
            }
        }

        if(is_full == 1)
        {
            exit(1);
        }

        int random = get_random_num(SQUARE_LEN);

        if(matrix[SQUARE_LEN-1][random] == 0)
        {
            matrix[SQUARE_LEN-1][random] = (get_random_num(2) + 1) * 2;
            break;
        }
    }
}

void fill_random_with_down()
{
    while(1)
    {
        int is_full = 1;
        int i;
        for(i=0; i<SQUARE_LEN; i++)
        {
            if(matrix[0][i] == 0)
            {
                is_full = 0;
                break;
            }
        }

        if(is_full == 1)
        {
            exit(1);
        }

        int random = get_random_num(SQUARE_LEN);

        if(matrix[0][random] == 0)
        {
            matrix[0][random] = (get_random_num(2) + 1) * 2;
            break;
        }
    }
}

void fill_random_with_left()
{
    while(1)
    {
        int is_full = 1;
        int i;
        for(i=0; i<SQUARE_LEN; i++)
        {
            if(matrix[i][SQUARE_LEN-1] == 0)
            {
                is_full = 0;
                break;
            }
        }

        if(is_full == 1)
        {
            exit(1);
        }

        int random = get_random_num(SQUARE_LEN);

        if(matrix[random][SQUARE_LEN-1] == 0)
        {
            matrix[random][SQUARE_LEN-1] = (get_random_num(2) + 1) * 2;
            break;
        }
    }
}

void fill_random_with_right()
{
    while(1)
    {
        int is_full = 1;
        int i;
        for(i=0; i<SQUARE_LEN; i++)
        {
            if(matrix[i][0] == 0)
            {
                is_full = 0;
                break;
            }
        }

        if(is_full == 1)
        {
            exit(1);
        }

        int random = get_random_num(SQUARE_LEN);

        if(matrix[random][0] == 0)
        {
            matrix[random][0] = (get_random_num(2) + 1) * 2;
            break;
        }
    }
}

void move_up_only()
{
    int i, j, k;

    for(i=0; i<SQUARE_LEN; i++)
    {
        for(j=0; j<SQUARE_LEN; j++)
        {
            if(matrix[j][i] == 0)
            {
                for(k=j+1; k<SQUARE_LEN; k++)
                {
                    if(matrix[k][i] != 0)
                    {
                        matrix[j][i] = matrix[k][i];
                        matrix[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void move_up_with_calculate()
{
    int i, j, k;

    for(i=0; i<SQUARE_LEN; i++)
    {
        for(j=0; j<SQUARE_LEN; j++)
        {
            if(matrix[j][i] == 0)
            {
                continue;
            }

            for(k=j+1; k<SQUARE_LEN; k++)
            {
                if(matrix[k][i] != 0)
                {
                    if(matrix[k][i] == matrix[j][i])
                    {
                        matrix[j][i] += matrix[k][i];
                        matrix[k][i] = 0;
                    }

                    break;
                }
            }
        }
    }
}

void move_down_only()
{
    int i, j, k;

    for(i=0; i<SQUARE_LEN; i++)
    {
        for(j=SQUARE_LEN-1; j>=0; j--)
        {
            if(matrix[j][i] == 0)
            {
                for(k=j-1; k>=0; k--)
                {
                    if(matrix[k][i] != 0)
                    {
                        matrix[j][i] = matrix[k][i];
                        matrix[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void move_down_with_calculate()
{
    int i, j, k;

    for(i=0; i<SQUARE_LEN; i++)
    {
        for(j=SQUARE_LEN-1; j>=0; j--)
        {
            if(matrix[j][i] != 0)
            {
                for(k=j-1; k>=0; k--)
                {
                    if(matrix[k][i] != 0)
                    {
                        if(matrix[k][i] == matrix[j][i])
                        {
                            matrix[j][i] += matrix[k][i];
                            matrix[k][i] = 0;
                        }

                        break;
                    }
                }
            }
        }
    }
}

void move_left_only()
{
    int i, j, k;

    for(i=0; i<SQUARE_LEN; i++)
    {
        for(j=0; j<SQUARE_LEN; j++)
        {
            if(matrix[i][j] == 0)
            {
                for(k=j+1; k<SQUARE_LEN; k++)
                {
                    if(matrix[i][k] != 0)
                    {
                        matrix[i][j] = matrix[i][k];
                        matrix[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void move_left_with_calculate()
{
    int i, j, k;

    for(i=0; i<SQUARE_LEN; i++)
    {
        for(j=0; j<SQUARE_LEN; j++)
        {
            if(matrix[i][j] != 0)
            {
                for(k=j+1; k<SQUARE_LEN; k++)
                {
                    if(matrix[i][k] != 0)
                    {
                        if(matrix[i][k] == matrix[i][j])
                        {
                            matrix[i][j] += matrix[i][k];
                            matrix[i][k] = 0;
                        }

                        break;
                    }
                }
            }
        }
    }
}

void move_right_only()
{
    int i, j, k;

    for(i=0; i<SQUARE_LEN; i++)
    {
        for(j=SQUARE_LEN-1; j>=0; j--)
        {
            if(matrix[i][j] == 0)
            {
                for(k=j-1; k>=0; k--)
                {
                    if(matrix[i][k] != 0)
                    {
                        matrix[i][j] = matrix[i][k];
                        matrix[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void move_right_with_calculate()
{
    int i, j, k;

    for(i=0; i<SQUARE_LEN; i++)
    {
        for(j=SQUARE_LEN-1; j>=0; j--)
        {
            if(matrix[i][j] != 0)
            {
                for(k=j-1; k>=0; k--)
                {
                    if(matrix[i][k] != 0)
                    {
                        if(matrix[i][k] == matrix[i][j])
                        {
                            matrix[i][j] += matrix[i][k];
                            matrix[i][k] = 0;
                        }

                        break;
                    }
                }
            }
        }
    }
}

int main(void)
{
    srand(time(NULL));

    print_matrix();

    while(1)
    {
        printf("1:up  2:down  3:left  4:right\nPlease enter your want:");

        int move = 0;

        scanf("%d", &move);

        switch(move)
        {
            case MOVE_UP:
                move_up_with_calculate();
                move_up_only();
                fill_random_with_up();
                break;
            case MOVE_DOWN:
                move_down_with_calculate();
                move_down_only();
                fill_random_with_down();
                break;
            case MOVE_LEFT:
                move_left_with_calculate();
                move_left_only();
                fill_random_with_left();
                break;
            case MOVE_RIGHT:
                move_right_with_calculate();
                move_right_only();
                fill_random_with_right();
                break;

            default: return 1;
        }

        printf("\033[11A");
        print_matrix();
    }

    return 0;
}