
#ifndef BANK_FILE_H
#define BANK_FILE_H

/*-------------------include------------------*/

#include <stdlib.h>
#include <stdio.h>


/*-------------------Defines------------------*/

#define Active 1    
#define Restricted 0
#define Closed 2
#define admin_pass_digits 5
#define admin_username_digits 5
#define account_max 3
#define Mode_Admin 1
#define Mode_client 2

/*-------------------types------------------*/

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef struct{

    uint8_t _full_name[100];
    uint8_t _address[50];
    uint8_t _national_ID[14];
    uint8_t _age;
    uint32_t _bank_ID;
    uint8_t _guardian[50];
    uint8_t _guardian_national_ID[14];
    uint8_t _account_status : 2 ;
    uint8_t _reserved : 6 ;
    uint32_t _balance;
    uint32_t _passcode;
}BANK;

/*-------------------function Prototypes------------------*/

void Admin_Creat_New_Account(void);

void open_exisisting_Account(void);

void Client_open_exisisting_Account(uint32_t ID, uint32_t pass);

void Change_Account_password(void);

void Make_transaction(void);

void Change_Account_Status(void);

void Get_Cash(void);

void Account_print(BANK * Acc_obj);

void Deposit_in_Account(void);

/*-------------------Varaibles------------------*/

 BANK _account_default_obj;

 BANK account_1;
 BANK account_2;
 BANK account_3;

 BANK * arr_account[account_max];

 BANK * ptr_Bank;
 uint8_t acount_flag ;

 uint8_t admin_pass[admin_pass_digits];
 uint8_t admin_username[admin_username_digits];

uint8_t _entrance_mode_admin ;

#endif