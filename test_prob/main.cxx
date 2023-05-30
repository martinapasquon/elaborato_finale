   
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

    ofstream out_rev("br_reverse_test20gennorip.txt", ios::app);
    ofstream out("p05_multi.txt");
    P[0]=P_0; P[1]=P_1; P[2]=P_2; 
  for (int y=0; y<n_tr_tot; y++){
         v[0]=N_0;
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

                gsl_ran_multinomial ( r,3 ,v[i-1] , P, n_figlie);
          
                v_1[i-1]=n_figlie[1];
                v_2[i-1]=n_figlie[2];
                v_0[i-1]=n_figlie[0];
                v[i]=((2*v_2[i-1])+v_1[i-1]);
          
                gsl_rng_free (  r );
      
            } 
        }while(v[n_gen-1]==0); // se la popolazione si estingue, fa un'altra simulazione
     
        gen[0]=0;
        gen[1]=1;
        gen[2]=2;  

        for(int i=n_gen-1; i>0; i--){
            v_gen.clear();
             for (long k=0; k<v[i]; k++) 
                v_gen.push_back(k+1);
                for (long k=0; k<v[i]; k++){
                    if( v_gen[k]>(v_2[i-1]+v_1[i-1]))
                        v_gen[k]=v_gen[k]-v_2[i-1];
                }
                  
                for(long k=0; k<v[i]-1; k++){
                    for(long j=k+1; j<v[i]; j++){
                        if (v_gen[k]==v_gen[j])
                            conta++;
                        }  
                }
           
                if(i>5) //trovo le probabilità per le ultime 5 generazioni
                     out << (double)conta/(v[i-1]) << "  " << (double)(v[i]-2*conta)/(v[i-1]) << endl;
            conta=0;
            conta1=0;
 
        }
    }

    out_rev.close();
    out.close();

    return 0;
}


