   

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

//somma=0;
//numero=0;
ifstream input("input.in");
input >> restart;
input.close();
if(restart==1){
/*
for (int n_Ngen0=0; n_Ngen0<25; n_Ngen0++){
   conta_N_0=0;
uguali_N_0=0;

  //  n_gen_0=60-n_Ngen0=*0.5;   
   P_alive=P_alive + 0.005;
     n_gen=n_gen_arr[n_Ngen0];
     n_gen_0=n_gen0_arr_0[n_Ngen0];
   // n_gen_0=n_gen_0*2.5;
   // n_gen=n_gen*(0.5 +0.5*n_Ngen0);
     /*
    for (int n_n=0; n_n <20; n_n++){
        // n_gen_0=n_gen_0+5;
        n_gen_0=n_gen_0*(1+0.1);
    //n_gen_0=n_gen0_arr[n_Ngen01];
      */ 
      v_dead=(1-pow(1-P_alive, 2));
      P_2=P_alive*P_alive;
      P_0=(pow(1-P_alive, 2));
      P_1=2.*P_alive*(1-P_alive);
      //const double P[3];
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
   //cout << v_2.size() << endl;
   
   for (int y=0; y<n_tr_tot; y++){
      
      //mu_arr[y+(n_n*n_tr_tot)+(n_Ngen01*n_n*n_tr_tot)]=mut_totali/(N_m*(n_gen_0+(n_alb*n_gen)));
      inizializza();
      genera_popolazione("da_buttareLC_CRC0282_ngen0_120_variare_Pa_7.txt");
      genera_popolazione_efficace("LMobabilita_1599LMerr.txt", "1599LMpoplaz.txt",  "1599LMposs.txt", y);
       //  if(y==0)
       //  stampa_dim_pop("1599LMpop.txt");
      trova_coalescenze("LC_CRC0282_ngen0_120.txt", y);
     

 //}
  //}
}v.clear(); v_possibili.clear(); v_possibili1.clear(); v_possibili2.clear(); v_1.clear(); v_2.clear(); v_0.clear();v_possibili_N0.clear();
//}


//}
}
if(restart==1){

//for (int n_Ngen01=0; n_Ngen01<25; n_Ngen01++){
 /*     
  // P_alive=P_alive + 0.005;
     n_gen=n_gen_arr[n_Ngen01];
     n_gen_0=n_gen0_arr_0[n_Ngen01];
   // n_gen_0=100+(10*n_Ngen01);
   //  n_gen_0=n_gen_0*1.5;
    // n_gen_0=100;
   // for (int n_n=0; n_n<20; n_n++){
     //     n_gen_0=n_gen_0+1;//n_gen_0*(1+0.01);
    //n_gen_0=n_gen0_arr[n_Ngen01];
      
      v_dead=(1-pow(1-P_alive, 2));
      P_2=P_alive*P_alive;
      P_0=(pow(1-P_alive, 2));
      P_1=2.*P_alive*(1-P_alive);
      P[0]=P_0; P[1]=P_1; P[2]=P_2;
     // double P[3]=[P_0, P_1, P_2];
*/
   /*
  for (int n_mu=0; n_mu<20; n_mu++){ 
  for (int y=0; y<n_tr_tot; y++){
    mu_arr[y+(n_Ngen01*n_tr_tot)]=(mut_totali/(N_m*(n_gen_0+(n_alb*n_gen))))*(0.1 + n_mu*0.1);
    */
    //  if((y+(n_n*n_tr_tot)+(n_Ngen01*27*n_tr_tot))<5000)
    //// cout << mu_arr[y+(n_n*n_tr_tot)+(n_Ngen01*27*n_tr_tot)]<<"  " << y+(n_n*n_tr_tot)+(n_Ngen01*27*n_tr_tot)<<"  "<<mut_totali/(N_m*(n_gen_0+(n_alb*n_gen)))<< "   "<< mut_totali<< "  "<< N_m*(n_gen_0+(n_alb*n_gen))<<  endl;

   //   }
 // }
//}
//}
  



  
   
   //void inizializza_mu();
//mu=mut_totali/(double)(N_m*(n_gen_0+(n_alb*n_gen)));
 cout << "mu  "<< mu << endl;  
       ifstream in_rami ("LC_CRC0282_ngen0_120.txt");
   int rev=0;
   double mu_iniz=mu*0.1;
   double delta_mu=mu*0.02;
  for (int l=0; l<(n_tr_tot); l++){
   in_rami >> tau[0] >> tau[1] >> tau[2] >> tau[3];
   for (int n_mu=0; n_mu<50; n_mu++){ 
    mu=mu_iniz+delta_mu*n_mu;

    //  cout << mu*N_m << endl;
   
       
       if(mu==0)
       cout << mu <<"  " << l <<   endl ;
   //cout <<y << "  " <<  tau[0] << "  " << tau[1] << endl;

   rami[0]=tau[0];
   rami[1]=tau[0];
   rami[2]=tau[2];
   rami[3]=tau[1];
   rami[4]=tau[3];
  
  // for (int n_mu=0; n_mu<36; n_mu++){
  
  // mu=mu+0.1E-9;
 // cout << mu << "  " << endl;
  
      for (int n_ramo=0; n_ramo< n_cellule+ (n_cellule-1); n_ramo++)
         metti_mutazioni(n_ramo);
      stampa_mutazioni("mut_LC_CRC0282_ngen0_120.txt" );
  } in_rami.close(); 
}
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
 
  
    struct timeval tv; // Seed generation based on time
    gettimeofday(&tv,0);
    unsigned long mySeed = tv.tv_sec + tv.tv_usec;
    T = gsl_rng_default; // Generator setup
    r = gsl_rng_alloc (T);
    gsl_rng_set(r, mySeed);
    
 // cout << *r << endl;
          //  cout << i << endl;
            gsl_ran_multinomial ( r,3 ,v[i-1] , P, n_figlie);
           // binomial_distribution< unsigned long long> distr1(v[i-1], P_1);
           //  v_1[i-1]=distr1(generator); 
            v_1[i-1]=n_figlie[1];
            v_2[i-1]=n_figlie[2];
            v_0[i-1]=n_figlie[0];
            v[i]=((2*v_2[i-1])+v_1[i-1]);
           // if(v[i]>200)
            //cout << n_figlie[1] << "  " << n_figlie[2] << "  " << n_figlie[0] << "  "<< v[i-1] << "  " << P[0]<<  endl;
            // double p=(P_2)/(P_0+P_2);
           // binomial_distribution<unsigned  long long> distr2((v[i-1]-v_1[i-1]), p);
             //v_2[i-1]=distr2(generator); 
          //out_gen_0 << v[n_gen_0 -1] << endl;   
          //   cout << v[i] << endl;
         gsl_rng_free (  r );
      }
      
   }while(v[n_gen_0 -1]<N_cell_bott);//cout << v[n_gen_0 -1] << endl;
   out_gen_0 << v[n_gen_0 -1] << endl;
   
   
   for (int x=0; x<n_alb; x++){
     // cout << x << endl;
      v[(n_gen*x)+n_gen_0]=N_0; 
      do{
         for(int i=1; i<n_gen; i++){
            
    const gsl_rng_type * T;
    gsl_rng * r;
    gsl_rng_env_setup();
 
  
    struct timeval tv; // Seed generation based on time
    gettimeofday(&tv,0);
    unsigned long mySeed = tv.tv_sec + tv.tv_usec;
    T = gsl_rng_default; // Generator setup
    r = gsl_rng_alloc (T);
    gsl_rng_set(r, mySeed);
            gsl_ran_multinomial ( r,3 ,v[(i+(n_gen*x)+n_gen_0)-1] , P, n_figlie);
            v_0[(i+(n_gen*x)+n_gen_0)-1 ]=n_figlie[0];
            v_1[(i+(n_gen*x)+n_gen_0) -1]=n_figlie[1];
            v_2[(i+(n_gen*x)+n_gen_0) -1]=n_figlie[2];
            v[i+(n_gen*x)+n_gen_0]=((2*v_2[(i+(n_gen*x)+n_gen_0) -1])+v_1[(i+(n_gen*x)+n_gen_0) -1]);
       
           //cout<< i+(n_gen*x)+n_gen_0 << "  " << i << "  " << x << endl;
              gsl_rng_free (  r );
  
    T = gsl_rng_default; // Generator setup
    r = gsl_rng_alloc (T);
    gsl_rng_set(r, mySeed);
            gsl_ran_multinomial ( r,3 ,v[((n_gen*n_alb)+n_gen_0)] , P, n_figlie);
            v_0[((n_gen*n_alb)+n_gen_0)]=n_figlie[0];
              gsl_rng_free (  r );
            /* binomial_distribution< long long> distr1(v[(i+(n_gen*x)+n_gen_0) -1], P_1);
             v_1[(i+(n_gen*x)+n_gen_0) -1]=distr1(generator); 
             double p=(P_2)/(P_0+P_2);
             binomial_distribution< long long> distr2((v[(i+(n_gen*x)+n_gen_0) -1]-v_1[(i+(n_gen*x)+n_gen_0) -1]), p);
             v_2[(i+(n_gen*x)+n_gen_0) -1]=distr2(generator);
             v[i+(n_gen*x)+n_gen_0]=((2*v_2[(i+(n_gen*x)+n_gen_0) -1])+v_1[(i+(n_gen*x)+n_gen_0) -1]);*/
         //  cout << v[i+(n_gen*x)+n_gen_0] << "  "  << i+(n_gen*x)+n_gen_0<< endl;
          
         }
        
      }while(v[n_gen -1 +n_gen*x+n_gen_0]< N_0);
   }// cout << "pow " << endl;
   out_gen_0.close();
}



