#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
	void intro(void);
	int oyun(void);
int main()
{
	int puanlar[10]={};
	int i = 0, score, oynayis, b;
	srand(time(NULL));
	printf("\t----\tMARS YOLCULUGU\t----\n");
	printf("    Mars Yolculugu oyununa hos geldiniz!\n   Devam etmek icin herhangi bir tusa basiniz...");
	getch();
	system("cls");
	intro();
		while(i<10)					//Oyun bittiginde tekrar baslatabilmek icin while dongusu.
		{
		system("cls");
		score=oyun();			//Oyunu baslatan fonksiyon.
		printf("\t----\tOYUN BITTI\t----\nPuanin: %d", score);
		printf("\t\nTekrar oynamak ister misin?(E/H)\n");
		puanlar[i] = score;
			i ++;
			oynayis ++;
		char a;
		scanf(" %c", &a);			//Cevabi kontrol eder.
			if (a == 'e'|| a == 'E')
				continue;
			else
			break;
		}
	printf("\t----\tPUANLAR\t----\n");
		for(b=1; b<9; b++)			//Puanlari yazdirir.
		{
			if(b>=oynayis)	break;	//Oynama sayisina ulasinca cikar.
			printf("\t%d. Oyun:\t%d puan\n", b, puanlar[b-1]);
		}
	printf("\tCikmak icin bir tusa bas...");
	fflush(stdin);
	getch();
	return 0;
}

void intro()
{
	char intro[4][100]={{"\tMarsa yolculuga hazir misin?\0"},{"\tDunyanin gozu senin uzerinde!\0"},{"Asteroidlere carpmadan uzay yolculugunu tamamla!\0"},{" Her carptigin asteroid kalkanina zarar verir.\0"}};
	int i,j;
	printf("\t----\tMARS YOLCULUGU\t----\n");
	for(i=0; i<4; i++)			//Giris cumlelerini harf harf yazdirir.
	{
		for(j=0; ; j++)
		{
			printf("%c", intro[i][j]);
			Sleep(50);
			if(intro[i][j]=='\0')
				break;
		}
		printf("\n");
	}
	Sleep(200);
	printf("\tDevam etmek icin bir tusa bas...\n");
	getch();
	system("cls");
	printf("\t----\tMARS YOLCULUGU\t----\n");
	printf("\tOyun basliyor hazir misin?\n");
	i=3;
	printf("\t  Yukleniyor");
	while(i>0){printf(" . "); Sleep(1000); i--;	}
	system("cls");
}



int oyun()
{
	char sirasatir[9][15]={{"              "},{"              "},{"              "},{"              "},{"              "},{"              "},{"              "},{"_______^______"},{"              "}};
	int i,j,a,b,c,k;
	int yon,tus,top;
	int sec = 7;
	int benzin = 1000;
	int puan = 5000;
	
	while(1)
	{
		
		a= rand()%14;
		printf("\t----\tMARS YOLCULUGU\t----\n\n");
		printf("\n\t----\tKalkan = %d\t----\n", puan);		
		b= rand()%14;
		printf("\n\t----\tBenzin = %d\t----\n\n", benzin);
		i=0;
		int yer = a;		
		c= rand()%14;
		if(benzin <= 300) sirasatir[0][b]='*';
		if(benzin <= 200) sirasatir[0][c]='*';
		printf("\t _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
		sirasatir[0][a]='*';
		for(i=0; i<8; i++)						//Ekrana sekli cizer.
	{
		printf("\t|");
		for(j=0; j<14; j++)
		{
			if(sirasatir[i][j]=='\0')
				break;
			printf("%c",sirasatir[i][j]);
			printf(" ");
		}
		printf("|\n");
	}
		printf("\n     (Araci ok tuslariyla hareket ettir.)");
		Sleep(100);
		system("cls");
		for(i=5; i>=0; i--)
		{
		strcpy(sirasatir[i+1],sirasatir[i]);	//En ust satiri en alta gelene kadar birer birer asagi kaydirir.
		strcpy(sirasatir[i],sirasatir[8]);
		}
		
		if(kbhit())								//Eger bir tusa basildiysa calisir
		{
		int tus = (int)getch();
			switch(tus)							//Basilan tusa gore aracin yerini degistirir.
			{
				case 75:						//Araci sola kaydirir.
				if(sec != 0)					//Aracin ekrandan cikmasini onler.
				{
					sirasatir[7][sec] = '_';
					sirasatir[7][sec-1] = '^';
					sec--;
				}
					break;
				case 77:						//Araci saga kaydirir.
				if(sec != 13)					//Aracin ekrandan cikmasini onler.
				{
					sirasatir[7][sec] = '_';
					sirasatir[7][sec+1] = '^';
					sec++;
				}
						break;
				case 81:
					return puan;
					break;
				case 113:
					return puan;
					break;
				default:
					break;
			}
		}
	
		for(i=0; i<14; i++)
			if(sirasatir[7][i] == '^' && sirasatir[6][i] == '*')	puan = puan - 50;			//Aracla goktasinin yeri ayni ise 50 puan azaltir.
		if(benzin == 0) break;																	//Benzin biittiðinde oynu bitirir.
		if(benzin <= 10) benzin -= 1;
		else benzin -= 10;
	}
	return puan;
}
	
