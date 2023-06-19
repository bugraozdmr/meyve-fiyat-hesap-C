#include <stdio.h>
#include <stdlib.h>



struct sepetler {
	struct meyveler {
		char name[20];
		int form, count, price;
	};
	float fiyat;
}sepet[2];

void meyve_ozellik(struct sepetler *a) {
	printf("meyvenin adi :"); fgets(a->name, sizeof(a->name), stdin);
	if (a->name[strlen(a->name) - 1] == '\n') {
		a->name[strlen(a->name) - 1] = '\0';
	}
	a->form = -1;
	while (a->form > 3 || a->form<0) {		//bu sekilde iki cevaptan birini alana kadar cikmayacak
		printf("meyvenin formu\n1.yuvarlak\n2.Kare\tkare nasil meyve olsun ???\ncevap :"); scanf("%d", &a->form);
	}
	printf("meyve gram :"); scanf("%d", &a->count);
	printf("meyve fiyati :"); scanf("%d", &a->price);
	getchar();		//sonda hata veriyor bosluk karakterini aliyor
}

float k=0;		//global degisken fiyat hesapliyor

void fiyat(struct sepetler* a) {
	//k degeri gelen 2 meyvenin fiyatlarini toplayacak ve istenilen yerden cagirilabiliyor
	if (a->form == 1) {
		k += (((float)a->price * (float)a->count) / 1000) * 2;
		if (a->count > 200) k += 3;
	}
	else {
		k += (float)a->price * (float)a->count / 1000 ;
		if (a->count > 200) k += 3;
	}
	
}

int main(){
	for (int i = 0; i < 2; i++) {
		meyve_ozellik(&sepet[i]);
		fiyat(&sepet[i]);
		printf("**********\n");
	}
	printf("sepet fiyati => %.2f", k);
}


