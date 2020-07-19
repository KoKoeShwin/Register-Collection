#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Written by Mr Koe Shwin
// Contact to koeshwin00@gmail.com if you found any error in this source code

struct Person{
    char nrc[50];
    char name[20];
    char Fname[20];
    char birth[20];
    int age;
    char address[30];
    char ph[20];
    char email[20];
    char job[15];
};
struct Person data;
int option;
char signal;
char select[30];
FILE *fp,*ft;
time_t t;

void welcome(void);
void menu(void);
void add();
datainput();
void view(void);
void search(void);
void erase(void);

int main()
{
    welcome();
    return 0;
}

void welcome(void)
{
    puts("\n****** WELCOME TO THE REGISTER COLLECTION PROGRAM ******");
    menu();
}

void menu(void)
{
    printf("\n\t(1)Adding NRC Data");
    printf("\n\t(2)Viewing All NRC Data");
    printf("\n\t(3)Removing Each NRC Data");
    printf("\n\t(4)Viewing Each NRC Data");
    printf("\n\t(5)Author");
    REV:
    printf("\n\nEnter Your Option : ");
    scanf("%d",&option);

    switch(option)
    {
        case 1:add();break;
        case 2:view();break;
        case 3:erase();break;
        case 4:search();break;
        case 5:system("Author.html");
        menu();
        default:
            printf("\n\aNo Entry !");
            goto REV;
    }

}

void add()
{
    time(&t);
    REV:
    datainput();
    fp=fopen("Record.txt","ab+");
    if(fp==0)
    {
        printf("\nFile Error !");
        exit(0);
    }
    fwrite(&data,sizeof(data),1,fp);

    printf("\nAdded Successfully  > %s ",ctime(&t));
    fclose(fp);

    printf("\nOne More (Y / N) :");
    signal=getch();
    if(toupper(signal)=='Y')
        goto REV;
    else
        menu();

}

 datainput()
 {
     fflush(stdin);
     printf("\nEnter NRC :");
     gets(data.nrc);
     printf("\nEnter Name :");
     gets(data.name);
     printf("\nEnter Father Name :");
     gets(data.Fname);
     printf("\nEnter Age :");
     scanf("%d",&data.age);
     fflush(stdin);
     printf("\nEnter Birthday :");
     gets(data.birth);
     printf("\nEnter JOB :");
     gets(data.job);
     printf("\nEnter Phone No :");
     gets(data.ph);
     printf("\nEnter Email Address :");
     gets(data.email);
     printf("\nEnter Physical Address :");
     gets(data.address);

     fflush(stdin);
 }

void view(void)
{
    fp=fopen("Record.txt","rb+");
    if(fp==0)
    {
        printf("\nFile Error !");
        exit(0);
    }
    while(fread(&data,sizeof(data),1,fp)==1)
    {
        printf("\n\nName :%s",data.name);
        printf("\nNRC No :%s",data.nrc);
        printf("\nFather Name :%s",data.Fname);
        printf("\nAge :%d",data.age);
        printf("\nJob :%s",data.job);
        printf("\nBirthday :%s",data.birth);
        printf("\nPhone No :%s",data.ph);
        printf("\nEmail Address :%s",data.email);
        printf("\nPhysical Address :%s",data.address);

    }
    fclose(fp);
    printf("\nPresss Any key to continue >>>> ");
    signal=getch();
    menu();
}

void search(void)
{
    fflush(stdin);
    printf("\n\tSearch By Name (1) or By NRC (2)");
    REV:
    printf("\nEnter Name or NRC :");
    gets(select);
        fp=fopen("Record.txt","rb+");
        if(fp==0)
        {
            printf("\nFile Error !");
            exit(0);
        }
        while(fread(&data,sizeof(data),1,fp)==1)
        {
            if(strcmp(select,data.name)==0)
            {
                printf("\nName :%s",data.name);
                printf("\nNRC No :%s",data.nrc);
                printf("\nFather Name :%s",data.Fname);
                printf("\nAge :%d",data.age);
                printf("\nJob :%s",data.job);
                printf("\nBirthday :%s",data.birth);
                printf("\nPhone No :%s",data.ph);
                printf("\nEmail Address :%s",data.email);
                printf("\nPhysical Address :%s",data.address);
                break;
            }
            else if(strcmp(select,data.nrc)==0)
            {
                printf("\nName :%s",data.name);
                printf("\nNRC No :%s",data.nrc);
                printf("\nFather Name :%s",data.Fname);
                printf("\nAge :%d",data.age);
                printf("\nJob :%s",data.job);
                printf("\nBirthday :%s",data.birth);
                printf("\nPhone No :%s",data.ph);
                printf("\nEmail Address :%s",data.email);
                printf("\nPhysical Address :%s",data.address);
                break;
            }


        }
        fclose(fp);

        printf("\nOne More (Y / N) :");
        signal=getch();
        if(toupper(signal)=='Y')
            goto REV;
        else
            menu();


}

void erase(void)
{
    time(&t);
    fflush(stdin);
    REV:
    printf("\nRemove by NRC :");
    gets(select);

    fp=fopen("Record.txt","rb+");
    ft=fopen("Tem.txt","ab+");
    if(fp==0 && ft==0)
    {
        printf("File Error !");
        exit(0);
    }
    while(fread(&data,sizeof(data),1,fp)==1)
    {
        if(strcmp(select,data.nrc)!=0)
        {
            fwrite(&data,sizeof(data),1,ft);
        }
        else
            signal='y';
    }
    fclose(fp);
    fclose(ft);
    remove("Record.txt");
    rename("Tem.txt","Record.txt");
    if(tolower(signal)=='y')
        printf("Erased Successfully > %s",ctime(&t));
    printf("\nOne More (Y / N) :");
    signal=getch();
    if(toupper(signal)=='Y')
        goto REV;
    else
            menu();

}





















