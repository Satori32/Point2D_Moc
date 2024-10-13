#include <stdio.h>
#include <math.h>

template<class T>
struct Point2D
{
	T X = 0;
	T Y = 0;

};

template<class T>
Point2D<T> ConstructPoint2D(T X, T Y) {
	Point2D<T> P;
	
	P.X = X;
	P.Y = Y;

	return P;
}

template<class T>
Point2D<T>& LotXY(Point2D<T>& In, double Theta) {
	double PI = 3.1415926535;
	double Rad = PI / 180.0;

	T X = sin(Rad * Theta) * In.X;
	T Y = cos(Rad * Theta) * In.Y;

	return ConstructPoint2D(X, Y);
}

template <class T>
Point2D<T> Line(const Point2D<T>& In, const Point2D<T>& To, double delta) {
	T X = To.X - In.X;
	T Y = To.Y - In.Y;

	return ConstructPoint2D(In.X + X * delta, In.Y + Y * delta);
}

template <class T>
bool ToZero(Point2D<T>& In) {
	In.X = 0;
	In.Y = 0;

	return true;
}


int main() {
	Point2D<double> P = ConstructPoint2D<double>(0, 0);

	Point2D<double> P2 = LotXY(P, 16);

	ToZero(P);
}