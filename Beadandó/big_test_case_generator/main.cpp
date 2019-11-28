#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;

int main()
{
    ofstream a("args.txt");
    srand(time(NULL));

    for(int ep_no = 1; ep_no <=50; ep_no++){
        char s[12];
        sprintf(s, "8ep%d.csv", ep_no);
        //cout<<s<<endl;
        ofstream f(s);
        a<<s<<" ";
        int szs = rand()% 31 + 20;
        f<<"ep"<<ep_no<<"\n";
        int sebesseghatar = rand()% 81 + 50;
        f<<sebesseghatar<<"\n";
        for(int szs_no = 1; szs_no <= szs; szs_no++){
            f<<"2019-03-";
            int nap = rand()% 31 + 1;
            if(nap<10)
                f<<"0";
            f<<nap<<";";
            int ora = rand()% 24;
            int perc = rand()% 60;
            if(ora<10)
                f<<"0";
            f<<ora<<":";
            if(perc<10)
                f<<"0";
            f<<perc<<";";
            int tipus = rand() % 100 + 1;
            if(tipus >= 1 && tipus<=70){
                int sebesseg = sebesseghatar + rand()% 100 + 20;
                f<<"gyorshajtas "<<sebesseg<<";";
            }
            if(tipus >= 71 && tipus<=80)
                f<<"piros_lampa;";
            if(tipus >= 81 && tipus<=85)
                f<<"vasuti_atjaro;";
            if(tipus >= 86 && tipus<=90)
                f<<"behajtasi_tilalom;";
            if(tipus >= 91 && tipus<=95)
                f<<"kotelezo_haladas;";
            if(tipus >= 96 && tipus<=98)
                f<<"leallosav;";
            if(tipus >= 99 && tipus<=100)
                f<<"korlatozott_zona;";

            for(int i=1;i<=3;i++){
                char r = rand()%26+65;
                f<<r;
            }

            int rendszam = rand() % 900 + 100;
            f<<rendszam<<"\n";
        }
    }
    return 0;
}
