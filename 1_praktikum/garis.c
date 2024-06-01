#include <stdio.h>
#include "garis.h"
#include <math.h>

void CreateGaris(GARIS *L, POINT P1, POINT P2){
	// I.F. P1 & P2 terdefinisi
	// F.S. terdefinisi dengan L.PAw = P1 dan L.PAkh = P2.
	// Membentuk sebuah L dari komponen-komponennya
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}

void BacaGARIS(GARIS *L){
	// I.S. Sembarang
	// F.S. Terdefinisi
	
	POINT P1, P2;
	BacaPOINT(&P1);
	BacaPOINT(&P2);

	while(EQ(P1, P2)){
		printf("Garis tidak valid\n");
		BacaPOINT(&P1);
		BacaPOINT(&P2);
	}
	
	CreateGaris(L, P1, P2);
}

void TulisGARIS(GARIS L){
	// I.S. L Terdefinisi
	// F.S. Tertulis di layar dengan format
	
	printf("(");
	TulisPOINT(PAwal(L));
	printf(",");
	TulisPOINT(PAkhir(L));
	printf(")");
}

float PanjangGARIS(GARIS L){
	return Panjang(PAwal(L), PAkhir(L));
}

float Gradien(GARIS L){
	return ((Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Absis(PAwal(L))));
}

void GeserGARIS(GARIS *L, float deltaX, float deltaY){
	Geser(&PAwal(*L), deltaX, deltaY);
	Geser(&PAkhir(*L), deltaX, deltaY);
}

boolean IsTegakLurus(GARIS L1, GARIS L2){
	return (Gradien(L1) * Gradien(L2) == -1);
}

boolean IsSejajar(GARIS L1, GARIS L2){
	return Gradien(L1) == Gradien(L2);
}

float JarakGARIS(GARIS L, POINT P){
	// y - y1 = (y2 - y1)/(x2 - x1) * (x - x1)
	// (x2 - x1)y - y1(x2 - x1) = (y2 - y1)x - (y2 - y1)x1
	// (y1 - y2)x + (x2 - x1)y + x1(y2 - y1) - y1(x2 - x1) = 0
	// Ax + By + C = 0
	
	float A = Ordinat(PAwal(L)) - Ordinat(PAkhir(L));
	float B = Absis(PAkhir(L)) - Absis(PAwal(L));
	float C = Absis(PAwal(L)) * (-A) - Ordinat(PAwal(L)) * (B);
	return (A*Absis(P) + B*Ordinat(P) + C) / sqrt(A*A + B*B);
}

boolean IsPointMemenuhiGaris(GARIS L, POINT P){
	if(JarakGARIS(L, P) == 0) return true;
	return false;
}
