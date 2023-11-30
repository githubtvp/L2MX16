#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *ptr;
    int i=0, j=0, n = 6;
    char *ch[n];
    for(i = 0; i < n; i++)
    {
       ch[i] = (char *)malloc(n*sizeof(char));
    }

  //  printf("\nEnter name :");
   // gets(ch);
    //char *ch2[6] = {"this", "is", "my", "name", "v", "perumal"};
    //ptr = (char *)malloc(n*sizeof(char));
    //ptr = ch;
    //printf("\n%s", ptr);

  //  n = strlen(ptr);
/*for(i= 0; i <n-1; i++)
{
    for(j= i+1; j <n; j++)
    {
        if( *(ptr + i) >  *(ptr + j))
        {
           // printf("Swap ");
            char temp = ' ';
            temp = *(ptr + i);
            *(ptr + i) = *(ptr + j);
            *(ptr + j) = temp;
        }
    }
}*/
char str[3][3];
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        scanf("%c",&str[i][j]);
    }
}

char (*p)[3] = str;
for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", p[i][j]);
        }
        printf("\n");
    }

printf("\n2. The name is : \n");
i = 0;
//n = strlen(ptr);
while(i < n)
{
    //printf("%s \n", *(ch2 + i));
    i++;
}


printf("\nTest line");
return 0;
}
