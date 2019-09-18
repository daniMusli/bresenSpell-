#include<GL/Glut.h> 
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<locale.h> 
#include <string>
#include <algorithm>
char secenek, secenekLatin, secenekPoligon;
std::string secenekJaponca;
// Bu Uygulama Bresenham Doğru Çizim Algoritmasının Demosu için yazdik uygulamizin anamenusunda 
// 4 tane secenek olup latin japonca veya bir polygon olmak uzere cizgilerle gosterebiliriz 
void poligonMenu() // poligon menusu icin 
{
	system("cls");
	std::cout << "\nLütfen asagidakilerden bir seçenek seçeniz :\n";
	std::cout << "1.Ucgen Ciz\n";
	std::cout << "2.dortgen Ciz\n";
	std::cout << "3.besgen Ciz\n";
	std::cout << "\nSecenek : ";
	std::cin >> secenekPoligon;
}
void japoncaMenu() // japonca karakter menusu 
{

	system("cls");
	std::cout << "\nLütfen asagidakilerden bir seçenek seçeniz :\n";
	std::cout << "bu karakterlerden bir karakter giriniz ki/ko/ni/yo\n";
	std::cout << "\nSecenek : ";
	std::cin >> secenekJaponca;
}
void latinMenu() // latince karakter menusu 
{
	system("cls");
	std::cout << "\nLütfen asagidakilerden bir seçenek seçeniz :\n";
	std::cout << "bu karakterlerden bir karakter giriniz A/F/E/V\n";
	std::cout << "\nSecenek : ";
	std::cin >> secenekLatin;


}
void mainMenu() // ana menusu 
{
	std::cout << "\nLütfen asagidakilerden bir seçenek seçeniz :\n";
	std::cout << "1. Latin karakter çiz\n";
	std::cout << "2. japonca karakter çiz\n";
	std::cout << "3. poligon sekli çiz\n";
	std::cout << "4. programi sonlandir\n";
	std::cout << "Secenek : ";
	std::cin >> secenek;
}
void myinit(void) // init fonksiyon
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // color buffer temizlemek icin 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // id matrix ile varolan matrisi carp
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0); // sol sag ust alt olarak sirayla portview boyutlari belirtmesi
}
 
void putPixel(int x, int y) // bir nokta render etmek icin 
{
	glBegin(GL_POINTS); // noktalar gostermek uzere bir gl ortami ac 
	glVertex2i(x, y); //iki boyut olarak integer degerleri alip bir nokta ciz
	glEnd();
}
void bressen(int x0, int y0, int x1, int y1) // bresenham algoritmasinin fonksiyonu 
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int x, y;
	if (dx >= dy) // eger m<1 ise 
	{
		int d = 2 * dy - dx; // karar degisken baslangic degeri 
		int ds = 2 * dy; // dogu ilk degeri
		int dt = 2 * (dy - dx); // kuzey dogu ilk degeri 
		if (x0 < x1) 
		{
			x = x0;
			y = y0;
		}
		else
		{
			x = x1; // swap islemi yap 
			y = y1;
			x1 = x0;
			y1 = y0;
		}
		putPixel(x, y);
		while (x < x1)
		{
			if (d < 0)
				d += ds; // nokta dogrunun ustunde doguya git 
			else // kuzey doguya git 
			{
				if (y < y1)
				{
					y++;
					d += dt;
				}
				else
				{
					y--;
					d += dt;
				}
			}
			x++;
			putPixel(x, y);
		}
	}
	else // m>1 ise  simdi y ye gore yapacaz 
	{ 
		int d = 2 * dx - dy; 
		int ds = 2 * dx;
		int dt = 2 * (dx - dy);
		if (y0 < y1)
		{
			x = x0;
			y = y0;
		}
		else
		{ // swap 
			x = x1;
			y = y1;
			y1 = y0;
			x1 = x0;
		}
		putPixel(x, y);
		while (y < y1)
		{
			if (d < 0) // batiya git 
				d += ds;
			else // guney batiya git 
			{
				if (x > x1)
				{
					x--;
					d += dt;
				}
				else
				{
					x++;
					d += dt;
				}
			}
			y++;
			putPixel(x, y);
		}
	}
	glutPostRedisplay();
}



