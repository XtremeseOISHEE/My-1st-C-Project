//ami ashol tumi nokol
#include<bits/stdc++.h>
#include "account.h"
int main()
{
    Account* st;
    cout<<"----------------Welcome to JU_CSE_FEST---------------\n";
    while(1)
    {
start:
        cout<<"1.Sign-up\n2.Log-in\n3.Exit\n\nChoose from above options.\n";
        char ch,ro;
        cin>>ch;
        if(ch=='1')
        {
one:
            cout<<"\n1.Register Account as Admin\n2.Register Account as Participant\n3.Back\n4.Exit\n";
            cin>>ro;
            if(ro=='1')
            {
                /*st= new admin();
                st->Register();*/
                admin k;
                k.Register();
            }
            else if(ro=='2')
            {
                st= new participant();
                st->Register();
            }
            else if(ro=='3')
            {
                goto start;
            }
            else if(ro=='4')
            {
                ch='3';
            }
            else
            {
                goto one;
            }
        }
        else if(ch=='2')
        {
            login();
        }
        else if(ch=='3')
        {
            break;
        }
        else
        {
            goto start;
        }
    }

    return 0;
    /*admin horse;
    //horse= new admin();
    horse.Register() ;
    horse.testshow();*/

}
