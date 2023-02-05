/*20ETCS002080 Mridula G. Narang*/
/*This is C program for a multi user ATM machine using sequential approach.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int pin1=1310,pin2=3112,option,enteredPin1,enteredPin2,count=0,amount=1,user;
    float balance1 = 2000,balance2 = 5000;
    int continueTransaction=1;
    
    time_t now;
    time(&now);
    printf("%s",ctime(&now));
    printf("=================*Welcome to ATM service*================= \n");
    printf("Select user \n Press 1 for user 1 and 2 for user 2: ");
    scanf("%d",&user);
    switch (user)
    {
    case 1:
        while(pin1 != enteredPin1)
        {
            printf("Please enter your pin: ");
            scanf("%d",&enteredPin1);
            if(enteredPin1!=pin1)
            {   
                printf("Invalid pin!!! \n");
            }
            count++;
            if(count==3 && enteredPin1!=pin1)
            {
                exit(0);
            }

        }

        while(continueTransaction != 0)
        {
            printf("=================*Available transactions*================= \n");
            printf("1.Withdrawal \n");
            printf("2.Deposit \n");
            printf("3.Check Balance \n");
            printf("4. Quit \n");
            printf("Please select an option: ");
            scanf("%d",&option);
            switch (option)
            {
                case 1:
                    while(amount % 100 != 0)
                    {
                        printf("Enter amount to withdraw: ");
                        scanf("%d",&amount); 
                        if(amount % 100 != 0)
                        {
                            printf("Amount should be multiple of 100 \n");
                        }
                    }
                    if(balance1 < amount)
                    {
                        printf("Insufficient balance. \n");
                        amount = 1;
                    }
                    else
                    {
            
                        balance1 -= amount;
                        printf("You have withdrawn Rs. %d. Your balance after withdrawal is Rs. %.2f \n",amount,balance1);

                    }
                    break;
                case 2:
                    printf("Enter amount to deposit: ");
                    scanf("%d",&amount);
                    balance1 += amount;
                    printf("You have deposited Rs. %d. Your balance after deposit is Rs. %.2f \n",amount,balance1);
                    break;
                case 3:
                    printf("Your balance is Rs. %.2f \n",balance1);
                    break;
                case 4:
                    printf("Thank you for choosing our ATM service. \n");
                    break;
    
                default: 
                    printf("Invalid input!!! \n");
                    break;
            }
            printf("Do you wish to perform another transaction? Press 1 for YES and 0 for NO  ");
            scanf("%d",&continueTransaction);
        }
        break;
        
    
    case 2:
        while(pin2 != enteredPin2)
        {
            printf("Please enter your pin: ");
            scanf("%d",&enteredPin2);
            if(enteredPin2!=pin2)
            {   
                printf("Invalid pin!!! \n");
            }
            count++;
            if(count==3 && enteredPin2!=pin2)
            {
                exit(0);
            }

        }

        while(continueTransaction != 0)
        {
            printf("=================*Available transactions*================= \n");
            printf("1.Withdrawal \n");
            printf("2.Deposit \n");
            printf("3.Check Balance \n");
            printf("4. Quit \n");
            printf("Please select an option: ");
            scanf("%d",&option);
            switch (option)
            {
                case 1:
                    while(amount % 100 != 0)
                    {
                        printf("Enter amount to withdraw: ");
                        scanf("%d",&amount); 
                        if(amount % 100 != 0)
                        {
                            printf("Amount should be multiple of 100 \n");
                        }
                    }
                    if(balance2 < amount)
                    {
                        printf("Insufficient balance. \n");
                        amount = 1;
                    }
                    else
                    {
            
                        balance2 -= amount;
                        printf("You have withdrawn Rs. %d. Your balance after withdrawal is Rs. %.2f \n",amount,balance2);

                    }
                    break;
                case 2:
                    printf("Enter amount to deposit: ");
                    scanf("%d",&amount);
                    balance2 += amount;
                    printf("You have deposited Rs. %d. Your balance after deposit is Rs. %.2f \n",amount,balance2);
                    break;
                case 3:
                    printf("Your balance is Rs. %.2f \n",balance2);
                    break;
                case 4:
                    printf("Thank you for choosing our ATM service. \n");
                    break;
    
                default: 
                    printf("Invalid input!!! \n");
                    break;
            }
            printf("Do you wish to perform another transaction? Press 1 for YES and 0 for NO  ");
            scanf("%d",&continueTransaction);
        }
        break;
    
    default:
        printf("Inavalid input!!!");
        break;
    
    }
    printf("Thank you for using our services.Have a nice day.");   
    return 0;
}
