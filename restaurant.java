package restaurant;

import java.text.SimpleDateFormat;      //formatting date 
import java.util.Date;                  //to get the current date
import java.util.Scanner;               //scanner class
import java.util.concurrent.*;          //for time sleep
import java.util.Random;                //to generate ea random number

//ITEM CLASS TO GROUP ALL ITEMS AND DETAILS-----
class Item
{
    int id[];
    String name[];
    int quantity[];
    float price[];
    Item(int id[], String name[], int quantity[], float price[])       //parametrized constructor
    {
        this.id = id.clone();
        this.quantity = quantity.clone();
        this.name = name.clone();
        this.price = price.clone();
    }
}

//BILLINGDISPLAY CLASS TO CALCULATE AND DISPLAY THE FINAL BILL---------
class BillingDisplay
{
    Item it;
    public BillingDisplay(Item it)      //parametrized constructor.
    {
        this.it =it;
    }
    public void billdisp()
    {
        float total = 0f;
        System.out.println("\t     \tName\t\t Item ID\t\tQuantity\tCost\n");    //TABLE----
        int j = 1;
        for(int i=0;i<it.id.length;i++)
            {
                if(it.name[i] == null)          //NULL ITEMS
                break;
                if(it.id[i] != -1)      //UNREMOVED ITEMS
                {
                    System.out.printf("\t%d. %20s|\t%8d|\t%8d|\t%8.2f|\n",j,it.name[i],it.id[i],it.quantity[i],it.price[i] * it.quantity[i]);
                    j++;
                    total += it.price[i] *it.quantity[i];
                }
                
            }
        System.out.println("\n\nTotal Cost : "+total);      //FINAL BILL----
    }
}

//MENU CLASS FOR PRESENTING THE MENU---------
class Menu
{
    int id[] = new int[10];
    String name[] = new String[10];
    int quantity[] = new int[10];
    float price[] = new float[10];

