//
// Created by anshk on 29-01-2024.
//
#include <stdio.h>
#include <math.h>
//
//// Define the function to be integrated
//double myFunction(double x) {
//    return x * x;  // Example function: f(x) = x^2
//}
//
//// Function to perform numerical integration using the trapezoidal rule
//double integrate(double (*function)(double), double a, double b, int num_intervals) {
//    double h = (b - a) / num_intervals;
//    double result = 0.5 * (function(a) + function(b));
//
//    for (int i = 1; i < num_intervals; ++i) {
//        result += function(a + i * h);
//    }
//
//    return result * h;
//}
//
//int main() {
//    double a = 0.0;   // Lower limit of integration
//    double b = 2.0;   // Upper limit of integration
//    int num_intervals = 1000;  // Number of intervals for the trapezoidal rule
//
//    double integral = integrate(myFunction, a, b, num_intervals);
//
//    printf("The integral of x^2 from %.2f to %.2f is: %.4f\n", a, b, integral);
//
//    return 0;
//}
// learnin how to integrate first
//double fun(double x){
//    return sin(x);
//}
//// trapezoid method
//double integral(double(*function)(double),double a, double b, int intervals){
//    double h = (b-a)/intervals;
//    double result = 0.5 *(function(a) + function(b));
//    for(int i = 1; i < intervals;++i){
//        result += function(a+i*h);
//    }
//    return result*h;
//}
//int main(){
//    double a = 0.0;
//    double b = M_PI;
//    int intervals = 1000;
//    double ans = integral(fun,a,b,intervals);
//    printf("%.2f",ans);
//}
// now going to fourier series
double fun(double x){
    return x + x*x;

}
double an(double x,double n){
    return fun(x)*cos(n*x);
}
double bn(double x, double n){
    return fun(x)*sin(n*x);
}

double integrate2(double (*function)(double, double), double a, double b, int num_intervals, double n) {
    double h = (b - a) / num_intervals;
    double result = 0.5 * (function(a, n) + function(b, n));

    for (int i = 1; i < num_intervals; ++i) {
        result += function(a + i * h, n);
    }

    return (1 / M_PI) * result * h;
}
double integrate(double (*function)(double),double a,double b,int intervals){
    double h = (b-a)/intervals;
    double result = 0.5*(function(a)+function(b));
    for(int i =1;i <intervals;++i){
        result += function(a+i*h);
    }
    return result*h;
}
int main(){
    double a = 0.0;
    double b = 2*M_PI;
    int intervals = 1000;
    double A0 = integrate(fun,a,b,intervals);
    double An = integrate2(an,a,b,intervals,1);
    double Bn = integrate2(bn,a,b,intervals,1);
    printf("fourier series =  %0.2f + %.2f cos(nx) + %.2f sin(nx)",A0/2,An,Bn);
}