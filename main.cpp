#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define n 80
                                                                                         
//distance: short - (10, 24), average - (21, 39), long (37, 60)
//speed: low - (0, 28), normal - (25, 75), high - (75, 150)
                                                                                         
//создание функций принадлежности 
void terms(float* arr,float min,float max)
{
    int i;
    float y=0;
    float x=(1/((max-min)/2));
    arr[0]=0;
    
    for (i=1;i<=((max-min)/2);i++)
    {
    y=y+x;
    arr[i]=y;
    }
    
    int a=i;
    for (i=a;i<(max-min);i++)
    {
    y=y-x;
    arr[i]=y;
    }
}
//проверка введенных параметров
float test_parameters1(float* arr1,float* arr2,float* arr3,int t)
{
    float t_res;
  if ((t>=10)&&(t<21))  
      t_res = arr1[t-10];
  if ((t>=21)&&(t<=24))
  {
     if (arr1[t-10]>=arr2[t-21]){
     t_res =  arr1[t-10];}
     else{ 
     t_res =  arr2[t-21];}
  }
  if ((t>24)&&(t<37))
     t_res =  arr2[t-21];
  if ((t>=37)&&(t<=39))
  {
     if (arr2[t-21]>=arr3[t-37]){
     t_res =  arr2[t-21];}
     else{
     t_res =  arr3[t-37];}
  }   
  if ((t>39)&&(t<=60))
     t_res = arr3[t-37];
  return t_res;
}

char* test_parameters2(float* arr1,float* arr2,float* arr3,int t)
{
    char* t_graph;
  if ((t>=10)&&(t<21))  
     t_graph = "short";
  if ((t>=21)&&(t<=24))
  {
     if (arr1[t-10]>=arr2[t-21]){
     t_graph = "short";}
     else{ 
      t_graph = "average";}
  }
  if ((t>24)&&(t<37))
     t_graph = "average";
  if ((t>=37)&&(t<=39))
  {
     if (arr2[t-21]>=arr3[t-37]){
    t_graph = "average";}
     else{
     t_graph = "long";}
  }  
  if ((t>39)&&(t<=60))
     t_graph = "long";
  printf("%s ",t_graph);
  return t_graph;
}

float test_parameters3(float* arr1,float* arr2,float* arr3,int h)
{
    float h_res;
  if (h<25)
     h_res = arr1[h];
  if ((h>=25)&&(h<=28))
  {
     if (arr1[h]>=arr2[h-25]){
     h_res =  arr1[h];}
     else{ 
     h_res =  arr2[h-25];}
  }  
  if ((h>28)&&(h<72))
     h_res = arr2[h-25];
  if ((h>=72)&&(h<=75))
  {
     if (arr2[h-25]>=arr3[h-72]){
     h_res =  arr2[h-25];}
     else{ 
     h_res =  arr3[h-72];}
  }  
  if ((h>75)&&(h<=150))
     h_res = arr3[h-72];
  return h_res;
}

char* test_parameters4(float* arr1,float* arr2,float* arr3,int h)
{
    char* h_graph;
  if (h<25)
     h_graph = "low";
 if ((h>=25)&&(h<=28))
  {
     if (arr1[h]>=arr2[h-25]){
     h_graph = "low";}
     else{ 
     h_graph = "normal";}
  }  
  if ((h>28)&&(h<72))
     h_graph = "normal";
  if ((h>=72)&&(h<=75))
  {
     if (arr2[h-25]>=arr3[h-72]){
     h_graph = "normal";}
     else{ 
      h_graph = "high";}
  }
  if ((h>75)&&(h<=150))
     h_graph = "high";
  printf("%s ",h_graph);
  return h_graph;
}

//вывод на основе проверки параметров
float* set_rule_graph(float* arr1,float* arr2,float* arr3,float* arr4,float* arr5,float* arr6,float* arr7,float* arr8,float* arr9,char* t,char* h)
  {
  float* rule_graph;
  if (t == "short") 
  {
    if (h == "low")
      {rule_graph = arr1;
      }
    if (h == "normal")
      {rule_graph = arr2;
      }
    if (h == "high")
      {rule_graph = arr3;}
  }  
  if (t == "average")
  {
    if (h == "low")
      rule_graph = arr4;
    if (h == "normal")
      rule_graph = arr5;
    if (h == "high")
      rule_graph = arr6;
  }   
  if (t == "long")
  {
    if (h == "low")
      rule_graph = arr9;
    if (h == "normal")
      rule_graph = arr8;
    if (h == "high")
      rule_graph = arr7;
  }
  return rule_graph;
  }


int distmax(float* arr1,float* arr2,float* arr3,int d)
{
  int k=0;
  if ((d>=10)&&(d<=17)) 
      k=1;
  if ((d>17)&&(d<21))
      k=2;  
  if ((d>=21)&&(d<=24))
  {
     if (arr1[d-10]>=arr2[d-21])
     k=2;
     else 
     k=1;
  }
  if ((d>24)&&(d<=30))
     k=1;
  if ((d>30)&&(d<37))
     k=2; 
  if ((d>=37)&&(d<=39))
  {
     if (arr2[d-21]>=arr3[d-37])
     k=2;
     else
     k=1;
  }   
  if ((d>39)&&(d<=49))
     k=1;
  if (d>49)
     k=2;  
  return k;
}
int spmax(float* arr1,float* arr2,float* arr3,int s)
{
  int k=0;
  if (s<=13)  
      k=1;
  if ((s>13)&&(s<25))
      k=2;  
  if ((s>=25)&&(s<=28))
  {
     if (arr1[s]>=arr2[s-12])
     k=2;
     else 
     k=1;
  }
  if ((s>28)&&(s<=50))
     k=1;
  if ((s>50)&&(s<72))
     k=2; 
  if ((s>=72)&&(s<=75))
  {
     if (arr2[s-12]>=arr3[s-28])
     k=2;
     else
     k=1;
  }   
  if ((s>75)&&(s<=111))
     k=1;
  if (s>111)
     k=2;  
  return k;
}
float result(float* arr1,float* arr2,float* arr3,float* arr4,float* arr5,float* arr6,float* arr7,float* arr8,float* arr9,char* t,char* h)
  {
  float r;
  if (t == "short") 
  {
    if (h == "low")
      r=5;
    if (h == "normal")
      r=15;
    if (h == "high")
      r=30;
  }  
  if (t == "average")
  {
    if (h == "low")
      r=-2;
    if (h == "normal")
      r=0;
    if (h == "high")
      r=2;
  }   
  if (t == "long")
  {
    if (h == "low")
      r=-30;
    if (h == "normal")
      r=-15;
    if (h == "high")
      r=-5;
  }
  return r;
  }

