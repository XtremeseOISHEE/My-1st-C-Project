#if !defined(EVENT)
#define EVENT
using namespace std;
class Event
{
protected:
    char name[300];
    char duration[50];
    char date[50];
    char start[50];
    int id;
public:
    Event():name("00"),duration(" "),date(" "),start(" ") {};
    Event(char x[],char y[],char z[],char t[])
    {
        strcpy(name,x);
        strcpy(duration,y);
        strcpy(date,z);
        strcpy(start,t);
    };
    ~Event() {};
    void set_event()
    {
        cout<<"Enter name of the event: ";
        cin>>name;
        cout<<"Enter starting time (5am with no space): ";
        cin>>start;
        cout<<"Enter Duration (format=> 03:00:00): ";
        cin>>duration;
        cout<<"Enter Date (format=> 03/01/2010) : ";
        cin>>date;
    }
    void show_event()
    {
        cout<<"Event ID: "<<id<<endl;
        cout<<"Event name: "<<name<<endl
            <<"Starting time: "<<start<<endl
            <<"Duration: "<<duration<<endl
            <<"Date: "<<date<<endl;
    }
    char* getname()
    {
        return name;
    }
    char* getduration()
    {
        return duration;
    }
    char* getdate()
    {
        return date;
    }
    char* getstart()
    {
        return start;
    }
    int getid()
    {
        return id;
    }
};
class contest:public Event
{
    int total_problem;
public:
    contest():Event(),total_problem(0)
    {
        int ub=5000,lb=1100;
        srand(time(0));
        id=rand()%(ub-lb+1)+lb;
    };
    contest(char x[],char y[],char z[],char t[],int m):Event(x,y,z,t),total_problem(m)
    {
        int ub=5000,lb=1100;
        srand(time(0));
        id=rand()%(ub-lb+1)+lb;
    };
    ~contest() {};
    void set_contest()
    {
        Event::set_event();
        cout<<"Enter number of problems in the contest: ";
        cin>>total_problem;
        write_contest();
    }
    int getproblem()
    {
        return total_problem;
    }
    void write_contest()
    {
        ofstream outfile;
        outfile.open("contest.dat",ios::app | ios::binary);
        outfile.write(((char*)this),(sizeof(*this)));
        outfile.close();
    }
    static int contest_count()
    {
        ifstream onfile;
        onfile.open("contest.dat",ios::binary);
        onfile.seekg(0,ios::end);//0 bytes before end e set krsi
        return (int)onfile.tellg()/sizeof(contest);
    }
    static void contestread();
    void contest_show()
    {
        Event::show_event();
        cout<<"Total no problems: "<<total_problem<<endl;
    }
};
vector<contest>contestdata(500);
void contest::contestread()
{

    ifstream onfile;
    onfile.open("contest.dat",ios::binary);
    onfile.seekg(0);
    int n=contest::contest_count();
    int i=0;
    while(i<n)
    {
        //cout<<i+1<<": ";
        onfile.read((char*)&contestdata[i],(sizeof(contest)));
        /*if(contestdata[i].getproblem()!=0)
        {
            contestdata[i].contest_show();
        }*/
        i++;
    }
}
class cultural_event: public Event
{
    char food[300];
    char place[200];
public:
    cultural_event():Event(),food(" "),place(" ")
    {
        int ub=15000,lb=11100;
        srand(time(0));
        id=rand()%(ub-lb+1)+lb;
    };
    cultural_event(char x[],char y[],char z[],char t[],char m[],char n[]):Event(x,y,z,t)
    {
        strcpy(food,m);
        strcpy(place,n);
        int ub=15000,lb=11100;
        srand(time(0));
        id=rand()%(ub-lb+1)+lb;
    };
    ~cultural_event() {};
    void set_cultural_event()
    {
        Event::set_event();
        cout<<"Enter Food package for catering: ";
        cin>>food;
        cout<<"Enter Venue of Cultural Event: ";
        cin>>place;
        write_culturalevent();
    }
    char* getfood()
    {
        return food;
    }
    char* getplace()
    {
        return food;
    }
    void write_culturalevent()
    {
        ofstream outfile;
        outfile.open("culturalevent.dat",ios::app | ios::binary);
        outfile.write(((char*)this),(sizeof(*this)));
        outfile.close();
    }
    static int cultural_eventcount()
    {
        ifstream onfile;
        onfile.open("culturalevent.dat",ios::binary);
        onfile.seekg(0,ios::end);//0 bytes before end e set krsi
        return (int)onfile.tellg()/sizeof(cultural_event);
    }
    static void cultural_eventread();
    void culturalevent_show()
    {
        Event::show_event();
        cout<<"Place: "<<place<<endl
            <<"Food: "<<food<<endl;
    }
};
vector<cultural_event>cultural_eventdata(500);
void cultural_event:: cultural_eventread()
{
    ifstream onfile;
    onfile.open("culturalevent.dat",ios::binary);
    onfile.seekg(0);
    int n=cultural_event::cultural_eventcount();
    int i=0;
    while(i<n)
    {
        //char r[]="00";
        //cout<<i+1<<": ";
        onfile.read((char*)&cultural_eventdata[i],(sizeof(cultural_event)));
        /*if(strcmp(cultural_eventdata[i].getname(),r)!=0)
        {
            cultural_eventdata[i].culturalevent_show();
        }*/
        i++;
        /*char r[]="00";
        cout<<i+1<<": ";
        cultural_eventdata[i]=new cultural_event();
        onfile.read((char*)cultural_eventdata[i],(sizeof(cultural_event)));
        if(strcmp(cultural_eventdata[i]->getname(),r)!=0)
        {
            cultural_eventdata[i]->culturalevent_show();
        }
        i++;*/
    }
}
class Rank
{
    char arr[500];
    int mark;
public:
    Rank() :arr(" "),mark(0)
    {
        srand(time(0));
        mark=rand()%250;
    };
    Rank(char b[])
    {
        strcpy(arr,b);
        srand(time(0));
        mark=rand()%250;
    }
    ~Rank(){};
    char* getname()
    {
        return arr;
    }
    int getmark()
    {
        return mark;
    }
    void setname(char* b)
    {
        strcpy(arr,b);
        srand(time(0));
        mark=rand()%250;
    }
    void setname()
    {
        cout<<"Enter Your Username: ";
        cin>>arr;
    }
    void setmark(int x)
    {
        srand(time(0));
        mark=rand()%x;
    }
};
Rank arr[30];
void create_rank()
{
    arr[0].setname("Oishee");
    arr[0].setmark(200);
    arr[1].setname("Beltik");
    arr[1].setmark(150);
    arr[2].setname("Roza");
    arr[2].setmark(260);
    arr[3].setname("Tarikul");
    arr[3].setmark(54);
    arr[4].setname("Rozar");
    arr[4].setmark(230);
    arr[5].setname("Cloy");
    arr[5].setmark(130);
    arr[6].setname("Anthony");
    arr[6].setmark(180);
    arr[7].setname("Nix");
    arr[7].setmark(172);
    arr[8].setname("Arora");
    arr[8].setmark(201);
    arr[9].setname("Rimi");
    arr[9].setmark(147);
    arr[10].setname("Shanto");
    arr[10].setmark(100);
    arr[11].setname("Sumaiya");
    arr[11].setmark(250);
    arr[12].setname("Tawhid");
    arr[12].setmark(250);
    arr[13].setname("Mursalin");
    arr[13].setmark(260);
    arr[14].setname("Pallas");
    arr[14].setmark(190);
    arr[15].setname("Shahed");
    arr[15].setmark(203);
    arr[16].setname("Reshmi");
    arr[16].setmark(140);
    arr[17].setname("Tuska");
    arr[17].setmark(136);
    arr[18].setname("Srabasti");
    arr[18].setmark(100);
    arr[19].setname("Maryam");
    arr[19].setmark(200);
    arr[20].setname("Khaled");
    arr[20].setmark(111);
    arr[21].setname("Chandan");
    arr[21].setmark(200);
    arr[22].setname("Diba");
    arr[22].setmark(100);
    arr[23].setname("Rinkey");
    arr[23].setmark(150);
    arr[24].setname("Ummatun");
    arr[24].setmark(123);
    arr[25].setname("Sourav");
    arr[25].setmark(174);
    arr[26].setname("Humaira");
    arr[26].setmark(192);
    arr[27].setname("Aunnono");
    arr[27].setmark(156);
    arr[28].setname("Redwan");
    arr[28].setmark(184);
}
void ranksort()
{
    create_rank();
    cout<<"Enter the Contest-id: ";
    int dd;
    cin>>dd;
    arr[29].setname();
    for(int i=0;i<29;i++)
    {
        for(int j=i+1;j<30;j++)
        {
            if(arr[i].getmark()<arr[j].getmark())
            {
                swap(arr[i],arr[j]);
            }
        }

    }
    joy:
    char r;
    cout<<"\n\nContest-Finished!\n1.See Rank\n2.Exit\n";
    cin>>r;
    cout<<endl;
    if(r=='1')
    {
        for(int i=0;i<30;i++)
        {
            cout<<"Rank: "<<setw(10)<<left<<i+1<<setw(20)<<left<<arr[i].getname()<<setw(10)<<left<<"Score: "<<setw(20)<<left<<arr[i].getmark()<<endl;
        }
    }
    else if(r=='2')
    {
        return;
    }
    else{
        goto joy;
    }

}


#endif

