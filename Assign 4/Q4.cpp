#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int gintii = 0;
int sawal()
{
    int fehrist = (rand() % 4) + 1;
    return fehrist;
}
bool Sawaals(int ilmulfazool, int ilmuleinstien, int ilmulbabarazam, int ilmulaimabaig)
{
    if((ilmulfazool >= 50) && (ilmulfazool <= 100))
    {
        return true;
        gintii = gintii + 1;
    }
    else
    {
        return false;
    }
    if((ilmuleinstien >= 50) && (ilmuleinstien <= 100))
    {
        return true;
        gintii = gintii + 1;
    }
    else
    {
        return false;
    }
    if((ilmulbabarazam >= 50) && (ilmulbabarazam <= 100))
    {
        return true;
        gintii = gintii + 1;
    }
    else
    {
        return false;
    }
    if((ilmulaimabaig >= 50) && (ilmulaimabaig <= 100))
    {
        return true;
        gintii = gintii + 1;
    }
    else
    {
        return false;
    }

}
int paisa (int sawalkiginti)
{
	int ajar;
    if ((sawalkiginti >= 1) && (sawalkiginti <= 3))
    {
        ajar = 100;
    }
    else if ((sawalkiginti >= 4) && (sawalkiginti <= 6))
    {
        ajar = 1000;
    }
    else if ((sawalkiginti >= 7) && (sawalkiginti <= 10))
    {
        ajar = 10000;
    }
    else if ((sawalkiginti > 10) && (sawalkiginti <= 15))
    {
        ajar = 15000;
    }
    return ajar;
}
bool kootrakh(int ilmulfazool, int ilmuleinstien, int ilmulbabarazam, int ilmulaimabaig)
{
    if((ilmulfazool > 20) && (ilmuleinstien > 20) && (ilmulbabarazam > 20) && (ilmulaimabaig > 20))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main ()
{
    srand(time(NULL));
    int prize = 0;
    int ilmulfazool = (rand() % 51) + 50;
    int ilmuleinstien = (rand() % 51) + 50;
    int ilmulbabarazam = (rand() % 51) + 50;
    int ilmulaimabaig = (rand() % 51) + 50;
    int qCount = 1;
    while ((qCount <= 15) && (kootrakh (ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig)))
    {
        int Question = sawal ();
        switch (Question)
        {
            case 1:
                cout << "Answer a Question from subject Science : ####" << "\n";
                if (Sawaals(ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig) == true)
                {
            		cout << "!!!Correct Answer!!!" << "\n";
                    ilmulfazool = ilmulfazool - 10;
                    prize = prize + paisa (qCount);
                    cout << "You got Prize  " << prize << "\n";
                    gintii = gintii + 1;
                    qCount = qCount + 1;
                }
                else if (Sawaals(ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig) == false)
                {
                    cout << "Wrong Answer!" << "\n";
                    qCount = qCount + 1;
                }
                cout << "\n";
            case 2:
                cout << "Answer a Question from subject History : ####" << "\n";
                if (Sawaals(ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig) == true)
                {
                    cout << "!!!Correct Answer!!!" << "\n";
                    ilmuleinstien = ilmuleinstien - 10;
                    prize = prize + paisa (qCount);
                    cout << "You got Prize  " << prize << "\n";
                    gintii = gintii + 1;
                    qCount = qCount + 1;
                }
                else if (Sawaals(ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig) == false)
                {
                    cout << "Wrong Answer!" << "\n";
                    qCount = qCount + 1;
                }
                cout << "\n";
            case 3:
                cout << "Answer a Question from subject Sport : ####" << "\n";
                if (Sawaals(ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig) == true)
                {
                    cout << "!!!Correct Answer!!!" << "\n";
                    ilmulbabarazam = ilmulbabarazam - 10;
                    prize = prize + paisa (qCount);
                    cout << "You got Prize  " << prize << "\n";
                    gintii = gintii + 1;
                    qCount = qCount + 1;
                }
                else if (Sawaals(ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig) == false)
                {
                    cout << "!!! Wrong Answer !!!" <<"\n";
                    qCount = qCount + 1;
                }
                cout << "\n";
            case 4:
                cout << "Answer a Question from subject Pop Culture : ####" << "\n";
                if (Sawaals(ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig) == true)
                {
                    cout << "!!!Correct Answer!!!" <<"\n";
                    ilmulaimabaig = ilmulaimabaig - 10;
                    prize = prize + paisa (qCount);
                    cout << "You got Prize  " << prize <<"\n";
                    gintii = gintii + 1;
                    qCount = qCount + 1;
                }
                else if (Sawaals(ilmulfazool, ilmuleinstien, ilmulbabarazam, ilmulaimabaig) == false)
                {
                    cout << "!!! Wrong Answer !!!" << "\n";
                    qCount = qCount + 1;
                }
                cout << "\n";
        }
    }
    cout << "Total Question Answered = " << gintii << "\n";
    cout << "Total Prize = " << prize << "\n";
    return 0;
}
