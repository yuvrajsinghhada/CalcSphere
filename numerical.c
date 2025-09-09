#include <stdio.h>
#include <math.h>

double f(double x){        // f(x) Definition
    return exp(x)-10;
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

// Numerical Differentiation
double derivative(double f(double x), double x0){
    double eps=1.0e-6; // eps is the Offset Used to Calculate the Derivative
    double x1 = x0 - eps;
    double x2 = x0 + eps;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

/* Numerical Integration */
// Left Side Integral Approximation
double leftIntegral(double f(double x), double a, double b, double n){
    double x,h,sum=0,integral;
    int i;
    h=fabs(b-a)/n;
    for(i=0;i<n;i++){
        x=a+i*h;
        sum=sum+f(x);
    }
    integral=h*sum;
    return integral;
}

// Right Side Integral Approximation
double rightIntegral(double f(double x), double a, double b, double n){
    double x,h,sum=0,integral;
    int i;
    h=fabs(b-a)/n;
    for(i=1;i<=n;i++){
        x=a+i*h;
        sum=sum+f(x);
    }
    integral=h*sum;
    return integral;
}

// Midpoint Riemann Sum Integral Approximation
double middleIntegral(double f(double x), double a, double b, double n){
    double x,h,sum=0,integral;
    int i;
    h=fabs(b-a)/n;
    for(i=0;i<n;i++){
        x=a+(2*i+1)*h/2;
        sum=sum+f(x);
    }
    integral=h*sum;
    return integral;
}

// Trapezoidal Rule
double trapezoidal(double f(double x), double a, double b, int n){
  double x,h,sum=0,integral;
  int i;
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  integral=(h/2)*(f(a)+f(b)+2*sum);
  return integral;
}

// Simpsons' Rule
double simpsons(double f(double x), double a, double b, int n){
    double x,h,oddTermSum=0,evenTermSum=0,integral;
    int i;
    h=fabs(b-a)/n;
    for(i=1;i<n;i=i+2){
        x=a+i*h;
        oddTermSum=oddTermSum+f(x);
    }
    for(i=2;i<n;i=i+2){
        x=a+i*h;
        evenTermSum=evenTermSum+f(x);
        }
    oddTermSum=4*oddTermSum;
    evenTermSum=2*evenTermSum;
    integral=h*(oddTermSum+evenTermSum+f(a)+f(b))/3;
    return integral;
}

/* Root Approximation */
// Newton Raphson Method
double newtonRaphson(double f(double x), double eps, double x0, double maxIterations){
    double x;
    int i=1;
    while(fabs((f(x)-0))>eps&&i<=maxIterations){
        x=x0;
        if(fabs(derivative(f,x0))>=0.0000000001){
            x0=x-f(x)/derivative(f,x);
            i++;
        }
    }
    return x0;
}

double newtonRaphsonRecursion(double f(double x), int maxIterations, double eps, double x0){
    if(maxIterations==1){
        return x0-f(x0)/derivative(f,x0);
    }
    double secondLastValue = newtonRaphsonRecursion(f,maxIterations-1,eps,x0);
    if(fabs(f(secondLastValue)-0)<eps){
        return secondLastValue;
    }
    double lastValue=secondLastValue-f(secondLastValue)/derivative(f,secondLastValue);
    return lastValue;
}

double printNewtonRaphson(double f(double x), double eps, double x0, double maxIterations){
    int i=1;
    double x;
    for(int j=1;j<=83;j++){
        printf("_");
    }
    printf("\n");
    printf("S.No.\tf(x)\t\tf'(x)\t\tx0\t\t|x-x0|\t\tf(x0)\n");
    for(int j=1;j<=83;j++){
        printf("-");        
    }
    printf("\n");
    while(fabs(f(x0)-0)>eps&&i<=maxIterations){
        x=x0;
        if(fabs(derivative(f,x0))>=0.0000000001){
            x0=x-f(x)/derivative(f,x);
            printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,f(x),derivative(f,x),x0,fabs(x-x0),f(x0));
            i++;
        }
    }
    for(int j=1;j<=83;j++){
        printf("-");        
    }
    printf("\n");
    return x0;
}

double fprintNewtonRaphson(double f(double x), double eps, double x0, double maxIterations){
    int i=1;
    double x;
    for(int j=1;j<=83;j++){
        fprintf(fopen("Calculator History.txt","a"),"_");
    }
    fprintf(fopen("Calculator History.txt","a"),"\n");
    fprintf(fopen("Calculator History.txt","a"),"S.No.\tf(x)\t\tf'(x)\t\tx0\t\t|x-x0|\t\tf(x0)\n");
    for(int j=1;j<=83;j++){
        fprintf(fopen("Calculator History.txt","a"),"-");        
    }
    fprintf(fopen("Calculator History.txt","a"),"\n");
    while(fabs(f(x0)-0)>eps&&i<=maxIterations){
        x=x0;
        if(fabs(derivative(f,x0))>=0.0000000001){
            x0=x-f(x)/derivative(f,x);
            fprintf(fopen("Calculator History.txt","a"),"%d\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,f(x),derivative(f,x),x0,fabs(x-x0),f(x0));
            i++;
        }
    }
    for(int j=1;j<=83;j++){
        fprintf(fopen("Calculator History.txt","a"),"-");        
    }
    fprintf(fopen("Calculator History.txt","a"),"\n");
    return x0;
}

// Bisection Method
double printBisection(double f(double x),double a, double b, double eps, int maxIterations){
    double c;
    if(f(a)*f(b)<=0){  
        int i=1;
        for(int j=0;j<83;j++){
            printf("_");
        }
        printf("\n");
        printf("S.No.\t  a\t\tb\t\tc\t\tf(c)\t\t|a-b|\n");
        for(int j=0;j<83;j++){
            printf("-");
        }
        printf("\n");
        do{
            c=(a+b)/2;
            printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,a,b,c,f(c),fabs(a-b));
            if(f(a)*f(c)>0){
                a=c;
            }
            else if(f(a)*f(c)<0){
                b=c;
            }
            i++;    
        }while(fabs(a-b)>eps&&i<=maxIterations);
        for(int j=0;j<83;j++){
            printf("-");
        }
        printf("\n");
        return c;
    }
    else{
        printf("\nThe Root does NOT Lie within Specified Bounds.\n");
    }
    return c;
}

// Secant Method
double printSecant(double f(double x), double x1, double x2, double eps, int maxIterations){
    int i=1;
    double x3;
    for(int j=0;j<66;j++){
            printf("_");
    }
    printf("\n");
    printf("S.No.\t   x1\t\tx2\t\tx3\t\tf(x3)\n");
    for(int j=0;j<66;j++){
            printf("-");
    }
    printf("\n");
    do{
        x3=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
        printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,x1,x2,x3,f(x3));
        x1=x2;
        x2=x3;
        i++;
    }while(fabs(f(x3))>eps&&i<=maxIterations);
    for(int j=0;j<66;j++){
            printf("-");
    }
    printf("\n");
    return x3;
}

