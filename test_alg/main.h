

#ifndef __fluid__
#define __fluid__


//parametri
const int N_0=100;
const int n_gen=10;
const int n_cellule=50;
//double b=1;
//double d=0.;

int conta_out=0;
//simulazione
const int n_tr_tot=1000;
int errore=0;

//matrice
int j=0, k=0;
int mn, mx;
int  alber=0;
long v_0[n_gen-1];
long v_1[n_gen-1];
long v_2[n_gen-1];
long conta_0[n_gen], conta_1[n_gen], conta_2[n_gen];
const unsigned long n_fin= N_0*pow(2,n_gen-1);
unsigned long tree[n_fin];
unsigned long tree_new[n_fin];
long int  branch[n_cellule][n_gen];
double P_alive=0.8;
double prob=0;
double P_2=P_alive*P_alive;
double P_0=(pow(1-P_alive, 2));
double P_1=2.*P_alive*(1-P_alive);
double P[3];
unsigned int  n_figlie[3]; 
unsigned long long  conta_norip=0;
//double P=0;
int conta[n_gen];
long costa=0;
long int cell[n_cellule];


int br_long=0;
int br_short=0;

//vector
unsigned long c=0;
unsigned long  v[n_gen];
unsigned long  v_possibili[n_gen];
unsigned long gen[n_cellule];
double p=0;
unsigned long N_max=0;
unsigned long N_av=0;
unsigned long  a_i=0;
double v_dead=(1-pow(1-P_alive, 2));
vector <unsigned long > bott;
vector <unsigned long > bott_fin;
vector <unsigned long > bott_coppie;
int conta_rev=0;
int conta1_rev=0;



//double figlie_av=2*b/(b+d);
double casuale=0;
unsigned long  a=0;
unsigned long  conta_uguali=0;
unsigned long  conta_err=0;


unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);



#endif

