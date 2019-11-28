#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ellenorzo_pontok{

    char nev[205];
    int szabalytalansagok_szama;

}ELLENORZO_PONTOK;


typedef struct szabalysertesek{

    char helyszin[205];
    char datum[15];
    char ido[10];
    char szabalytalansag_tipusa[30];
    int birsag_osszege;
    int rogzitett_sebesseg;
    int sebessegtullepes;
    char rendszam[15];

}SZABALYSERTESEK;


int birsag_osszegenek_meghatarozasa_gyorshajtas(int sebessegtullepes, int sebesseghatar){

    if(sebesseghatar <= 50){
        if(sebessegtullepes >= 15 && sebessegtullepes <=25)
            return 30000;
        if(sebessegtullepes >= 26 && sebessegtullepes <=35)
            return 45000;
        if(sebessegtullepes >= 36 && sebessegtullepes <=45)
            return 60000;
        if(sebessegtullepes >= 46 && sebessegtullepes <=55)
            return 90000;
        if(sebessegtullepes >= 56 && sebessegtullepes <=65)
            return 130000;
        if(sebessegtullepes >= 66 && sebessegtullepes <=75)
            return 200000;
        if(sebessegtullepes >= 76)
            return 300000;
    }

    if(sebesseghatar > 50 && sebesseghatar<= 100){
        if(sebessegtullepes >= 15 && sebessegtullepes <=30)
            return 30000;
        if(sebessegtullepes >= 31 && sebessegtullepes <=45)
            return 45000;
        if(sebessegtullepes >= 45 && sebessegtullepes <=60)
            return 60000;
        if(sebessegtullepes >= 61 && sebessegtullepes <=75)
            return 90000;
        if(sebessegtullepes >= 76 && sebessegtullepes <=90)
            return 130000;
        if(sebessegtullepes >= 91 && sebessegtullepes <=105)
            return 200000;
        if(sebessegtullepes >= 106)
            return 300000;
    }

    if(sebesseghatar > 100){
        if(sebessegtullepes >= 20 && sebessegtullepes <=35)
            return 30000;
        if(sebessegtullepes >= 36 && sebessegtullepes <=50)
            return 45000;
        if(sebessegtullepes >= 51 && sebessegtullepes <=65)
            return 60000;
        if(sebessegtullepes >= 66 && sebessegtullepes <=80)
            return 90000;
        if(sebessegtullepes >= 81 && sebessegtullepes <=95)
            return 130000;
        if(sebessegtullepes >= 96 && sebessegtullepes <=110)
            return 200000;
        if(sebessegtullepes >= 111)
            return 300000;
    }

    return 0;
}


int birsag_osszegenek_meghatarozasa(char tipus[], int sebessegtullepes, int sebesseghatar){
    if(strcmp(tipus, "gyorshajtas") == 0)
        return birsag_osszegenek_meghatarozasa_gyorshajtas(sebessegtullepes, sebesseghatar);
    if(strcmp(tipus, "vasuti_atjaro") == 0)
        return 60000;
    if(strcmp(tipus, "piros_lampa") == 0 || strcmp(tipus, "kotelezo_haladas") == 0)
        return 50000;
    if(strcmp(tipus, "leallosav") == 0)
        return 100000;
    if(strcmp(tipus, "behajtasi_tilalom") == 0 || strcmp(tipus, "korlatozott_zona") == 0)
        return 30000;
    return 0;
}


