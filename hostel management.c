#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int main_exit;  //globally declared variable with default value = 0.

//functions----
void menu();
void insert();
void edit();
void viewlist();
void erase();
void search();
void closer();
int login();

struct date         //a structure for dob.
{
    int month,day,year;
};

struct detail           //structure for details of the student.
{
    char name[60];
    char mail_id[30];
    int room_no;
    double phone;
    char hostel_name[10];
    char roll_no[10];
    struct date dob;
}add,upd,check,rem;         //A structure for each function.

//LOGIN FUNCTION---------------------
int login()
{
    int i=0;
    char username[10],password[10];
    char c = ' ';
    char user[10] = "myhostel";         //standard user name.
    char pass[10] = "password";         //standard password.

    while(1)            //infinite loop.
    {
        system("cls");      //clear screen.
        printf("\n  **************************  LOGIN FORM  **************************  ");
        printf(" \n                       ENTER THE USERNAME:-");
        scanf("%s", &username);
        fflush(stdin);
        printf(" \n                       ENTER THE PASSWORD:-");
        while(i<10)
        {
            password[i]=getch();
            c=password[i];
            if(c==13)
                break;        //i.e if enter key is pressed.
            else
                printf("*");        //to keep the password invisible.
            i++;
        }
        password[i] = '\0';
        i = 0;
        if(strcmp(username,user)==0 && strcmp(password,pass)==0)        //match.
        {
            printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
            getch();
            break;
        }
        else            //incorrect
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
            getch();
        }
    }
    system("cls");
}

//MAIN FUNCTION-------------
void main()
{
	login();
    menu();
}

//MENU FUNCTION----------------------
void menu()
{
    system("cls");
    int choice;
    printf("\n\n\t\t\tHOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\t WELCOME TO THE MAIN MENU ");
    printf("\n\n\t\t1. Enter new Student's data\n\t\t2. Update information of existing account\n\t\t3. Search the details of an existing account\n\t\t4. Removing existing account\n\t\t5. View all students list\n\t\t0. Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

        case 1:insert();
        break;
        case 2:edit();
        break;
        case 3:search();
        break;
        case 4:erase();
        break;
        case 5:viewlist();
        break;
        case 0:closer();
        break;
        default:menu();
    }
}