void displayA(void)  
{

	glClear(GL_COLOR_BUFFER_BIT); // renk bufferi temizle   
	glColor3f(1, 0.2, 0); //  renk orange olarak ayarla
	glPointSize(4); // her nokta kac tane pixel ayarla
	// A ciz
	bressen(0, 0, 100, 200);
	bressen(100, 200, 200, 0);
	bressen(50, 100, 150, 100);
	glFlush(); // frame bufferin icindeki degerleri ekrana yansit 
}
void displayE(void)
{
	glClear(GL_COLOR_BUFFER_BIT);      
	glColor3f(1, 0.2, 0); 
	glPointSize(4); 
	// Drawing an E

	bressen(0, 200, 100, 200);
	bressen(0, 200, 0, 0);
	bressen(0, 100, 100, 100);
	bressen(0, 0, 100, 0);
	glFlush(); 
}
void displayF(void)
{

	glClear(GL_COLOR_BUFFER_BIT);   
	glColor3f(1, 0.2, 0); 
	glPointSize(4); 

	bressen(0, 100, 0, -120);
	bressen(0, 0, 87, 0);
	bressen(0, 100, 100, 100);

	glFlush(); 
}
void displayV(void)
{

	glClear(GL_COLOR_BUFFER_BIT);      
	glColor3f(1, 0.2, 0); 
	glPointSize(4); 
	// drawing a V 
	bressen(-100, 200, 0, 0);
	bressen(0, 0, 100, 200);
	glFlush(); 
}
void displayKI(void)
{

	glClear(GL_COLOR_BUFFER_BIT);   
	glColor3f(1, 0.2, 0); 
	glPointSize(4); 
	// drawing a KI 
	bressen(-30, 200, 0, 0);
	bressen(-70, 140, 30, 160);
	bressen(-76, 110, 36, 130);

	glFlush(); // flushes the frame buffer to the screen
}
void displayKO(void)
{

	glClear(GL_COLOR_BUFFER_BIT);      
	glColor3f(1, 0.2, 0); 
	glPointSize(4); 
	// drawing a KO 
	bressen(0, 0, 200, 0);
	bressen(200, 0, 200, 180);
	bressen(200, 180, 0, 180);

	glFlush(); 
}
void displayNI(void)
{

	glClear(GL_COLOR_BUFFER_BIT);    
	glColor3f(1, 0.2, 0); 
	glPointSize(4); 
	// drawing a NI 
	bressen(0, 0, 200, 0);
	bressen(30, 70, 170, 70);


	glFlush();
}
void displayYO(void)
{

	glClear(GL_COLOR_BUFFER_BIT);    
	glColor3f(1, 0.2, 0);
	glPointSize(4); 
	// drawing a NI 
	bressen(0, 0, 200, 0);
	bressen(200, 0, 200, 300);
	bressen(200, 150, 0, 150);
	bressen(200, 300, 0, 300);
	glFlush(); // flushes the frame buffer to the screen
}
void displayUcgen(void)
{

	glClear(GL_COLOR_BUFFER_BIT);    
	glColor3f(1, 0.2, 0);
	glPointSize(4);
	// drawing a triangle 
	bressen(0, 0, 100, 200);
	bressen(100, 200, 200, 0);
	bressen(0, 0, 200, 0);
	glFlush(); // flushes the frame buffer to the screen

}
void displayDortgen(void)
{

	glClear(GL_COLOR_BUFFER_BIT);    
	glColor3f(1, 0.2, 0); 
	glPointSize(4);
	// drawing a quadrangle 
	bressen(0, 0, 200, 0);
	bressen(0, 0, 100, 100);
	bressen(100, 100, 300, 100);
	bressen(200, 0, 300, 100);
	glFlush(); // flushes the frame buffer to the screen

}
void displayBesgen(void)
{

	glClear(GL_COLOR_BUFFER_BIT);  
	glColor3f(1, 0.2, 0);
	glPointSize(4); 
	// drawing a star
	bressen(0, 0, 100, 200);
	bressen(100, 200, 200, 0);
	bressen(220, 140, -20, 140);
	bressen(0, 0, 220, 140);
	bressen(200, 0, -20, 140);
	glFlush();

}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Turkish");
	while (1)
	{
		mainMenu();

		switch (secenek)
		{
		case '1':
			latinMenu();
			secenekLatin = toupper(secenekLatin);
			switch (secenekLatin)
			{
			case 'A':
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);// glut ekranin boyutlari ayarla width ve height 
				glutInitWindowPosition(500, 500);// gut ekrani bilgisayarin ekrani nereye gozuksun 
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");// belirledigimiz ayarlarla bir tane glut pencereyi olusturur
				myinit();
				glutDisplayFunc(displayA);// display olayi ve display olay kontrolcu link yapmak icim 
				glutMainLoop();// varolan olayi tekrarla 
			case 'E':
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayF);
				glutMainLoop();
			case 'F':
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayF);
				glutMainLoop();
			case 'V':
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayV);
				glutMainLoop();
			}
		case '2':
			japoncaMenu();
			std::transform(secenekJaponca.begin(), secenekJaponca.end(), secenekJaponca.begin(), ::toupper);
			if (secenekJaponca == "KI")
			{
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayKI);
				glutMainLoop();
			}
			if (secenekJaponca == "KO")
			{
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayKO);
				glutMainLoop();
			}
			if (secenekJaponca == "NI")
			{
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayNI);
				glutMainLoop();
			}
			if (secenekJaponca == "YO")
			{
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayYO);
				glutMainLoop();
			}

		case '3':
			poligonMenu();
			switch (secenekPoligon)
			{
			case '1':
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayUcgen);
				glutMainLoop();
			case '2':
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru");
				myinit();
				glutDisplayFunc(displayDortgen);
				glutMainLoop();
			case '3':
				glutInit(&argc, argv);
				glutInitWindowSize(640, 480);
				glutInitWindowPosition(500, 500);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutCreateWindow("Bilgisayar Grafigi 2.soru ");
				myinit(); 
				glutDisplayFunc(displayBesgen);
				glutMainLoop(); 
			}

		case '4': // kullanci 4 girerse program sonlansin
			exit(0);
		default: // kullanci yanlis bir secenek girerse 
			std::cout << "\nYanlis bir secenek girdiniz lutfen tekrar Deneyiniz..\n\n";

		}
	}


}