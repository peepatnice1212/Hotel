#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<dir.h>
#include<ctype.h>
#define USER_MAX 20

int main();
int main_login();
char admin();

typedef struct
{
	char name[10];
	char password[10];
} User;

User list[USER_MAX];

char name[10];
User login()
{

	char password[10];
	User lg;
	printf("\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\n");
	printf("\n  Username : ");
	scanf("%s", name);
	strcpy(lg.name, name);
	printf("\n  Password : ");

	int p = 0;
	do
	{
		password[p] = getch();
		if (password[p] != '\r')
		{
			printf("*");
		}
		p++;
	} while (password[p - 1] != '\r');
	password[p - 1] = '\0';

	strcpy(lg.password, password);

	return lg;
}


void writeToFile(User u)
{
	FILE *fw = fopen("login.txt", "a+");
	fprintf(fw, u.name);
	fprintf(fw, "\t");
	fprintf(fw, u.password);
	fprintf(fw, "\n");
}

// determine whether the user exists
int exist(User u)
{
	int i;
	for (i = 0; i < USER_MAX; i++)
	{
		if (0 == strcmp(list[i].name, u.name) && 0 == strcmp(list[i].password, u.password))
		{
			return 1;
		}
	}
	return -1;
}

//registered user
void registerUser()
{
	char name[10];
	char password_1[10];
	char password_2[10];
	User user;
	int i;
	printf("\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\n");
	printf("\n  Username : ");
	scanf("%s", name);
	strcpy(user.name, name);

	// determine whether there has been a registered user
	for (i = 0; i < USER_MAX; i++)
	{
		if (0 == strcmp(list[i].name, name))
		{
			system("cls");
			printf("\n  Wrong  \n");
			printf("\n  This Username is already logged in. Please change Username  \n");
			getch();
			system("cls");
			registerUser();

			return;
		}
	}

	printf("\n  Password : ");
	scanf("%s", password_1);
	printf("\n  Confirm your password : ");
	scanf("%s", password_2);
	if (strcmp(password_2, password_1) > 0 || strcmp(password_2, password_1) < 0)
	{
		system("cls");
		printf("\n  Wrong  \n");
        printf("\n  Username or Password is Incorrect  \n");
		getch();
		system("cls");
		registerUser();
	}
	strcpy(user.password, password_1);
	writeToFile(user);
	printf("\n  Register Succesful  \n");
	getch();
}

