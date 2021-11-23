#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char    **add1(char *str)
{
    char c;
    int fd1 = open(str, O_RDONLY);
    int i = 0;
    int j;
    int contw;
    int contl[2];
    char    **dicc;
    if (fd1 == -1)
    {
		write(1, "Dict Error", 10);
        return(0);
    }
    contw = 0;
    contl[1] = 0;
    while (read(fd1, &c, 1) != 0)
    {
        contl[0] = 0;
        while (c != '\n')
        {
            read(fd1, &c, 1);
            contl[0]++;
        }
        contw++;
        if (contl[0] > contl[1])
            contl[1] = contl[0];
        read(fd1, &c, 1);
    }
    close(fd1);
    dicc = (char **) malloc((contw + 2) * sizeof(char *));
    while (i < contw + 2)
    {
        dicc[i] = (char *) malloc((contl[1] + 5) * sizeof(char));
        i++;
    }
    dicc[0][0] = '\n';
    i = 1;
    open(str, O_RDONLY);
    while (read(fd1, &c, 1) != 0)
    {
        while (i < contw + 1)
        {
            j = -1;
            while (j++ < contl[1] + 4)
            {
                if (c != '\n')
                {
                    dicc[i][j] = c;
                    read(fd1, &c, 1);
                }
                else
                    dicc[i][j] = 0;
            }
            dicc[i][j - 3] = '\n';
            dicc[i][j - 2] = 0;
            if (c != '\n')
                dicc[i][j] = c;
            read(fd1, &c, 1);
            i++;
        }
    }
    dicc[i][0] = 0;
    close(fd1);
    return (dicc);
}