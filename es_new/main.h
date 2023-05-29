

#ifndef __fluid__
#define __fluid__

//parametri esperimento
int N_0=100;
int n_gen=34;
const int n_cellule=3;
//double b=1.1886;
//double d=0.7346;
const int N_cell_bott=1065000;
int n_gen_0=120;
double mut_totali=2099;
//int n_gen0_arr_0[23]={3350,3200,3050,2900,2750,2600,2450,2300,2150,2000,1850,1700,1550,1400,1250,1100,950,800,650,500,350,200,50};
//int n_gen0_arr_0[26]={ 4100,3950,3800,3650,3500,3350,3200,3050,2900,2750,2600,2450,2300,2150,2000,1850,1700,1550,1400,1250,1100,950,800,650,500,350};
//int n_gen0_arr_0[32]={ 5000,4850,4700,4550,4400,4250,4100,3950,3800,3650,3500,3350,3200,3050,2900,2750,2600,2450,2300,2150,2000,1850,1700,1550,1400,1250,1100,950,800,650,500,350};
// usato prima int n_gen0_arr_0[33]={324,  265,  224,  196,  174,  157,  143,  131,  122,  114, 107, 101, 95, 90, 86, 82, 79, 76, 73, 70, 67, 65, 63, 61, 59, 57, 56, 55, 54, 52, 51, 50, 49};
// usato prima int n_gen_arr[25]={49, 44, 40, 37, 35, 33, 31, 29, 28, 26, 25, 24, 23, 22, 21, 21, 20, 19, 19, 18, 18, 17, 17, 17, 16};
 int n_gen0_arr_0[33]={324,265,224,196,174,157,  143,  131,  122,  114, 107, 101, 95, 90, 86, 82, 79, 76, 73, 70, 67, 65, 63, 61, 59, 57, 56, 55, 54, 52, 51, 50, 49};
int n_gen_arr[33]={104,84,71,61,54,49, 44, 40, 37, 35, 33, 31, 29, 28, 26, 25, 24, 23, 22, 21, 21, 20, 19, 19, 18, 18, 17, 17, 17, 16};
//int n_gen_arr[33]={ 104,84,71,61,54,49, 44, 40, 37, 35, 33, 31, 29, 28, 26, 25, 24, 23, 22, 21, 21, 20, 19, 19, 18, 18, 17, 17, 17, 16, 16, 15, 15};
double mu_arr[1000*5*1000];
unsigned int n_figlie[3];
const int n_alb=7;
const int n_cell=2;
double N_m=2748711013;
double mu=6.33828E-09;
int v_i=0;
//double numero_basi[5]={N_m,N_m,N_m,N_m,N_m};
//double mu_rate[5]={mu,mu,mu,mu,mu};

//simulazione
const int n_tr_tot=1000;
int restart;
double uguali_N_0=0;
int conta_N_0=0;
//simulazione popolazione
vector <unsigned long long> v;
vector <unsigned long long> v_possibili;
vector <unsigned long long> v_possibili2;
vector <unsigned long long> v_possibili1;
vector <unsigned long long> v_possibili_N0;
vector <unsigned long long> v_0;
vector <unsigned long long> v_1;
vector <unsigned long long> v_2;
unsigned long long  gen[n_cellule];

//double p=0.6;
unsigned long long N_max=0;
int a=0;
unsigned long long  a_i=0;
int conta=0;
int conta1=0,  conta_gen0=0;
unsigned long long  conta_norip=0;
double P_alive=0.57814634;
double v_dead=(1-pow(1-P_alive, 2));
double P_2=P_alive*P_alive;
double P_0=(pow(1-P_alive, 2));
double P_1=2.*P_alive*(1-P_alive);
unsigned long long  costa=0, costa_a=0, costa_b=0, conta_probablilita=0;
double P[3];
 

vector <unsigned long long> bott;
vector <unsigned long long> bott_fin;
vector <unsigned long long> bott_coppie;
unsigned long long  conta_uguali=0;
int errore=0;



//simulazione mutazioni
int rami[5];
int tau[n_cellule];
int ar, br, cr, dr;
//int rami_piccoli[n_cellule+(n_cellule-1)];
int mutazioni[n_cellule+ (n_cellule-1)];
int mutazioni_tot=0;
int N_iter=0;
int i_ramo=0;
int mut_tot=0;
//ouble mu_arr[n_cellule+ (n_cellule-1)];
double mu_2[n_cellule+ (n_cellule-1)];

double mu_av[n_cellule+ (n_cellule-1)];
double mu2_av[n_cellule+ (n_cellule-1)];
double stdev_mu[n_cellule+ (n_cellule-1)];

vector <int> tipo_mut_0;
vector <int> tipo_mut_1;
vector <int> tipo_mut_2;
vector <int> tipo_mut_3;
vector <int> tipo_mut_4;
vector <int> tipo_mut_tot;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);

//functions
void gen_i(int, int, int, char const*, int );
void inizializza(void);
void genera_popolazione(char const*);
void genera_popolazione_efficace(char const*, char const*, char const*, int);
void trova_coalescenze(char const*, int);
void stampa_dim_pop(char const*);
void inizializza_mu(void);
void assegna_rami(char const*, int);
void metti_mutazioni(int);
void stampa_mutazioni(char const *);

#endif

