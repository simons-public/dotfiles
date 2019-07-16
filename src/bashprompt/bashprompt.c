/* prompt command */
/* use with PROMPT_COMMAND='export EXIT=$? ; PS1=$(./a.out)' */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <locale.h>
#include "colors.h"

#define HOSTNAME_MAX 255
#define USERNAME_MAX 32

#define BULLET "•"
#define PROMPT_CHARACTER "↝"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stdout, "usage: "
        "PROMPT_COMMAND='PS1=\"$(%s ${?})\"'\n", argv[0]);
        exit(1);
    }

    setlocale(LC_ALL, "en_US.utf8");
    char path[FILENAME_MAX];
    char hostname[HOSTNAME_MAX];
    char username[USERNAME_MAX];
    char home[FILENAME_MAX];
    char shell[FILENAME_MAX];

    struct passwd *pw = getpwuid(geteuid());
    strcpy(username, pw->pw_name);
    strcpy(home, pw->pw_dir);
    strcpy(shell, pw->pw_shell);

    getcwd(path, FILENAME_MAX);
    gethostname(hostname, HOSTNAME_MAX);


    // set terminal title
    fprintf(stdout, "\\[\e]2;\\u@\\h:\\w\\a\\]");

    // reset & empty line
    fprintf(stdout, "%s\n", RESET);

    /* first line */
    if (strncmp(argv[1], "0", 10)) {
        fprintf(stdout, "%s%s%s", LI_RED, BULLET, RESET);
    } else {
        fprintf(stdout, "%s%s%s", GREEN, BULLET, RESET);
    }

    fprintf(stdout, "%s%s%s\n", DIM, path, RESET);
    /* end first line */

    /* second line */
    fprintf(stdout, "%s%s%s@%s%s%s%s ", BLUE, username, WHITE, GREEN, hostname, PROMPT_CHARACTER, RESET);
    /* end second line */

    // command styling
    fprintf(stdout, "%s", LI_RED);
}
