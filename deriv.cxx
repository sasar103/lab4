#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void print(double* p, const int N, const double dx, const double xmin);
double arrayfiller(double* p, const double xmax, const double xmin, const double dx, const int N);
double derivative(double* p, const int N, const double dx);


int main(){
  
  const int N = 100;
  double p[N];
  double d[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);
  arrayfiller(p,xmax,xmin,dx,N);
  // call to function which fills array p here
  // call to functio which calculates the derivative
 
  derivative(p,N,dx);
   print(p,N,dx,xmin);

  return 0;
}



void print(double* p, const int N, const double dx, const double xmin)
{
   ofstream out("data.dat");
   for(int i=0; i<N; i++)
       out << i*dx + xmin << "\t" << p[i] << endl;
     out.close();
}

double arrayfiller(double* p, const double xmax, const double xmin, const double dx, const int N)
{
      for(int j=0;j<N;j++)
      {
	p[j]=exp(-pow(xmin+j*dx,2));
      }
    return 0;
}

double derivative(double* p , const int N, const double dx)
{
  double newp;
  double newnewp=0;
  for(int i=0;i<N-2;i++)
  {
      newp=p[i];
      p[i]=(p[i+1]-newnewp)/(2*dx);
      newnewp=newp;
  }
  p[N-1]=-p[N-2]/(2*dx);
  
  return 0;
}