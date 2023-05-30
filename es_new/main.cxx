   

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include "funzioni.h"
#include "main.h"
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_rng.h>
#include <sys/time.h>

using namespace std;
int main() {


unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);


ifstream input("input.in");
input >> restart;
input.close();
if(restart==1){ //simulazione della popolazione e delle coalescenze
/* // togliere il commento per effettuare una simulazione al variare di Ngen0, P_alive e/o n_gen (**)
for (int n_Ngen0=0; n_Ngen0<25; n_Ngen0++){
   conta_N_0=0;
   uguali_N_0=0;
 
   P_alive=P_alive + 0.005;
   n_gen=n_gen_arr[n_Ngen0];
   n_gen_0=n_gen0_arr_0[n_Ngen0];
  */ 
    
    v_dead=(1-pow(1-P_alive, 2));
    P_2=P_alive*P_alive;
    P_0=(pow(1-P_alive, 2));
    P_1=2.*P_alive*(1-P_alive);
      P[0]=P_0;
      P[1]=P_1;
      P[2]= P_2;
   cout << n_gen_0 << "  " << n_gen << "  " << P_alive << endl;
 
    v.resize(n_gen_0 +n_alb*n_gen, 0);
   v_possibili.resize(n_gen_0 +n_alb*n_gen, 0);
   v_possibili2.resize(n_gen_0 +n_alb*n_gen, 0);
   v_possibili1.resize(n_gen_0 +n_alb*n_gen, 0);
    v_possibili_N0.resize(n_gen_0 +n_alb*n_gen, 0);
    v_0.resize((n_gen_0 +n_alb*n_gen), 0);
   v_1.resize((n_gen_0 +n_alb*n_gen), 0);
   v_2.resize((n_gen_0 +n_alb*n_gen), 0);

   
   for (int y=0; y<n_tr_tot; y++){
        inizializza(); //inizializza la popolazione e i contatori
        genera_popolazione("popolazione.txt"); //genera la popolazione di cellule
        genera_popolazione_efficace("prob_1599LM.txt", "1599LM_popolazione.txt",  "1599LM_possibili.txt", y); //genera la popolazione efficace
       //  if(y==0) // togliere il commento per stampare su file la dimensione della popolazione e della popolazione efficace per una simulazione
       //  stampa_dim_pop("1599LMpop.txt");
         trova_coalescenze("LC_CRC0282_ngen0_120.txt", y); //trova le coalescenze delle Ncell cellule
    }v.clear(); v_possibili.clear(); v_possibili1.clear(); v_possibili2.clear(); v_1.clear(); v_2.clear(); v_0.clear();v_possibili_N0.clear();



//} // togliere il commento se si toglie anche in  (**)
}
if(restart==1){ //simulazione delle mutazioni
 /* // togliere il commento se si toglie anche in  (**)  
for (int n_Ngen01=0; n_Ngen01<25; n_Ngen01++){
     P_alive=P_alive + 0.005;
     n_gen=n_gen_arr[n_Ngen01];
     n_gen_0=n_gen0_arr_0[n_Ngen01];
   
      v_dead=(1-pow(1-P_alive, 2));
      P_2=P_alive*P_alive;
      P_0=(pow(1-P_alive, 2));
      P_1=2.*P_alive*(1-P_alive);
      P[0]=P_0; P[1]=P_1; P[2]=P_2;

 }
*/
  

   ifstream in_rami ("LC_CRC0282_ngen0_120.txt"); //si usa un file che contiene le coalescenze per simulare le mitazioni
   int rev=0;
   double mu_iniz=mu*0.1;
   double delta_mu=mu*0.02;
  for (int l=0; l<(n_tr_tot); l++){ //leggo le coalescenze 
   in_rami >> tau[0] >> tau[1] >> tau[2] >> tau[3];
   for (int n_mu=0; n_mu<50; n_mu++){  //se voglio far variare mu, se no commento e uso il mu nell'header
    mu=mu_iniz+delta_mu*n_mu;



   rami[0]=tau[0];
   rami[1]=tau[0];
   rami[2]=tau[2];
   rami[3]=tau[1];
   rami[4]=tau[3];
  
 
  
   for (int n_ramo=0; n_ramo< n_cellule+ (n_cellule-1); n_ramo++)
        metti_mutazioni(n_ramo); //associa le mutazioni ai rami 
   stampa_mutazioni("mut_LC_CRC0282_ngen0_120.txt" ); //stampa su file le mutazioni
  } in_rami.close(); 
}




return 0;
}




void inizializza(){
   for(int i=1; i<n_gen; i++)
      v[i]=0;
      conta1=0;
      conta=0;
}



