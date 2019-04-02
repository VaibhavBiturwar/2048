#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
/*left 75
right 77
up 72
down 80
*/
using namespace std;

class game
{
private:
     int g[4][4],i,j;
    int n,a,b,c,d;

public:
    game()
    {
         for(i=0;i<4;i++)
           for(j=0;j<4;j++)
              g[i][j]=0;

    srand(time(NULL));
    a=rand()%4;
    b=rand()%4;
    c=rand()%4;
    d=rand()%4;
    while(a==c && b==d)
     {
       c=rand()%4;
       d=rand()%4;
     }
     g[a][b]=g[c][d]=2;
     }

     void display()
     {
         for(i=0;i<4;i++)
            {for(j=0;j<4;j++)
               {
                   if(g[i][j]==0)
                    {
                        cout.width(4);
                        cout<<" "<<"|";
                        }
                   else
                   {
                    cout.width(4);
                    cout<<g[i][j]<<"|";
                   }
               }
         cout<<endl<<"- - - - - - - - - -"<<endl;
            }
         cout<<endl<<endl;
     }

     void left()
     {
         int i=0;j=0,c=4;
         int flag=0;

         while(c)
         {
             for(j=0;j<4;j++)
         for(i=0;i<3;i++)
         {
             if(g[j][i]==0)
             {
                 g[j][i]=g[j][i+1];
                 g[j][i+1]=0;

             }
             else if(g[j][i]==g[j][i+1])
             {
                 if(g[j][i]!=0)
                    flag=1;
                 g[j][i]*=2;
                 g[j][i+1]=0;

             }
         }
         c--;
         }
        next();
            }

    void right()
    {
         int i=0;j=0,c=4;
         int flag=0;

         while(c)
         {
             for(j=0;j<4;j++)
         for(i=3;i>0;i--)
         {
             if(g[j][i]==0)
             {
                 g[j][i]=g[j][i-1];
                 g[j][i-1]=0;

             }
             else if(g[j][i]==g[j][i-1])
             {
                 g[j][i]*=2;
                 if(g[i][j]!=0)
                 flag=1;
                 g[j][i-1]=0;

             }
         }
         c--;
         }
         if(flag)
            next();

     }

    void up()
    {
         int i=0;j=0,c=4;
         int flag=0;

         while(c)
         {
             for(j=0;j<4;j++)
         for(i=0;i<3;i++)
         {
             if(g[i][j]==0)
             {
                 g[i][j]=g[i+1][j];
                 g[i+1][j]=0;

             }
             else if(g[i][j]==g[i+1][j])
             {
                 if(g[i][j]!=0)
                    flag=1;
                 g[i][j]*=2;
                 g[i+1][j]=0;

             }
         }
         c--;
         }
        next();
            }

    void down()
    {
         int i=0;j=0,c=4;
         int flag=0;

         while(c)
         {
             for(j=0;j<4;j++)
         for(i=3;i>0;i--)
         {
             if(g[i][j]==0)
             {
                 g[i][j]=g[i-1][j];
                 g[i-1][j]=0;

             }
             else if(g[i][j]==g[i-1][j])
             {
                 g[i][j]*=2;
                 if(g[j][i]!=0)
                 flag=1;
                 g[i-1][j]=0;

             }
         }
         c--;
         }
         if(flag)
            next();

     }
    void next()
    {
        int a,b;
         a=rand()%4;
         b=rand()%4;
         while(g[a][b]!=0)
         {
              a=rand()%4;
              b=rand()%4;
         }
         int val;
         val=rand()%2;
         if(val==0)
         g[a][b]=2;
         else
         g[a][b]=4;
    }
    void check()
    {
        int j,i;
        for(i=0;i<4;i++)
            for(j=0;j<4;i++)
        {
            if(g[i][j]!=1024)
            cout<<"***** YOU WIN *****"<<endl;
        }
    }


};


int main()
{
       game obj1;
       cout<<"USE ARROW KEYS TO PLAY AND Q TO EXIT"<<endl;
       char c;

       while(1)
       {
        obj1.display();
        c=0;
        ///obj1.check();
        switch(c=getch())
        {
        case 75:
            obj1.left();
            break;
        case 77:
            obj1.right();
            break;
        case 72:
            obj1.up();
            break;
        case 80:
            obj1.down();
            break;
        case 'q':
            return 0;
            break;

        }
       }
    return 0;
}
