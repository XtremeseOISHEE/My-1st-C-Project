#if !defined(ACCOUNT)
#define ACCOUNT
#include "event.h"
using namespace std;
class Account
{
protected:
    char name[300];
    char username[300];
    char password[120];
public:
    Account():name(" "),username(" "),password(" ") {};
    Account(char x[],char y[],char z[])
    {
        strcpy(name,x);
        strcpy(username,y);
        strcpy(password,z);
    };
    ~Account() {};
    virtual void testshow()=0;
    char* getusername()
    {
        return username;
    }
    char* getpassword()
    {
        return password;
    }
    virtual void Register()=0;
    friend void login();
};
class admin: public Account
{
private:
    char admin_code[4];
public:
    admin():Account()
    {
        strcpy(admin_code,"####");
    };
    admin(char x[],char y[],char z[]):Account(x,y,z)
    {
        strcpy(admin_code,"####");
    };
    ~admin() {};
    void Register()
    {
        cout<<"\nRegister account as an admin\nEnter required admin code: ";
        char k[10];
        cin>>k;
        if(strcmp(k,admin_code)==0)
        {
            cout<<"\n****************REGISTRATION AS AN ADMIN***************************\n";
            cout<<"Name: ";
            cin>>name;
            cout<<"User-name: ";
            cin>>username;
            cout<<"Password: ";
            cin>>password;
            writefile();
        }
        else
        {
            cout<<"Invalid Admin Code!"<<endl;
        }
        return ;
    }
    void writefile()
    {
        ofstream outfile;
        outfile.open("admin.dat",ios::app | ios::binary);
        outfile.write((char*)(this),(sizeof(*this)));
        outfile.close();
        return;
    }
    void testshow()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"password: "<<password<<endl;
    }
    static int admincount()
    {
        ifstream onfile;
        onfile.open("admin.dat",ios::binary);
        onfile.seekg(0,ios::end);//0 bytes before end e set krsi
        return (int)onfile.tellg()/sizeof(admin);
    }
    static void adminpage()
    {
beg:
        char t;
        cout<<"---------------Welcome to Event Settings---------------\n";
        cout<<"\n1.Set Contest\n2.Set Cultural Event\n3.Log-Out\n";
        cin>>t;
        if(t=='1')
        {
            contest p;
            p.set_contest();
            cout<<endl;
            goto beg;
        }
        else if(t=='2')
        {
            cultural_event q;
            q.set_cultural_event();
            cout<<endl;
            goto beg;
        }
        else if(t=='3')
        {
            return;
        }
        else
        {
            goto beg;
        }
    }
    static void adfileread();
};

