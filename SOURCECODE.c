#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void ExM()
{
     double t,V_0,r,V;
           printf("Please enter the time(in days) at which you want to find the volume of cancer cell:\n");
            scanf("%lf",&t);
           printf("Please enter initial volume(in millimeter cube) of cancer cell:\n");
            scanf("%lf",&V_0);
           printf("Please enter growth rate per day(approximately in the range between 0.1 to 0.05 per day):\n");
            scanf("%lf",&r);
            V=V_0*exp(r*t);
            printf("The volume of cancer cell after %.2lf days is %.2lf\n",t,V);
}

void LoM()
{
      double L,K,t;
    printf("Please enter the time(in days) at which you want to find the volume of cancer cell:\n");
    scanf("%lf",&t);
    printf("please enter growth rate:\n");
    scanf("%lf",&K);
    printf("please enter carrying capacity(cubic millimeters):\n");
    scanf("%lf",&L);
    double TumorVolume=(L)/(1+exp(-K*t));
    printf("Volume of tumor after time %lf is %lf",t,TumorVolume);
}

void GoM()
{
    int t;
    double result;
    printf("Please enter the time(in days) at which you want to find the volume of cancer cell:\n");
    scanf("%d", &t);
    result = 1607.299 * exp(-2.4825 * (exp(-0.0321 * t)));
    printf("The final volume of tumor after time t - %lf\n", result);
}

double drift(double V, double r, double K) {
    return r * V * log(K / V);
}

void maruy(double *t_values, double *V, int num_points, double r, double K, double sigma) {

    srand(42);

    V[0] = 1.0; 

    for (int i = 1; i < num_points; i++) {
        
        double dW = sigma * V[i-1] * ((double)rand() / RAND_MAX - 0.5);


        V[i] = V[i-1] + drift(V[i-1], r, K) * (t_values[i] - t_values[i-1]) + dW;
    }
}

void SGoM()
{
    double r = 0.1; 
    double K = 1000.0; 
    double sigma = 0.1; 

    double t_start = 0.0; 
    double t_end = 100.0; 
    int num_points = 10000;
    double t_values[num_points];


    double V[num_points];

    for (int i = 0; i < num_points; i++) {
        t_values[i] = t_start + i * (t_end - t_start) / (num_points - 1);
    }


    maruy(t_values, V, num_points, r, K, sigma);

    int abc;
    while(1){
    printf("Please enter the time(in days) at which you want to find the volume of cancer cell:(t<100)\n");
    abc=0;
    scanf("%d",&abc);
    if(abc<100)
    {
        break;
    }
    }
     
    printf("Time (days)\tVolume (cubic mm)\n");
    
        printf("%.2f\t%.2f\n", t_values[abc*100], V[abc*100]);
    
}


int main()
{
    printf("There are several types of tumor\n");
    printf("1. Exponential Model\n");
    printf("2. Logistic Model\n");
    printf("3. Gomportz Model\n");
    printf("4. Stochastic Gomportz Model\n");
    
    
    printf("From which model do you want to calculate the volume of tumor, \nEnter the number of model: ");
    int n;
    scanf("%d",&n);
    
    switch(n)
    {
        case 1:
        {
            ExM();
            break;
        }
        
        case 2:
        {
            LoM();
            break;
        }
        
        case 3:
        {
            GoM();
            break;

        }
        
        case 4:
        {
            SGoM();
            break;

        }
        
    }

    return 0;
}