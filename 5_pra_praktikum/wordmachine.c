#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while(currentChar == BLANK && currentChar != MARK){
        ADV();
    }
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true; 
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true; 
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord(){
    int i=0;
    while(currentChar != BLANK && !EOP && i < NMax){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}