int main()
{
    int dist,sp;
    int a,m=0;
    float k=0;
//создание термов
float* short_distance_values = (float*)malloc(n * sizeof(int));
terms (short_distance_values,10,24);
float* average_distance_values = (float*)malloc(n * sizeof(int));
terms (average_distance_values,21,39);
float* long_distance_values = (float*)malloc(n * sizeof(int));
terms (long_distance_values,37,60);

float* low_speed_values = (float*)malloc(n * sizeof(int));
terms (low_speed_values,1,28);
float* normal_speed_values= (float*)malloc(n * sizeof(int));
terms (normal_speed_values,25,75);
float* high_speed_values = (float*)malloc(n * sizeof(int));
terms (high_speed_values,72,150);

//правила нечеткого вывода
float* lightly_press =(float*)malloc(n * sizeof(int));
terms(lightly_press,5,17);
float* press = (float*)malloc(n * sizeof(int));
terms(press,15,32);
float* hard_press = (float*)malloc(n * sizeof(int));
terms(hard_press,30,45);

float* press_a_little =(float*)malloc(n * sizeof(int));
terms(press_a_little,0,7);
float* do_nothing = (float*)malloc(n * sizeof(int));
terms(do_nothing,3,5);
float* release_a_little = (float*)malloc(n * sizeof(int));
terms(release_a_little,1,7);

float* lightly_release = (float*)malloc(n * sizeof(int));
terms(lightly_release,5,17);
float* release = (float*)malloc(n * sizeof(int));
terms(release,15,32);
float* hard_release = (float*)malloc(n * sizeof(int));
terms(hard_release,30,45);
printf("\n");
printf("\n");
printf("Введите параметры состояния автомобиля, после чего будет выведено нужное положение педали тормоза ");
printf("\n");
printf("Положительное значение в градусах означает необходимость нажать на педаль, отрицательное-отпустить ");
printf("\n");
printf("Введите расстояние: ");
scanf("%d", &dist );
printf("Введите скорость: ");
scanf("%d", &sp);
if ((dist<10)||(dist>60)||(sp<0)||(sp>150))
{
    printf("Ошибка! Неправильные входные параметры! ");
    return 0;
}
//проверка входных параметров
float t_res = test_parameters1(short_distance_values,average_distance_values,long_distance_values,dist);
 char* t_graph= test_parameters2(short_distance_values,average_distance_values,long_distance_values,dist);
 float h_res= test_parameters3(low_speed_values,normal_speed_values,high_speed_values,sp);
 char* h_graph= test_parameters4(low_speed_values,normal_speed_values,high_speed_values,sp);
//определение подходящего для вывода терма
float* rules = set_rule_graph(lightly_press,press,hard_press,press_a_little,do_nothing,release_a_little,lightly_release,release,hard_release,t_graph,h_graph);
k= result(lightly_press,press,hard_press,press_a_little,do_nothing,release_a_little,lightly_release,release,hard_release,t_graph,h_graph);
printf("%f ",t_res);
printf("%f ", h_res);
//вывод
float min;
if (t_res>=h_res) 
{
    min=h_res;
    m=spmax(low_speed_values,normal_speed_values,high_speed_values,sp);
}
else
{
    min=t_res;
    m=distmax(short_distance_values,average_distance_values,long_distance_values,dist);
}
printf("\n");
if (min==0)
{
    int i=1;
    while(rules[i]>0)
    {
        i++;
    }
    a=i;
    if (k<0) k=k-a;
    if (k>0) k=k+a;
}
else
{
    if ((k<0)&&(m==1))
    {
        for (int i=0;i<n;i++)
        {
            if ((rules[i]<min)&&(rules[i-1]<=rules[i])&&(rules[i+1]>=min))
            {
                a=i;
            }
        }
        k=k-a;
    }
    if ((k<0)&&(m==2))
    {
        for (int i=0;i<n;i++)
        {
            if ((rules[i]<min)&&(rules[i+1]<=rules[i])&&(rules[i-1]>=min))
            {
                a=i;
            }
        }
        k=k-a;
    }
    if ((k>=0)&&(m==1))
    {
        for (int i=0;i<n;i++)
        {
            if ((rules[i]<min)&&(rules[i+1]<=rules[i])&&(rules[i-1]>=min))
            {
                a=i;
            }
        }
        k=k+a;
    }
    if ((k>=0)&&(m==2))
    {
        for (int i=0;i<n;i++)
        {
            if ((rules[i]<min)&&(rules[i-1]<=rules[i])&&(rules[i+1]>=min))
            {
                a=i;
            }
        }
        k=k+a;
    }
}
printf("\n");
printf("Необходимое изменение положения педали(в градусах): ");
printf("%f ",k);
return 0;
}
