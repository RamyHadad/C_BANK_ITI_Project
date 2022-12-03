
#include "BANK.h"
/*-------------------Varaibles------------------*/

 BANK _account_default_obj =
{
   ._full_name = " Default Account",
   ._address = " ",
   ._national_ID[0] = 0,
   ._age = 0 ,
   ._bank_ID = 1111,
   ._guardian = " ",
   ._guardian_national_ID[0] = 0,
   ._account_status = 1,
   ._balance = 0 
};

 BANK * arr_account[account_max]={&account_1,&account_2,&account_3};

//  BANK account_1 = {

//  ._full_name = " ramy haddad",
//    ._address = " badr city ",
//    ._national_ID[0] = 29707271500055,
//    ._age = 25 ,
//    ._bank_ID = 225511,
//    ._guardian = " ",
//    ._guardian_national_ID[0] = 0,
//    ._account_status = 1,
//    ._balance = 2500 

//  };

 BANK * ptr_Bank = (BANK *)  0;
 uint8_t acount_flag = 0;

 uint8_t admin_pass[admin_pass_digits] = "1234";
 uint8_t admin_username[admin_username_digits] = "ramy";
/*-------------------Helper function prototypes------------------*/
static void Generate_Randoms(uint32_t * value);
 

/*-------------------function Defination------------------*/

void Admin_Creat_New_Account(void)
{

    ptr_Bank = arr_account[acount_flag];

    printf("Please enter the full name\n");
    fflush(stdin);
    gets(ptr_Bank->_full_name);
    fflush(stdin);
    printf("Please enter the address\n");
    gets((ptr_Bank->_address));
    printf("Please enter the National ID\n");
    gets((ptr_Bank->_national_ID));
    printf("Please enter the age\n");
    scanf("%d",&(ptr_Bank->_age));
    if (ptr_Bank->_age < 21 )
    {  
        printf("Please enter the Guardian National ID\n");
        fflush(stdin);
        gets((ptr_Bank->_guardian_national_ID));
    }
    printf("Please enter the initial Balance\n");
    fflush(stdin);
    scanf("%d",(&ptr_Bank->_balance));
    ptr_Bank->_account_status = Active ;
    Generate_Randoms(&(ptr_Bank->_bank_ID));
    uint8_t x;
    uint8_t temp_ptr = &x;
    ptr_Bank->_bank_ID += (ptr_Bank->_passcode>>2);
    ptr_Bank->_passcode = (uint32_t) (temp_ptr+5) ;
    acount_flag++;

    printf("ID = %u\n",ptr_Bank->_bank_ID);
    //printf("deubg bug bug bug");
    printf("pass = %d\n",ptr_Bank->_passcode);
    
    //return ptr_Bank;
}

void open_exisisting_Account(void){
    uint32_t temp_ID = 0; 
    printf("please enter Account's Bank_ID\n");
    scanf("%u",&temp_ID);

    for (int i = 0; i<account_max; i++)
    {
        if( temp_ID == arr_account[i]->_bank_ID )
        {
            ptr_Bank = arr_account[i];
            break;
        }
        else
        {
            ptr_Bank = &(_account_default_obj);
        }
    }

    if( ptr_Bank != &(_account_default_obj))
    {
        uint8_t temp_open_acc = 0;
        printf("please choose an option\nMake Transcation press 1\nChange Account Status press 2\nGet Cash press 3\nDeposit in Account press 4\n");
        scanf("%d",&temp_open_acc);
        switch (temp_open_acc)
        {
        case 1 : Make_transaction();break;
        case 2 : Change_Account_Status(); _entrance_mode_admin =1 ; break;
        case 3 : Get_Cash(); printf("new balance = %d\n",ptr_Bank->_balance);  break;
        case 4 : Deposit_in_Account(); printf("new balance = %d\n",ptr_Bank->_balance); break;
        default: printf("invalid option\n"); break;
        }
    }
    else
    {
        printf("account doesn't exist");
    }

}