int beolvas(FILE* fajl, ELLENORZO_PONTOK* ep, SZABALYSERTESEK* szs, int ossz_db_eddig, const int sorszam){

    char s[205];
    int db = 0;
    fgets(ep[sorszam].nev, 205, fajl);
    ep[sorszam].nev[strlen(ep[sorszam].nev)-1] = '\0';
    fgets(s, 205, fajl);
    int sebesseghatar = atoi(s);

    while(fgets(s, 205, fajl) != NULL){
        strcpy(szs[ossz_db_eddig + db].helyszin, ep[sorszam].nev);
        char* token = strtok(s, ";");
        strcpy(szs[ossz_db_eddig + db].datum, token);
        token = strtok(NULL, ";");
        strcpy(szs[ossz_db_eddig + db].ido, token);
        token = strtok(NULL, ";");
        char tipus[30];
        strcpy(tipus, token);
        token = strtok(NULL, "\n");
        strcpy(szs[ossz_db_eddig + db].rendszam, token);

        if(tipus[0]=='g'){
            token = strtok(tipus, " ");
            strcpy(szs[ossz_db_eddig + db].szabalytalansag_tipusa, token);
            token = strtok(NULL, " ");
            szs[ossz_db_eddig + db].rogzitett_sebesseg = atoi(token);
            szs[ossz_db_eddig + db].sebessegtullepes = szs[ossz_db_eddig + db].rogzitett_sebesseg - sebesseghatar;
        }
        else{
            strcpy(szs[ossz_db_eddig + db].szabalytalansag_tipusa, tipus);
            szs[ossz_db_eddig + db].rogzitett_sebesseg = 0;
            szs[ossz_db_eddig + db].sebessegtullepes = 0;
        }

        szs[ossz_db_eddig + db].birsag_osszege = birsag_osszegenek_meghatarozasa(szs[ossz_db_eddig + db].szabalytalansag_tipusa, szs[ossz_db_eddig + db].sebessegtullepes, sebesseghatar);

        db++;
    }

    ep[sorszam].szabalytalansagok_szama = db;
    return db;

}


long long int birsag_szum(int osszes_elemszam, SZABALYSERTESEK* szs){

    long long int sum = 0;
    for(int i=0; i<osszes_elemszam; i++)
        sum += szs[i].birsag_osszege;
    return sum;

}


int hasonlit_ellenorzo_pontok(const void* x1, const void* x2){

    ELLENORZO_PONTOK* a = (ELLENORZO_PONTOK*) x1;
    ELLENORZO_PONTOK* b = (ELLENORZO_PONTOK*) x2;

    if(a->szabalytalansagok_szama != b->szabalytalansagok_szama)
        return b->szabalytalansagok_szama - a->szabalytalansagok_szama;
    else
        return strcmp(a->nev, b->nev);

}


int tipus_count(int osszes_elemszam, SZABALYSERTESEK* szs, char tipus[]){

    int db = 0;
    for(int i=0; i<osszes_elemszam; i++)
        if(strcmp(szs[i].szabalytalansag_tipusa, tipus) == 0)
            db++;
    return db;

}


int hasonlit_sebessegtullepes(const void* x1, const void* x2){

    SZABALYSERTESEK* a = (SZABALYSERTESEK*) x1;
    SZABALYSERTESEK* b = (SZABALYSERTESEK*) x2;

    if(a->sebessegtullepes != b->sebessegtullepes)
        return b->sebessegtullepes - a->sebessegtullepes;
    else
        return strcmp(a->rendszam, b->rendszam);

}


int hasonlit_rendszamok(const void* x1, const void* x2){

    SZABALYSERTESEK* a = (SZABALYSERTESEK*) x1;
    SZABALYSERTESEK* b = (SZABALYSERTESEK*) x2;

    return strcmp(a->rendszam, b->rendszam);

}


