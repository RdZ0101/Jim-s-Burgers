//Stage-C
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

float discount=0; //Used to allocate the discount value.

//enums
enum BurgerType{
	Chicken,
	Ham,
	Vegie
};

//structure definitions.
typedef struct
{
	enum BurgerType t;
	int Quantity;
	float TotalPrice;
	
}burger;

typedef struct 
{
	char ReciptNo[5];
	float TotalOrder;
	burger* b;
	
}order;

//function prototypes
float DiscountCalc(int Qty, float total);
/*char CancelOrder(char BillNo, char ReciptNo);*/

int main()
{
	int count=1;//Using count variable to keep track of the number of orders.
	order *o=(order*)malloc(sizeof(order)*(count+1));
	
	
	
	int option=0;//option is used to gain users input for the main menu.
	

	while(option!=3)
	{
		char add;//To get the user's choice whether to add more burgers or not.
		int uPrice=0;//Price of a burger is .considered the unit price.
		int btcount=1;//Used to keep track of burger types within an order.
		char type;//Burger type char value
		o[count].b = (burger*)malloc(sizeof(burger)*(btcount+1));
		float Total=0;//to store the current total value payable.
		
		printf("Welcome to Tasty Burgers\nPlace your order here..\n 1. Order Burger \n 2. Cancel \n 3. Exit \n\nSelect your option: \n");
		scanf("%d",&option); 
		fflush(stdin);
		switch(option)//Switch used to drive the main menu.
		{
			case 1 :
					do
					{	printf("Select the Burger Type \nA - Chicken Burger - 15$ \nB - Ham Burger - 17$ \nC - Vegie Burger -13$ \nX - To return to Main Menu\nSelect your burger type\n");
						scanf("%s",&type);
						fflush(stdin);
						switch(type)//main menu
						{
							case 'A' :uPrice=15;	
										o[count].b[btcount].t=0;
										break;
							case 'B' :uPrice=17;	
										o[count].b[btcount].t=1;
										break;
							case 'C' :uPrice=13;	
										o[count].b[btcount].t=2;
										break;
							case 'X':break;
							default	:printf("Invalid Burger Type\n");
										continue;
						}
						if(type=='X')//to exit to main menu.
							break;
						else
						{
							printf("How many burgers you wish you order? \n");
							scanf("%d",&o[count].b[btcount].Quantity);//Assigning value to Quantity in burger structure.Using count as the element in the burger array.
							Total=Total+uPrice*o[count].b[btcount].Quantity;//Total bill value.
							printf("Your current bill value is: $%.2f \n", Total);
							printf("Press \"Y\" to add more burgers into your order or Press \"N\" to process your order now.\n");
							scanf("%s",&add);
							fflush(stdin);
							btcount++;
						}
					}while(add!='N');
					printf("\nYour total bill value is: $%.2f \n", Total);
					
					DiscountCalc(o[count].b[btcount].Quantity, Total);/*function used for calculating the Discount. In Prior Stages the following code was here
					if(o[count].b[btcount].Quantity>4)//Evaluating whether the order qualifies for a discount.
					{
						discount = 0.9;
						printf("Discount 10%% -  $%.2f \n",Total*0.1);
					}
					else
					{
						discount = 1;
					}*/
					
					o[count].TotalOrder = Total*discount;//Final price. 
					printf("Final bill value is: $%.2f \n", o[count].TotalOrder);
					//Sorting the count based on being decimals in order to fit into the array elements.
					if(count<10)//if count is <10 it can be allocated into one element.
					{
						char charCount=count+'0';//Converting count into a char in order to fit into the char array.
						o[count].ReciptNo[0] ='B';
						o[count].ReciptNo[1] ='0';
						o[count].ReciptNo[2] ='0';
						o[count].ReciptNo[3] =charCount; //Assigning a char value.
						o[count].ReciptNo[4] ='\0';
						o[count].ReciptNo[5] ='\0';
					}
					else //if count>10 it must be broken down in order to fit into each element.
					{
						o[count].ReciptNo[0] ='B';
						o[count].ReciptNo[1]='0';
						o[count].ReciptNo[2] ='0';
						int tenth=(count/10); //finding the multiple of ten for the count using division by 10. 
						char charTenth=tenth+'0';//converting to char.
						o[count].ReciptNo[3] = charTenth; 
						int Remainder=count%10; //Finding the remainder  after the division by 10 in order to get a decimal value. 
						char charRemainder=Remainder+'0'; //converting to char.
						o[count].ReciptNo[4] =charRemainder;
						o[count].ReciptNo[5] ='\0';
					}
					printf("Your receipt number is ");
					for(int i=0;i<6;i++) //printing the Recipt number using loop since it's a char array.
					{
						char n = o[count].ReciptNo[i];
						printf("%c",n);
					}
					printf("\nPlease go to a register and make the payment by quoting the Receipt Number - ");
					for(int i=0;i<6;i++)
					{
						char n = o[count].ReciptNo[i];
						printf("%c",n);
					}
					printf("\n\n<<Press Any Key to show the main menu >>\n\n");
					count++;
					(getch());
					break;
					o[count].b = (burger*)realloc(o[count].b, sizeof(burger)*(btcount+1));
			case 2 :printf("Please enter your Recipt Number :");
					char billNo[6]; //Variable to store the Reccipt number which needs to be deleted.
					scanf("%s",&billNo); //Using string instead of  char in order to create a string which can be compared later to the recipt number.
					for(count=1;count<25;count++)
					{

						if(strcmp(billNo,o[count].ReciptNo)==0) //Using comparison results to initiate the deletion. 
						{
	
							for(int i=0;o[count].ReciptNo[i]!='\0';i++)//using Swap to change the recipt number.
							{
								o[count].ReciptNo[i]=o[count].ReciptNo[i+1];
							}
							o[count].TotalOrder=o[count+1].TotalOrder;
				
					
							printf("Your order has been cancelled. Thank you.\n");
						}
						else
							printf("Invalid Reccipt Number. Please try again.\n");
						break;
					} 
					printf("\n<<Press Any Key to show the main menu >>\n\n");
					(getch());
					
					/*
					CancelOrder(billNo, o[count].ReciptNo);
					This Function call was here instead of the code segment above for the cancel order. Replaced it with the code segment since i was getting errors in stage C.*/
					
			
			case 3 :break;
			
			default:printf("\n\n Invalid Option\n\n<<Press Any Key to show the main menu >>\n\n");
					(getch());
					continue;//Incase the user enters a wrong input
		};
	};

	
	return 0;
};

//functions
float DiscountCalc(int Qty,float total)
{
	if(Qty>5)//Evaluating whether the order qualifies for a discount.
	{
		discount = 0.9;
		printf("Discount 10%% -  $%.2f \n",total*0.1);
	}
	else
	{
		discount = 1;
	}
	return discount;
}

/*char CancelOrder(char BillNo, char ReciptNo)
{
	for(count=1;count<25;count++)
	{

		if(strcmp(billNo,o[count].ReciptNo)==0) //Using comparison results to initiate the deletion. 
		{
	
			for(int i=0;o[count].ReciptNo[i]!='\0';i++)
			{
				o[count].ReciptNo[i]=o[count].ReciptNo[i+1];
			}
			o[count].TotalOrder=o[count+1].TotalOrder;
				
					
			printf("Your order has been cancelled. Thank you.\n");
		}
		else
			printf("Invalid Recipt Number.\n");
			break;
	}
	printf("\n<<Press Any Key to show the main menu >>\n\n");
	(getch());
}*/