void genera_popolazione(char const* filename){
   ofstream out_gen_0 (filename, ios:: app);
   v[0]=1;
    
   do{
    
      for(int i=1; i<n_gen_0; i++){
          const gsl_rng_type * T;
          gsl_rng * r;
          gsl_rng_env_setup();
          struct timeval tv;
          gettimeofday(&tv,0);
          unsigned long mySeed = tv.tv_sec + tv.tv_usec;
          T = gsl_rng_default; // Generator setup
          r = gsl_rng_alloc (T);
          gsl_rng_set(r, mySeed);

          gsl_ran_multinomial ( r,3 ,v[i-1] , P, n_figlie);
          
            v_1[i-1]=n_figlie[1];
            v_2[i-1]=n_figlie[2];
            v_0[i-1]=n_figlie[0];
            v[i]=((2*v_2[i-1])+v_1[i-1]);
           
         gsl_rng_free (  r );
      }
      
   }while(v[n_gen_0 -1]<N_cell_bott); //se la popolazione non raggiunge il minimo della dimensione ripete la simulazione
   out_gen_0 << v[n_gen_0 -1] << endl;
   
   
   for (int x=0; x<n_alb; x++){
      v[(n_gen*x)+n_gen_0]=N_0; 
      do{
         for(int i=1; i<n_gen; i++){
             const gsl_rng_type * T;
             gsl_rng * r;
             gsl_rng_env_setup();
             struct timeval tv; 
             gettimeofday(&tv,0);
             unsigned long mySeed = tv.tv_sec + tv.tv_usec;
             T = gsl_rng_default; 
             r = gsl_rng_alloc (T);
             gsl_rng_set(r, mySeed);
            gsl_ran_multinomial ( r,3 ,v[(i+(n_gen*x)+n_gen_0)-1] , P, n_figlie);
            v_0[(i+(n_gen*x)+n_gen_0)-1 ]=n_figlie[0];
            v_1[(i+(n_gen*x)+n_gen_0) -1]=n_figlie[1];
            v_2[(i+(n_gen*x)+n_gen_0) -1]=n_figlie[2];
            v[i+(n_gen*x)+n_gen_0]=((2*v_2[(i+(n_gen*x)+n_gen_0) -1])+v_1[(i+(n_gen*x)+n_gen_0) -1]);
       
      
             gsl_rng_free (  r );
  
             T = gsl_rng_default; // Generator setup
             r = gsl_rng_alloc (T);
             gsl_rng_set(r, mySeed);
            gsl_ran_multinomial ( r,3 ,v[((n_gen*n_alb)+n_gen_0)] , P, n_figlie);
            v_0[((n_gen*n_alb)+n_gen_0)]=n_figlie[0];
              gsl_rng_free (  r );      
         }
        
      }while(v[n_gen -1 +n_gen*x+n_gen_0]< N_0);
   }
   out_gen_0.close();
}

   
   
void genera_popolazione_efficace(char const* filename, char const* filename1, char const* filename2, int y){
// ofstream out_prob(filename);
//ofstream out_v_v0(filename1, ios::app);
//ofstream out_possibili(filename2, ios::app);
      gen[0]=1;
      gen[1]=2;
      gen[2]=45;  
      



     
     
    for(int i= (n_gen*n_alb)+n_gen_0-1; i>n_gen*(n_alb-1)+n_gen_0; i--){
         v_possibili[i]=v[i];
         v_possibili[( n_gen*(n_alb-1))+n_gen_0]=N_0;
      }
      
       
      for(int i= n_gen*(n_alb-1)+n_gen_0; i>0; i--){
      
         for (int l=0;l < v_possibili[i]; l++){             
            conta_uguali=0;  conta_norip=0; 
            do{
               conta_norip=0;
               uniform_int_distribution<int> dist(1,v[i]); 
               a_i= dist(generator);
               for (int k=0; k<bott.size(); k++){
                  if(a_i==bott[k])
                     conta_norip++;       
               }
            }while(conta_norip>0);
         
            costa=a_i;
            if(a_i>(v[i-1])){
               costa=costa-(v[i]-(v[i-1]));
                 }
         
            for (int k=0; k<bott_coppie.size(); k++){
               if(costa==bott_coppie[k])
                  conta_uguali+=1;
                     
            }
            
            bott.push_back(a_i);
            bott_coppie.push_back(costa);
               if(conta_uguali==0)
                  bott_fin.push_back(a_i);
         }
         v_possibili[i-1]=bott_fin.size();
         bott.clear(); 
         bott_fin.clear();
         bott_coppie.clear();
          
      }
//out_prob.close();
//out_v_v0.close();
//out_possibili.close();
}
   
   
   
void stampa_dim_pop(char const* filename){
   ofstream out(filename, ios::app);
   for (int cposs=n_gen*n_alb+n_gen_0-1; cposs>=0; cposs--){
        out << cposs << "     " <<  v_possibili[cposs] <<   "     " << v[cposs] <<  "     " << v_possibili_N0[cposs] << "     "  << v_0[cposs] << endl;}
   out.close();

}

