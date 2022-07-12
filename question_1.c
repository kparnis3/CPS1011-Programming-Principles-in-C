#include "question_1.h"

bool get_text_from_user(char *buf, size_t buf_size){
    printf("Input a paragraph of text\n");
    fgets(buf, buf_size, stdin);

    return true;
}

bool clean_and_validate(char *str){

    for(int i=0; i<strlen(str-1); i++){
        if (32 < str[i] && str[i] < 126){
            return false;
        }
    }

    if(str[strlen(str)-1] == '\n' && strlen(str) != 1 )
    {
        str[strlen(str)-1] = '\0';
        printf("Cleaned Text: %s\n", str);
        return true;

    }
    else
        return false;

}

void convert_to_lower_case(char *str, size_t len){

    for(int i=0; i<len; i++){
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i] = str[i] + 32;
        }
    }

    printf("Output of lower: %s\n", str);
}

int is_word_char(char ch){ //i
    if((64 < ch && ch < 91) || (96 < ch && ch < 123) ) {

        return 1;
    }
    else
        return 0;
}

int is_sentence_terminator(char ch){ //ii
    if(ch == 46 || ch == 33 || ch == 63) {

        return 1;

    } else
        return 0;
}

int count_sentences(const char *text, size_t len){ //iii
    int count = 0;
    int pre = 0;

        for (int i = 0; i < len; i++){

            if(text[i-1] == 46 || text[i-1] == 33 || text[i-1] == 63){
                pre = 1;
            }
            if ((text[i] == 46 || text[i] == 33 || text[i] == 63) && pre==0) {
                count++;
            }
            pre= 0;
        }

    return count;
}

void get_char_counts(const char *text, size_t len, char_counts_t *counts) {
    counts->word=0;
    counts->space=0;
    counts->other=0;

    for (int i = 0; i < len; i++) {
        if ((96 < text[i] && text[i] < 123)) {
            counts->word++;
        } else if(text[i] == 32){
            counts->space++;
        } else{
            counts->other++;
        }

    }
}
int count_words(const char *text, size_t len) {
    int words = 0;
    int letter = 0;

    for (int i = 0; i < len+1; i++)
    {
        if((64 < text[i] && text[i] < 91)  || (96 < text[i] && text[i] < 123)){
            letter=1;

        }

        if((text[i]==' ' || text[i]=='\n' || text[i]=='\t' || text[i]=='\0') && letter==1)
        {
            words++;
            letter=0;
        }

    }
    return words;
}

void get_letter_frequencies(const char *text, size_t len, int freq[26], int *max_freq){
    *max_freq=0;

    for (int i = 0; i < len; i++) {
        freq[text[i] - 'a']++;
    }

    for (int i = 0; i < len; i++){
       if(*max_freq < freq[text[i] - 'a'] && (96 < text[i] && text[i] < 123)){
           *max_freq = freq[text[i] - 'a'];
       }
    }

    printf("Letter Frequencies\n");
    for (int i = 0; i < len; i++) {
        if (freq[text[i] - 'a'] != 0 && (96 < text[i] && text[i] < 123)) {

            printf("[%c] :  %d\n", text[i], freq[text[i] - 'a']);

            freq[text[i] - 'a'] = 0;
        }
    }


}

void get_text_statistics(const char *text, size_t len, statistics_t *data) {

    char_counts_t char_counts;
    int freq_max[40];
    int freqt[26] = {0};

    get_char_counts(text, strlen(text), &char_counts);
    data->sentences = count_sentences(text, len);

    data->char_info.word = char_counts.word;
    data->char_info.space = char_counts.space;
    data->char_info.other = char_counts.other;

    data->words = count_words(text, len);

    get_letter_frequencies(text, len, freqt, freq_max);
    data->max_freq = freq_max[0];

    data->most_freq_chars; //most_freq


}

bool get_text_from_file(const char* file_path, char *buf, size_t buf_size) {
    FILE *fp;
    fp = fopen(file_path, "r");

    if (fp == NULL) {
        printf("Error: file not found\n");
        return false;
    }

    do {
    } while (fgets(&buf[strlen(buf)], buf_size, fp)!=NULL);

    return true;
}

bool print_menu(menu_choice_t *user_choice){

    char int_choice = 0;

       printf("1. User input\n");
       printf("2. File input\n");
       printf("3. Quit\n");

     scanf("%c", &int_choice);

      switch (int_choice)
       {
           case '1':
                *user_choice = USER_INPUT;
               break;
           case '2':
                *user_choice = FILE_INPUT;
               break;
           case '3':
                *user_choice = QUIT;
               break;
           default:
                *user_choice = INVALID;
               return false;

   }

    return true;
}
