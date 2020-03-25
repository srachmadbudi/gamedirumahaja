#include "Trap_game.h"

trap_game::trap_game(int n , string name, char*** simpangan_, int *counter_)
{
//    this->simpangan = *simpangan_;
    simpangan_ptr = simpangan_;
    this->n = n;
    this->score = 0;
    this->kehidupan =3;
    counter_ptr = counter_;
    counter = *counter_ptr;
//    printf("coutner sebel %d\n",counter);
//    counter++;
//    *counter_ptr = counter;
//    printf("coutner sebel2 %d\n",counter);
    player = name;
    steps = 0;
    simpangan = new char * [n];

    for (int i = 0; i < n; ++i ){
//        printf("simpang1 %d\n",i);
        simpangan[i] = new char [n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
//            printf("simpang %d %d\n",i,j);
            simpangan[i][j]=' ';
        }
    }
//    printf("KELUAR\n");
    simpangan[0][0]='*';
    simpangan[n-1][n-1]='@';
    *simpangan_ptr = simpangan;
//    printf("KELUAR2\n");

}

void trap_game::randomObstruction(double percent)
{

    int c=(percent*n*n);
    while(c>0)
    {
        int i=rand()%n;
        int j=rand()%n;
        if(simpangan[i][j]!='X' && simpangan[i][j]!='#' && (i!=0 || j!=0))
        {
            simpangan[i][j]='X';
            c--;
        }
    }
    *simpangan_ptr = simpangan;
}


void trap_game::redefine(int n1)
{
    n=n1;
    steps=0;
    simpangan = new char * [n];

    for (int i = 0; i < n; ++i )
        simpangan[i] = new char [n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            simpangan[i][j]=' ';
    }

    simpangan[0][0]='*';
    simpangan[n-1][n-1]='@';

    *simpangan_ptr = simpangan;
}

void trap_game::Gambar_simpangan()
{
    cout<<"\n\n LEVEL "<<counter<<"\n\n";
    int i,j=0;
    cout<<"\n\n\n";

    for(i=0;i<n;i++)
    {
        cout<<"\t "<<(i+1)<<" ";
    }

    cout<<"\n";

    for(i=0;i<n;i++)
    {
        cout<<"\t  ___  ";
    }
    cout<<"\n";
    while(j<n)
    {
        for(i=0;i<n;i++)
        {
            if(simpangan[i][j]!=' ')
                printf("\t| _%c_ |",simpangan[i][j]);

            else
                cout<<"\t| ___ |";
        }
        cout<<"\n";
        j++;
    }
    *simpangan_ptr = simpangan;
    cout<<"\n\n\n\n\n";
}

