#include "question_1.h"
#define BUFFER_SIZE 1024


int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    bool txt = false;
    statistics_t statistics;
    menu_choice_t choice;
    char string[999];
    char buf[999];
    char filep[999];

    label:
    do {
        txt = print_menu(&choice);
       if(!txt){
           while (getchar() != '\n');
       }
    }while(!txt);

    if (choice == QUIT)
    {
        exit(1);
    }
    else if (choice == USER_INPUT)
    {
        while (getchar() != '\n');
        txt = get_text_from_user(string,998);
        if (!txt)
            puts("false");

        txt =  clean_and_validate(string);
        if (!txt)
            puts("false");

        convert_to_lower_case(string, strlen(string));
        get_text_statistics(string, strlen(string), &statistics);

        printf("+-----------------------------+--------+\n");
        printf("| Feature                     | Value  |\n");
        printf("+-----------------------------+--------+\n");
        printf("| Number of characters        | %6d |\n", statistics.char_info.word + statistics.char_info.space + statistics.char_info.other);
        printf("| Number of word characters   | %6d |\n", statistics.char_info.word);
        printf("| Number of spaces            | %6d |\n", statistics.char_info.space);
        printf("| Number of other characters  | %6d |\n", statistics.char_info.other);
        printf("| Number of words             | %6d |\n", statistics.words);
        printf("| Number of sentences         | %6d |\n", statistics.sentences);
        printf("| Maximum frequency           | %6d |\n", statistics.max_freq);
        printf("| Most frequent letter(s)     |      []|\n");
        printf("+-----------------------------+--------+\n");
        goto label;
    }
    else if(choice == FILE_INPUT) {
        while (getchar() != '\n');
        printf("Input a file location\n");

        //C:\\Users\\Owner\\CLionProjects\\CPS1011_tutorials\\Fileio\\q1.txt
        scanf("%70[^\n]%*c", filep);

        txt = get_text_from_file(filep, buf, BUFFER_SIZE);
        if (!txt)
            puts("false");

        else {
            txt =  clean_and_validate(buf);
            if (!txt)
                puts("false");

            convert_to_lower_case(buf, strlen(buf));
            get_text_statistics(buf, strlen(buf), &statistics);

            printf("+-----------------------------+--------+\n");
            printf("| Feature                     | Value  |\n");
            printf("+-----------------------------+--------+\n");
            printf("| Number of characters        | %6d |\n", statistics.char_info.word + statistics.char_info.space + statistics.char_info.other);
            printf("| Number of word characters   | %6d |\n", statistics.char_info.word);
            printf("| Number of spaces            | %6d |\n", statistics.char_info.space);
            printf("| Number of other characters  | %6d |\n", statistics.char_info.other);
            printf("| Number of words             | %6d |\n", statistics.words);
            printf("| Number of sentences         | %6d |\n", statistics.sentences);
            printf("| Maximum frequency           | %6d |\n", statistics.max_freq);
            printf("| Most frequent letter(s)     |      []|\n");
            printf("+-----------------------------+--------+\n");
        }
        goto label;
    }

     return 0;

}