void trova_coalescenze(char const* filename, int y){ 
   v[0]=1;

   for(int i= (n_gen*n_alb)+n_gen_0-1; i>0; i--){
   
         if ((gen[0])!=gen[1] and gen[0]!=gen[2]){
            if(gen[1]!=gen[2]){
               uniform_int_distribution<unsigned long long> dista(1,v_possibili[i]);
               gen[0]= dista(generator);

               do{
                  uniform_int_distribution<unsigned long long> distb(1,v_possibili[i]);
                  gen[1]= distb(generator);
               }while(gen[0]==gen[1]);

               do{
                  uniform_int_distribution<unsigned long long> distc(1,v_possibili[i]);
                  gen[2]= distc(generator);
               }while(gen[0]==gen[2] or gen[1]==gen[2]);
            
               for (int l=0;l < n_cellule; l++){ 
                  if(i<= (n_gen*(n_alb-1))){
                    if( gen[l]>(v_possibili[i-1])){
                        gen[l]=gen[l]-(v_possibili[i]-v_possibili[i-1]);
                     }
                   }
                else{
                  if( gen[l]>(v_1[i-1]+v_2[i-1])){
                         gen[l]=gen[l]-(v_2[i-1]);
                   }
                  
                }
             }     
             conta=i;  
            }
         }     
   }
    
   if(gen[0]==gen[1] and gen[0]==gen[2]){
      cout << "erroe!!" << endl;
   }
   if (gen[0]==gen[1] and gen[0]!=gen[2]) gen_i(0,1,2, filename, conta);
   else if (gen[0]==gen[2] and gen[0]!=gen[1]) gen_i(0,2,1, filename, conta);
   else if (gen[1]==gen[2] and gen[1]!=gen[0]) gen_i(1,2,0, filename, conta);


  conta=0;
  conta1=0;
  gen[0]=1;
  gen[1]=2;
  gen[2]=45;  
 }



 void inizializza_mu(){
   for (int i=0; i<n_cellule; i++){
      mu_arr[i]=0;
      mu_2[i]=0;
   }
 }



void assegna_rami(char const * filename, int y){
   ifstream in_rami (filename, ios::app);
   int rev=0;
   for(int k=0; k<=y; k++)
       in_rami >> tau[0] >> tau[1] >> tau[2] >> tau[3] ;

   rami[0]=tau[0];
   rami[1]=tau[0];
   rami[2]=tau[2];
   rami[3]=tau[1];
   rami[4]=tau[3];
   in_rami.close();
}

void metti_mutazioni(int a ){
binomial_distribution< long long> distr(N_m*rami[a],mu);
mutazioni[a]=distr(generator); 
}




void stampa_mutazioni(char const *filename){
   ofstream out_mutazioni(filename, ios::app);
   out_mutazioni << mutazioni[0] <<"      " << mutazioni[1] <<"      "<<mutazioni[2] <<"      "<<mutazioni[3] <<"      " <<  mutazioni[4] << endl;
   out_mutazioni.close();
}





void gen_i(int a, int b, int c, char const*filename, int conta) {
   ofstream out_coal(filename, ios:: app);
   v[0]=1;
     for(int j=conta-1; j>0; j--){

      if ( gen[a]!=gen[c]){
         uniform_int_distribution<unsigned long long> distl(1,v_possibili[j]); 
         gen[a]= distl(generator);
  
         do{
            uniform_int_distribution<unsigned long long> distk(1,v_possibili[j]); 
            gen[c]= distk(generator);
         }while(gen[a]==gen[c]);

        if(j>(n_gen*(n_alb-1))){
         if(gen[a]>(v_1[j-1]+v_2[j-1])){
       
         gen[a]=gen[a]-v_2[j-1];
         }
               
          if(gen[c]>(v_1[j-1]+v_2[j-1])){
           
         gen[c]=gen[c]-v_2[j-1];  
          }  
        }
        else{
          if(gen[a]>v_possibili[j-1]){
       
         gen[a]=gen[a]-(v_possibili[j]-v_possibili[j-1]);
         }
               
          if(gen[c]>v_possibili[j-1]){
           
         gen[c]=gen[c]-(v_possibili[j]-v_possibili[j-1]);  
          }  

        }
         conta1=j;
        
    }
}
  if (gen[a]==gen[c]){
      out_coal  <<  n_gen*n_alb +n_gen_0 -conta  << setw(10) << n_gen*n_alb +n_gen_0 -conta1 << setw(10) << conta-conta1 <<  setw(10) << conta1 << endl;

 
 } 
out_coal.close();
}
