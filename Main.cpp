

#include<stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

// L*dI/dx+RI=V; I(0)=I0

// I-->y , x--->x

// dy/dx=(V-Ry)/L  , V,R,L - параметры уравнения


// A sample differential equation "dy/dx = (x - y)/2"
float dydx(float x, float y, float L, float R, float V)
{
  return((V - R * y) / L);
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
float rungeKutta()
{
  // Count number of iterations using step size or
  // step height h
  //cout << setw(5) << left << "n " << std::setw(8) << std::left << "Шаг"
  //  << setw(8) << left << "xn " << std::setw(8) << std::left << "Vn\n";
  float L = 0.0;
  float R = 0.0;
  float V = 0.0;
  cout << "Процесс установления тока в цепи с сомоиндукцией описывается дифференциальным уравнением:\n\n";
  cout << "   L*dI/dx+RI=V , где x-время(c), I(x)-сила тока(A), R-сопротивление(Ом), V-напряжение(В), L-коэффициент самоиндукции(Гн)\n\n";
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
  cout << "Граница вычислений по x\n" << "x(граничн)=";
  cin >> x;
  cout << "Точность выхода за границу\n" << "Епсилон=";
  float Epsilon = 0.0f;
  cin >> Epsilon;
  cout << "Максимальное количество шагов\n" << "n=";
  int n_max = 0;
  cin >> n_max;


  int n = (int)((x - x0) / h);
  if (n >= n_max) {
    n = n_max;
  }



  cout << "\nМетод Рунге-Кутты четвертого порядка, где f(x,y)=(V-Ry)/L\n";
  cout << " k1 = h * f(x, y)\n";
  cout << " k2 = h * f(x + h/2, y + (k1)/2)\n";
  cout << " k3 = h * f(x + h/2, y + (k2)/2)\n";
  cout << " k4 = h * f(x + h, y + k3)\n";
  cout << " V(n+1) = V(n) + (1/6) * (k1 + 2 * k2 + 2 * k3 + k4)\n\n";

  cout << setw(5) << left << "n " << std::setw(8) << std::left << "Шаг"
    << setw(8) << left << "xn " << std::setw(9) << std::left << "Vn" << std::setw(9) << std::left << "Vn(удв)" << std::setw(9) << std::left << "S*";

  float k1, k2, k3, k4, k5;

  // Iterate for number of iterations
  //float y = y0;
  for (int i = 1; i <= n ; i++)
  {
    if(x0-Epsilon<=x&&y-Epsilon)
    // Apply Runge Kutta Formulas to find
    // next value of y
    //x0 = x0 + h;
    k1 = h * dydx(x0, y, L, R, V);
    k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1, L, R, V);
    k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2, L, R, V);
    k4 = h * dydx(x0 + h, y + k3, L, R, V);

    float S = 0.0f;
    float S_1 = 0.0f;
    
    float x0_1 = 0;
    x0_1 = x0 + h /(2.0f);
    float k1_1 = 0, k2_2 = 0, k3_3 = 0, k4_4 = 0, y1_1 = 0;
    k1_1 = (h / (2.0F)) * dydx(x0_1, y, L, R, V);
    k2_2 = (h / (2.0F)) * dydx(x0_1 + 0.5 * h, y + 0.5 * k1, L, R, V);
    k3_3 = (h / (2.0f)) * dydx(x0_1 + 0.5 * h, y + 0.5 * k2, L, R, V);
    k4_4 = (h / (2.0f)) * dydx(x0_1 + h, y + k3, L, R, V);
    y1_1 = y + (1.0 / 6.0) * (k1_1 + 2 * k2_2 + 2 * k3_3 + k4_4);
    // Update next value of y
    y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
    //printf("\n%f", y);
    //cout << y << "\n";
    // Update next value of x
    //x0 = x0 + h;

    x0_1 = x0_1 + h;
    k1_1 = (h / (2.0F)) * dydx(x0_1, y1_1, L, R, V);
    k2_2 = (h / (2.0F)) * dydx(x0_1 + 0.5 * h, y1_1 + 0.5 * k1, L, R, V);
    k3_3 = (h / (2.0f)) * dydx(x0_1 + 0.5 * h, y1_1 + 0.5 * k2, L, R, V);
    k4_4 = (h / (2.0f)) * dydx(x0_1 + h, y1_1 + k3, L, R, V);
    y1_1 = y1_1 + (1.0 / 6.0) * (k1_1 + 2 * k2_2 + 2 * k3_3 + k4_4);
    
    S = (y1_1 - y) / (16 - 1);
    S_1 = S * 16;


    cout << "\n" << setw(5) << std::left << i << std::setw(8) << std::left << h
      << setw(8) << left << x0 << std::setw(9) << std::left << y << std::setw(9) << std::left << y1_1 << std::setw(9) << std::left << S_1;
    x0 = x0 + h;
  }

  return y;
}


// Driver method

  int main()
{
  setlocale(LC_ALL, "Russian");
  rungeKutta();
  return 0;
}
  


void vivod() {
  cout << "Введите параметры задачи\n";
}

