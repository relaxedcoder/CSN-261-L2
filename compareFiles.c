#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/** @file */

/**
* @param argc Number of arguments taken by main function
* @param argv Arguments stored as an array of char sequences
*/

int main(int argc,char * argv[])
{
    /** Checking for correct number of arguments */
    if(argc!=3)
    {
        printf("Number of arguments not equal to 2, returning!\n");
        return -1;
    }

    FILE * fin1 = fopen(argv[1],"r");
    FILE * fin2 = fopen(argv[2],"r");
    char s1[2000];
    char s2[2000];
    int flag=0;

    /** Reading from both files inputfile.txt and decryptedOutputfile.txt */
    while(!feof(fin1) && !feof(fin2))
    {
        fgets(s1,2000,fin1);
        fgets(s2,2000,fin2);

        /** Checking for equality condition line-by-line */
        if(strcmp(s1,s2)!=0)
        {
            flag=1;
            break;
        }
    }
    fclose(fin1);
    fclose(fin2);
    if(flag==0) printf("Both are equal!\n");
    else printf("Both are not equal!\n");
    return 0;
}
