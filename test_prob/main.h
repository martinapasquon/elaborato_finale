

#ifndef __fluid__
#define __fluid__




const int N_0=50;
long conta_out=0;
const int n_gen=10;
const int n_cellule=3;
const int n_tr_tot=50000;
double cost=0;
int n=0;


double coppie_2=0;

long v[n_gen];
long double diff[n_gen];
double p=0;
long N_max=0;
int N_av=0;
long coppie=0;
long b_root=0;
long v_0[n_gen-1];
long v_1[n_gen-1];
long v_2[n_gen-1];
double P_alive=0.5;
double P_2=P_alive*P_alive;
double P_0=(pow(1-P_alive, 2));
double P_1=2.*P_alive*(1-P_alive);
double P[3];
unsigned int n_figlie[3];

double casuale=0;
long int cell[n_cellule];
long gen[n_cellule];
double v_dead=(1-pow(1-P_alive, 2));
long costa=0, costa_a=0, costa_b=0;
long  a=0;
int conta=0; 
int conta1=0;

vector <unsigned long> v_gen;

//unsigned seed = chrono::system_clock::now().time_since_epoch().count();
//default_random_engine generator(seed);

#endif

