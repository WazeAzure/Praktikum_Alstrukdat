#include <stdio.h>
#include "point.h"
#include "point.c"

int main(){
	POINT start, end, origin;
	BacaPOINT(&start);
	BacaPOINT(&end);
	BacaPOINT(&origin);

	TulisPOINT(start);
	printf("\n");
	TulisPOINT(end);
	printf("\n");
	TulisPOINT(origin);
	printf("\n");

	printf("%d\n", EQ(start, end));
	printf("%d\n", NEQ(start, end));
	printf("%d\n", IsOrigin(origin));
	printf("Sb-x %d\n", IsOnSbX(start));
	printf("Sb-y %d\n", IsOnSbY(end));
	printf("kuadran start %d\n", Kuadran(start));
	printf("kuadran end %d\n", Kuadran(end));
	printf("kuadran origin %d\n", Kuadran(origin));
	TulisPOINT(NextX(start));
	TulisPOINT(NextY(start));
	POINT p2 = PlusDelta(start, 0, -2);
	
	printf("Jarak0 end - %f\n", Jarak0(p2));
	printf("Panjang start - end - %f\n", Panjang(start, end));

	TulisPOINT(p2);

	Geser(&p2, 1, 2);
	TulisPOINT(p2);

	printf("\n");

	GeserKeSbX(&p2);
	TulisPOINT(p2);

	printf("\n");
	
	GeserKeSbY(&p2);
	TulisPOINT(p2);

	printf("\n");
	
	TulisPOINT(MirrorOf(origin, true));

	printf("\n");

	Mirror(&p2, 1);
	TulisPOINT(p2);

	printf("\n");
	
	Putar(&p2, 90);
	TulisPOINT(p2);

	PersamaanLinearDuaVariabel(start, end);
	return 0;
}
