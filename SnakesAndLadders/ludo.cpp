#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>

int posx[77] = { 0, 102, 127, 152, 177, 202, 227, 265, 265, 265, 265, 265, 265, 315, 365, 365, 365, 365, 365, 365, 402, 427, 452, 477, 502, 527, 527, 527, 502, 477, 452, 427, 402, 365, 365, 365, 365, 365, 365, 315, 265, 265, 265, 265, 265, 265, 227, 202, 177, 152, 127, 102, 102, 127, 152, 177, 202, 227, 327, 315, 315, 315, 315, 315, 327, 502, 477, 452, 427, 402, 327, 315, 315, 315, 315, 315, 327 };
int posy[77] = { 0, 195, 195, 195, 195, 195, 195, 157, 132, 107, 82, 57, 32, 32, 32, 57, 82, 107, 132, 157, 195, 195, 195, 195, 195, 195, 245, 295, 295, 295, 295, 295, 295, 332, 357, 382, 407, 432, 457, 457, 457, 432, 407, 382, 357, 332, 295, 295, 295, 295, 295, 295, 245, 245, 245, 245, 245, 245, 245, 57, 82, 107, 132, 157, 245, 245, 245, 245, 245, 245, 245, 432, 407, 382, 357, 332, 245 };
int initposx[8] = { 130, 205, 130, 205, 425, 500, 425, 500 };                                                                                                                                                                                           //                    //                      //                      //
int initposy[8] = { 60, 60, 135, 135, 355, 355, 430, 430 };
int t = -1;
int cmsg;
char *msg, *tmsg;
void callput();
void clear();
void pmsg()
{
    std::cout << (tmsg) << std::endl;
}
int throwd()
{
    while (1)
    {
        int x = 25 + rand() % 41;
        char n[1], nl[1], nr[1];
        int tn = x % 8;
        if (tn + 1 == 1)
        {
            *n = '1';
            *nl = '2';
            *nr = '4';
        }
        else if (tn + 1 == 2)
        {
            *n = '2';
            *nl = '3';
            *nr = '6';
        }
        else if (tn + 1 == 3)
        {
            *n = '3';
            *nl = '1';
            *nr = '5';
        }
        else if (tn + 1 == 4)
        {
            *n = '4';
            *nl = '2';
            *nr = '6';
        }
        else if (tn + 1 == 5)
        {
            *n = '5';
            *nl = '1';
            *nr = '4';
        }
        else if (tn + 1 >= 6)
        {
            *n = '6';
            *nl = '3';
            *nr = '5';
        }
        *(n + 1) = '\0';
        *(nl + 1) = '\0';
        *(nr + 1) = '\0';
        std::cout << n << std::endl;
        std::cout << nl << std::endl;
        std::cout << nr << std::endl;
        if (rand() % 5 == 0)
        {
                return tn;
        }
    }
}

