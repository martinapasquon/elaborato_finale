

#ifndef __fluid__
#define __fluid__




const int N_0=1;
int conta_out=0;
const int n_gen=15;
const int n_cellule=3;

const int n_tr_tot=10000;
int j=0, k=0;
int mn, mx;
int  alber=0;
const unsigned long n_fin= N_0*pow(2,n_gen-1);
unsigned long tree[n_fin];
unsigned long  tree_new[n_fin];
unsigned long  branch_a[n_gen];
unsigned long  branch_b[n_gen];
unsigned long  branch_c[n_gen];
int br_long=0;
int br_short=0;


unsigned long v[n_gen];
unsigned long v_possibili[n_gen];
long v_0[n_gen-1];
long v_1[n_gen-1];
long v_2[n_gen-1];
double P_alive=0.8;
double P_2=P_alive*P_alive;
double P_0=(pow(1-P_alive, 2));
double P_1=2.*P_alive*(1-P_alive);
unsigned long a_i=0;
double p=0;
unsigned long N_max=0;
int N_av=0;
double v_dead=(1-pow(1-P_alive, 2));

unsigned long costa=0, costa_a=0, costa_b=0;
double casuale=0;
unsigned long cell[n_cellule];
unsigned long gen[n_cellule];
unsigned long a=0;
int conta[n_cellule];
unsigned long conta_uguali=0;
int conta_rev=0;
int conta1_rev=0;
unsigned long conta_norip=0;
vector <unsigned long> bott;
vector <unsigned long> bott_fin;
vector <unsigned long> bott_coppie;
double P[3];
unsigned int n_figlie[3];
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);

//functions
void gen_i(int, int, int);

#endif

