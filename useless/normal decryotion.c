#include<stdio.h>

int count_data(char encrypted_data[1000])
{
    int i=0, count_data=0;

    for(i=0, count_data=0; ;i++,count_data++)
    {
        if(encrypted_data[i]==0)
        {
            break;
        }
    }
    printf("%d\n\n", count_data);

    return count_data;
}


char data_decryption(char encrypted_data[1000], int count_data)
{
    char data[1000];
    int i;

    for(i=0;i<=count_data;i++)
    {
        data[i]=encrypted_data[i]-1;
    }

    printf("%s", data);
}


main()
{
    char encrypted_data[1000];
    scanf("%s", &encrypted_data);
    int count;
    count=count_data(encrypted_data);

    data_decryption(encrypted_data, count);
}
