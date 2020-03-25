#include <iostream>
#include "Graph.h"
#include "Player.h"
#include "Trap_game.h"
#include "Level.h"

int counter = 1, player_count = 0;
vector <class player> lead;

bool compare(player i1,player i2)
{
    return(i1.pl_score>i2.pl_score);
}

void add_player(string name,int sco,int count_player)
{
    player p1;
    p1.pl_name=name;
    p1.pl_score=sco;
    lead.push_back(p1);
    count_player++;
}

void update_player(string name,int sco,int count_player)
{
    for(int i=0;i<count_player;i++)
    {
        if(lead[i].pl_name==name)
        {
            lead[i].pl_name=sco;
            count_player++;
        }
    }
}

int find_pl(string name,int count_player)
{
    int temp=0;
    for(int i=0;i<count_player;i++)
    {
        if(lead[count_player].pl_name==name)
        {
            temp=1;
        }
    }
    return temp;
}

void create_lead()
{
    sort(lead.begin(),lead.end(),compare);
    ofstream m4("n1.txt");

    for(int i=0;i<player_count;i++)
    {
        m4<<lead[i].pl_name<<" "<<lead[i].pl_score<<"\n";
    }

    m4.close();
}

void get_player_count()
{
    ifstream m1("n1.txt");

    if(!m1.fail())
    {
        string n;
        while(!m1.eof())
        {
            getline(m1,n);
            player_count++;
        }
    }

    m1.close();
}

int find_player(string n1,int score_of_pl,int count_player)
{
    string nam;
    int score_p;
    ifstream m2("n1.txt");

    if(!m2.fail())
    {
        while(!m2.eof())
        {
            m2>>nam>>score_p;
            if(nam!="")
            {
                add_player(nam,score_p,count_player);
            }
        }

        if(find_pl(n1,count_player)!=1)
        {
            add_player(n1,score_of_pl,count_player);
        }

        else if(find_pl(n1,count_player))
        {
            update_player(n1,score_of_pl,count_player);
        }

        m2.close();
    }
}

void show_lead()
{
    int count_temp=1;
    for(int i=0;i<player_count;i++)
    {
        cout<<lead[i].pl_name<<" "<<lead[i].pl_score<<endl;
        count_temp++;
    }
}


int main() {
    char** simpangan;

    srand(time(NULL));
    string name;
    int n=7;
    double c;

    cout<<"----------------------------------------------------------------------------------------------\n";
    cout<<"--------------------------------------- JUNGLE'S TRAP ---------------------------------------\n";
    cout<<"----------------------------------------------------------------------------------------------\n";
    cout<<"\n";
    cout<<"\nYour Name : ";

    cin>>name;
    cout<<endl;
    getchar();

    cout<<"HI "<<name<<" "<<"WELCOME TO THE JUNGLE !"<<endl<<endl;
    cout<<"\nLET ME TELL YOU, HOW TO GO OUT FROM HERE !"<<endl<<endl;
    cout<<"--------------------------------------- READ THIS : ---------------------------------------"<<endl<<endl;
    cout<<"1. YOU HAVE 3 ADDITIONAL LIVES AND IT WILL REDUCE WHEN YOU TRY TO COPY YOUR PREVIOUS MOVE\n"<<endl;;
    cout<<"2. THERE ARE 5 JUNGLES WITH DIFFERENT POINTS\n"<<endl;;
    cout<<"3. AVOID TAKING ROUTES FULL OF OBSTACLES AND GET TO THE PASSENGER ON TIME\n"<<endl;;
    cout<<"4. IF YOU PASSES THE LIMIT OF THE JUNGLE WHICH IS NOT THE WAY TO GO OUT, YOU WILL DIE\n"<<endl;;
    cout<<"-------------------------------------------------------------------------------------------\n"<<endl;;
    cout<<"\nPRESS ENTER TO PLAY"<<endl;

    getchar();

    int sp = 0, p_score = 0;
    trap_game JT(n,name,&simpangan,&counter);
//    printf("Hao %c\n",simpangan[0][0]);
    Levels lvl;
    Graph junggle(n,&simpangan) ;

    while(counter<=5)
    {
        int sp=0;
        char ch;
        c = lvl.level(n);
        while(sp==0)
        {
            JT.redefine(n);
            junggle.redef_graph(n);
            JT.randomObstruction(c);
            junggle.init();
//            junggle.Cetak();
            junggle.checkEdge();
            sp = junggle.minEdge(0,(n*n)-1);

            if(sp!=0)
            {
                JT.Gambar_simpangan();
            }
        }

        char lo;
        int p_score, temp = JT.move(0,0);

        if(!temp)
        {
            JT.score_play(sp,c);
            cout<<"\nYour total Steps : "<<(JT.steps+1);
            cout<<"\nYour Score : "<<JT.score;
            cout<<"\nMin Steps : "<<sp<<endl;
            cout<<"\n------------------------ PRESS ENTER TO CONTINUE ------------------------"<<endl;
            cin>>lo;
        }

        else if(temp)
        {
            cout<<"\nYour Score : "<<0;
            cout<<"\nMin Steps : "<<sp<<endl;
            counter=6;
            getchar();
            cout<<"\n------------------------ PRESS ENTER TO CONTINUE ------------------------"<<endl;
            cin>>lo;
            break;
        }
        counter++;
        n++;
    }

    int c_play = 0;
    get_player_count();
    find_player(JT.player,JT.score,c_play);
    create_lead();
    show_lead();
    return 0;
}
