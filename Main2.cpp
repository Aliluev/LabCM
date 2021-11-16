/*


#include<stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

// A sample differential equation "dy/dx = (x - y)/2"
float dydx(float x, float y, float L, float R, float V)
{
  return((V - R * y) / L);
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
float rungeKutta(float x0, float y0, float x, float h,float L,float R,float V,int n_max)
{
  // Count number of iterations using step size or
  // step height h
  int n = (int)((x - x0) / h);
  if (n >= n_max) {
    n = n_max;
  }
  float k1, k2, k3, k4, k5;

  cout << setw(5) << left << "n " << std::setw(8) << std::left << "Шаг"
    << setw(8) << left << "xn " << std::setw(8) << std::left << "Vn";


  // Iterate for number of iterations
  float y = y0;
  for (int i = 1; i <= n; i++)
  {
    // Apply Runge Kutta Formulas to find
    // next value of y
    k1 = h * dydx(x0, y, L, R, V);
    k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1, L, R, V);
    k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2, L, R, V);
    k4 = h * dydx(x0 + h, y + k3, L, R, V);

    // Update next value of y
    y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);;

    // Update next value of x
    x0 = x0 + h;

    cout << "\n" << setw(5) << std::left << i << std::setw(8) << std::left << h
      << setw(8) << left << x0 << std::setw(8) << std::left << y << std::setw(8) << std::left;

  }

  return y;
}

// Driver method
int main()
{
  setlocale(LC_ALL, "Russian");
  float L = 0.0;
  float R = 0.0;
  float V = 0.0;
  cout << "Процесс установления тока в цепи с сомоиндукцией описывается дифференциальным уравнением\n";
  cout << "   L*dI/dx+RI=V\n\n";
  cout << "Введите параметры задачи\n";
  cout << "L-коэффициент самоиндукции\n";
  cout << "L=";
  cin >> L;
  cout << "R-сопротивление\n";
  cout << "R=";
  cin >> R;
  cout << "V-напряжение\n";
  cout << "V=";
  cin >> V;
  float x0 = 0;
  float y = 0.0, x = 0.0, h = 0.0;
  cout << "\n" << "Введите параметры задачи Коши\n";
  cout << "Сила тока I в момент времени x=0\n";
  cout << "I=";
  cin >> y;
  //float x0 = 0, y = 2, x = 2, h = 0.2;
  cout << "Введите параметры метода\n";
  cout << "Начальный шаг\n" << "h=";
  cin >> h;
  cout << "Граница вычеслений по x\n" << "x(граничн)=";
  cin >> x;
  cout << "Точность выхода за границу\n" << "Епсилон=" << "Пока нет реализации!!!!!";
  cout << "Максимальное количество шагов\n" << "n=";
  int n_max = 0;
  cin >> n_max;

  cout << "\nМетод Рунге-Кутты четвертого порядка\n";
  cout << " k1 = h * dydx(x0, y, L, R, V)\n";
  cout << " k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1, L, R, V)\n";
  cout << " k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2, L, R, V)\n";
  cout << " k4 = h * dydx(x0 + h, y + k3, L, R, V)\n";
  cout << " y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4)\n\n";

  //float x0 = 0, y = 1, x = 2, h = 0.2;
    rungeKutta(x0, y, x, h,L,R,V,n_max);
  return 0;
}

*/