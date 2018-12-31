#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

void retirement (int startAge, double initial,  retire_info working,
  retire_info retired)

void retirement(int startAge, double initial, retire_info working, retire_info retired); // info about being retired


int main(void) {
  typedef struct _retire_info retire_info;
  retire_info working;
  working.months = 489;
  working.contribution = 1000.00;
  working.rate_of_return = 0.045;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000.00;
  retired.rate_of_return = 0.01;
  retirement(327, 21345.00, working, retired);
  return EXIT_SUCCESS;
}

void retirement(int startAge, double initial, 
                struct _retire_info working, struct _retire_info retired) {
  int age = startAge; // months
  int ageYear = startAge/12;
  int ageMonth = startAge%12;
  double balance = initial;

  for (int month = 0; month < working.months; month++) {
    printf("Age %3d month %2d you have $%.2lf\n", ageYear, ageMonth, balance);
    age++;
    ageYear = age/12;
    ageMonth = age%12;
    balance = balance + working.contribution + (balance * working.rate_of_return/12.0);
  }

  for (int month = 0; month < retired.months; month++) {
    printf("Age %3d month %2d you have $%.2lf\n", ageYear, ageMonth, balance);
    age++;
    ageYear = age/12;
    ageMonth = age%12;
    balance = balance + retired.contribution + (balance * retired.rate_of_return/12.0);   
  }
}