void kiir(FILE* fajl, int ellenorzo_pontok_szama, ELLENORZO_PONTOK* ep, int osszes_elemszam, SZABALYSERTESEK* szs){

    fprintf(fajl, "A honap soran %d birsag kerult kiszabasra, osszesen %lld forint ertekben.\n\n", osszes_elemszam, birsag_szum(osszes_elemszam, szs));

    fprintf(fajl, "Megoszlas ellenorzo pontok szerint:\n");
    qsort(ep, ellenorzo_pontok_szama, sizeof(ELLENORZO_PONTOK), hasonlit_ellenorzo_pontok);
    for(int i=0; i<ellenorzo_pontok_szama; i++)
        fprintf(fajl, "%0.2f%% - %s\n", ep[i].szabalytalansagok_szama /(double) osszes_elemszam * 100, ep[i].nev);
    fprintf(fajl, "\n");

    fprintf(fajl, "Megoszlas szabalysertes tipusa szerint:\n");
    fprintf(fajl, "%0.2f%% - %s\n", tipus_count(osszes_elemszam, szs, "gyorshajtas") /(double) osszes_elemszam * 100, "gyorshajtas");
    fprintf(fajl, "%0.2f%% - %s\n", tipus_count(osszes_elemszam, szs, "vasuti_atjaro") /(double) osszes_elemszam * 100, "vasuti_atjaro");
    fprintf(fajl, "%0.2f%% - %s\n", tipus_count(osszes_elemszam, szs, "piros_lampa") /(double) osszes_elemszam * 100, "piros_lampa");
    fprintf(fajl, "%0.2f%% - %s\n", tipus_count(osszes_elemszam, szs, "leallosav") /(double) osszes_elemszam * 100, "leallosav");
    fprintf(fajl, "%0.2f%% - %s\n", tipus_count(osszes_elemszam, szs, "behajtasi_tilalom") /(double) osszes_elemszam * 100, "behajtasi_tilalom");
    fprintf(fajl, "%0.2f%% - %s\n", tipus_count(osszes_elemszam, szs, "kotelezo_haladas") /(double) osszes_elemszam * 100, "kotelezo_haladas");
    fprintf(fajl, "%0.2f%% - %s\n", tipus_count(osszes_elemszam, szs, "korlatozott_zona") /(double) osszes_elemszam * 100, "korlatozott_zona");
    fprintf(fajl, "\n");

    if(tipus_count(osszes_elemszam, szs, "gyorshajtas") < 10)
        fprintf(fajl, "%d legnagyobb sebessegtullepes:\n", tipus_count(osszes_elemszam, szs, "gyorshajtas"));
    else
        fprintf(fajl, "10 legnagyobb sebessegtullepes:\n");
    qsort(szs, osszes_elemszam, sizeof(SZABALYSERTESEK), hasonlit_sebessegtullepes);
    int i = 0;
    while(szs[i].sebessegtullepes > 0 && i < 10){
        fprintf(fajl, "%s %s %s %s %d %d\n", szs[i].helyszin, szs[i].datum, szs[i].ido, szs[i].rendszam, szs[i].rogzitett_sebesseg-szs[i].sebessegtullepes, szs[i].rogzitett_sebesseg);
        i++;
    }
    fprintf(fajl, "\n");

    qsort(szs, osszes_elemszam, sizeof(SZABALYSERTESEK), hasonlit_rendszamok);
    int van_visszatero = 0;
    for(int i=1; i<osszes_elemszam; i++)
        if(strcmp(szs[i].rendszam, szs[i-1].rendszam) == 0){
            van_visszatero = 1;
            break;
        }
    if(van_visszatero)
        fprintf(fajl, "Visszatero szabalysertok:\n");
    else
        fprintf(fajl, "Nincs visszatero szabalyserto.\n");
    for(int i=1; i<osszes_elemszam; i++)
        if(strcmp(szs[i].rendszam, szs[i-1].rendszam) == 0){
            fprintf(fajl, "%s\n", szs[i].rendszam);
            while(strcmp(szs[i].rendszam, szs[i-1].rendszam) == 0)
                i++;
        }

}


int main(int argc, char* argv[]){

    FILE* fajl;
    ELLENORZO_PONTOK* ep = (ELLENORZO_PONTOK*) malloc(305 * sizeof(ELLENORZO_PONTOK));
    SZABALYSERTESEK* szs = (SZABALYSERTESEK*) malloc(100005 * sizeof(SZABALYSERTESEK));

    int elemszam_adott_ellenorzo_ponton = 0;
    int osszes_elemszam = 0;
    int ellenorzo_pontok_szama = 0;

    for(int i=1; i<argc; i++){
        fajl = fopen(argv[i], "r");
        elemszam_adott_ellenorzo_ponton = beolvas(fajl, ep, szs, osszes_elemszam, ellenorzo_pontok_szama);
        osszes_elemszam += elemszam_adott_ellenorzo_ponton;
        ellenorzo_pontok_szama++;
        fclose(fajl);
    }

    fajl = fopen("statisztika_2019_marcius.txt", "w");
    kiir(fajl, ellenorzo_pontok_szama, ep, osszes_elemszam, szs);
    fclose(fajl);
    free(szs);
    return 0;
}