//NEW ENTRY FUNCTION-----------
void insert()
{
    system("cls");

    FILE *ptr,*room;
    ptr = fopen("record.txt","a+");          //keeps track of the student records.
    room = fopen("room.txt","a+");          //keeps track of the rooms booked.
    while(1)
    {
        int flag=0;
        printf("\t\t\t\t ADD STUDENTS DATA ");
        printf("\nEnter your roll number:");
        scanf("%s",check.roll_no);

        //scans one entry at a time---------
        while (fscanf(ptr,"%s %s %d/%d/%d %lf %s %d %s",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.phone, &add.mail_id, &add.room_no, &add.hostel_name)!=EOF)
        {
            if(strcmp(check.roll_no,add.roll_no) == 0)
            {
                printf("You have already registered and booked a hostel room.\n_________________________________________________________________________\n");
                flag=1;
                break;
            }
        }
        if(!flag)
            break;
    }
    strcpy(add.roll_no,check.roll_no);
    printf("\nEnter your name: ");
    scanf("%s",add.name);
    fflush(stdin);

    //exception handling------
    while(1)
    {
        printf("\nEnter your date of birth (mm/dd/yyyy): ");
        scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
        if(!(add.dob.day>0 && add.dob.day<32 && add.dob.month<13 && add.dob.month>0))
            printf("INVALID... please try again.\n_________________________________________________________________________\n");
        else
            break;
    }

    //exception handling------
    while(1)
    {
        printf("\nEnter your phone number: ");
        scanf("%lf",&add.phone);
        if(add.phone < 1000000000 || add.phone > 9999999999)
            printf("Please enter a 10 digit phone number.\n_________________________________________________________________________\n");
        else
            break;
    }
    printf("\n Enter your email id : ");
    scanf("%s",add.mail_id);
    fflush(stdin);
    printf("\n Enter your hostel block name from BH-1, BH-2, BH-3: ");
    scanf("%s",add.hostel_name);
    fflush(stdin);

    //TO CHECK WETHER ROOM IS BOOKED OR NOT--------
    while(1)
    {
        int flag=0;
        printf("\n Enter your room no.: ");
        fflush(stdin);
        scanf("%d",&check.room_no);
        while (fscanf(room,"%d",&add.room_no)!=EOF)
        {
            if(add.room_no == check.room_no)
            {
                printf("This room has already been booked.\n Please opt for some other room.\n_________________________________________________________________________\n");
                flag=1;
                break;
            }
        }
        if(!flag)
            break;
    }
    add.room_no = check.room_no;
    printf("Room booked successfully by %s.\n", add.name);
    fprintf(ptr,"%s %s %d/%d/%d %lf %s %d %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.phone, add.mail_id, add.room_no, add.hostel_name);
    fprintf(room, "%d\n", add.room_no);
    fclose(room);
    fclose(ptr);
    printf("The Student has been added into the Records.\n_________________________________________________________________________\n");

    //ending choices----------
    while(1)
    {
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
        if(main_exit != 1 && main_exit != 0)
            printf("\nInvalid!");
        else
            break;
    }
    if (main_exit == 1)
        menu();
    else if(main_exit == 0)
            closer();
}

//VIEW FUNCTION--------
void viewlist()
{
    system("cls");
    FILE *v;

    v= fopen("record.txt","r");
    int count = 0;

    //VIEWING LIST---------
    printf("\nROLL NO.\t\tNAME\t\tPHONE\n");

    //scans one entry at a time---------
    while (fscanf(v,"%s %s %d/%d/%d %lf %s %d %s",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.phone, &add.mail_id, &add.room_no, &add.hostel_name)!=EOF)
    {
        printf("\n%8s\t\t%10s\t\t%.0lf",add.roll_no,add.name,add.phone);
        count++;        //keeping track of the records shown.
    }
    fclose(v);

    if(count == 0)
        printf("No records exist!");
    else
        printf("\n\n%d Records were shown.\n_________________________________________________________________________\n",count);

    //ending choices----------
    while(1)
    {
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
        if(main_exit != 1 && main_exit != 0)
            printf("\nInvalid!");
        else
            break;
    }
    if (main_exit == 1)
        menu();
    else if(main_exit == 0)
            closer();
}

//SEARCH FUNCTION-------------------
void search()
{
    system("cls");
    FILE *ptr;
    int count = 0;
    ptr = fopen("record.txt","r");
    printf("\n\nEnter the roll number:");
    scanf("%s",&check.roll_no);

    //scans one entry at a time---------
    while (fscanf(ptr,"%s %s %d/%d/%d %lf %s %d %s",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.phone, &add.mail_id, &add.room_no, &add.hostel_name)!=EOF)
    {
        if(strcmp(add.roll_no,check.roll_no) == 0)
        {
            count = 1;
            printf("\nROLL NO.: %s\nName: %s \nDOB: %d/%d/%d \nPhone number: %.0lf \nE-Mail id: %s \nRoom No: %d \nHostel Block: %s \n_________________________________________________________________________\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.phone, add.mail_id, add.room_no, add.hostel_name);
        }
    }
    fclose(ptr);
    if(count == 0)
        printf("\nRecord not found!");

    //ending choices----------
    while(1)
    {
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
        if(main_exit != 1 && main_exit != 0)
            printf("\nInvalid!");
        else
            break;
    }
    if (main_exit == 1)
        menu();
    else if(main_exit == 0)
            closer();
}

//EDIT FUNCTION---------------
void edit()
{
    system("cls");
    int count = 0;
    FILE *o, *n;
    o = fopen("record.txt","r");
    n = fopen("new.txt","w+");

    printf("\nEnter the roll no. of the student whose info you wish to update:");
    scanf("%s",upd.roll_no);

    //scans one entry at a time---------
    while (fscanf(o,"%s %s %d/%d/%d %lf %s %d %s",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.phone, &add.mail_id, &add.room_no, &add.hostel_name)!=EOF)
    {
        if (strcmp(add.roll_no,upd.roll_no) == 0)
        {
            count = 1;

            //exception handling-------
            while(1)
            {
                printf("\nEnter the new phone number: ");
                scanf("%lf",&upd.phone);
                if(upd.phone < 1000000000 || upd.phone > 9999999999)
                    printf("Please enter a 10 digit phone number.\n_________________________________________________________________________\n");
                else
                    break;
            }
            printf("Enter the new mail id: ");
            scanf("%s",upd.mail_id);
            fflush(stdin);
            fprintf(n,"%s %s %d/%d/%d %lf %s %d %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, upd.phone, upd.mail_id, add.room_no, add.hostel_name);
            printf("Your changes are saved.\n_________________________________________________________________________\n");
        }
        else
            fprintf(n,"%s %s %d/%d/%d %lf %s %d %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.phone, add.mail_id, add.room_no, add.hostel_name);
    }
    fclose(o);
    fclose(n);
    remove("record.txt");               //deletes the record file.
    rename("new.txt","record.txt");     //renames the new file as record.

    if(count != 1)
        printf("\nRecord not found.\n_________________________________________________________________________\n");

    //ending choices----------
    while(1)
    {
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
        if(main_exit != 1 && main_exit != 0)
            printf("\nInvalid!");
        else
            break;
    }
    if (main_exit == 1)
        menu();
    else if(main_exit == 0)
            closer();
}

//DELETE FUNCTION---------
void erase()
{
    system("cls");
    FILE *o, *n, *o1, *n1;
    int count = 0;
    o = fopen("record.txt","r");
    n = fopen("new.txt","w");
    o1 = fopen("room.txt","r");
    n1 = fopen("new1.txt","w");

    printf("Enter the roll no. of the student whose data you wish to delete: ");
    scanf("%s",rem.roll_no);

    //scans one entry at a time---------
    while (fscanf(o,"%s %s %d/%d/%d %lf %s %d %s",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.phone, &add.mail_id, &add.room_no, &add.hostel_name)!=EOF)
    {
        if (strcmp(add.roll_no,rem.roll_no) == 0)
        {
            count ++;
            printf("\nRecord deleted successfully.\n_________________________________________________________________________\n");
        }
        else
        {
            fprintf(n1,"%d\n",add.room_no);
            fprintf(n,"%s %s %d/%d/%d %lf %s %d %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.phone, add.mail_id, add.room_no, add.hostel_name);
        }
    }
    fclose(o1);
    fclose(n1);
    fclose(o);
    fclose(n);
    remove("room.txt");
    rename("new1.txt","room.txt");
    remove("record.txt");
    rename("new.txt","record.txt");

    if(count == 0)
        printf("\nRecord not found!\n_________________________________________________________________________\n");

    //ending choices----------
    while(1)
    {
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
        if(main_exit != 1 && main_exit != 0)
            printf("\nInvalid!");
        else
            break;
    }
    if (main_exit == 1)
        menu();
    else if(main_exit == 0)
            closer();
}

//CLOSING FUNCTION--------
void closer()
{
    system("cls");
    printf("\n\n\nThank you!\n\n\t ~by MANAN PATEL\n\n\n");
}
