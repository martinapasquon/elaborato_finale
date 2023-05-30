

#ifndef __simulazione__
#define __simulazione__




const int N_0=50; //numero di cellule alla generazione 0
long conta_out=0;
const int n_gen=10; //numero di generazioni
const int n_cellule=3;
const int n_tr_tot=50000; //numero di simulazioni
double cost=0; 
int n=0;


double coppie_2=0;

long v[n_gen];
long double diff[n_gen];
long v_0[n_gen-1];
long v_1[n_gen-1];
long v_2[n_gen-1];
double P_alive=0.5;
double P_2=P_alive*P_alive;
double P_0=(pow(1-P_alive, 2));
double P_1=2.*P_alive*(1-P_alive);
double P[3];
unsigned int n_figlie[3];

long int cell[n_cellule];
long gen[n_cellule];
double v_dead=(1-pow(1-P_alive, 2));
long  a=0;
int conta=0; 

vector <unsigned long> v_gen;


#endif

