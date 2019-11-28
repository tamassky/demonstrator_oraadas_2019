#include <stdio.h>
#include <stdlib.h>

int compareFiles(FILE *fp1, FILE *fp2)
{
    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    int error = 0, pos = 0, line = 1;

    while (ch1 != EOF || ch2 != EOF)
    {
        pos++;

        if (ch1 == '\n' && ch2 == '\n')
        {
            line++;
            pos = 0;
        }

        if (ch1 != ch2)
        {
            error++;
            printf("Hiba! Sor: %d, pozicio: %d \n", line, pos);
            return error;
        }

        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }

    return error;
}

int main()
{
    FILE* out;
    FILE* ok;
    int elfogadva = 0;

    remove("t1out.txt");
    remove("t2out.txt");
    remove("0out.txt");
    remove("1out.txt");
    remove("2out.txt");
    remove("3out.txt");
    remove("4out.txt");
    remove("5out.txt");
    remove("6out.txt");
    remove("7out.txt");
    remove("8out.txt");
    remove("9out.txt");

    int hiba=-1;
    system("main t1debrecen_33.csv t1nyiregyhaza_m3_jobb.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("t1megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        puts("1. minta teszteset: OK!");
    }
    else
        puts("1. minta teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "t1out.txt");



    hiba=-1;
    system("main t2bocskaikert.csv t2debrecen_jozsa_35.csv t2dunakeszi.csv t2szigetvar_67.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("t2megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        puts("2. minta teszteset: OK!\n");
    }
    else
        puts("2. minta teszteset: ERROR!\n");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "t2out.txt");



    hiba=-1;
    system("main 0szekesfehervar.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("0megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("0. teszteset: OK!");
    }
    else
        puts("0. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "0out.txt");



    hiba=-1;
    system("main 1balatonkenese.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("1megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("1. teszteset: OK!");
    }
    else
        puts("1. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "1out.txt");



    hiba=-1;
    system("main 2solymar.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("2megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("2. teszteset: OK!");
    }
    else
        puts("2. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "2out.txt");



    hiba=-1;
    system("main 3solymar.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("3megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("3. teszteset: OK!");
    }
    else
        puts("3. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "3out.txt");



    hiba=-1;
    system("main 4nyiregyhaza.csv 4mateszalka.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("4megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("4. teszteset: OK!");
    }
    else
        puts("4. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "4out.txt");



    hiba=-1;
    system("main 5nyiregyhaza.csv 5mateszalka.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("5megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("5. teszteset: OK!");
    }
    else
        puts("5. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "5out.txt");



    hiba=-1;
    system("main 6solymar.csv 6szekesfehervar.csv 6nyiregyhaza.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("6megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("6. teszteset: OK!");
    }
    else
        puts("6. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "6out.txt");



    hiba=-1;
    system("main 7szekesfehervar.csv 7solymar.csv 7balatonkenese.csv 7cegled.csv 7nyiregyhaza.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("7megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("7. teszteset: OK!");
    }
    else
        puts("7. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "7out.txt");



    hiba=-1;
    system("main 8ep1.csv 8ep2.csv 8ep3.csv 8ep4.csv 8ep5.csv 8ep6.csv 8ep7.csv 8ep8.csv 8ep9.csv 8ep10.csv 8ep11.csv 8ep12.csv 8ep13.csv 8ep14.csv 8ep15.csv 8ep16.csv 8ep17.csv 8ep18.csv 8ep19.csv 8ep20.csv 8ep21.csv 8ep22.csv 8ep23.csv 8ep24.csv 8ep25.csv 8ep26.csv 8ep27.csv 8ep28.csv 8ep29.csv 8ep30.csv 8ep31.csv 8ep32.csv 8ep33.csv 8ep34.csv 8ep35.csv 8ep36.csv 8ep37.csv 8ep38.csv 8ep39.csv 8ep40.csv 8ep41.csv 8ep42.csv 8ep43.csv 8ep44.csv 8ep45.csv 8ep46.csv 8ep47.csv 8ep48.csv 8ep49.csv 8ep50.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("8megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("8. teszteset: OK!");
    }
    else
        puts("8. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "8out.txt");



    hiba=-1;
    system("main 9ep1.csv 9ep2.csv 9ep3.csv 9ep4.csv 9ep5.csv 9ep6.csv 9ep7.csv 9ep8.csv 9ep9.csv 9ep10.csv 9ep11.csv 9ep12.csv 9ep13.csv 9ep14.csv 9ep15.csv 9ep16.csv 9ep17.csv 9ep18.csv 9ep19.csv 9ep20.csv 9ep21.csv 9ep22.csv 9ep23.csv 9ep24.csv 9ep25.csv 9ep26.csv 9ep27.csv 9ep28.csv 9ep29.csv 9ep30.csv 9ep31.csv 9ep32.csv 9ep33.csv 9ep34.csv 9ep35.csv 9ep36.csv 9ep37.csv 9ep38.csv 9ep39.csv 9ep40.csv 9ep41.csv 9ep42.csv 9ep43.csv 9ep44.csv 9ep45.csv 9ep46.csv 9ep47.csv 9ep48.csv 9ep49.csv 9ep50.csv 9ep51.csv 9ep52.csv 9ep53.csv 9ep54.csv 9ep55.csv 9ep56.csv 9ep57.csv 9ep58.csv 9ep59.csv 9ep60.csv 9ep61.csv 9ep62.csv 9ep63.csv 9ep64.csv 9ep65.csv 9ep66.csv 9ep67.csv 9ep68.csv 9ep69.csv 9ep70.csv 9ep71.csv 9ep72.csv 9ep73.csv 9ep74.csv 9ep75.csv 9ep76.csv 9ep77.csv 9ep78.csv 9ep79.csv 9ep80.csv 9ep81.csv 9ep82.csv 9ep83.csv 9ep84.csv 9ep85.csv 9ep86.csv 9ep87.csv 9ep88.csv 9ep89.csv 9ep90.csv 9ep91.csv 9ep92.csv 9ep93.csv 9ep94.csv 9ep95.csv 9ep96.csv 9ep97.csv 9ep98.csv 9ep99.csv 9ep100.csv 9ep101.csv 9ep102.csv 9ep103.csv 9ep104.csv 9ep105.csv 9ep106.csv 9ep107.csv 9ep108.csv 9ep109.csv 9ep110.csv 9ep111.csv 9ep112.csv 9ep113.csv 9ep114.csv 9ep115.csv 9ep116.csv 9ep117.csv 9ep118.csv 9ep119.csv 9ep120.csv 9ep121.csv 9ep122.csv 9ep123.csv 9ep124.csv 9ep125.csv 9ep126.csv 9ep127.csv 9ep128.csv 9ep129.csv 9ep130.csv 9ep131.csv 9ep132.csv 9ep133.csv 9ep134.csv 9ep135.csv 9ep136.csv 9ep137.csv 9ep138.csv 9ep139.csv 9ep140.csv 9ep141.csv 9ep142.csv 9ep143.csv 9ep144.csv 9ep145.csv 9ep146.csv 9ep147.csv 9ep148.csv 9ep149.csv 9ep150.csv 9ep151.csv 9ep152.csv 9ep153.csv 9ep154.csv 9ep155.csv 9ep156.csv 9ep157.csv 9ep158.csv 9ep159.csv 9ep160.csv 9ep161.csv 9ep162.csv 9ep163.csv 9ep164.csv 9ep165.csv 9ep166.csv 9ep167.csv 9ep168.csv 9ep169.csv 9ep170.csv 9ep171.csv 9ep172.csv 9ep173.csv 9ep174.csv 9ep175.csv 9ep176.csv 9ep177.csv 9ep178.csv 9ep179.csv 9ep180.csv 9ep181.csv 9ep182.csv 9ep183.csv 9ep184.csv 9ep185.csv 9ep186.csv 9ep187.csv 9ep188.csv 9ep189.csv 9ep190.csv 9ep191.csv 9ep192.csv 9ep193.csv 9ep194.csv 9ep195.csv 9ep196.csv 9ep197.csv 9ep198.csv 9ep199.csv 9ep200.csv 9ep201.csv 9ep202.csv 9ep203.csv 9ep204.csv 9ep205.csv 9ep206.csv 9ep207.csv 9ep208.csv 9ep209.csv 9ep210.csv 9ep211.csv 9ep212.csv 9ep213.csv 9ep214.csv 9ep215.csv 9ep216.csv 9ep217.csv 9ep218.csv 9ep219.csv 9ep220.csv 9ep221.csv 9ep222.csv 9ep223.csv 9ep224.csv 9ep225.csv 9ep226.csv 9ep227.csv 9ep228.csv 9ep229.csv 9ep230.csv 9ep231.csv 9ep232.csv 9ep233.csv 9ep234.csv 9ep235.csv 9ep236.csv 9ep237.csv 9ep238.csv 9ep239.csv 9ep240.csv 9ep241.csv 9ep242.csv 9ep243.csv 9ep244.csv 9ep245.csv 9ep246.csv 9ep247.csv 9ep248.csv 9ep249.csv 9ep250.csv 9ep251.csv 9ep252.csv 9ep253.csv 9ep254.csv 9ep255.csv 9ep256.csv 9ep257.csv 9ep258.csv 9ep259.csv 9ep260.csv 9ep261.csv 9ep262.csv 9ep263.csv 9ep264.csv 9ep265.csv 9ep266.csv 9ep267.csv 9ep268.csv 9ep269.csv 9ep270.csv 9ep271.csv 9ep272.csv 9ep273.csv 9ep274.csv 9ep275.csv 9ep276.csv 9ep277.csv 9ep278.csv 9ep279.csv 9ep280.csv 9ep281.csv 9ep282.csv 9ep283.csv 9ep284.csv 9ep285.csv 9ep286.csv 9ep287.csv 9ep288.csv 9ep289.csv 9ep290.csv 9ep291.csv 9ep292.csv 9ep293.csv 9ep294.csv 9ep295.csv 9ep296.csv 9ep297.csv 9ep298.csv 9ep299.csv 9ep300.csv");
    out = fopen("statisztika_2019_marcius.txt", "r");
    ok = fopen("9megoldas.txt", "r");
    hiba = compareFiles(out, ok);
    if(hiba==0){
        elfogadva++;
        puts("9. teszteset: OK!");
    }
    else
        puts("9. teszteset: ERROR!");
    fclose(out);
    fclose(ok);
    rename("statisztika_2019_marcius.txt", "9out.txt");




    printf("\nElfogadott tesztesetek: %d/10\n\n", elfogadva);
    char a;
    getc(a);
    return 0;
}