vector<admin>admindata(100);
void admin:: adfileread()
{
    ifstream onfile;
    onfile.open("admin.dat",ios::binary);
    onfile.seekg(0);
    int n=admin::admincount();
    int i=0;
    while(i<n)
    {
        //cout<<i+1<<": ";
        onfile.read((char*)&admindata[i],(sizeof(admin)));
        //admindata[i].testshow();
        i++;
    }
}
class participant: public Account
{
private:
    char session[20];
    char department[300];
    char university[300];
    int reg_no;
public:
    participant():Account(),session(" "),department("Computer Science And Engineering"),university("Jahanagirnagar University"),reg_no(0) {};
    participant(char x[],char y[],char z[],char s[],char p[],char d[],int f):Account(x,y,z),reg_no(f)
    {
        strcpy(session,s);
        strcpy(department,p);
        strcpy(university,d);
    };
    ~participant() {};
    void Register()
    {
        cout<<"\n****************REGISTRATION AS AN PARTICIPANT***************************\n";
        cout<<"Name: ";
        cin>>name;
        cout<<"Registration no: ";
        cin>>reg_no;
        cout<<"Session: ";
        cin>>session;
        cout<<"Department: ";
        cin>>department;
        cout<<"University: ";
        cin>>university;
        cout<<"User-name: ";
        cin>>username;
        cout<<"Password: ";
        cin>>password;
        filewrite();
    }
    void filewrite()
    {
        ofstream outfile;
        outfile.open("participant.dat",ios::app | ios::binary);
        outfile.write((char*)this,(sizeof(*this)));
        outfile.close();
    }
    static int participantcount()
    {
        ifstream onfile;
        onfile.open("participant.dat",ios::binary);
        onfile.seekg(0,ios::end);//0 bytes before end e set krsi
        return (int)onfile.tellg()/sizeof(participant);
    }
    static void partfileread();
    void testshow()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"password: "<<password<<endl;
        cout<<"session: "<<session<<endl;
        cout<<"registration no: "<<reg_no<<endl;
        cout<<"University: "<<university<<endl;
    }
    static void participantpage()
    {
        char r;
        cout<<"Welcome to your events!"<<endl;

        char dong[80];
        cout<<"Enter today's date (format=> 03/01/2010) : ";
        cin>>dong;


        int d;//date
        d=dong[0]-48;
        d*=10;
        d+=(dong[1]-48);
        int a;//month
        a=dong[3]-48;
        a*=10;
        a+=(dong[4]-48);
        int q;//year
        q=dong[6]-48;
        q*=1000;
        q+=((dong[7]-48)*100)+((dong[8]-48)*10)+(dong[9]-48);
        contest::contestread();
        cultural_event::cultural_eventread();

//norman:
        while(1)
        {
            /*cout<<"Fao\n";
            contestdata[0].contest_show();
            cultural_eventdata[0].culturalevent_show();
            cout<<"Fao\n";*/
            cout<<"\n1.Preview Contests\n2.Preview Cultural Events\n3.Log-Out.\n";
            cin>>r;
            cout<<endl;
            if(r=='1')
            {
rong:
                cout<<"\n1.Today's Contest\n2.Upcoming Contest\n3.Previous Contest\n4.Exit Contests\n";
                char w;
                cin>>w;
                cout<<endl;
                if(w=='4')
                {
                   // goto norman;
                   cout<<endl;
                   continue;
                }
                else if(w=='1')
                {
                    int chore=0;
                    //today
                    int i=0;
                    while(i<500)
                    {

                        /*
                        cout<<endl;
                        cout<<"Hudai\n";
                        contestdata[i].contest_show();
                        cout<<"Hudai\n";
                        */
                        /*char lara[80];
                        if(strcmp(" ",lara)==0)
                        {
                            break;
                        }
                        strcpy(lara,contestdata[i].getdate());
                        int s;//date
                        s=lara[0]-48;
                        s*=10;
                        s+=(lara[1]-48);
                        int v;//month
                        v=lara[3]-48;
                        v*=10;
                        v+=(lara[4]-48);
                        int g;//year
                        g=lara[6]-48;
                        g*=1000;
                        g+=((lara[7]-48)*100)+((lara[8]-48)*10)+(lara[9]-48);*/
                        if(strcmp(contestdata[i].getdate(),dong)==0/*g==q && v==a && s==d*/)
                        {
                            chore++;
                            contestdata[i].contest_show();
                            cout<<endl;
                        }
                        i++;
                    }
                    if(chore==0)
                    {
                        cout<<endl;
                        cout<<"No Contest for today!\n";
                        cout<<endl;
                    }
                    else{
                        tory:
                        cout<<"1.Enter Contest Arena\n2.Exit\n";
                        char ww;
                        cin>>ww;
                        if(ww=='1')
                        {
                            ranksort();
                        }
                        else if(ww='2')
                        {

                        }
                        else
                        {
                            goto tory;
                        }
                    }
                    goto rong;
                }
                else if(w=='2')
                {
                    int chore=0;
                    //tomorrow
                    int i=0;
                    while(i<500)
                    {
                        /*
                        cout<<"Hudai\n";
                        contestdata[i].contest_show();
                        cout<<"Hudai\n";*/


                        char lara[80];
                        strcpy(lara,contestdata[i].getdate());
                        if(strcmp(" ",lara)==0)
                        {
                            break;
                        }

                        int s;//date
                        s=lara[0]-48;
                        s*=10;
                        s+=(lara[1]-48);
                        int v;//month
                        v=lara[3]-48;
                        v*=10;
                        v+=(lara[4]-48);
                        int g;//year
                        g=lara[6]-48;
                        g*=1000;
                        g+=((lara[7]-48)*100)+((lara[8]-48)*10)+(lara[9]-48);
                        if((g>q) || ((g==q)&& (v>a)) ||((g==q) && (v==a)&& (s>d)) )
                        {
                            chore++;
                            contestdata[i].contest_show();
                            cout<<endl;
                        }
                        i++;
                    }
                    if(chore==0)
                    {
                        cout<<endl;
                        cout<<"No Contest update till now!\n";
                        cout<<endl;
                    }
                    goto rong;
                }
                else if(w=='3')
                {
                    int chore=0;
                    //past
                    int i=0;
                    while(i<500)
                    {
                        char lara[80];
                        strcpy(lara,contestdata[i].getdate());
                        if(strcmp(" ",lara)==0)
                        {
                            break;
                        }
                        int s;//date
                        s=lara[0]-48;
                        s*=10;
                        s+=(lara[1]-48);
                        int v;//month
                        v=lara[3]-48;
                        v*=10;
                        v+=(lara[4]-48);
                        int g;//year
                        g=lara[6]-48;
                        g*=1000;
                        g+=((lara[7]-48)*100)+((lara[8]-48)*10)+(lara[9]-48);

                        if((g<q) || ((g==q)&& (v<a)) ||((g==q) && (v==a)&& (s<d)) )
                        {
                            chore++;
                            contestdata[i].contest_show();
                            cout<<endl;
                        }
                        i++;
                    }
                    if(chore==0)
                    {
                        cout<<endl;
                        cout<<"No Past Contest Record Available!\n";
                        cout<<endl;
                    }
                    goto rong;
                }
                else
                {
                    goto rong;
                }

            }
            else if(r=='2')
            {

                /*char dong[80];
                cout<<"Enter today's date (format=> 03/01/2010) : ";
                cin>>dong;

                int d;//date //
                d=dong[0]-48;
                d*=10;
                d+=(dong[1]-48);
                int a;//month
                a=dong[3]-48;
                a*=10;
                a+=(dong[4]-48);
                int q;//year
                q=dong[6]-48;
                q*=1000;
                q+=((dong[7]-48)*100)+((dong[8]-48)*10)+(dong[9]-48);*/
jong:
                cout<<"\n1.Today's Cultural Event\n2.Upcoming Cultural Event\n3.Previous Cultural Event\n4.Exit Cultural Event\n";
                char w;
                cin>>w;
                cout<<endl;
                if(w=='4')
                {
                    //goto norman;
                    continue;
                }
                else if(w=='1')
                {
                    int chore=0;

                    //today
                    int i=0;
                    while(i<500)
                    {
                        /*
                         cout<<"Hudai\n";
                         cultural_eventdata[i].culturalevent_show();
                         cout<<"Hudai\n";*/
                        /*char lara[80];
                        if(strcmp(" ",lara)==0)
                        {
                            break;
                        }
                        strcpy(lara,contestdata[i].getdate());
                        int s;//date
                        s=lara[0]-48;
                        s*=10;
                        s+=(lara[1]-48);
                        int v;//month
                        v=lara[3]-48;
                        v*=10;
                        v+=(lara[4]-48);
                        int g;//year
                        g=lara[6]-48;
                        g*=1000;
                        g+=((lara[7]-48)*100)+((lara[8]-48)*10)+(lara[9]-48);*/
                        if(strcmp(cultural_eventdata[i].getdate(),dong)==0/*g==q && v==a && s==d*/)
                        {
                            chore++;
                            cultural_eventdata[i].culturalevent_show();
                            cout<<endl;
                        }
                        i++;
                    }
                    if(chore==0)
                    {
                        cout<<endl;
                        cout<<"No Cultural Programme Found Today!\n";
                        cout<<endl;
                    }
                    goto jong;
                }
                else if(w=='2')
                {
                    int chore=0;
                    //tomorrow
                    int i=0;
                    while(i<500)
                    {
                        /*
                        cout<<"Hudai\n";
                         cultural_eventdata[i].culturalevent_show();
                         cout<<"Hudai\n";
                            */

                        char lara[80];

                        strcpy(lara,cultural_eventdata[i].getdate());

                        if(strcmp(" ",lara)==0)
                        {
                            break;
                        }

                        int s;//date
                        s=lara[0]-48;
                        s*=10;
                        s+=(lara[1]-48);
                        int v;//month
                        v=lara[3]-48;
                        v*=10;
                        v+=(lara[4]-48);
                        int g;//year
                        g=lara[6]-48;
                        g*=1000;
                        g+=((lara[7]-48)*100)+((lara[8]-48)*10)+(lara[9]-48);
                        if((g>q) || ((g==q)&& (v>a)) ||((g==q) && (v==a)&& (s>d)) )
                        {
                            chore++;
                            cultural_eventdata[i].culturalevent_show();
                            cout<<endl;
                        }
                        i++;
                    }
                    if(chore==0)
                    {
                        cout<<endl;
                        cout<<"No Cultural Event Ahead!\n";
                        cout<<endl;
                    }
                    goto jong;
                }
                else if(w=='3')
                {
                    int chore=0;
                    //past
                    int i=0;
                    while(i<500)
                    {
                        char lara[80];
                        strcpy(lara,cultural_eventdata[i].getdate());
                        if(strcmp(" ",lara)==0)
                        {
                            break;
                        }
                        int s;//date
                        s=lara[0]-48;
                        s*=10;
                        s+=(lara[1]-48);
                        int v;//month
                        v=lara[3]-48;
                        v*=10;
                        v+=(lara[4]-48);
                        int g;//year
                        g=lara[6]-48;
                        g*=1000;
                        g+=((lara[7]-48)*100)+((lara[8]-48)*10)+(lara[9]-48);

                        if((g<q) || ((g==q)&& (v<a)) ||((g==q) && (v==a)&& (s<d)) )
                        {
                            chore++;
                            cultural_eventdata[i].culturalevent_show();
                            cout<<endl;
                        }
                        i++;
                    }
                    if(chore==0)
                    {
                        cout<<endl;
                        cout<<"No Past Cultural-Event Record Available!\n";
                        cout<<endl;

                    }
                    goto jong;
                }
                else
                {
                    goto jong;
                }
            }
            else if(r=='3')
            {
                //return;
                break;
            }
            else
            {
                cout<<"Oops!Choose carefully!"<<endl;
               // goto norman;
            }
        }

    }

};
vector<participant>participantdata(100);
void participant:: partfileread()
{
    ifstream onfile;
    onfile.open("participant.dat",ios::binary);
    onfile.seekg(0);
    int n=participant::participantcount();
    int i=0;
    while(i<n)
    {
        //cout<<i+1<<": ";
        onfile.read((char*)&participantdata[i],(sizeof(participant)));
        //participantdata[i].testshow();
        i++;
    }
}
void login()
{
    int x=participant::participantcount();
    int y=admin::admincount();
rose:
    cout<<"\n********************Welcome!********************"<<endl<<"\n********************Login********************\n";
    cout<<"1.Login as Participant\n2.Login as Admin\n3.Exit Login\nEnter option as per above.\n";
    char a;
    cin>>a;
    if(a=='1')
    {
        participant::partfileread();
        //eta participant portal
        cout<<"\n---------------Participant Portal---------------\n";
        //x niye kaj korbo
        char j[300],k[120];
        cout<<"User-name: ";
        cin>>j;
        cout<<"Password: ";
        cin>>k;
        int i=0,f=0;
        for(; i<x; i++)
        {
            if((strcmp(participantdata[i].getusername(),j)==0) && (strcmp(participantdata[i].getpassword(),k)==0))
            {
                f=1;
                cout<<"\n\nLogin Successful!"<<endl;
                participant::participantpage();
                break;
            }
        }
        if(f==0)
        {
            cout<<"\n\nNo such User-name found or password was incorrect!"<<endl;
            goto rose;
        }
    }
    else if(a=='2')
    {
        admin::adfileread();
        cout<<"\n---------------Admin Portal---------------\n";
        //y niye kaj korbo
        char j[300],k[120];
        cout<<"User-name: ";
        cin>>j;
        cout<<"Password: ";
        cin>>k;
        int i=0,f=0;
        for(; i<y; i++)
        {
            if((strcmp(admindata[i].getusername(),j)==0) && (strcmp(admindata[i].getpassword(),k)==0))
            {
                f=1;
                cout<<"\n\nLogin Successful!"<<endl;
                admin::adminpage();
                break;
            }
        }
        if(f==0)
        {
            cout<<"\n\nNo such User-name found or password was incorrect!"<<endl;
            goto rose;
        }
    }
    else if(a=='3')
    {
        return;
    }
    else
    {
        login();
    }

}


#endif
/*void test()
    {
        cout<<"Name: ";
        cin.get(username,300);
        getchar();
        cout<<"Password: ";
        cin>>password;
        cout<<endl;
    }*/