void Client_open_exisisting_Account(uint32_t ID, uint32_t pass)
{
    for (int i = 0; i<account_max; i++) // ID searching
    {
        if( ID == arr_account[i]->_bank_ID )
        {
            ptr_Bank = arr_account[i];
            printf("Account Found!!\n");
            break;
        }
        else
        {
            ptr_Bank = &(_account_default_obj);
        }
    }

    if( (pass == ptr_Bank->_passcode) ) 
    {   
        printf("successful Login!!\n");
        uint8_t temp_open_acc = 0;
        printf("please choose an option\nMake Transcation press 1\nChange Account password press 2\nGet Cash press 3\nDeposit in account press 4\nBack to Main press 5");
        scanf("%d",&temp_open_acc);
        switch (temp_open_acc)
        {
        case 1 : Make_transaction(); break;
        case 2 : Change_Account_password(); break;
        case 3 : Get_Cash(); break;
        case 4 : Deposit_in_Account(); break;
        case 5 : break;
        default: printf("invalid option\n"); break;
        }
    }
    else
    {
        printf("account doesn't exist or Wrong Password\n");
    }

}

void Make_transaction(void){
    
     uint32_t temp_ID = 0; 
     uint32_t temp_balance = 0; 
    printf("please enter reciptient Account's Bank_ID");  
    scanf("%u",&temp_ID);
    printf("please enter amount to be send");
    scanf("%u",&temp_balance);
    if( (temp_balance<=ptr_Bank->_balance ) && ( ptr_Bank->_account_status == Active) )
    {   
        ptr_Bank->_balance -= temp_balance ;
        BANK * reciptent_ptr_acc = (BANK*) 0 ;

        // modify reciptent balance through  

        for (int i = 0; i<account_max; i++)
        {
            if( temp_ID == arr_account[i]->_bank_ID )
            {
                reciptent_ptr_acc = arr_account[i];
                break;
            }
        }
        reciptent_ptr_acc->_balance += temp_balance ;
    }
    else
    {
        printf("no suffcient funds!! or restricted account");
    }


}

void Change_Account_Status(void){
    uint8_t temp = 0 ;
    printf("choose account status :\n1. press 1 for Active \n2. press 2 for Restriction \n3. press 3 for Closed \n");
    scanf("%d",&temp);
    switch (temp)
    {
    case 1: ptr_Bank->_account_status = Active ; break;
    case 2: ptr_Bank->_account_status = Restricted ; break;
    case 3: ptr_Bank->_account_status = Closed ; break;

    default: ptr_Bank->_account_status = Active ; 
        break;
    }

}

void Get_Cash(void){
    uint32_t temp_balance = 0; 
    printf("please enter amount to be withdrawn\n");
    scanf("%d",&temp_balance);
    if( (temp_balance<=ptr_Bank->_balance ) && ( ptr_Bank->_account_status == Active) )
    {
           ptr_Bank->_balance -= temp_balance ;
    }

}

void Deposit_in_Account(void){

     uint32_t temp_balance = 0; 
    printf("please enter amount to be deposited");
    scanf("%u",&temp_balance);
    if(( ptr_Bank->_account_status == Active) )
    {
           ptr_Bank->_balance += temp_balance ;
    }
}

void Account_print(BANK * Acc_obj){

printf("_full_name = %s\n",Acc_obj->_full_name);
printf("_address = %s\n",Acc_obj->_address);
printf("_national_ID = %s\n",Acc_obj->_national_ID);
printf("_age= %d\n",Acc_obj->_age);
printf("_bank_ID= %u\n",Acc_obj->_bank_ID);
printf("_guardian = %s\n",Acc_obj->_guardian);
printf("_guardian_national_ID = %s\n",Acc_obj->_guardian_national_ID);
switch (Acc_obj->_account_status)
{
case 1 : printf("Active\n"); break;
case 0 : printf("Restricted\n"); break;
case 2 : printf("Closed\n"); break;
default: break;
}
printf("_balance= %d\n",Acc_obj->_balance);
printf("_passcode= %d\n",Acc_obj->_passcode);

}

void Change_Account_password(void) 
{
    uint32_t new_pass = 0 ;
    printf("Please enter the new password");
    scanf("%d",&new_pass);
    ptr_Bank->_passcode = new_pass;
}


/*------------------- Static function Defination------------------*/

static void Generate_Randoms(uint32_t * value)
{
    //srand(time(0));
   * value = (rand() % (4294967055 - 2556200012 + 1)) + 2556286731 ;
   //* value *= -1 ; 
}

uint8_t string_check_uint8(uint8_t * str_1 , uint8_t * str_2 )
{
    uint8_t * temp_ptr_str =  str_1 ;
    uint8_t counter = 0;
    if( (sizeof(str_1)) != (sizeof(str_2)))
    {
        return 0;
    }
    while (temp_ptr_str[counter] != '\0')
    {
       if(str_1[counter]!=str_2[counter])
       {
        return 0;
       }
       counter++;
       temp_ptr_str++;
    }
    
    return 1;
}