int main(){

    FILE *fp;
    fp = fopen("Calculator History.txt","w");

    double infinity=1.7976931348623157E+308;

    printf("Hi There!\n");
    printf("Which of the following tasks would you like to perform?\n");
    printf("1.Numerical Differentiation\n");
    printf("2.Numerical Integration\n");
    printf("3.Root Approximation\n");
    printf("Enter S.No. of desired task: ");

    int a;
    scanf("%d",&a);
    if(a==1){
        double x0;
        printf("Enter point at which you wish to compute derivative: ");
        scanf("%lf",&x0);
        printf("Derivative: %lf\n", derivative(f,x0));
        fprintf(fp,"Derivative: %lf\n", derivative(f,x0));
    }

    if(a==2){
        printf("Which method would you like?\n");
        printf("1.Riemann Sum\n");
        printf("2.Simpsons' Rule\n");
        int b;
        scanf("%d",&b);
        if(b==1){
            double a,b,n;
            printf("Enter Lower Limit, Upper Limit and Partitions: ");
            scanf("%lf %lf %lf",&a,&b,&n);

            printf("Using Left Riemann Sum: %lf\n",leftIntegral(f,a,b,n));
            printf("Using Right Riemann Sum: %lf\n",rightIntegral(f,a,b,n));
            printf("Using Midpoint Rule: %lf\n",middleIntegral(f,a,b,n));
            printf("Using Trapezoidal Rule: %lf\n",trapezoidal(f,a,b,n));

            fprintf(fp,"Using Left Riemann Sum: %lf\n",leftIntegral(f,a,b,n));
            fprintf(fp,"Using Right Riemann Sum: %lf\n",rightIntegral(f,a,b,n));
            fprintf(fp,"Using Midpoint Rule: %lf\n",middleIntegral(f,a,b,n));
            fprintf(fp,"Using Trapezoidal Rule: %lf\n",trapezoidal(f,a,b,n));
        }
        if(b==2){
            double a,b,n;
            printf("Enter Lower Limit, Upper Limit and Partitions: ");
            scanf("%lf %lf %lf",&a,&b,&n);

            printf("Using Simpsons' Rule: %lf\n",simpsons(f,a,b,n));
            fprintf(fp,"Using Simpsons' Rule: %lf\n",simpsons(f,a,b,n));
        }
    }

    if(a==3){
        printf("Which method would you like?\n");
        printf("1.Newton-Raphson Method\n");
        printf("2.Bisection Method\n");
        printf("3.Secant Method\n");
        int c;
        scanf("%d",&c);
        if(c==1){
            double x,eps;
            int maxIterations;
            printf("Enter the Initial Guess: ");
            scanf("%lf",&x);
            printf("Enter the Desired Accuracy: ");
            scanf("%lf",&eps);
            printf("Enter the Max. Number of Steps: ");
            scanf("%d",&maxIterations);

            printf("One of the Roots of the Given Equation is: %lf\n",printNewtonRaphson(f,x,eps,maxIterations));
            printf("One of the Roots of (using Recursion) is: %lf\n",newtonRaphsonRecursion(f,maxIterations,eps,x));

            fprintf(fp,"One of the Roots of the Given Equation is: %lf\n",printNewtonRaphson(f,x,eps,maxIterations));
            fprintf(fp,"One of the Roots of (using Recursion) is: %lf\n",newtonRaphsonRecursion(f,maxIterations,eps,x));
            fprintNewtonRaphson(f,eps,x,maxIterations);
        }
        if(c==2){
            double a,b,x,eps;
            int maxIterations;
            printf("Enter the Initial Guesses: ");
            scanf("%lf %lf",&a, &b);
            printf("Enter the Desired Accuracy: ");
            scanf("%lf",&eps);
            printf("Enter the Max. Number of Steps: ");
            scanf("%d",&maxIterations);
            printBisection(f,a,b,eps,maxIterations);

        }
        if(c==3){
            double x1,x2,eps;
            int maxIterations;
            printf("Enter the Initial Guesses: ");
            scanf("%lf %lf",&x1,&x2);
            printf("Enter the Desired Accuracy: ");
            scanf("%lf",&eps);
            printf("Enter the Max. Number of Steps: ");
            scanf("%d",&maxIterations);
            printSecant(f,x1,x2,eps,maxIterations);
        }
    }

    return 0;
}