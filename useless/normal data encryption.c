#include<stdio.h>

int count_data(char data[1000])
{
    int i=0, count_data=0;

    for(i=0, count_data=0; ;i++,count_data++)
    {
        if(data[i]==0)
        {
            break;
        }
    }
    printf("%d\n\n", count_data);

    return count_data;
}


char data_encryption(char data[1000], int count_data)
{
    char encrypted_data[1000];
    int i;

    for(i=0;i<=count_data;i++)
    {
        encrypted_data[i]=data[i]+1;
    }

    printf("%s", encrypted_data);
}


main()
{
    char data[1000], encrypt_data[1000];
    scanf("%s", &data);
    int count;
    count=count_data(data);

    data_encryption(data, count);
}
