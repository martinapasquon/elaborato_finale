   

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
//CODICE CHE TROVA LE COALESCENZE CON L'ALGORITMO USATO PER SIMULARE LA POPOLAZIONE EFFICACE
////////////////////////////////////
//si consiglia di commentare/decommentare un codice o l'altro, non di usarli contemporaneamente
/*
    ofstream out_vec_3("vect_15_1_3.txt");
    ofstream out_vec_2("vect_15_1_2.txt");
    P[0]=P_0;
    P[1]=P_1;
    P[2]= P_2;
    for (int y=0; y<n_tr_tot; y++){
        do{v[0]=N_0;
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
            gsl_ran_multinomial ( r,3 ,v[i-1] , P, n_figlie);
            v_1[i-1]=n_figlie[1];
            v_2[i-1]=n_figlie[2];
            v_0[i-1]=n_figlie[0];
            v[i]=((2*v_2[i-1])+v_1[i-1]);
            gsl_rng_free (  r );  
        }

    }while(v[n_gen-1]<n_cellule);
    v_possibili[n_gen-1]=n_cellule;
      
    for(int i= n_gen-1 ; i>0; i--){
        for (int l=0;l < v_possibili[i]; l++){
            conta_uguali=0;  
            do{
                conta_norip=0;
                uniform_int_distribution<unsigned long> dist(1,v[i]); 
                a_i= dist(generator);
                    for (unsigned long k=0; k<bott.size(); k++){
                         if(a_i==bott[k])
                              conta_norip++;                   
                    }
            }while(conta_norip>0);

            costa=a_i;
            if(a_i>(v_2[i-1]+v_1[i-1])){
                    costa=a_i-v_2[i-1];
            }
             
            for (unsigned long k=0; k<bott_coppie.size(); k++){
                if(costa==bott_coppie[k])
                    conta_uguali+=1;
            }
            bott.push_back(a_i);
            bott_coppie.push_back(costa);
            if(conta_uguali==0)
                bott_fin.push_back(a_i);
             
        }

               
        v_possibili[i-1]=bott_fin.size();
            if(v_possibili[i-1]==1 and v_possibili[i]==3){
                cout << "errore!!"<< endl;
            }
            if(v_possibili[i-1]!=v_possibili[i] and v_possibili[i-1]==2){
                out_vec_3 << n_gen-(i-1) << endl;
            }
            if(v_possibili[i-1]!=v_possibili[i] and v_possibili[i-1]==1){
                out_vec_2 << n_gen-(i-1) << endl;
            }
              
           
            bott.clear(); 
            bott_fin.clear();
            bott_coppie.clear();

    }
}
out_vec_3.close();
out_vec_2.close();
  
*/
//CODICE CHE TROVA LE COALESCENZE CON L'ALGORIRMO BACKWARD
////////////////////////////////////

    ofstream out_rev("br_reverse_15_0.8.txt");
    for (int y=0; y<n_tr_tot; y++){
         conta1_rev=30;
         conta_rev=30;
         P[0]=P_0;
         P[1]=P_1;
         P[2]= P_2;
       
         do{
            v[0]=N_0;
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
    
                gsl_ran_multinomial ( r,3 ,v[i-1] , P, n_figlie);
                v_1[i-1]=n_figlie[1];
                v_2[i-1]=n_figlie[2];
                v_0[i-1]=n_figlie[0];
                v[i]=((2*v_2[i-1])+v_1[i-1]);
                gsl_rng_free (  r );  
            } 
        }while(v[n_gen-1]<n_cellule);
        gen[0]=0;
        gen[1]=1;
        gen[2]=2;  

        for(int i=n_gen-1; i>0; i--){ 
             if (gen[0]!=gen[1] and gen[0]!=gen[2]){
                if(gen[1]!=gen[2]){
                     uniform_int_distribution<unsigned long> dist(1,v[i]);
                     gen[0]= dist(generator);
                     do{
                         uniform_int_distribution<unsigned long> dist(1,v[i]);
                         gen[1]= dist(generator);
                     }while(gen[0]==gen[1]);
                     do{
                         uniform_int_distribution<unsigned long> dist(1,v[i]);
                         gen[2]= dist(generator);
                     }while(gen[0]==gen[2] or gen[1]==gen[2]);
               
                     for (int l=0;l < n_cellule; l++){
                         if( gen[l]>(v_2[i-1]+v_1[i-1])){
                             gen[l]=gen[l]-v_2[i-1];
                         }
                     }
                     
                     conta_rev=i;
                }
             }
        }
     
        if(gen[0]==gen[1] or gen[0]==gen[2]){
             if(conta_rev!=30){
                 out_rev <<n_gen +1- conta_rev << endl;}
        }
        else if( gen[2]==gen[1] ){
            if(conta_rev!=30){
                out_rev <<n_gen +1 - conta_rev << endl;
            }
        }
      
        if(gen[0]==gen[1] and gen[0]==gen[2]){
            cout << "err tutte e tre sono uguali!" << n_gen+1- conta_rev << "  "<< v[conta_rev] << "  "<<  endl;
        }
        
        if (gen[0]==gen[1] and gen[0]!=gen[2]){ gen_i(0,1,2);}
        else if (gen[0]==gen[2] and gen[0]!=gen[1]){ gen_i(0,2,1) ;}
        else if (gen[1]==gen[2] and gen[1]!=gen[0]){ gen_i(1,2,0);}

    
  
        if (out_rev.eof()){
            cout << "è stata raggiunta la fine del file, esco!"<< endl;
            exit(11);
        }
    
        conta_rev=0;
        conta1_rev=0;
        gen[0]=1;
        gen[1]=2;
        gen[2]=3;  
    }
  

    out_rev.close();

return 0;
}







void gen_i(int a, int b, int c) {
    int n_cell=n_cellule-1;
    ofstream Rami_grandi("br_reverse_long_15_0.06.txt", ios::app);
    for(int i=conta_rev-1; i>0; i--){
        if ( gen[a]!=gen[c]){
             uniform_int_distribution<unsigned long> distl(1,v[i]); 
             gen[a]= distl(generator);
             do{
                uniform_int_distribution<unsigned long> distk(1,v[i]); 
                gen[c]= distk(generator);
             }while(gen[a]==gen[c]);
 
             if( gen[a]>(v_2[i-1]+v_1[i-1])){
                    gen[a]=gen[a]-v_2[i-1];
             }
             if( gen[c]>(v_2[i-1]+v_1[i-1])){
                  gen[c]=gen[c]-v_2[i-1];
             }

             conta1_rev=i;
        }
    }

    if (gen[a]==gen[c]){
         Rami_grandi  <<  conta_rev-conta1_rev  << setw(20) << n_gen +1-conta1_rev << endl;
    }
    
  
    Rami_grandi.close();
}
