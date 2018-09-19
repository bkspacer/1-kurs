//Решение квадратных уравнений
//Августовкие занятия по программированию
//М. Лашин, 2018

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

 //! Функция решения линейного уравнения вида k*x = 0
 //! 
 //! @author Михаил Лашин
 //!
 //! @param [in]  k Коэффициент при x
 //! @param [in]  b Свободный коэффициент
 //! @param [out] x Корень
 //!
 //! @return Количество корней уравнения
 //!
 //! - Возвращаемые значения функции SlvLineEquation 
 //! -# 1 : уравнение имеет единственный корень x = -k/b
 //! -# 0 : уравнение не имеет корней
 //! -# InfOfRoots = -1 : уравнение имеет бесконечное множество решений
 //! -------------------------------------------------------------------

int SlvLineEquation (double k, double b, double* x) {
    assert ( k != NULL );
    assert ( b != NULL );
    assert ( x != NULL );
	
	const int InfOfRoots = -1;
	
	if (k == 0) {
		
		if (b == 0){
			return (InfOfRoots);
		}
		else {
			return (0);
		}
		
	}
	
	else {
		*x = -b/k;
		return (1);
	}
}


 //! Функция решения квадратного уравнения
 //! 
 //! @author Михаил Лашин
 //!
 //! @param [in]  a Старший коэффициент многочлена второй степени
 //! @param [in]  b Коэффициент первой степени
 //! @param [in]  c Младший коэффициент
 //! @param [out] x1 Первый корень
 //! @param [out] x2 Второй корень
 //!
 //! @return Количество корней уравнения
 //!
 //! - Возвращаемые значения функции SolvingSqare 
 //! -# 2 : уравнение имеет два корня 
 //! -# 1 : уравнение имеет один корень (корни совпадают)
 //! -# 0 : уравнение не имеет корней в действительных числах
 //! -# InfOfRoots = -1 : уравнение имеет бесконечное множество решений
 //! ------------------------------------------------------------------


int SolvingSquare (double a, double b, double c, double* x1, double* x2) {
    
    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));
   
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    
    const int InfOfRoots = -1;
    
	if (a == 0) {
		return(SlvLineEquation (b,c, x1));
	}
	
	else {
		
		double d = b*b - 4*a*c;
		
		
		if (d < 0) {
			return (0);
		}
		
		if (d == 0) {
			*x1 = -b / (2*a);
			*x2 = *x1;
			return (1);
		}
		
		if (d > 0) {
			double sd = sqrt(d);
			*x1 = (-b + sd) / (2*a);
			*x2 = (-b - sd) / (2*a);
			return (2);
		}
		
	}
}

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    double a = 0, b = 0, c = 0;

    printf ( "Решение квадратных уравнений, М. Лашин\n");
    printf ( "--------------------------------------\n");

    printf ("\n", "Введите коэффициенты квадратного уравнения\n");
    printf ("a -> ");
    scanf ("%lf", &a);
    printf ("b -> ");
    scanf ("%lf", &b);
    printf ("%s","c -> ");
    scanf ("%lf", &c);
    printf ("%s","\n");

    
    int nRoots = 0;
    double x1 = 0, x2 = 0;
    nRoots = SolvingSquare (a, b, c, &x1, &x2);
    
    switch ( nRoots ) {
        case -1: {
            printf ("Уравнение имеет бесконечное множество решений\n");
            break;
        }

        case 0:{
            printf ("Уравнение не имеет корней в действительных числах\n");
            break;
        }
        case 1: {
        	/*int AnsSize = 6;
        	printf ("Введите точность отображаемых ответов (количество знаков после запятой от 1 до 10) -> ");
			scanf (" %d",AnsSize);
			if (AnsSize < 1 || AnsSize > 10) {
				AnsSize = 6;
			}*/
            printf ("Уравнение имеет один корень, X = %lf\n", x1);
            break;
        }
        case 2: {
            printf ( "Уравнение имеет два корня\n");
			printf ( "X1 = %lf\n", x1);
			printf ( "X2 = %lf\n", x2);
            break;
        }

        default: {
            printf ("Error, nRoots = %i\n", nRoots);
            break;
        }
    }

    return 0;
}
