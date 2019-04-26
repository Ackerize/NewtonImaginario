#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision
#include <complex>

using namespace std;
//Definimos la función
inline complex<long double> f(complex<long double> x) { return (pow(x,3) - ( complex<long double>(2,0)*x) +complex<long double> (2,0) ); }
//Derivada de la función
inline complex<long double>  df(complex<long double>  x) { return (complex<long double> (3,0) * pow(x,2) ) - complex<long double>(2,0)  ;}

/*
p0: Aproximación inicial
TOL: tolerancia
Nmax: número máximo de iteraciones
*/
void newton(complex<long double> p0,long double  TOL,double Nmax){

	complex<long double> p;
	for(int i=0; i < Nmax; i++){
		p = p0 - f(p0)/df(p0);		
		cout << i << setprecision(20) << "\t" << p0 << 	"\t" << "p = "<<p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){	
	// Invocamos el método según los datos del problema
	
	long double tol = pow(10, -10) ;
	complex<long double> p0 = complex<long double> (1,1) ;
	
	newton(p0, tol, 40);
	return 0;
}