void dice()
{
    char n[2];
    if (t + 1 == 1)
        *n = '1';
    else if (t + 1 == 2)
        *n = '2';
    else if (t + 1 == 3)
        *n = '3';
    else if (t + 1 == 4)
        *n = '4';
    else if (t + 1 == 5)
        *n = '5';
    else
        *n = '6';
    *(n + 1) = '\0';
    if (t >= 0)
        std::cout << n << std::endl;
    else
        std::cout << "LUDO" << std::endl;
    *n = NULL;
}
class ludo
{
public:
    int nr[4];       //no.of rounds
    int init[4];     //strating or not 1-starting 0-not starting
    int d[4];        //direction 1-e 2-n 3-w 4-s
    int kill;           //killed or not 1-yes killed 0-not killed any
    int key;         //to select among 1 2 3 4
    int c;           //color r-1 g-2 b-3 y-4
    int nv;          //no. of values got
    int *v;          //values
    int bv[4];       //box values 1-52 for direction
    int h[4];        //home? 1-home 0-not home
    int sumv;        //sum of values
    int nomove[4];   //can't move  1-nomove 0-canmove
    int u[4];         //used? 1-used 0-not used
    int kc[4];	//kc increases for every dice point.key count
    ludo(int);
    int sum();
    void readv();
    int search(int);
    void yougot();
    void remove(int);
    int cantmove();
    void setmove();
    void initnomove();
    void move();
    void killr();        //checks killing chance for red
    void killg();
    void killb();
    void killy();
};
ludo r(1), g(2), b(3), y(4);
ludo::ludo(int col)
{
    for (int i = 0; i<4; i++)
    {
        if (c == 1)
            d[i] = 4;
        else if (c == 2)
            d[i] = 1;
        else if (c == 3)
            d[i] = 3;
        else
            d[i] = 2;
        kc[i] = 0;
        nr[i] = 0;
        init[i] = 1;
        u[i] = 0;
        bv[i] = 0;
        h[i] = 0;
        nomove[i] = 0;
    }
    kill = 0;
    key = 1;
    nv = 0;
    v = NULL;
    sumv = 0;
}
int ludo::sum()
{
    sumv = 0;
    for (int i = 0; i<nv; i++)
        sumv += v[i];
    return sumv;
}
void ludo::readv()
{
    if (c == 1)
        msg = "Turn for red";
    else if (c == 2)
        msg = "Turn for green";
    else if (c == 3)
        msg = "Turn for blue";
    else
        msg = "Turn for yellow";
    clear();
    t = throwd();
    dice();
    while (t + 1 >= 6 || t + 1 == 4)
    {
        if (t + 1 == 4)
            v[nv] = 4;
        else
            v[nv] = 6;
        nv++;
        yougot();
        std::cout << "Press enter to roll the dice again." << std::endl;
        getch();
        clear();
        t = throwd();
        clear();
    }
    v[nv] = t + 1;
    nv++;

    clear();
    yougot();
}
int ludo::search(int k)
{
    for (int i = 0; i<nv; i++)
    {
        if (v[i] == k)
            return 1;
    }
    return 0;
}
void ludo::yougot()
{
    clear();
    if (nv>0)
    {
        std::cout << "You got:" << std::endl;
        for (int j = 0; j<nv; j++)
            printf("\n%d ", v[j]);
    }
}
void ludo::remove(int k)
{
    for (int i = 0; i<nv; i++)
    {
        if (v[i] == k)
        {
            for (int j = i; j<nv - 1; j++)
                v[j] = v[j + 1];
            nv--;
            break;
        }
    }
}
int ludo::cantmove()
{
    int c = 0;
    for (int i = 0; i<4; i++)
        if (nomove[i] == 1)
            c++;
    if (c == 4)
        return 1;
    else
        return 0;
}
void ludo::setmove()
{
    for (int i = 0; i<4; i++)
        nomove[i] = 0;
}
void ludo::initnomove()
{
    for (int i = 0; i <= 3; i++)
    {
        if (init[i] == 1)
        {
            if (search(6))
                nomove[i] = 0;
            else
                nomove[i] = 1;
        }
        else if (h[i] == 1)
            nomove[i] = 1;
        else if (sum()>(58 - kc[i]))
            nomove[i] = 1;
        else if (h[i] == 0)
            nomove[i] = 0;
    }
}
void ludo::move()
{
    printf("\nEnter which key to move:");
    key = getch() - 48;
    if (key >= 1 && key <= 4)
    {
        if (init[key - 1] == 1)
        {
            if (search(6))
            {
                if (c == 1)
                {
                    d[key - 1] = 3;
                    bv[key - 1] = 2;
                    kc[key - 1] = 2;
                    r.killr();
                }
                else if (c == 2)
                {
                    d[key - 1] = 4;
                    bv[key - 1] = 15;
                    kc[key - 1] = 2;
                    g.killg();
                }
                else if (c == 3)
                {
                    d[key - 1] = 2;
                    bv[key - 1] = 41;
                    kc[key - 1] = 2;
                    b.killb();
                }
                else
                {
                    d[key - 1] = 1;
                    bv[key - 1] = 28;
                    kc[key - 1] = 2;
                    y.killy();
                }
                init[key - 1] = 0;
                remove(6);
                yougot();
            }
            else
            {
                printf("You don't have dice point 6 to move your key.\n");
                nomove[key - 1] = 1;
            }
        }
        else
        {
            int k;
            printf("Enter any dice point you got:");
            k = getch() - 48;
            while (1)
            {
                if (search(k))
                {
                    if (c == 1 && kill == 1)
                    {
                        if (bv[key - 1] <= 52 && bv[key - 1] + k>52 && bv[key - 1] + k <= 58)
                        {
                            if (bv[key - 1] + k == 58)
                                h[key - 1] = 1;
                            bv[key - 1] += k;
                            kc[key - 1] += k;
                            remove(k);
                            d[key - 1] = 3;
                        }
                        else if (bv[key - 1] >= 53)
                        {
                            if (bv[key - 1] + k <= 58)
                            {
                                if (bv[key - 1] + k == 58)
                                    h[key - 1] = 1;
                                bv[key - 1] += k;
                                kc[key - 1] += k;
                                remove(k);
                                d[key - 1] = 3;
                            }
                            else
                            {
                                printf("Can't move this key.");
                                nomove[key - 1] = 1;
                            }
                        }
                        else if (bv[key - 1] + k>52)
                        {
                            bv[key - 1] = bv[key - 1] + k - 52;
                            if (kc[key - 1] + k>52)
                                kc[key - 1] = kc[key - 1] + k - 52;
                            else
                                kc[key - 1] += k;
                            remove(k);
                        }
                        else
                        {
                            bv[key - 1] += k;
                            if (kc[key - 1] + k>52)
                                kc[key - 1] = kc[key - 1] + k - 52;
                            else
                                kc[key - 1] += k;
                            remove(k);
                        }
                    }
                    else if (c == 2 && kill == 1)
                    {
                        if (bv[key - 1] <= 13 && bv[key - 1] + k>13 && bv[key - 1] + k <= 19)
                        {
                            if (bv[key - 1] + k == 19)
                                h[key - 1] = 1;
                            bv[key - 1] += (k + 45);
                            kc[key - 1] += k;
                            remove(k);
                            d[key - 1] = 4;
                        }
                        else if (bv[key - 1] >= 59)
                        {
                            if (bv[key - 1] + k <= 64)
                            {
                                if (bv[key - 1] + k == 64)
                                    h[key - 1] = 1;
                                bv[key - 1] += k;
                                kc[key - 1] += k;
                                remove(k);
                                d[key - 1] = 4;
                            }
                            else
                            {
                                printf("Can't move this key.");
                                nomove[key - 1] = 1;
                            }
                        }
                        else if (bv[key - 1] + k>52)
                        {
                            bv[key - 1] = bv[key - 1] + k - 52;
                            if (kc[key - 1] + k>52)
                                kc[key - 1] = kc[key - 1] + k - 52;
                            else
                                kc[key - 1] += k;
                            remove(k);
                        }
                        else
                        {
                            bv[key - 1] += k;
                            if (kc[key - 1] + k>52)
                                kc[key - 1] = kc[key - 1] + k - 52;
                            else
                                kc[key - 1] += k;
                            remove(k);
                        }
                    }
                    else if (c == 3 && kill == 1)
                    {
                        if (bv[key - 1] <= 39 && bv[key - 1] + k>39 && bv[key - 1] + k <= 45)
                        {
                            if (bv[key - 1] + k == 45)
                                h[key - 1] = 1;
                            bv[key - 1] += (k + 31);
                            kc[key - 1] += k;
                            remove(k);
                            d[key - 1] = 2;
                        }
                        else if (bv[key - 1] >= 71)
                        {
                            if (bv[key - 1] + k <= 76)
                            {
                                if (bv[key - 1] + k == 76)
                                    h[key - 1] = 1;
                                bv[key - 1] += k;
                                kc[key - 1] += k;
                                remove(k);
                                d[key - 1] = 2;
                            }
                            else
                            {
                                printf("Can't move this key.");
                                nomove[key - 1] = 1;
                            }
                        }
                        else if (bv[key - 1] + k>52)
                        {
                            bv[key - 1] = bv[key - 1] + k - 52;
                            if (kc[key - 1] + k>52)
                                kc[key - 1] = kc[key - 1] + k - 52;
                            else
                                kc[key - 1] += k;
                            remove(k);
                        }
                        else
                        {
                            bv[key - 1] += k;
                            if (kc[key - 1] + k>52)
                                kc[key - 1] = kc[key - 1] + k - 52;
                            else
                                kc[key - 1] += k;
                            remove(k);
                        }
                    }
                    else if (c == 4 && kill == 1)
                    {
                        if (bv[key - 1] <= 26 && bv[key - 1] + k>26 && bv[key - 1] + k <= 32)
                        {
                            if (bv[key - 1] + k == 32)
                                h[key - 1] = 1;
                            bv[key - 1] += (k + 38);
                            kc[key - 1] += k;
                            remove(k);
                            d[key - 1] = 1;
                        }
                        else if (bv[key - 1] >= 65)
                        {
                            if (bv[key - 1] + k <= 70)
                            {
                                if (bv[key - 1] + k == 70)
                                    h[key - 1] = 1;
                                bv[key - 1] += k;
                                kc[key - 1] += k;
                                remove(k);
                                d[key - 1] = 1;
                            }
                            else
                            {
                                printf("Can't move this key.");
                                nomove[key - 1] = 1;
                            }
                        }
                        else if (bv[key - 1] + k>52)
                        {
                            bv[key - 1] = bv[key - 1] + k - 52;
                            if (kc[key - 1] + k>52)
                                kc[key - 1] = kc[key - 1] + k - 52;
                            else
                                kc[key - 1] += k;
                            remove(k);
                        }
                        else
                        {
                            bv[key - 1] += k;
                            if (kc[key - 1] + k>52)
                                kc[key - 1] = kc[key - 1] + k - 52;
                            else
                                kc[key - 1] += k;
                            remove(k);
                        }
                    }
                    else if (bv[key - 1] + k>52)
                    {
                        bv[key - 1] = bv[key - 1] + k - 52;
                        if (kc[key - 1] + k>52)
                            kc[key - 1] = kc[key - 1] + k - 52;
                        else
                            kc[key - 1] += k;
                        remove(k);
                    }
                    else
                    {
                        bv[key - 1] += k;
                        if (kc[key - 1] + k>52)
                            kc[key - 1] = kc[key - 1] + k - 52;
                        else
                            kc[key - 1] += k;
                        remove(k);
                    }
                    if ((bv[key - 1] >= 1 && bv[key - 1] <= 6) || (bv[key - 1] >= 12 && bv[key - 1] <= 13) || (bv[key - 1] >= 20 && bv[key - 1] <= 24))
                        d[key - 1] = 3;
                    else if ((bv[key - 1] >= 27 && bv[key - 1] <= 32) || (bv[key - 1] >= 38 && bv[key - 1] <= 39) || (bv[key - 1] >= 46 && bv[key - 1] <= 50))
                        d[key - 1] = 1;
                    else if ((bv[key - 1] >= 7 && bv[key - 1] <= 11) || (bv[key - 1] >= 40 && bv[key - 1] <= 45) || (bv[key - 1] >= 51 && bv[key - 1] <= 52))
                        d[key - 1] = 2;
                    else if ((bv[key - 1] >= 14 && bv[key - 1] <= 19) || (bv[key - 1] >= 25 && bv[key - 1] <= 26) || (bv[key - 1] >= 33 && bv[key - 1] <= 37))
                        d[key - 1] = 4;
                    if (c == 1)
                        r.killr();
                    else if (c == 2)
                        g.killg();
                    else if (c == 3)
                        b.killb();
                    else
                        y.killy();
                    clear();
                    yougot();
                    break;
                }
                else
                {
                    printf("You don't have that point.\nEnter right point you have:");
                    k = getch() - 48;
                }
            }
        }
    }
    else
        printf("You Entered wrong key.\n");
}
void ludo::killr()
{
    int chsafe = bv[key - 1] != 49 && bv[key - 1] != 10 && bv[key - 1] != 23 && bv[key - 1] != 36;
    for (int i = 0; i<4; i++)
    {
        if (chsafe == 1 && bv[key - 1] == g.bv[i])
        {
            r.kill = 1;
            g.bv[i] = 0;
            g.kc[i] = 0;
            g.init[i] = 1;
            g.d[i] = 1;
            r.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            r.readv();
        }
        else if (chsafe == 1 && bv[key - 1] == b.bv[i])
        {
            r.kill = 1;
            b.bv[i] = 0;
            b.kc[i] = 0;
            b.init[i] = 1;
            b.d[i] = 3;
            r.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            r.readv();
        }
        else if (chsafe == 1 && bv[key - 1] == y.bv[i])
        {
            r.kill = 1;
            y.bv[i] = 0;
            y.kc[i] = 0;
            y.init[i] = 1;
            y.d[i] = 2;
            r.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            r.readv();
        }
    }
}
void ludo::killg()
{
    int chsafe = bv[key - 1] != 49 && bv[key - 1] != 10 && bv[key - 1] != 23 && bv[key - 1] != 36;
    for (int i = 0; i<4; i++)
    {
        if (chsafe == 1 && bv[key - 1] == r.bv[i])
        {
            g.kill = 1;
            r.bv[i] = 0;
            r.kc[i] = 0;
            r.init[i] = 1;
            r.d[i] = 4;
            g.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            g.readv();
        }
        else if (chsafe == 1 && bv[key - 1] == b.bv[i])
        {
            g.kill = 1;
            b.bv[i] = 0;
            b.kc[i] = 0;
            b.init[i] = 1;
            b.d[i] = 3;
            g.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            g.readv();
        }
        else if (chsafe == 1 && bv[key - 1] == y.bv[i])
        {
            g.kill = 1;
            y.bv[i] = 0;
            y.kc[i] = 0;
            y.init[i] = 1;
            y.d[i] = 2;
            g.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            g.readv();
        }
    }
}
void ludo::killb()
{
    int chsafe = bv[key - 1] != 49 && bv[key - 1] != 10 && bv[key - 1] != 23 && bv[key - 1] != 36;
    for (int i = 0; i<4; i++)
    {
        if (chsafe == 1 && bv[key - 1] == g.bv[i])
        {
            b.kill = 1;
            g.bv[i] = 0;
            g.kc[i] = 0;
            g.init[i] = 1;
            g.d[i] = 1;
            b.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            b.readv();
        }
        else if (chsafe == 1 && bv[key - 1] == r.bv[i])
        {
            b.kill = 1;
            r.bv[i] = 0;
            r.kc[i] = 0;
            r.init[i] = 1;
            r.d[i] = 4;
            b.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            b.readv();
        }
        else if (chsafe == 1 && bv[key - 1] == y.bv[i])
        {
            b.kill = 1;
            y.bv[i] = 0;
            y.kc[i] = 0;
            y.init[i] = 1;
            y.d[i] = 2;
            b.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            b.readv();
        }
    }
}
void ludo::killy()
{
    int chsafe = bv[key - 1] != 49 && bv[key - 1] != 10 && bv[key - 1] != 23 && bv[key - 1] != 36;
    for (int i = 0; i<4; i++)
    {
        if (chsafe == 1 && bv[key - 1] == g.bv[i])
        {
            y.kill = 1;
            g.bv[i] = 0;
            g.kc[i] = 0;
            g.init[i] = 1;
            g.d[i] = 1;
            y.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            y.readv();
        }
        else if (chsafe == 1 && bv[key - 1] == b.bv[i])
        {
            y.kill = 1;
            b.bv[i] = 0;
            b.kc[i] = 0;
            b.init[i] = 1;
            b.d[i] = 3;
            y.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            y.readv();
        }
        else if (chsafe == 1 && bv[key - 1] == r.bv[i])
        {
            y.kill = 1;
            r.bv[i] = 0;
            r.kc[i] = 0;
            r.init[i] = 1;
            r.d[i] = 4;
            y.yougot();
            std::cout << "Press enter to roll the dice" << std::endl;
            getch();
            y.readv();
        }
    }
}
void put(int bv, int d, int c, int id)
{
    printf("box value: %d, direction: %d, color: %d, id: %d", bv, d, c, id);
}
int checkhome()
{
    if (r.h[0] == 1 && r.h[1] == 1 && r.h[2] == 1 && r.h[3] == 1)
        return 1;
    else if (g.h[0] == 1 && g.h[1] == 1 && g.h[2] == 1 && g.h[3] == 1)
        return 2;
    else if (b.h[0] == 1 && b.h[1] == 1 && b.h[2] == 1 && b.h[3] == 1)
        return 3;
    else if (y.h[0] == 1 && y.h[1] == 1 && y.h[2] == 1 && y.h[3] == 1)
        return 4;
    return 0;
}
void rturn()
{
    cmsg = 1;
    msg = "Turn for red";
    clear();
    std::cout << "Press enter to roll the dice" << std::endl;
    getch();
    r.readv();
    while (r.nv>0)
    {
        r.initnomove();
        if (r.bv[0] == 0 && r.bv[1] == 0 && r.bv[2] == 0 && r.bv[3] == 0 && !(r.search(6)))
        {
            printf("\nBetter Luck next time.");
            break;
        }
        else if (r.cantmove())
        {
            printf("Can't move any keys.");
            break;
        }
        else
            r.move();
        r.setmove();
    }
}
void gturn()
{
    cmsg = 2;
    msg = "Turn for green";
    clear();
    std::cout << "Press enter to roll the dice" << std::endl;
    getch();
    g.readv();
    while (g.nv>0)
    {
        g.initnomove();
        if (g.bv[0] == 0 && g.bv[1] == 0 && g.bv[2] == 0 && g.bv[3] == 0 && !(g.search(6)))
        {
            printf("\nBetter Luck next time.");
            break;
        }
        else if (g.cantmove())
        {
            printf("Can't move any keys.");
            break;
        }
        else
            g.move();
        g.setmove();
    }
}
void bturn()
{
    cmsg = 3;
    msg = "Turn for blue";
    clear();
    std::cout << "Press enter to roll the dice" << std::endl;
    getch();
    b.readv();
    while (b.nv>0)
    {
        b.initnomove();
        if (b.bv[0] == 0 && b.bv[1] == 0 && b.bv[2] == 0 && b.bv[3] == 0 && !(b.search(6)))
        {
            printf("\nBetter Luck next time.");
            break;
        }
        else if (b.cantmove())
        {
            printf("Can't move any keys.");
            break;
        }
        else
            b.move();
        b.setmove();
    }
}
void yturn()
{
    cmsg = 4;
    msg = "Turn for yellow";
    clear();
    std::cout << "Press enter to roll the dice" << std::endl;
    getch();
    y.readv();
    while (y.nv>0)
    {
        y.initnomove();
        if (y.bv[0] == 0 && y.bv[1] == 0 && y.bv[2] == 0 && y.bv[3] == 0 && !(y.search(6)))
        {
            printf("\nBetter Luck next time.");
            break;
        }
        else if (y.cantmove())
        {
            printf("Can't move any keys.");
            break;
        }
        else
            y.move();
        y.setmove();
    }
}
void clear()
{
    dice();
    pmsg();
}
int stop()
{
    printf("\nPress 'x' to exit or 'p' to pause or Enter to continue:");
    int sp = getc(stdin);
    if (sp == 'e')
        return 1;
    else if (sp == 'p')
        return 2;
    else
        return 0;
}
void scp()
{
    int sp = stop();
    if (sp == 1)
        exit(0);
    else if (sp == 2)
        while (1)
        {
            std::cout << "Game is paused to play press 'p'." << std::endl;
            if (getch() == 'p')
                break;
        }
}
void play()
{
    int menu;
    while (1)
    {
        printf("*******MENU*******\n1.ABOUT\n2.INSTRUCTIONS\n3.PLAYERS\n4.DEVELOPERS\n5.START\n6.EXIT\nEnter Your choice:[ ]\b\b");
        menu = getch() - 48;
        if (menu == 6)
            exit(0);
        if (menu == 5)
            break;
        if (menu>5 || menu<1)
        {
            printf("Enter right choice.");
        }
        else
        {
            switch (menu)
            {
            case 1: printf("\t\t\t\tABOUT\n\nThere can be 2 or 4 players.\nFor 2 players opposite colors should be selected.\nEach key can go to start position only when you have a dice point 6.\nNow the keys can go for a round where it should kill other player toy inorder   to reach its Home.\nIf a round is completed without killing other player toy atleast once should go for another round.\nIf one get a dice point 6 or 4 or kills other player toy will get another chanceto roll the dice.\nA player will win the game if all his/her keys reach their Home first.\n\nPress Enter to skip this menu.");
                getch();
                break;
            case 2: printf("\t\t\t\tINSTRUCTIONS\n\nPress Enter to roll the dice.\nPress Enter to stop rolling the dice.\nEnter which key out of 1/2/3/4 to move.\nEnter the dice point [you got] to be moved.\nKill other player toy to reach the Home.\n\nPress Enter to skip This Menu.");
                getch();
                break;
            case 3: printf("\t\t\t\tPLAYERS\n\nThere can be 2 or 4 players.\nFor 2 players opposite colors should be selected.\nLike Red and Yellow or Green and Blue.\n\nPress Enter to skip this menu.");
                getch();
                break;
            case 4: printf("\t\t\t\tDEVELOPERS\n\nCSE\nII year\n\nN.Anusha\nB.smitha\nN.deepika\nK.pavaniswarupa\nM.sunithasowjanya\n\nPress Enter to skip this menu.");
                getch();
                break;
            }
        }
    }
    int chhome, rp = 0, gp = 0, bp = 0, yp = 0, np, pc, selected = 0;
    printf("Number of players:\n1.Two players.\n2.Four players.\n0.To quit.");
    while (1)
    {
        printf("\nEnter your choice:");
        np = getch() - 48;
        switch (np)
        {
        case 0: return;
        case 1: printf("\nEnter 1 to select Red and Yellow other to select Green and Blue:");
            pc = getch() - 48;
            if (pc == 1)
                rp = yp = 1;
            else
                gp = bp = 1;
            selected = 1;
            break;
        case 2: rp = gp = bp = yp = 1;
            selected = 1;
            break;
        default: printf("\nEnter right number of players.");
        }
        if (selected)
            break;
    }
    clear();
    chhome = checkhome();
    while (chhome == 0)
    {
        if (rp)
        {
            rturn();
            scp();
        }
        if (checkhome())
            break;
        if (gp)
        {
            clear();
            gturn();
            scp();
        }
        if (checkhome())
            break;
        if (yp)
        {
            clear();
            yturn();
            scp();
        }
        if (checkhome())
            break;
        if (bp)
        {
            clear();
            bturn();
            if (stop())
                exit(0);
        }
        clear();
        r.v = g.v = b.v = y.v = NULL;
        r.nv = g.nv = b.nv = y.nv = 0;
        chhome = checkhome();
    }
    if (chhome == 1)
        printf("Red player won the game.");
    else if (chhome == 2)
        printf("Green player won the game.");
    else if (chhome == 3)
        printf("Blue player won the game.");
    else if (chhome == 4)
        printf("Yellow player won the game.");
    getch();
}