int trap_game::move(int x,int y)
{
    pair<int,int> K;
    char ch;
    int termin=0;
    do
    {
        cout<<"\nUP = 'W'";
        cout<<"\nDOWN = 'S'";
        cout<<"\nLEFT = 'A'";
        cout<<"\nRIGHT = 'D'";
        cout<<"\nUNDO = 'U'";
        cout<<"\nQUIT = 'Q'";
        cout<<"\n";
        cout<<"\nYour Lives : "<<kehidupan;
        cout<<"\nEnter Your Move : ";

        ch=getchar();

        switch(ch)
        {
            case 'W':
            {
                if(y>0 && simpangan[x][y-1]!='X'&& simpangan[x][y-1]!='@')
                {
                    simpangan[x][y]='_';

                    if(!S.empty())
                    {
                        K=S.top();
                    }

                    S.push(make_pair(x,y));
                    y-=1;

                    if((K.first==x)&&(K.second==y))
                    {
                        kehidupan--;
                    }

                    simpangan[x][y] = '*';
                    steps++;
                }

                else if(simpangan[x][y-1]=='@')
                {
                    cout<<"\nCONGRATULATION FOR YOUR FREEDOM !";
                    y-=1;
                    break;
                }

                else
                    cout<<"\nCan't Move up Bro";
                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    exit(0);
                }
                break;
            }

            case 'A':
            {
                if(x>0 && simpangan[x-1][y]!='X'&& simpangan[x-1][y]!='*')
                {
                    simpangan[x][y]='_';

                    if(!S.empty())
                    {
                        K=S.top();
                    }

                    S.push(make_pair(x,y));
                    x-=1;

                    if((K.first==x)&&(K.second==y))
                    {
                        kehidupan--;
                    }

                    simpangan[x][y] = '*';
                    steps++;
                }

                else if(simpangan[x-1][y]=='@')
                {
                    cout<<"\nCONGRATULATION FOR YOUR FREEDOM !";
                    x-=1;
                    break;
                }
                else
                    cout<<"\nCan't Move left Bro";

                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    exit(0);
                }

                break;
            }

            case 'S':
            {
                if(y>=0 && y+1<n && simpangan[x][y+1]!='X' && simpangan[x][y+1]!='@')
                {
                    simpangan[x][y]='_';
                    if(!S.empty())
                    {
                        K=S.top();
                    }

                    S.push(make_pair(x,y));
                    y+=1;

                    if((K.first==x)&&(K.second==y))
                    {
                        kehidupan--;
                    }

                    simpangan[x][y] = '*';
                    steps++;
                }

                else if(simpangan[x][y+1]=='@')
                {
                    cout<<"\nCONGRATULATION FOR YOUR FREEDOM !";
                    y+=1;
                    break;
                }

                else
                    cout<<"\nCan't Move Down Bro";

                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    exit(0);
                }
                break;
            }

            case 'D':
            {
                if(x>=0 && x+1<n && simpangan[x+1][y]!='X' && simpangan[x+1][y]!='@')
                {
                    simpangan[x][y]='_';
                    if(!S.empty())
                    {
                        K=S.top();
                    }

                    S.push(make_pair(x,y));
                    x+=1;

                    if((K.first==x)&&(K.second==y))
                    {
                        kehidupan--;
                    }

                    simpangan[x][y] = '*';
                    steps++;
                }

                else if(simpangan[x+1][y]=='@')
                {
                    cout<<"\nCONGRATULATION FOR YOUR FREEDOM !";
                    x+=1;
                    break;
                }

                else
                    cout<<"\nCan't Move Right Bro";

                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    exit(0);
                }

                break;
            }

            case 'U':
            {
                int i,j;
                if(S.empty()==true)
                {   cout<<"\nUNDO NOT POSSIBLE BRO";
                    break;

                }
                else
                {
                    pair<int,int> P=S.top();
                    i=P.first;
                    j=P.second;
                    S.pop();
                    simpangan[x][y] = '_';
                    simpangan[i][j] = '*';
                    x=i;
                    y=j;
                    steps--;
                }

                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    int count_player=0;
                }
                else
                    kehidupan--;
                break;
            }

            case 'Q':
            {
                cout<<"\n"<<player<<" Your Steps : "<<steps;
                termin=1;
                int count_player=0;
            }
        }

        if(termin==0)
        {
            Gambar_simpangan();
        }

        else
        {
            break;
        }
    }

    while(simpangan[x][y]!='@' && termin==0);
    *simpangan_ptr = simpangan;
    return(termin);
}

void trap_game::score_play(int shortest , double percent)
{
    int longest = (n*n)-(percent*n*n);
    int avg = (longest+shortest)/2;
    int count=0;

    if((steps+1)>avg)
    {
        score += 40;
    }

    else if((steps+1) == avg)
    {
        score+=50;
    }

    else if((steps+1)<avg)
    {
        if((steps+1)==shortest)
            score+=100;

        else
        {
            count = (steps+1)-shortest;
            if(count==1)
                score+=94;

            else if(count==2)
                score+=88;

            else if(count==3)
                score+=82;

            else if(count==4)
                score+=76;

            else if(count==5)
                score+=70;

            else if(count==6)
                score+=64;

            else
                score+=55;

        }
    }
}
