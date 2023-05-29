

#ifndef __fluid__
#define __fluid__




const int N_0=1;
int conta_out=0;
const int n_gen=15;
const int n_cellule=3;
const int n_tr_tot=100000;
int n=0;
long j=0, k=0;
int mn, mx;
int  alber=0;
const long  n_fin= N_0*pow(2,n_gen-1);
long tree[n_fin];
long  tree_new[n_fin];
long  branch_a[n_gen];
long  branch_b[n_gen];
long  branch_c[n_gen];
int errore=0;
int br_long=0;
int br_short=0;

long v[n_gen];
long N_max=0;
int N_av[n_gen-1];
int v_tot[n_gen-1];
int coppie=0;
int b_root=0;
//double b=;
//double d=0;
long x=0;
long v_0[n_gen-1];
long v_1[n_gen-1];
long v_2[n_gen-1];
double prob=0; 
double P_alive=1;
double P_2=P_alive*P_alive;
double P_0=(pow(1-P_alive, 2));
double P_1=2.*P_alive*(1-P_alive);
double figlie_av=2*P_alive;
double casuale=0;
long cell[n_cellule];
long gen[n_cellule];
int v_alive=0;
double v_dead=1.-(pow(1-P_alive, 2));
long costa=0, costa_a=0, costa_b=0;
long a=0;
int conta[n_cellule];
int conta_rev=0;
int conta1_rev=0;
double P[3];
unsigned int n_figlie[3];


unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);

//functions
void gen_i(int, int, int, int);
int factorial(int, int );
#endif

