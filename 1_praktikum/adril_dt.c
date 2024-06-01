# include "datetime.h"
# include <stdio.h>

int GetMaxDay(int M, int Y){
    if (M == 2){
        if ((!(Y % 4) && (Y % 100)) || !(Y % 400)) return 29;
        else return 28;
    }
    else if(1 <= M && M <= 7){
        if (M & 1) return 31;
        else return 30;
    }
    else{
        if (M & 1) return 30;
        else return 31;
    }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
    return ((1900 <= Y && Y <= 2030) && (1 <= M && M <= 12) && (1 <= D && D <= GetMaxDay(M, Y)) && IsTIMEValid(h, m, s));
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
    Year(*D) = YYYY;
    Month(*D) = MM;
    Day(*D) = DD;
    CreateTime(&Time(*D), hh, mm, ss);
}

void BacaDATETIME(DATETIME *D){
    int DD, MM, YY, h, m, s;
    scanf("%d%d%d%d%d%d", &DD, &MM, &YY, &h, &m, &s);
    while (!IsDATETIMEValid(DD, MM, YY, h, m, s))
    {
        printf("DATETIME tidak valid\n");
        scanf("%d%d%d%d%d%d", &DD, &MM, &YY, &h, &m, &s);
    }
    CreateDATETIME(D, DD, MM, YY, h, m, s);
}

void TulisDATETIME(DATETIME D){
    printf("%d/%d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

boolean DEQ(DATETIME D1, DATETIME D2){
    return ((Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) == Day(D2)) && TEQ(Time(D1), Time(D2)));
}

boolean DNEQ(DATETIME D1, DATETIME D2){
    return !DEQ(D1, D2);
}

boolean DLT(DATETIME D1, DATETIME D2){
    return ((Year(D1) < Year(D2)) || (Year(D1) == Year(D2) && Month(D1) < Month(D2)) || (Year(D1) == Year(D2) && Month(D1) == Month(D2) && Day(D1) < Day(D2)) || (Year(D1) == Year(D2) && Month(D1) == Month(D2) && Day(D1) == Day(D2) && TLT(Time(D1), Time(D2))));
}

boolean DGT(DATETIME D1, DATETIME D2){
    return DLT(D2, D1);
}

DATETIME DATETIMENextNDetik(DATETIME D, int N){
    int hariTambah = N / 86400;
    if (TIMEToDetik(Time(D)) + N % 86400 >= 86400) hariTambah++;
    Time(D) = NextNDetik(Time(D), N % 86400);
    for (int i = 0; i < hariTambah; i++){
        if (Day(D) + 1 > GetMaxDay(Month(D), Year(D))){
            Day(D) = 1;
            if (Month(D) == 12){
                Month(D) = 1;
                Year(D)++;
            }
            else{
                Month(D)++;
            }
        }
        else{
            Day(D)++;
        }
    }
    return D;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    int hariKurang = N / 86400;
    if (TIMEToDetik(Time(D)) - (N % 86400) < 0) hariKurang++;
    Time(D) = PrevNDetik(Time(D), N % 86400);
    for (int i = 0; i < hariKurang; i++){
        if (Day(D) - 1 < 1){
            if (Month(D) == 1){
                Year(D)--;
                Month(D) = 12;
                Day(D) = 31;
            }
            else{
                Month(D)--;
                Day(D) = GetMaxDay(Month(D), Year(D));
            }
        }
        else{
            Day(D)--;
        }
    }
    return D;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME Dakh){
    // Hitung Detik Akhir
    long int detikAkhir = Year(Dakh) * 365 + Day(Dakh);
    for (int i = 0; i < Month(Dakh) - 1; i++){
        detikAkhir += GetMaxDay(i + 1, Year(Dakh));
    }
    detikAkhir += ((Year(Dakh) - 1)/4) - ((Year(Dakh) - 1)/100) + ((Year(Dakh) - 1)/400);

    // Hitung Detik Awal
    long int detikAwal = Year(DAw) * 365 + Day(DAw);
    for (int i = 0; i < Month(DAw) - 1; i++){
        detikAwal +=  GetMaxDay(i + 1, Year(DAw));
    }
    detikAwal += ((Year(DAw) - 1)/4 - (Year(DAw) - 1)/100 + (Year(DAw) - 1)/400);
    return (detikAkhir - detikAwal) * 86400 + TIMEToDetik(Time(Dakh)) - TIMEToDetik(Time(DAw));
}