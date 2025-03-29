#include <stddef.h>
#include <stdio.h>

typedef struct s_data
{
    void *mlx;
    void *win;
    char **map;
    int height;
    int width;
} t_data;

void fct2(int *n)
{
    *n = 9;
}
void fct(int *a)
{
    *a = 2;
    fct2(a);
}

int main()
{
    int i;

    i = 0;
    fct(&i);
    printf("%d\n", i);
    return 0;
}
