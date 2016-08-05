#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "msg.h"

void check_fp(FILE *fp);

int main(void)
{
    char ch;
    char c;
    FILE *fp;
    user_t user;


    while (1)
    {
        printf("**********************\n");
        printf("\t1 - Add user\n");
        printf("\t2 - Display\n");
        printf("\t3 - Delete user\n");
        printf("\t4 - Exit\n");
        printf("**********************\n");
        printf("Enter a choice:");
        //scanf("%c", &ch);
        //printf("ch = %c\n", ch);
        ch = getchar();
        //printf("ch = %c\n", ch);
        while ((c = getchar()) != '\n')
            ;

        switch(ch)
        {
            case '1':
            {
                char file_name[30];

                printf("Enter name : ");
                scanf("%[^\n]", user.name);
                getchar();
                printf("Enter the password : ");
                scanf("%[^\n]", user.password);
                getchar();
                
                fp = fopen("users.db", "a");
                check_fp(fp);
                fwrite(&user, sizeof(user_t), 1, fp);
                fclose(fp);

                strcpy(file_name, user.name);
                strcat(file_name, ".db");
                fp = fopen(file_name, "w");
                check_fp(fp);
                fclose(fp);

                strcpy(file_name, user.name);
                strcat(file_name, "_as.db");
                fp = fopen(file_name, "w");
                check_fp(fp);
                fclose(fp);

                strcpy(file_name, user.name);
                strcat(file_name, "_off.db");
                fp = fopen(file_name, "w");
                check_fp(fp);
                fclose(fp);

                break;
            }

            case '2':
            {
                fp = fopen("users.db", "r");
                check_fp(fp);

                printf("\n-------All names------------");
                while ((fread(&user, sizeof(user_t), 1, fp)) == 1)
                {
                    printf("\n%s", user.name);
                }
                fclose(fp);
                printf("\n");
                printf("-----------------------------\n");
                break;
            }

            case '3':
            {
                FILE *fp1;
                char name[20];
                char file_name[20];
                int flag = 0;

                printf("Enter the name to be deleted : ");
                scanf("%[^\n]", name);
                fp = fopen("users.db", "r");
                check_fp(fp);
                fp1 = fopen("tempfile", "w");
                check_fp(fp1);
                rewind(fp);
                
                while ((fread(&user, sizeof(user_t), 1, fp)) == 1)
                {
                    if ((strcmp(user.name, name)) != 0)
                        fwrite(&user, sizeof(user_t), 1, fp1);
                    else
                        flag = 1;
                }
                fclose(fp1);
                fclose(fp);
                remove("users.db");
                rename("tempfile", "users.db");

                if (flag == 1)
                {
                    strcpy(file_name, name);
                    strcat(file_name, ".db");
                    remove(file_name);

                    strcpy(file_name, name);
                    strcat(file_name, "_as.db");
                    remove(file_name);

                    strcpy(file_name, name);
                    strcat(file_name, "_off.db");
                    remove(file_name);

                    printf("Delete Success! \n");
                }
                else
                {
                    printf("No such user ! \n");
                }

                break;
            }

            case '4':
            {
                exit(0);
            }

            default:
                printf("Enter error choice. Please reselect. \n");
        }
    }

    return 0;
}

void check_fp(FILE *fp)
{
    if (fp == NULL)
    {
        printf("fopen error\n");
        exit(0);
    }
}