    //MENU METHOD----
    public Item menu()
    {
        Scanner sc = new Scanner(System.in);  
        int choice,choice2 = 0;
        char or;
        int i= 0;
        while(true)     //infinite loop.
        {
            //MENU----
            System.out.println("*************************** MENU ***************************");
            System.out.println("Please enter your choice: ");
            System.out.println("1. Salad");
            System.out.println("2. Main Course");
            System.out.println("3. Desert And Drinks");
            choice = sc.nextInt();

            //CASES TAKEN---
            switch(choice)
            {
                case 1:
                System.out.println("\t      Name \t\tPrice");
                System.out.println("\t1.Hand Tossed Salad  |\t5$");
                System.out.println("\t2.Ceasar Salad       |\t8$");
                System.out.println("\t3.Roasted Vegetables |\t12$");
                System.out.println("\t4.Loaded Baked Potato|\t12$");
                System.out.print("Enter the desired item: ");
                choice2 = sc.nextInt();
                System.out.print("\n\t Enter the desired quantity: ");
                quantity[i] = sc.nextInt();
                if(choice2 == 1) 
                {
                        price[i] = 5f;
                        name[i] = "Hand Tossed Salad";
                }
                else if(choice2 == 2)
                    {
                        price[i] = 8f;
                        name[i] = "Ceasar Salad";
                    }
                else if(choice2 == 3)
                    {
                        price[i] = 12f;
                        name[i] = "Roasted Vegetables";
                    }
                else if(choice2 == 4)
                    {
                        price[i] = 12f;
                        name[i] = "Loaded Baked Potato";
                    }
                break;
                case 2:
                System.out.println("\t      Name \t\tPrice");
                System.out.println("\t1.Saada Dosa         |\t8$");
                System.out.println("\t2.Special Masala Dosa|\t10$");
                System.out.println("\t3.Idli               |\t7$");
                System.out.println("\t4.Uttapam            |\t7$");
                System.out.println("\t5.Mendu Vada         |\t5$");
                System.out.print("Enter the desired item: ");
                choice2 = sc.nextInt();
                System.out.print("\n\t Enter the desired quantity: ");
                quantity[i] = sc.nextInt();
                if(choice2 == 1) 
                    {
                        price[i] = 8f;
                        name[i] = "Saada Dosa";
                    }
                else if(choice2 == 2)
                    {
                        price[i] = 10f;
                        name[i] = "Special Masala Dosa";
                    }
                else if(choice2 == 3)
                    {
                        price[i] = 7f;
                        name[i] = "Idli";
                    }
                else if(choice2 == 4)
                    {
                        price[i] = 7f;
                        name[i] = "Mendu Vada";
                    }
                else if(choice2 == 5)
                    {
                        price[i] = 5f;
                        name[i] = "Mendu Vada";
                    }
                break;
                case 3:
                System.out.println("\t      Name \t\tPrice");
                System.out.println("\t1.Fresh Juice        |\t2$");
                System.out.println("\t2.Cappachino         |\t3$");
                System.out.println("\t3.Donuts             |\t4$");
                System.out.println("\t4.Cookies N Cream    |\t3$");
                System.out.print("Enter the desired item: ");
                choice2 = sc.nextInt();
                System.out.print("\n\t Enter the desired quantity: ");
                quantity[i] = sc.nextInt();
                if(choice2 == 1) 
                    {
                        price[i] = 2f;
                        name[i] = "Fresh Juice";
                    }
                else if(choice2 == 2)
                    {
                        price[i] = 3f;
                        name[i] = "Cappachino";
                    }
                else if(choice2 == 3)
                    {
                        price[i] = 4f;
                        name[i] = "Donuts";
                    }
                else if(choice2 == 4)
                    {
                        price[i] = 3f;
                        name[i] = "Cookies N Cream";
                    }
                break;
            }

            //Unique ids for each item baught------
            id[i] = (choice*10 + choice2);

            //RETURNS THE ID OF THE ITEM------
            System.out.print("Do you wish to order another item(y/n): ");
            or = sc.next().charAt(0);
            if(or =='Y' || or == 'y')
            {
                if(i>10)        //MAX OREDER LIMIT-----
                {
                    System.out.println("You have exceeded limit for one Order!");
                    break;
                }
                i++;
            }
            else
            {
                //CONFIRMATION TO FININSH ORDER----
                System.out.println("Are you sure ?(y/n)");
                System.out.println("You may edit your order later, but from now on you will not be able to add any more orders.");
                char sure = sc.next().charAt(0);
                if(sure == 'Y' || sure == 'y')
                {
                    i++;
                    break;
                }
            }
        }
        //Details grouped into Item----
        Item item = new Item(id, name, quantity, price);
        return item;  
    }
}

public class restaurant {

