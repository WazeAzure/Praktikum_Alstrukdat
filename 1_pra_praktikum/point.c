// Nama	: Edbert Eddyson Gunawan
// NIM	: 13522039
//
// File: point.c
// Tanggal: 31 Agustus 2023
#include <stdio.h>
#include "point.h"
#include <math.h>
#include "boolean.h"

void CreatePoint (POINT * P, float X, float Y){
// Membentuk sebuah POINT dari komponen-komponennya	
	Absis(*P) = X;
	Ordinat(*P) = Y;	
}

void BacaPOINT(POINT * P){
	float X, Y;

	scanf("%f %f", &X, &Y);

	CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P){
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2){
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ(POINT P1, POINT P2){
	return !EQ(P1, P2);
}

boolean IsOrigin(POINT P){
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX(POINT P){
	return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P){
	return (Absis(P) == 0);
}

int Kuadran(POINT P){
	if (!IsOrigin(P) && !IsOnSbX(P) && !IsOnSbY(P)){
		if(Absis(P) > 0 && Ordinat(P) > 0) return 1;
		else if (Absis(P) < 0 && Ordinat(P) > 0) return 2;
		else if(Absis(P) < 0 && Ordinat(P) < 0) return 3;
		else if(Absis(P) > 0 && Ordinat(P) < 0) return 4;
	}
}

POINT NextX(POINT P){
	POINT P2;

	CreatePoint(&P2, Absis(P)+1, Ordinat(P));

	return P2;
}

POINT NextY(POINT P){
	POINT P2;
	
	CreatePoint(&P2, Absis(P), Ordinat(P)+1);
	
	return P2;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY){
	POINT P2;

	CreatePoint(&P2, Absis(P) + deltaX, Ordinat(P) + deltaY);

	return P2;
}

POINT MirrorOf(POINT P, boolean SbX){
	POINT P2;
	// SbX ^ 0			SbX ^ 1
	if(SbX) CreatePoint(&P2, Absis(P), -Ordinat(P));
	else CreatePoint(&P2, -Absis(P), Ordinat(P));
	
	return P2;
}

float Jarak0(POINT P){
	return sqrt((Absis(P) * Absis(P)) + (Ordinat(P) * Ordinat(P)));
}

float Panjang(POINT P1, POINT P2){
	return sqrt(pow(Absis(P2) - Absis(P1), 2) + pow(Ordinat(P2) - Ordinat(P1), 2)); 
}

void Geser(POINT *P, float deltaX, float deltaY){
	Absis(*P) = Absis(*P) + deltaX;
	Ordinat(*P) = Ordinat(*P) + deltaY;
}

void GeserKeSbX(POINT *P){
	Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P){
	Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX){
	if(Absis(*P) != 0 && Ordinat(*P) != 0){
		if(!SbX) Absis(*P) = -Absis(*P);
		else Ordinat(*P) = -Ordinat(*P);
	}
}

void Putar(POINT *P, float Sudut){
	float rad = Sudut * M_PI / 180;
 	float x = Absis(*P);
	float y = Ordinat(*P);
	Absis(*P) = x*cos(rad)+y*sin(rad);
	Ordinat(*P) = -x * sin(rad)+y*cos(rad);	
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2){
	int m = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
	int a = m;
	int b = Ordinat(P1) - (m * Absis(P1));

	printf("(%d,%d)", a, b);
}