void genera_popolazione_efficace(char const* filename, char const* filename1, char const* filename2, int y){
    //  ofstream out_LMobabilita(filename);
//ofstream out_v_v0(filename1, ios::app);
//ofstream out_possibili(filename2, ios::app);
      gen[0]=1;
      gen[1]=2;
      gen[2]=45;  
      



     
     
    for(int i= (n_gen*n_alb)+n_gen_0-1; i>n_gen*(n_alb-1)+n_gen_0; i--){
         v_possibili[i]=v[i];
         v_possibili[( n_gen*(n_alb-1))+n_gen_0]=N_0;
        // cout<< i << "  " <<v_possibili[i] << endl;

      }
      
       
      for(int i= n_gen*(n_alb-1)+n_gen_0; i>0; i--){
       //  if(i<=n_gen_0)
    //cout <<i << "  " << v_possibili[i] << "  " << v[i] << endl;
         for (int l=0;l < v_possibili[i]; l++){
           
             
            conta_uguali=0;  conta_norip=0; 
            do{
               conta_norip=0;
               uniform_int_distribution<int> dist(1,v[i]); 
               a_i= dist(generator);
              //  cout << "a_i MRima " << a_i << endl;
               for (int k=0; k<bott.size(); k++){
                  if(a_i==bott[k])
                     conta_norip++;
                        // cout << i << "   " <<v[i-1] << "  " << v_possibili[i] <<  "   ai= " << a_i << "  bott=" << bott[k] << "conta uguali= " << conta_norip << endl;
               }
            }while(conta_norip>0);
         
            costa=a_i;
          if(a_i>(v[i-1])){
                 // cout << "LMima"  << gen[l] << "  " << v_2[i-1] << endl;
                  costa=costa-(v[i]-(v[i-1]));
                 // cout <<"dopo"  << gen[l] << endl;
                 }
         
            for (int k=0; k<bott_coppie.size(); k++){
               if(costa==bott_coppie[k])
                  conta_uguali+=1;
                      //   cout << "ai= " << a_i << "  bott=" << bott[k] << "conta uguali= " << conta_uguali << endl;
            }
            
           
               
            
               // cout << costa << "  " <<  endl;
               // cout <<"alla fine: " <<  "  ai= " << a_i  << "conta uguali= " << conta_uguali << endl;
            bott.push_back(a_i);
            bott_coppie.push_back(costa);
               if(conta_uguali==0)
                  bott_fin.push_back(a_i);
         }
         v_possibili[i-1]=bott_fin.size();
     // cout <<v_possibili[i]<< "  " <<  v_possibili[i-1] << "  " <<v[i] << "  " << v[i-1]  << endl;
        // conta_LMobablilita= v_possibili[i]- v_possibili[i-1];
        // out_LMobabilita << (double)(conta_LMobablilita)/(v_possibili[i-1]) << "  " << (double)(v_possibili[i]-2*conta_LMobablilita)/(v_possibili[i-1]) << endl;  

         bott.clear(); 
         bott_fin.clear();
         bott_coppie.clear();
         
           
      }
         
      
        


}
void stampa_dim_pop(char const* filename){
   ofstream out(filename, ios::app);
   for (int cposs=n_gen*n_alb+n_gen_0-1; cposs>=0; cposs--){
      //  if((cposs-n_gen_0)%n_gen ==0 and cposs>n_gen_0)
         //  v[cposs]=N_0;

        out << cposs << "     " <<  v_possibili[cposs] <<   "     " << v[cposs] <<  "     " << v_possibili_N0[cposs] << "     "  << v_0[cposs] << endl;}
   out.close();

}

