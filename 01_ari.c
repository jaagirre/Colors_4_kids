/*
Egilea:  jaagirre@mondragon.edu_____________________________
Ariketaren Describapena: Umeek koloreak eta formak ikasteko programa bat gauzatu behar duzue.
						Aplikazioak kolore desberdiñeko bi forma bistaratuko ditu eta programak
						kolore konkretu batengaitik galdetuko gaitu. Erabiltzaileak arratoia erabiliz
						forma bat aukeratuko du eta apliakzioak ondo egin duen esango dio. Kolore zuzena
						aukeratzen badu "Ondo egina X koloredun 'forma' aukeratu duzu." eta bestela 
					    "Aukeratutako forma ez da X koloretakoa Y baizik".
_____________________________________________________________________________________________________
Erabiltzaileari eman behar diogun hasierako datuak (zer eta nola/formatua/unitateak eta idnetifikadore bat)
(Datu formatuak: texto , zenbakia, bistaratzekoa, kalkulatua, unitateak, ....): 
	1)Bi karratu , bat kolore bateki eta beste bat beste kolore batekin. karratuak x0 eta y0 puntuak eta aldeen luzera edukiko dituzte ezaugarri lez.
		1.1)A karratua : (50, 50) puntuan eta alde bakoitza 100 pixel neurtuko ditu eta kolore bat edukiko du
		1.2)B karratua : (50, 50) puntuan eta alde bakoitza 100 pixel neurtuko ditu eta best ekolore bat edukiko du
	2)Testu bat erabiltzaileari egin behar duena adieraziz, hots , "X koloreko karratua hautatu"
		2.1)Alegiazkoa forma edo beti kolore berdian aukeratu (zenabki oso batekin 1=GORRIA 2=URDINA)
		2.2)esaldia, audio lez , "Zein karratu da gorria?"
_____________________________________________________________________________________________________
Erabiltzaileak eman behar dituen datuak eta nola/emango du datu horiek:
	1)Arratoia erabiliz form abaten edo beste baten  sakatuko du , hots , posizioa bat izango da. (x,y) formatuan
______________________________________________________________________________________________

Irteerako datuak/mezuak/irudiak:
	1)Igerri edo ez duen esaldi bat egomngo da
		1.1) Aplikazioak aukeratutako forma dagokion koloreko den edo ez kalkultau behar du. Hortarako iralurritako posizio
		a zein karratukoa den erabaki nehar dugu eta ondoren forma horren kolorea  (hau fluxu diagraman agertu beharko da)
		1.2)"Zorionak gorri  kolorea ondo aukeratu duzu!"
		1.3)"Ez duzu igerri, karratu urdina aukeratu duz eta ez gorria" 
___________________________________________________________________________________________

Balidapen konkretuak: (iguel balidapenak lehenego , edo ez????????????????)
B1 )
Sarrerak: 
	s1 : (50,50) posizioan 100 pixeleko karratu gorri bat
	s2:  (250, 50)  posizioan 100 pixeleko karratu urdina
	s3: "Zein da gorria?"
	e1: Erabiltzaileak (150, 80) posizioan sakatuko du, aprox.
Irteerak:"Ondo egina, karratu gorria ondo aukeratu duzu!"

B2 )
Sarrerak:
s1 : (50,50) posizioan 100 pixeleko karratu gorri bat
s2:  (250, 50)  posizioan 100 pixeleko karratu urdina
s3: "Zein da gorria?"
e1: Erabiltzaileak (280, 80) posizioan sakatuko du, aprox.
Irteerak:"Ez duzu igerri , karratu urdin asakatu duzu eta ez gorria!"

B3 )
Sarrerak:
s1 : (50,50) posizioan 100 pixeleko karratu gorri bat
s2:  (250, 50)  posizioan 100 pixeleko karratu urdina
s3: "Zein da gorria?"
e1: Erabiltzaileak (30, 30) posizioan sakatuko du, aprox.
Irteerak:"Ez duzu formarikaukeratu!"
___________________________________________________________________________________________________
Ariketa azpi-arazoetan banandu posible bada:
IT1:_Bi karratuak margotu
	Adibidez:
	Sarrerak: (50,50) posizioan 100 pixeleko karratu gorri bat
	Irteerak:_(250, 50)  posizioan 100 pixeleko karratu urdina
IT2:_Esaldia esan
	Sarrerak: Zein da gorria?"
	
IT3:__Erabilztailearen sakatu duenposizioa irakurri eta zein forma sakatu duen erabaki
	Sarrerak: Arratoiaren posizioa
	Irteerak:Zein forma sakatu duen
IT4:Kolore egokia edo desegfokia sakatu duen erabki eta dagokion mezua esan.
	Sarrerak: 
		Aukeratu duen kolorea
		Eta galdetu den kolorea
	Irteerak:
		Esan beharreko esaldia
*/

#include <stdio.h>

extern "C"{

#include "SDL.h"
#include "NewTypes.h"
#include "graphics.h"
#include "soinua.h"
#include "text.h"
#include "ebentoak.h"
#include "sagua.h"
}

#include "libt2s.h"

#define BOOLEAN  unsigned char 
#define	TRUE 1
#define FALSE 0


int main(int argc, char *argv[]){
	int x0 = 50;
	int y0 = 50;
	int x1 = 200;
	int y1 = 50;
	int tamaina = 100;
	int x = 0; 
	int y = 0;
	int tekla = 0;
	BOOLEAN igerria = FALSE;

	printf("Lehen ariketa .\n");
	/*Inicialziacimos el sistema grafico*/
	if (inicializaSistemaGrafico() == -1){
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		exit(1);
	}
	T2S_create();
	/*Algoritmo para pintar un cuadrado ROJO*/
	//Coloreentzako RGB dezimal formatuan : http://www.mathsisfun.com/hexadecimal-decimal-colors.html
	//******************************************************************************************
	//IT2
	//100 lerro margotuko ditugu
	for (y = y0; y < y0 + 100; y++){
		//orain lerro bat 100 puntuz margotuko dugu
		for (x = x0; x < x0 + 100; x++){
			plot(x, y, 16711680);
		}
	}
	for (y = y1; y < y1 + 100; y++){
		//orain lerro bat 100 puntuz margotuko dugu
		for (x = x1; x < x1 + 100; x++){
			plot(x, y, 255);
		}
	}
	//*****************************************************************************
	//IT3
	actualizaPantalla();
	T2S_play("Aplikazioa honen helburua koloreak ikastea da.");
	T2S_play("Mesedez aukeratu karratu gorria?");
	//*************************************************************************************
	//IT4
	do{
		tekla = ebentoaEntzun();
	} while (tekla != SAGU_BOTOIA_EZKERRA);
	
	//x-k konprobatu
	if (sagua.x > x0 && sagua.x < x0 + 100){
		if (sagua.y > y0 && sagua.y < y0 + 100){
			igerria = TRUE;
		}
	}
	
	if (igerria){
		T2S_play("Zorionak!! Karratu gorria aukeratu duzu!");
	}
	else{
		T2S_play("Ez duzu karratu gorria aukeratu. Saiatu berriro be!");
	}
		
	printf("Sakatu return bukatzeko...");
	finalizaSistemaGrafico();
	T2S_destroy();
	getchar();
	return 0;
}