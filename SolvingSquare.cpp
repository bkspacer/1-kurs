//������� ���������� ���������
//����������� ������� �� ����������������
//�. �����, 2018

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

 //! ������� ������� ����������� ���������
 //! 
 //! @author ������ �����
 //!
 //! @param [in]  a ������� ����������� ���������� ������ �������
 //! @param [in]  b ����������� ������ �������
 //! @param [in]  c ������� �����������
 //! @param [out] x1 ������ ������
 //! @param [out] x2 ������ ������
 //!
 //! @return ���������� ������ ���������
 //!
 //! - ������������ �������� ������� SolvingSqare 
 //! -# 2 : ��������� ����� ��� ����� 
 //! -# 1 : ��������� ����� ���� ������ (����� ���������)
 //! -# 0 : ��������� �� ����� ������ � �������������� ������
 //! -# InfOfRoots = -1 : ��������� ����� ����������� ��������� �������
 //! 


int SolvingSquare (double a, double b, double c, double *x1, double *x2) {
    
    const int InfOfRoots = -1;

	if (a == 0) {
		
		if (b == 0) {
			
			if (c == 0) {
				
			    return (InfOfRoots);
			    
			}
			
			else {
				
			   return (0);
				
			}
		}
		
		else {
			
			
			*x1 = -b/c;
			*x2 = *x1;
			return(1);
			
		}
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
			*x1 = (-b + sqrt (d)) / (2*a);
			*x2 = (-b - sqrt (d)) / (2*a);
			return (2);
		}
		
	}
}

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    double a = 0, b = 0, c = 0;

    printf ( "������� ���������� ���������, �. �����\n");
    printf ( "--------------------------------------\n");

    printf ("\n", "������� ������������ ����������� ���������\n");
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
            printf ("��������� ����� ����������� ��������� �������\n");
            break;
        }

        case 0:{
            printf ("��������� �� ����� ������ � �������������� ������\n");
            break;
        }
        case 1: {
            printf ("��������� ����� ���� ������, X = %lf\n", x1);
            break;
        }
        case 2: {
            printf ( "��������� ����� ��� �����\n");
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
