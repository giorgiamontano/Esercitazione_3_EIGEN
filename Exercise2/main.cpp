#include <iostream>
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

Vector2d soluzione_PALU (Matrix2d A, Vector2d b) 
{
	Vector2d x_PALU = A.fullPivLu().solve(b); 
	return x_PALU;
}

Vector2d soluzione_QR (Matrix2d A, Vector2d b)
{
	Vector2d x_QR = A.colPivHouseholderQr().solve(b);
	return x_QR;
}


int main()
{
	Vector2d x_esatta;
	x_esatta << -1.0e+0, -1.0e+00;
	
	Matrix2d A1;
	A1 << 5.547001962252291e-01, -3.770900990025203e-02, 8.320502943378437e-01, -9.992887623566787e-01;
	Vector2d b1;
	b1 << -5.169911863249772e-01, 1.672384680188350e-01;
	
	Vector2d x1_PALU = soluzione_PALU(A1, b1);
	double err1_PALU = (x1_PALU - x_esatta).norm() / x_esatta.norm();
	cout << "L'errore relativo associato al primo sistema risolto mediante fattorizzazione PALU è " << err1_PALU << endl;
	
	Vector2d x1_QR = soluzione_QR(A1, b1);
	double err1_QR = (x1_QR - x_esatta).norm() / x_esatta.norm();
	cout << "L'errore relativo associato al primo sistema risolto mediante fattorizzazione QR è " << err1_QR << endl;
	
	
	
    Matrix2d A2;
	A2 << 5.547001962252291e-01, -5.540607316466765e-01, 8.320502943378437e-01, -8.324762492991313e-01;
	Vector2d b2;
	b2 << -6.394645785530173e-04, 4.259549612877223e-04;
	
	Vector2d x2_PALU = soluzione_PALU(A2, b2);
	double err2_PALU = (x2_PALU - x_esatta).norm() / x_esatta.norm();
	cout << "L'errore relativo associato al secondo sistema risolto mediante fattorizzazione PALU è " << err2_PALU << endl;
	
	Vector2d x2_QR = soluzione_QR(A2, b2);
	double err2_QR = (x2_QR - x_esatta).norm() / x_esatta.norm();
	cout << "L'errore relativo associato al secondo sistema risolto mediante fattorizzazione QR è " << err2_QR << endl;
	
	
	Matrix2d A3;
	A3 << 5.547001962252291e-01, -5.547001955851905e-01, 8.320502943378437e-01, -8.320502947645361e-01;
	Vector2d b3;
	b3 << -6.400391328043042e-10, 4.266924591433963e-10;
	
	Vector2d x3_PALU = soluzione_PALU(A3, b3);
	double err3_PALU = (x3_PALU - x_esatta).norm() / x_esatta.norm();
	cout << "L'errore relativo associato al terzo sistema risolto mediante fattorizzazione PALU è " << err3_PALU << endl;
	
	Vector2d x3_QR = soluzione_QR(A3, b3);
	double err3_QR = (x3_QR - x_esatta).norm() / x_esatta.norm();
	cout << "L'errore relativo associato al terzo sistema risolto mediante fattorizzazione QR è " << err3_QR << endl;
	
    return 0;
}