#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

int main() {

    int year;
    int subject;
    /*char language;*/

    printf("Enter a year (2007 - 2022): ");
    scanf("%d", &year);

    printf("\n===================\n|  Subject Codes  |\n===================\n| Accounting | 32 |\n| Physics    | 21 |\n===================\n\nSubject Code: ");
    scanf("%d", &subject);

    /*if(subject == 01)

        language = 'I';

    else

        language == 'E';*/

    char *cmd;
    asprintf(&cmd, "START https://www.examinations.ie/archive/exampapers/%d/LC0%02dALP000EV.pdf", year, subject);
    system(cmd);
    free(cmd);
}