int menu()
{
	int choice;
	printf("\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\n");
	printf("\t\t\t       --------------------------------------------\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  Please choose number 1 or 2 to proceed  |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  1 . Log In                              |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  2 . Register                            |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       --------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("  Please Enter Numner : ");
	scanf("%d", &choice);
	printf("\n");
    printf("\n");
	return choice;
}

int main_login()
{
	User test[USER_MAX];
	FILE *fp = fopen("login.txt", "r");
	int i = 0;
	User u;
	if (NULL == fp)
	{
		perror("  Failed : ");
		getch();
		return -1;
	}
	for (i = 0; i < USER_MAX; i++)
	{
		char uname[10];
		char upassword[10];
		fscanf(fp, "%s%s", uname, upassword);

		strcpy(list[i].name, uname);
		strcpy(list[i].password, upassword);
	}

	int choice = menu();
	if (1 == choice)
	{
		system("cls");
		u = login();
		if (1 == exist(u))
		{
			printf("\n  Log In Succesful  \n");
			getch();
		}
		else
		{
			system("cls");
			printf("\n  Wrong  \n");
			printf("\n  Username or Password is Incorrect  \n");
			getch();
			system("cls");
			main_login();
		}
	}
	else if (2 == choice)
	{
		system("cls");
		registerUser();
	}
	else
	{
		main();
		return 0;
	}
}








//***********************



int AdminorCustomer(int numberadcos)
{
    printf("\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t|\t  WELCOME TO NICE Hotel\t\t|\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\n");
    printf("\t\t\t       --------------------------------------------\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  Please choose number 1 or 2 to proceed  |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  1 . Admin                               |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  2 . Customer                            |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       --------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("  Please select a number : ");
    scanf("%d",&numberadcos);
    return numberadcos ;
}





int Firstpage(int numberfirstpage)
{
    printf("\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t|\t  WELCOME TO NICE Hotel\t\t|\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\n");
    printf("\t\t\t       --------------------------------------------\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  Please choose number 1 or 2 to proceed  |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  1 . Make a hotel booking list           |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       |  2 . Exit                                |\n");
    printf("\t\t\t       |                                          |\n");
    printf("\t\t\t       --------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("  Please select a number : ");
    scanf("%d",&numberfirstpage);
    return numberfirstpage ;
}




//***********






int Select(int numberSelect)
{
    printf("\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
    printf("\t\t\t\t|                                       |\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\n");
    printf("\t--------------------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                              Please select an item to do                                       |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|  1 . Special promotion                                                                         |\n");
    printf("\t|      (For those who want to book 5 rooms or more, we will have a 20 percent discount)          |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|  2 . Book a room                                                                               |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|  3 . Exit                                                                                      |\n");
    printf("\t|                                                                                                |\n");
    printf("\t--------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("  Please select a number : ");
    scanf("%d",&numberSelect);
    return numberSelect ;
}






int main ()
{
    int numberfirstpage = 0 , numbersecondpage , numberSelect , numberadcos;
    int a , b , c , d , choice;
    d = AdminorCustomer(numberadcos);
    system("cls");
    if(d==2)//for customer**********
    {
        a = Firstpage(numberfirstpage);
        system("cls");
        again:
        if(a==1)//next**************
            {

            	//****
            	main_login();
            	system("cls");


            	char *filename = name ; //{name}

                char tld[] = ".txt";


                strcat(filename, tld);
                //printf("%s", filename);
                printf("\n") ;
                printf("  Please Enter to Continue  ") ;
                printf("\n") ;

                FILE*fp;
                fp=fopen(filename,"w");
                fclose(fp);
            	getch();
            	//****

                system("cls");


                c = Select(numberSelect);
                system("cls");
                if(c==1)
                    {
                        int numberSpecial , howmanyspeacial , nightspecial;
                        int i ;
                        printf("\n");
                        printf("\t\t\t\t-----------------------------------------\n");
                        printf("\t\t\t\t|                                       |\n");
                        printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
                        printf("\t\t\t\t|                                       |\n");
                        printf("\t\t\t\t-----------------------------------------\n");
                        printf("\n");
                        printf("\t\t\t       --------------------------------------------\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |            Special Promotion             |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |      --> Divided by room size <--        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  1 . Standard            500 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  2 . Superior            700 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  3 . Deluxe              900 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  4 . Suite              1200 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |      --> Divided by room view <--        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  5 . Gardenview         1400 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  6 . Seaview            1500 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  7 . Poolview           1600 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  8 . Pool Access        1800 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  9 . Beach Front        2000 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       --------------------------------------------\n");
                        printf("\n");
                        printf("\n");
                        /*char filename[500];
                        printf("  Enter Name : ");
                        scanf("%s",filename);*/
                        printf("\n");
                        printf("  How many nights to book? : ");
                        scanf("%d",&nightspecial);
                        printf("\n");
                        printf("  How many rooms do you want to book? : ") ;
                        scanf("%d",&howmanyspeacial);
                        for(i=1;i<=howmanyspeacial;i++)
                        {
                            printf("\n");
                            printf("  Please select a number : ");
                            scanf("%d",&numberSpecial);
                            if(numberSpecial==1)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","Standard   500",nightspecial);
                                fclose(fp);
                            }
                            else if(numberSpecial==2)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","Superior   700",nightspecial);
                                fclose(fp);
                            }
                            else if(numberSpecial==3)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","Deluxe   900",nightspecial);
                                fclose(fp);
                            }
                            else if(numberSpecial==4)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","Suite   1200",nightspecial);
                                fclose(fp);
                            }
                            else if(numberSpecial==5)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","Gardenview   1400",nightspecial);
                                fclose(fp);
                            }
                            else if(numberSpecial==6)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","Seaview   1500",nightspecial);
                                fclose(fp);
                            }
                            else if(numberSpecial==7)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","Poolview   1600",nightspecial);
                                fclose(fp);
                            }
                            else if(numberSpecial==8)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","PoolAccess   1800",nightspecial);
                                fclose(fp);
                            }
                            else if(numberSpecial==9)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d \n","BeachFront   2000",nightspecial);
                                fclose(fp);
                            }
                        }
                        printf("\n");
                        printf("\n");



                        //********************
                        system("cls");
                        char room[20] ;
                        int numberReceipt , price , night , sum;
                        char filename[500];
                        printf("\n");
                        printf("\n");
                        printf("\t\t\t\t-----------------------------------------\n");
                        printf("\t\t\t\t|                                       |\n");
                        printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
                        printf("\t\t\t\t|                                       |\n");
                        printf("\t\t\t\t-----------------------------------------\n");
                        printf("\n");
                        printf("\t--------------------------------------------------------------------------------------------------\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t|                              Accommodation reservation receipt                                 |\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t--------------------------------------------------------------------------------------------------\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t|          Room type            Price        Number of nights booked        discount             |\n");
                        printf("\t|                                                                                                |\n");
                        FILE*fp = fopen(name,"r");
                        while(fscanf(fp,"%s %d %d",room,&price,&night)!=EOF)
                            {
                                sum+=price ;
                                printf("\t\t   %s \t%13d \t        Total %d nights \t        %s \n",room , price , night,"Total 20 percent");
                            }
                        printf("\n");
                        printf("\n");
                        printf("                                                                              All to pay : %d \n",(sum-(sum*20/100)-13)) ;
                        fclose(fp);
                        printf("\t|                                                                                                |\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t--------------------------------------------------------------------------------------------------\n");
                        printf("\n");
                        printf("\n");
                        printf("  --------->  Thank you for using the service  <---------  ");
                        printf("\n");
                        printf("\n");
                    }
                else if(c==2)
                    {
                        int numberBook , howmanybook , nightbook ;
                        int i ;
                        printf("\n");
                        printf("\t\t\t\t-----------------------------------------\n");
                        printf("\t\t\t\t|                                       |\n");
                        printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
                        printf("\t\t\t\t|                                       |\n");
                        printf("\t\t\t\t-----------------------------------------\n");
                        printf("\n");
                        printf("\t\t\t       --------------------------------------------\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |              Book a room                 |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |      --> Divided by room size <--        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  1 . Standard            500 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  2 . Superior            700 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  3 . Deluxe              900 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  4 . Suite              1200 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |      --> Divided by room view <--        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  5 . Gardenview         1400 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  6 . Seaview            1500 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  7 . Poolview           1600 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  8 . Pool Access        1800 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       |  9 . Beach Front        2000 baht        |\n");
                        printf("\t\t\t       |                                          |\n");
                        printf("\t\t\t       --------------------------------------------\n");
                        printf("\n");
                        printf("\n");
                        /*char filename[500];
                        printf("  Enter Name : ");
                        scanf("%s",filename);*/
                        printf("\n");
                        printf("  How many nights to book? : ");
                        scanf("%d",&nightbook);
                        printf("\n");
                        printf("  How many rooms do you want to book? : ") ;
                        scanf("%d",&howmanybook);
                        for(i=1;i<=howmanybook;i++)
                        {
                            printf("\n");
                            printf("  Please select a number : ");
                            scanf("%d",&numberBook);
                            if(numberBook==1)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp,"%s %d\n","Standard   500 ",nightbook);
                                fclose(fp);
                            }
                            else if(numberBook==2)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp," %s %d\n","Superior   700 ",nightbook);
                                fclose(fp);
                            }
                            else if(numberBook==3)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp," %s %d\n","Deluxe   900 ",nightbook);
                                fclose(fp);
                            }
                            else if(numberBook==4)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp," %s %d\n","Suite   1200 ",nightbook);
                                fclose(fp);
                            }
                            else if(numberBook==5)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp," %s %d\n","Gardenview   1400 ",nightbook);
                                fclose(fp);
                            }
                            else if(numberBook==6)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp," %s %d\n","Seaview   1500 ",nightbook);
                                fclose(fp);
                            }
                            else if(numberBook==7)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp," %s %d\n","Poolview   1600 ",nightbook);
                                fclose(fp);
                            }
                            else if(numberBook==8)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp," %s %d\n","PoolAccess   1800",nightbook);
                                fclose(fp);
                            }
                            else if(numberBook==9)
                            {
                                FILE*fp = fopen(filename,"a");
                                fprintf(fp," %s %d\n","BeachFront   2000",nightbook);
                                fclose(fp);
                            }
                        }
                        printf("\n");
                        printf("\n");



                    //***********************************
                        system("cls");
                        char room[20] ;
                        int numberReceipt , price2=0 , night , sum2=0;
                        char filename[500];
                        printf("\n");
                        printf("\t\t\t\t-----------------------------------------\n");
                        printf("\t\t\t\t|                                       |\n");
                        printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
                        printf("\t\t\t\t|                                       |\n");
                        printf("\t\t\t\t-----------------------------------------\n");
                        printf("\n");
                        printf("\t--------------------------------------------------------------------------------------------------\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t|                              Accommodation reservation receipt                                 |\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t--------------------------------------------------------------------------------------------------\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t|          Room type            Price        Number of nights booked        discount             |\n");
                        printf("\t|                                                                                                |\n");
                        FILE*fp = fopen(name,"r");
                        while(fscanf(fp,"%s %d %d",room,&price2,&night)!=EOF)
                            {
                                sum2 = sum2 + price2;
                                printf("\t\t   %s \t%13d \t        Total %d nights \t\t        - \n",room , price2 , night) ;
                                //printf("%d",price2) ;
                            }
                        printf("\n");
                        printf("\n");
                        printf("                                                                              All to pay : %d \n", sum2) ;
                        fclose(fp);
                        printf("\t|                                                                                                |\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t|                                                                                                |\n");
                        printf("\t--------------------------------------------------------------------------------------------------\n");
                        printf("\n");
                        printf("\n");
                        printf("  --------->  Thank you for using the service  <---------  ");
                        printf("\n");
                        printf("\n");
                    }

                else if(c==3)
                {
                    system("cls");
                    printf("\n");
                    printf("\t\t\t\t-----------------------------------------\n");
                    printf("\t\t\t\t|                                       |\n");
                    printf("\t\t\t\t|\t\t BYE BYE                |\n");
                    printf("\t\t\t\t|                                       |\n");
                    printf("\t\t\t\t-----------------------------------------\n");
                    printf("\n");
                    printf("\n");
                }
            }
        else if(a==2)
            {
                system("cls");
                printf("\n");
                printf("\t\t\t\t-----------------------------------------\n");
                printf("\t\t\t\t|                                       |\n");
                printf("\t\t\t\t|\t\t BYE BYE                |\n");
                printf("\t\t\t\t|                                       |\n");
                printf("\t\t\t\t-----------------------------------------\n");
                printf("\n");
                printf("\n");
            }
    }
    else if(d==1)//for admin
    {
        FILE *admins;
        char username[50], password[50];
        admins = fopen("admin.txt", "r");
        char Lusername[50], Lpassword[50];
        printf("\n");
        printf("\t\t\t\t-----------------------------------------\n");
        printf("\t\t\t\t|                                       |\n");
        printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
        printf("\t\t\t\t|                                       |\n");
        printf("\t\t\t\t-----------------------------------------\n");
        printf("\n");
        printf("\n  Username : ");
        scanf("%s", username);
        printf("\n  Password : ");
        int p = 0;
         do
         {
          password[p] = getch();
          if (password[p] != '\r')
          {
           printf("*");
          }
          p++;
         } while (password[p - 1] != '\r');
         password[p - 1] = '\0';

         while (fscanf(admins, "%s", Lusername) && fscanf(admins, "%s", Lpassword))
         {
          if (strcmp(username, Lusername) == 0 && strcmp(password, Lpassword) == 0)
          { //include string.h

           printf("\n  Log In Succesful  \n");
           getch();
           break;
          }

          if (feof(admins))
          {
           system("cls");
           printf("\n  Wrong!!  \n");
           printf("\n  Passwords do not match  \n");
           getch();
           system("CLS");
           main();

          }
         }

         fclose(admins);

         int adminnum ;
         system("cls");
         printf("\n");
         printf("\n");
         printf("\t\t\t\t-----------------------------------------\n");
         printf("\t\t\t\t|                                       |\n");
         printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
         printf("\t\t\t\t|                                       |\n");
         printf("\t\t\t\t-----------------------------------------\n");
         printf("\n");
         printf("\t\t\t       --------------------------------------------\n");
         printf("\t\t\t       |                                          |\n");
         printf("\t\t\t       |  Please choose number 1 or 2 to proceed  |\n");
         printf("\t\t\t       |                                          |\n");
         printf("\t\t\t       |  1 . Delete Data                         |\n");
         printf("\t\t\t       |                                          |\n");
         printf("\t\t\t       |  2 . Add Data                            |\n");
         printf("\t\t\t       |                                          |\n");
         printf("\t\t\t       --------------------------------------------\n");
         printf("\n");
         printf("\n");
         printf("  Select Number : ") ;
         scanf("%d",&adminnum) ;

         if(adminnum==1)
         {
             system("cls");
             printf("\n");
            printf("\t\t\t\t-----------------------------------------\n");
            printf("\t\t\t\t|                                       |\n");
            printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
            printf("\t\t\t\t|                                       |\n");
            printf("\t\t\t\t-----------------------------------------\n");
            printf("\n");
             FILE *fileptr1, *fileptr2;
                char filename[40];
                char ch;
                int delete_line, temp = 1;

                printf("\n  Enter file name : \n");
                scanf("%s", filename);
                //open file in read mode
                fileptr1 = fopen(filename, "r");
                ch = getc(fileptr1);
               while (ch != EOF)
                {
                    printf("%c", ch);
                    ch = getc(fileptr1);
                }
                //rewind
                rewind(fileptr1);
                printf("\n  Enter line number of the line to be deleted : \n");
                scanf("%d", &delete_line);
                //open new file in write mode
                fileptr2 = fopen("replica.c", "w");
                ch = 'A';
                while (ch != EOF)
                {
                    ch = getc(fileptr1);
                    //except the line to be deleted
                    if (temp != delete_line)
                    {
                        //copy all lines in file replica.c
                        putc(ch, fileptr2);
                    }
                    if (ch == '\n')
                    {
                        temp++;
                    }
                }
                fclose(fileptr1);
                fclose(fileptr2);
                remove(filename);
                //rename the file replica.c to original name
                rename("replica.c", filename);
                printf("\n  The contents of file after being modified are as follows : \n");
                fileptr1 = fopen(filename, "r");
                ch = getc(fileptr1);
                while (ch != EOF)
                {
                    printf("%c", ch);
                    ch = getc(fileptr1);
                }
                fclose(fileptr1);
                getch();

         }

         else if(adminnum==2)
         {
             char data[200] ;
             char filename[40];
             char dataroom[20] ;
             char ch;
             int dataprice , datanight ;
             system("cls");
             printf("\n");
            printf("\t\t\t\t-----------------------------------------\n");
            printf("\t\t\t\t|                                       |\n");
            printf("\t\t\t\t|\t\tNICE Hotel\t\t|\n");
            printf("\t\t\t\t|                                       |\n");
            printf("\t\t\t\t-----------------------------------------\n");
            printf("\n");

            printf("\n  Enter file name : \n");
            scanf("%s", filename);

            FILE *fileptr3 ;
            fileptr3 = fopen(filename, "r");
                ch = getc(fileptr3);
               while (ch != EOF)
                {
                    printf("%c", ch);
                    ch = getc(fileptr3);
                }
            fclose(fileptr3);


            FILE *fp;
            fp = fopen(filename, "a");
            printf("\n\n  Enter data : \n");
            scanf("%s %d %d",dataroom , &dataprice , &datanight);
            fprintf(fp,"%s %d %d\n", dataroom , dataprice , datanight);
            fclose(fp) ;

            FILE*fileptr1 ;
            fileptr1 = fopen(filename, "r");
                ch = getc(fileptr1);
                while (ch != EOF)
                {
                    printf("%c", ch);
                    ch = getc(fileptr1);
                }
                fclose(fileptr1);
                printf("  Add data Complete  ") ;
                getch() ;
         }




    }

}




