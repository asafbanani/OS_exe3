#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define LINELEN (80)

char *mygets(char *buf, int len);

int main(int argc, char *argv[]) {
    char str1[LINELEN + 1];
    char str2[LINELEN + 1];

    if (argc != 2)
        return -1;

    while (1) {
        if (mygets(str1, LINELEN) == NULL)
            break;
        if (mygets(str2, LINELEN) == NULL)
            break;

        int rc = fork();
        if (rc < 0)
            exit(1);

        else if (rc == 0) {
            int len = (int)strlen(argv[1]);
            char func[len + 3];
            if (argv[1][0] == '.' || argv[1][0] == '/') {
                strcpy(func, argv[1]);
            } else {
                func[0] = '.';
                func[1] = '/';
                func[2] = '\0';
                strcat(func, argv[1]);
            }
            char *myargs[4];
            myargs[0] = strdup(func);
            myargs[1] = strdup(str1);
            myargs[2] = strdup(str2);
            myargs[3] = NULL;
            execvp(myargs[0], myargs);
            exit(-1);
        } else {
            int res = -2;
            int status;
            wait(&status);
            if(WIFEXITED(status))
            {
            	res = WEXITSTATUS(status);
            	printf("%d\n", res);	
            }
            else
            {
            	status = -2, res = -2;
            	int wc = wait(&status);
            	if(wc != -1 && WIFEXITED(status))
            	{
            		res = WEXITSTATUS(status);
            	}
            	printf("%d\n", res);
            }
            fflush(stdout);
        }
    }

    return 0;
}

char *mygets(char *buf, int len) {
    char *retval;

    retval = fgets(buf, len, stdin);
    buf[len] = '\0';
    if (buf[strlen(buf) - 1] == 10) /* trim \r */
        buf[strlen(buf) - 1] = '\0';
    else if (retval)
        while (getchar() != '\n'); /* get to eol */

    return retval;
}

