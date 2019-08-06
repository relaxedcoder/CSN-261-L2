#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int label = 1;

/** This is the function to run recursive check for the equality of all elements in respective quadrants.
* @param imgdata Pointer to the 2 dimensional image array
* @param rep Pointer to the 2 dimensional array(maximal square array)
* @param dim The length of any side of imgdata array (It's a power of 2)
* @param istart The row index from which equality check is done
* @param jstart The column index from which equality check is done
* @param level This denotes the current level in the quadtree
*/

void process(int ** imgdata,int ** rep,int dim,int istart,int jstart,int level)
{
    if(dim==0) return;
    int sum=0;
    int product=1;
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            sum += imgdata[i+istart][j+jstart];
            product *= imgdata[i+istart][j+jstart];
        }
    }
    if(sum==0 || product==1)
    {
        for(int i=0;i<dim;i++)
        {
            for(int j=0;j<dim;j++)
            {
                rep[i+istart][j+jstart] = label;
            }
        }
        int val = (sum==0)?0:1;
        printf("(%d,%d,%d)\n",label,val,level);
        label++;
    }
    else
    {
        process(imgdata,rep,dim/2,istart,jstart,level+1);
        process(imgdata,rep,dim/2,istart,jstart+dim/2,level+1);
        process(imgdata,rep,dim/2,istart+dim/2,jstart,level+1);
        process(imgdata,rep,dim/2,istart+dim/2,jstart+dim/2,level+1);
    }
}

int main()
{
    int ** data = (int**)malloc(100*sizeof(int*));
    for(int i=0;i<100;i++)
    {
        data[i] = (int*)malloc(100*sizeof(int));
    }
    int ** maximal = (int**)malloc(100*sizeof(int*));
    for(int i=0;i<100;i++)
    {
        maximal[i] = (int*)malloc(100*sizeof(int));
    }
    FILE * fin = fopen("C:/Users/hp/Desktop/input.txt","r");
    int a=0,b;
    while(!feof(fin))
    {
        b=0;
        char c[250];
        fgets(c,250,fin);
        char * token = strtok(c," ");
        while(token)
        {
            data[a][b] = atoi(token);
            token = strtok(NULL," ");
            b++;
        }
        a++;
    }
    int maxd = (a>=b)?a:b;
    int perfect=1;
    while(perfect<maxd)
    {
        perfect*=2;
    }
    int ** imgdata = (int**)malloc(perfect*sizeof(int*));
    for(int i=0;i<perfect;i++)
    {
        imgdata[i] = (int*)malloc(perfect*sizeof(int));
        for(int j=0;j<perfect;j++)
        {
            imgdata[i][j] = 0;
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            imgdata[i+perfect-a][j+perfect-b] = data[i][j];
        }
    }
    process(imgdata,maximal,perfect,0,0,0);
    return 0;
}
