#include"User.h"
#include<string.h>
int User::num_user;
User::User()
{
    memset(userName,'\0',sizeof(userName));
    memset(userPassword,'\0',sizeof(userPassword));
}


