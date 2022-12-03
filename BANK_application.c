
#include "BANK.h"
#include <string.h>

int main(void)
{   
    //  BANK * Local_ptr_acc = Admin_Creat_New_Account();
    //  Account_print(ptr_Bank);
     
     uint8_t _entrance_main = 1 ;

     while (_entrance_main)
     {  _entrance_main = 0;
        uint8_t mode = 0;
        printf("Please choose the Mode :\nAdmin press 1\nClient Press 2\n");
        scanf("%d",&mode);
        /*chossing mode between client and admin*/
        if (mode == Mode_Admin ) // Admin mode
        {    _entrance_mode_admin = 1 ;
                
                uint8_t temp_pass[admin_pass_digits];
                uint8_t temp_username[admin_username_digits];

                printf("Please enter Username\n");
                scanf("%s", temp_username);
                /*-----debug----*/
                //gets(temp_username);
                //fgets(temp_username,admin_username_digits,stdin);
                //printf("%s",temp_username);

                printf("Please enter Password\n");
                scanf("%s", temp_pass);
                /*-----debug----*/
                //gets(temp_pass);
                //fgets(temp_pass,admin_pass_digits,stdin);
                //printf("%s",temp_pass);
                // uint8_t temp1 = strcmp(temp_username,admin_username);
                // printf("user ret = %d",temp1);
                // uint8_t temp2 = strcmp(temp_pass,admin_pass);
                // printf("pass ret = %d",temp2);

                uint8_t cmp_user = strcmp(temp_username,admin_username) ;
                uint8_t cmp_pass = strcmp(temp_pass,admin_pass) ;

            while (_entrance_mode_admin)
            {   
                _entrance_mode_admin = 0;
        
            if ( (cmp_user == 0) && ( cmp_pass == 0) ) // pass & user check
            {
                uint8_t temp_admin_menu = 0;
                //_entrance_mode_admin = 0;
                //_entrance_main = 1;
                printf("Create New Account press 1\nOpen Existing Account press 2\nBack to Main press 3\nExit press 4\n");
                scanf("%d",&temp_admin_menu);
                switch (temp_admin_menu)
                {
                case 1 : Admin_Creat_New_Account(); _entrance_mode_admin = 1 ; _entrance_main = 1; Account_print(ptr_Bank); break;
                case 2 : open_exisisting_Account(); break;
                case 3 : _entrance_main = 1 ; _entrance_mode_admin = 0; break;
                case 4 : _entrance_main = 0 ; _entrance_mode_admin = 0; break;
                default: break;
                }
                 
            }

            else 
            {   
                printf("invalid pass or username\n");
                //_entrance_mode_admin = 1;
               // _entrance_main = 1;
            }

           }
           // _entrance_main = 1 ;
            
        }

        else if (mode == Mode_client )  // Client mode
        {  
            uint8_t temp_pass = 0;
            uint8_t temp_bank_ID = 0;
            printf("Please enter your Bank ID\n");
            scanf("%u",&temp_bank_ID);
            printf("Please enter Password");
            scanf("%d",&temp_pass);
            Client_open_exisisting_Account(temp_bank_ID,temp_pass);
            _entrance_main = 1 ;

        }

        else // Invalid mode
        {
            printf("Invalid Option\n");
            _entrance_main = 1 ;
        }

    
     

     }
     
    return 0;
}