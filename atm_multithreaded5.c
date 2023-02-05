/*This is a C program to stimulate the working of an ATM machine using multithreaded approach.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define true 1

// array to store account holders names
char username[7][10] = {"James","Lily","Harry","Draco","Hermione","Ronald","John"};
// array to store account balance of each account holder
int balance[7] = {100000,200000,5000000,60000,700000,900000,400000};
// array to store the pin number for each account holder
int pin[7] = {1310,3112,1802,412,106,1206,903}; 
int enteredpin;
int key1,key2;
int choice;
sem_t display; //binary semaphore
void transactions(int);
void deposit(int x)
{
    int position;
    if(x==1)
    {
        position = key1;
    }
    else
    {
        position = key2;
    }
    int deposit_amount;
    //locking the semaphore
    sem_wait(&display);
    printf("User %d : Please enter the amount to be deposited: ",x);
    scanf("%d",&deposit_amount);
    balance[position] += deposit_amount;
    printf("\n Congratulations!! You have deposited Rs. %d into your account.",deposit_amount); 
    //unlocking semaphore
    sem_post(&display);
}

void withdraw(int y)
{
    int position;
    if(y==1)
    {
        position = key1;
    }
    else
    {
        position = key2;
    }
    int withdraw_amount;
    //locking semaphore
    sem_wait(&display);
    printf("\n User %d : Please enter the amount you wish to withdraw : ",y);
    scanf("%d",&withdraw_amount);
    if ((balance[position]-withdraw_amount)<1000) //minimum balance is Rs. 1000
    {
        printf("You have insufficient balance. \n");
    }
    else
    {
        balance[position] -= withdraw_amount;
        printf("You have sucessfully withdrawn Rs. %d. \n",withdraw_amount);
    }
    //unlocking semaphore
    sem_post(&display);
}

void check_balance(int z)
{
    int position;
    if (z==1)
    {
        position = key1;
    }
    else
    {
        position = key2;
    }
    //locking semaphore
    sem_wait(&display);
    printf("User %d : Your balance is Rs. %d \n",z,balance[position]);
    sem_post(&display);
}

void *start(void *a)
{
    int b = *((int *)a);
    while (true)
    {
        int match=0; //checks whether the pin entered by user matches with the pin stored in the array
        sem_wait(&display);
        printf("\n User %d : Please enter your pin:  (Press 0 to skip)",b);
        scanf("%d",&enteredpin);
        sem_post(&display);
        if (enteredpin==0)
        {
            sleep(4);
            continue;
        }
        for (int i = 0; i < 7; i++)
        {
            if (enteredpin == pin[i])
            {
                match = 1;
                if (b==1)
                {
                    key1 = i;
                }
                else
                {
                    key2 = i;
                }
            }
            
        }
        // checking whether the entered pin is valid or not
        if (match==1)
        {
            sem_wait(&display);
            if (b==1)
            {
                printf("\n User ID %d : Welcome %s \n",a,username[key1]);
            }
            else
            {
                printf("\n User ID %d : Welcome %s \n",a,username[key2]);
            }
            transactions(b);
        }
        printf("Please enter a valid pin.");
    }  
}

void transactions(int c)
{
    while (true)
    {
        printf("\n User %d Please select a service \n",c);
        printf("\t1. Check Balance \n 2. Withdraw \n 3. Deposit \n 4. Press 4 to logout of your account \n 5. Press 0 to terminate \n");
        scanf("%d",&choice);
        sem_post(&display);
        switch (choice)
        {
        case 1:
            check_balance(c);
            break;

        case 2:
            withdraw(c);
            break;

        case 3:
            deposit(c);
            break;

        case 4:
            printf("Thank you for using our services. \n");
            (*start)(&c);
            break;
        case 0:
            exit(0);
            break;

        default:
            printf("Enter valid choice. \n");
            break;
        }
        sem_wait(&display);
    }
    
}

int main(int argc, char const *argv[])
{
    pthread_t thread1,thread2;
    sem_init(&display,0,1);
    int user1 = 1, user2 = 2;
    printf("\n **Welcome to the ATM service** \n");
    pthread_create(&thread1,NULL,&start,&user1);
    pthread_create(&thread2,NULL,&start,&user2);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    sem_destroy(&display);
    return 0;
}
