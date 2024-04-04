#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int numLetters (string text);
int numWords (string text);
int numSentences (string text);
int main(void)
{


// Prompt the user for some text
string text = get_string("Text: ");
int letters = numLetters(text);
int totalwords = numWords(text);
int totalSent = numSentences(text);

// Compute the Coleman-Liau index (index = 0.0588 * L - 0.296 * S - 15.8)
float L = ((float)letters / (float)totalwords) * 100;
float s = ((float)totalSent / (float)totalwords) * 100;
float subindex = 0.0588 * L - 0.296 * s - 15.8;
int index = round(subindex);

// Print the grade level
if(index > 16){
    printf("Grade 16+\n");
}
else if(index < 1){
    printf("Before Grade 1\n");
}
else{
    printf("Grade %i\n", index);
}
}

// Count the number of letters, words, and sentences in the text
int numLetters (string text){
int numL = 0;
int len = strlen(text);

for(int i = 0; i < len; i++){
    char c = text[i];
    if (isalpha(c) != 0){
        numL++;
    }
}
return numL;
}



int numWords (string text){
int len = strlen(text);
int words = 0;
for(int i = 1; i < len + 1; i++){
    char c = text[i];
    if(c == ' '){
        words++;
    }
}
words += 1;
return words;
}



int numSentences (string text){
int len = strlen(text);
int sentences = 0;
for(int i = 0; i < len + 1; i++){
    char c = text[i];
    if(c =='.'|| c == '!' || c == '?'){
        sentences++;
    }
}
return sentences;
}
