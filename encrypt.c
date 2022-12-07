#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDS 1000

int main()
{
    int i,len,encodenumber;
    char filename[20];
    char buffer[50];
    FILE *fp;

    system("clear");

    printf("\tENCRYPT FILE\n\n");
    printf("Enter filename: ");
    scanf("%s", filename);

    if ((fp=fopen(filename, "r")) == NULL)
    {
        printf("\n[*]\tERROR OPENING FILE\t[*]\n");
        exit(1);
    }

    while(fgets(buffer,MAXWORDS,fp) == NULL) {
        printf("\n[*]\tREADING\t[*]\n");
    }

    printf("\n[*]\tREAD SUCCESSFUL\t[*]\n");
    printf("BUFFER = %s\n", buffer);

    fclose(fp);

    len = strlen(buffer);
    printf("LEN = %d\n", len);

    printf("\nEnter encode number: ");
    scanf("%d", &encodenumber);

    if ((fp=fopen(filename, "w")) == NULL)
    {
        printf("\n[*]\tERROR OPENING FILE\t[*]\n");
        exit(1);
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            fprintf(fp,"%c",buffer[i]+encodenumber);
            printf("\n[*]\tENCODING\t[*]\n");
        }
        printf("\n");
        printf("\n[*]\tFILE ENCRYPTED SUCCESSFULLY\t[*]\n");
    }

    fclose(fp);
}