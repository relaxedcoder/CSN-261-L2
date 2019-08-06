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
    if(argc!=5)
    {
        printf("Number of arguments not equal to 4, returning.");
        return -1;
    }

    /** The required arguments n, a and b copied from argv 1, 2 and 3 respectively */
    int n,aprime=0,bprime=0,a,b;
    n = atoi(argv[1]);
    a = atoi(argv[2]);
    b = atoi(argv[3]);

    /** Checking for condition (if n<1) */
    if(n<1)
    {
        printf("n is less than 1, returning.");
        return -1;
    }

    /** This loop is to find aprime */
    while((a*aprime-1)%n!=0)
    {
        aprime++;
    }

    /** This loop is to find bprime */
    while((b*aprime+bprime)%n!=0)
    {
        bprime++;
    }
    FILE * fin = fopen(argv[4],"r");
    int count = 0;
    char c[2000];

    /** I have taken input character-by-character from file */
    while(!feof(fin))
    {
        fscanf(fin,"%c",&c[count]);
        count++;
    }
    fclose(fin);
    char nc[2000];

    /** Implementation of transposition decipher */
    for(int k=0;k<(count/n);k++)
    {
        for(int i=0;i<n;i++)
        {
            int j=(aprime*i+bprime)%n;
            nc[k*n+i]=c[k*n+j];
        }
    }
    FILE * fout = fopen("decryptedOutputfile.txt","w");

    /** Writing to decrypted content to decryptedOutputfile.txt */
    fprintf(fout,"%s",nc);
    fclose(fout);
    return 0;
}