void trova_coalescenze(char const* filename, int y){ 
   v[0]=1;

   for(int i= (n_gen*n_alb)+n_gen_0-1; i>0; i--){
    // cout <<"ii " <<i << "  " <<v[i] <<"  "  << v[i-1]<<"  " <<y << endl;
       /*
           if((i-n_gen_0)%n_gen ==0 and i>n_gen_0){
            // cout <<i << "  "<<  v[i] << endl;
               binomial_distribution<unsigned long long> distribution(2*v[i-1], P_alive);
               v[i]=distribution(generator); 
            // cout << v[i] << endl;
            }
       v_possibili[i]=v[i];
        v_possibili[i-1]=v[i-1];
*/

   // v_possibili2[i-1]=v_possibili[i]-v_possibili[i-1];
   // v_possibili1[i-1]=v_possibili[i]-(2*v_possibili2[i-1]);
         if ((gen[0])!=gen[1] and gen[0]!=gen[2]){
            if(gen[1]!=gen[2]){
              // cout << v[i] <<"  " << i << endl;
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
               //if(i<20)
              //  cout << v[i] <<"  " << v[i-1] <<  endl;
               for (int l=0;l < n_cellule; l++){ //cout <<"MRima" <<  gen[l] << endl;
                 if(i<= (n_gen*(n_alb-1))){
                  if( gen[l]>(v_possibili[i-1])){
                 // cout << "LMima"  << gen[l] << "  " << v_possibili[i-1] <<"  " << v_possibili[i]<<  "  " << v_possibili2[i-1] << "  " << v_possibili1[i-1]  << endl;
                  gen[l]=gen[l]-(v_possibili[i]-v_possibili[i-1]);
                // cout <<"dopo"  << gen[l] << endl;
                 }
                 }
                 else{
                  if( gen[l]>(v_1[i-1]+v_2[i-1])){
                 // cout << "LMima"  << gen[l] << "  " << v_possibili[i-1] <<"  " << v_possibili[i]<<  "  " << v_possibili2[i-1] << "  " << v_possibili1[i-1]  << endl;
                  gen[l]=gen[l]-(v_2[i-1]);
                // cout <<"dopo"  << gen[l] << endl;
                 }
                  
                 }
               //  else
                // cout << "non "  << gen[l] << "  " << v_possibili[i-1] <<"  " << v_possibili[i]<<  "  " << v_possibili2[i-1] << "  " << v_possibili1[i-1]  << endl;
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
   //cout <<y << "  " <<  tau[0] << "  " << tau[1] << endl;

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
//cout << mu << endl;
//mu_arr[a]+=(double)mutazioni[a]/(rami[a]*N_m);
//mu_2[a]+=pow(((double)mutazioni[a]/(rami[a]*N_m)),2);
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
     /*
      if((i-n_gen_0)%n_gen ==0 and i>n_gen_0){
              // cout <<i << "  "<<  v[i] << endl;
               binomial_distribution<unsigned long long> distribution(2*v[i-1], P_alive);
               v[i]=distribution(generator); 
            // cout << v[i] << endl;
            }
       v_possibili[i]=v[i];
       v_possibili[i-1]=v[i-1];*/
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
         //cout << v[i] <<"  " << v[i-1] << "  "<< gen[a] << "  " << gen[c] <<  endl;
    }
}
  if (gen[a]==gen[c]){
      out_coal  <<  n_gen*n_alb +n_gen_0 -conta  << setw(10) << n_gen*n_alb +n_gen_0 -conta1 << setw(10) << conta-conta1 <<  setw(10) << conta1 << endl;

  //  cout << y << "  " <<  n_gen*n_alb +n_gen_0 -conta  << "   " << n_gen*n_alb +n_gen_0 -conta1 << endl;
 } 
out_coal.close();
}
