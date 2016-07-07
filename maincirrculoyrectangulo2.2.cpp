#include <iostream>
#include <math.h>


const float PI=3.14;
float radio;
float perimetro;
float c;
float h;

struct Punto{double x, y;};
struct Triangulo{struct Punto trngA, trngB, trngC;};



float farea(float a){  //funcion  para calcular area de circulo//
	return PI*radio*radio;
}



float parea(float a)
	{                                 //funcion para perimetro del circulo//
		return 2*PI*radio;
	}


	float arectangulo (float a , float b)
	{                                     // funcio para area de rectangulo//
		return (c*h);
	}

	float perimetrodelrectangulo(float a , float b){

		return 2*(c+h);
	}

//calcula la distancia geometrica de dos puntos en el plano
double distanciaEntre2Puntos(struct Punto puntoA, struct Punto puntoB){
	return
		sqrt(
			pow(puntoA.x - puntoB.x , 2) +
     		pow(puntoA.y - puntoB.y , 2)
		);
}

//suma las distancias entre los puntos de un triangulo dado
double perimetroTriangulo(struct Triangulo triangulo){
	return distanciaEntre2Puntos(triangulo.trngA, triangulo.trngB) +
		distanciaEntre2Puntos(triangulo.trngA, triangulo.trngC) +
		distanciaEntre2Puntos(triangulo.trngB, triangulo.trngC);
}



int main() {

	struct Punto triangulo1, triangulo2, triangulo3;
	struct Triangulo trianguloFigura;

	std::cout<<"ingrese radio\n";
	std::cin>>radio;
	std::cout<<"ingrese base del rectangulo\n";
	std::cin>>c;
	std::cout<<"ingrese altura del rectangulo\n";
	std::cin>>h;

	std::cout << "\nIngrese 3 puntos para formar un triangulo:\nPunto 1.x : "; std::cin >> triangulo1.x;
	std::cout << "Punto 1.y : "; std::cin >> triangulo1.y;
	std::cout << "\nPunto 2.x : "; std::cin >> triangulo2.x;
	std::cout << "Punto 2.y : "; std::cin >> triangulo2.y;
	std::cout << "\nPunto 3.x : "; std::cin >> triangulo3.x;
	std::cout << "Punto 3.y : "; std::cin >> triangulo3.y;

	float areacirculo;
	float areadelrectangulo;
	float prectangulo;
	areacirculo = farea(radio);
	perimetro= parea(radio);
	areadelrectangulo= arectangulo(c, h);
	prectangulo= perimetrodelrectangulo(c , h);

	std::cout<<"\nel perimetro del circulo es\n"<<perimetro;
	std::cout<<"\nel area del circulo es\n"<<areacirculo;
	std::cout<<"\nel area del rectangulo es\n"<<areadelrectangulo;
	std::cout<<"\nel perimetro del rectangulo es\n"<<prectangulo << std::endl;

	trianguloFigura.trngA = triangulo1;
	trianguloFigura.trngB = triangulo2;
	trianguloFigura.trngC = triangulo3;
	std::cout << "El perimetro del triangulo es: " << perimetroTriangulo(trianguloFigura) << std::endl;
	
	// ----Seccion Area del Triangulo-----
	
	float GetArea(float p, struct Triangulo triangulo);
	
	std::cout << "El area del triangulo es: " << GetArea(perimetroTriangulo(trianguloFigura),trianguloFigura) << std::endl;

return 0;
}

float GetArea(float p, struct Triangulo triangulo){      //Funcion obtiene el area con los lados y el semiperimetro
	float a,b,c;
	a=p/2 - distanciaEntre2Puntos(triangulo.trngA, triangulo.trngB);
	b=p/2 - distanciaEntre2Puntos(triangulo.trngA, triangulo.trngC);
	c=p/2 - distanciaEntre2Puntos(triangulo.trngB, triangulo.trngC);
			
	return sqrt(p/2*a*b*c);
}

