

#ifndef __fluid__
#define __fluid__

//parametri esperimento
int N_0=100; //numero di cellule dei bottlenecks
int n_gen=34; //numero di generazioni tra due bottlenecks 
const int n_cellule=3; //numero di cellule sequenziate
const int N_cell_bott=1065000; //numero minimo di cellule alla generazione N_gen0
int n_gen_0=120; //numero di generazioni tra l'inizio dell'esperimento e il primo bottleneck (N_gen0)
double mut_totali=2099; //mutazioni totali
//array se si vuole far variare N_gen0 (il primo valore è per P_a=0.52, il secondo per P_a=0.525 ecc, P_a varia di 0.05. L'array è ugulale per tutte le
//linee cellulari).
int n_gen0_arr_0[33]={324,265,224,196,174,157,  143,  131,  122,  114, 107, 101, 95, 90, 86, 82, 79, 76, 73, 70, 67, 65, 63, 61, 59, 57, 56, 55, 54, 52, 51, 50, 49};
//array se si vuole far variare N_gen (il primo valore è per P_a=0.52, il secondo per P_a=0.525 ecc, P_a varia di 0.05 e b-d è tenuto costante. 
//qui ad es è per la linea cellulare CRC1599LM, ma è diverso per ogni linea cellualre)
int n_gen_arr[33]={35,36,37,37,38,39, 40, 41, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 61, 62};


double mu_arr[1000*5*1000];
unsigned int n_figlie[3];
const int n_alb=7; //numero di bottlenecks a N_0
const int n_cell=2;
double N_m=2748711013; //numero di basi sequenziate
double mu=6.33828E-09; //tasso di mutazione
int v_i=0;


//simulazione
const int n_tr_tot=1000; //numero di simulazioni
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


unsigned long long N_max=0;
int a=0;
unsigned long long  a_i=0;
int conta=0;
int conta1=0,  conta_gen0=0;
unsigned long long  conta_norip=0;
double P_alive=0.57814634; //P_a 
double v_dead=(1-pow(1-P_alive, 2));
double P_2=P_alive*P_alive; //probabilità di avere due figlie
double P_0=(pow(1-P_alive, 2)); //probabilità di non avere figlie
double P_1=2.*P_alive*(1-P_alive);  //probabilità di avere una figlia
unsigned long long  costa=0, costa_a=0, costa_b=0, conta_probablilita=0;
double P[3];
 

vector <unsigned long long> bott;
vector <unsigned long long> bott_fin;
vector <unsigned long long> bott_coppie;
unsigned long long  conta_uguali=0;
int errore=0;



//simulazione mutazioni
int rami[5];
int mutazioni[n_cellule+ (n_cellule-1)];
int mutazioni_tot=0;
int N_iter=0;
int i_ramo=0;
int mut_tot=0;

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