    //LOGIN METHOD-------------------
    public static void login()
    {
        Scanner sc = new Scanner(System.in);
        String username,password;
        final String user = "dhaaba";            //standard unchagable username.
        final String pass = "password";         //standard unchangable password.

        while(true)            //infinite loop.
        {
            System.out.print("\n  **************************  LOGIN FORM  **************************  ");
            System.out.print("\n\n                       ENTER THE USERNAME:-");
            username = sc.next();
            System.out.print(" \n                       ENTER THE PASSWORD:-");
            password = sc.next();

            //We could also have used a ThreadMask to hide the password on the console---------
            if(user.equals(username) && pass.equals(password))        //MATCH.
            {
                System.out.print("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
                System.out.println("Press 'c' to continue or any other key go back to login");
                if(sc.next().charAt(0) == 'c')
                break;
            }
            else            //Incorrect
            {
                System.out.println("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
                System.out.println("Press 'g' to go back to login form or any other key to exit");
                if(sc.next().charAt(0) != 'g')
                System.exit(0);
            }
        }
    }
    public static void main(String[] args) {

        login();        //login method---
        Scanner sc = new Scanner(System.in);  
        String name;
        char res;
        int ed;

        //TO SHOW THE CURRENT TIME---
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");  
        Date date = new Date();  

        //TO GENERATE A RECIEPT-----
        Random rand = new Random();
        int r1 = rand.nextInt(100);
        int r2 = 57, r3 = 99, r4 = 7, r5 = 17, r6 = 22;             //default made reservations. 
        int r0;

        //Menu object to display menu and place orders----
        Menu m = new Menu();

        //INTRODUCTION------
        System.out.println("*************************** ANGREZI DHABBA ***************************");
        System.out.println("An upmost WELCOME!\nTo our Online platflorm taking in consideration of the pandemic we have reopned digitally!");
        System.out.println("What's your good name sir/ma'am ?");
        name = sc.next();

        while(true)             //infinite loop.
        {
            System.out.println("\n\n"+name+", have you made any reservations for the time slot? (y/n)");
            res = sc.next().charAt(0);
            if(res == 'n' || res == 'N')
            {
                long timeToSleep = 10L;

                // Create a TimeUnit object 
                TimeUnit time = TimeUnit.SECONDS;
                
                //EXCEPTION HANDLING-----------------------------
                try {
                System.out.println("\nPlease wait while we book your slot...");

                // using sleep() method
                time.sleep(timeToSleep);
                System.out.println("We have booked your slot at : "); 
                }
                catch (InterruptedException e) { 
                    System.out.println("Interrupted while allocating slot..."); 
                }

                //DISPLAY THE TIME OF BOOKING--------
                System.out.println(formatter.format(date)); 
                System.out.println("\nYour food will be delivered an hour after booking as per policies.");
                //Provide the reciept number generated-----
                System.out.println("Here is your ID reciept number: "+r1);
                break;
            }
            else
            {
                System.out.println("Enter the id reciept number: ");
                r0 = sc.nextInt();
                if(r0==r2||r0==r3||r0==r4||r0==r5||r0==r6)
                {
                    System.out.println("Your food will be delivered within half an hour as per policies.");
                    break;
                }
                else 
                System.out.println("No such booking has been made.");
            }  
        }
        System.out.println("You may place your order now: ");
        Item item = m.menu();

        //BILLING DISPLAY------
        BillingDisplay bd = new BillingDisplay(item);
        while(true)         //infinte loop--------
        {
            System.out.println("\nShall we consider this as the final order or do you wish to:\n1. Edit\n2. Remove\n3. Final Order");
            ed = sc.nextInt();

            //edit--------
            if(ed == 1)
            {
                System.out.println("Which Item do you wish to edit "+name+"?");
                bd.billdisp();
                System.out.print("Enter the Item number: ");
                int itemid = sc.nextInt();
                int flag = 0;
                for(int x=0;x<item.id.length;x++)
                {
                    if(item.id[x] == itemid)        //item ids match-------
                    {
                        flag = 1;
                        System.out.print("Enter the new Quantity: ");
                        item.quantity[x] = sc.nextInt();
                        bd = new BillingDisplay(item);      //new order stored in the table-----
                        break;
                    }
                }    
                if(flag == 0)
                    System.out.println("You have ordered no such item, Try again...");        
            }

            //remove------
            else if(ed == 2)
            {
                System.out.println("Which Item do you wish to remove "+name+"?");
                bd.billdisp();
                System.out.print("Enter the Item ID: ");
                int itemid = sc.nextInt();
                int flag = 0;
                for(int x=0;x<item.id.length;x++)
                {
                    if(item.id[x] == itemid)    //item ids match---------
                    {
                        flag =1;
                        item.id[x] = -1;
                        System.out.println("The Item: "+item.name[x]+" is removed.");
                        bd = new BillingDisplay(item);      //new orders stored in table-----------
                        break;
                    } 
                }
                if(flag == 0)
                    System.out.println("You have ordered no such item, Try again...");   
            }
            else
            {
                long timeToSleep = 10L;         //10Seconds.
                // Create a TimeUnit object 
                TimeUnit time = TimeUnit.SECONDS; 

                //EXCEPTION HANDLING-------------------------------
                try {
                System.out.println("Please wait while your bill is being made...\n"); // using sleep() method
                time.sleep(timeToSleep); 
                bd.billdisp();

                //OUTRO-----
                System.out.println("To be paid in cash on delivery(COD).");
                System.out.println("THANKYOU for your visit "+name+".\nWe hope you pick our restraunt again for quenching your hunger with our delicious cuisines!\n");
                System.out.println("\n\t\t\t\t~by MANAN PATEL");
                break;
                }
                catch (InterruptedException e) { 
                    System.out.println("Interrupted while billing...");
                }  
            }
        }
    }
}
