   

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
// ALGORITMO CHE SIMULA L'ALBERO FORWARD
//  si consiglia di commentare/decommentare uno dei due algoritmi alla volta
//////////////////////
/*
    ofstream out_matr("br_matr_50cell_N0100_0.8.txt", ios::app);

    for(int n_tr=0; n_tr<n_tr_tot; n_tr++){
         ofstream out("tree.txt");
         //simula la generazione 0
         do{
            j=0;
            for(int k=0; k<N_0; k++){
                for(int i=0; i<n_fin/N_0; i++){
                   tree[j]=k+1;
                   out<< tree[j] << setw(10);
                   j++;
                }
            }
        }while(j==0);
        out << endl;
        //simula le altre generazioni, tranne l'ultima
        do{
            for(int l=1; l<n_gen-1; l++){
                j=0; 
                for(int m=0; m<N_0*pow(2,l); m++){
                     uniform_real_distribution<double> unif_dist(0,1); 
                     prob=unif_dist(generator);
                     for(int i=0; i<n_fin/(N_0*pow(2,l)); i++){
                        if(l<(n_gen-1)){
                            if(P_alive>=prob and tree[j]!=0 ){
                                 tree_new[j]=m+1;
                             }
                             else tree_new[j]=0;
                        out << tree_new[j] <<setw(10);
                        }  
                    j++; 
                    } 
                }
                for(int m=0; m<n_fin; m++){tree[m]=tree_new[m];}
                out << endl;
            }
         k=0;
         //simula l'ultima generazione
         for(int i=0; i<n_fin; i++){ 
              uniform_real_distribution<double> unif_dist(0,1); 
              prob=unif_dist(generator);
              if(P_alive>=prob and tree[i]!=0 ){
                    tree_new[i]=k+1;
                    k++;
              }
              else tree_new[i]=0;
              out << tree_new[i]<< setw(10);
         } 
         out.close();
   
        }while (k<=n_cellule); // controllo che la popolazione ottenuta abbia almeno n_cellule cellule
         do{ //estrae le n_cellule cellule dalla generazione finale 
        for (int i=0; i< n_cellule; i++){
             do{
                 uniform_int_distribution<int> unif_int(0,n_fin-1); 
                 cell[i]=unif_int(generator);
             }while(tree_new[cell[i]]==0);
        }
        conta_err=0;
        for (int i=0; i<n_cellule; i++){
            for (int j=i+1; j<n_cellule; j++){
                if(cell[i]==cell[j] and i!=j)
                    conta_err++;
            }
        }
        }while(conta_err!=0);
        //risale l'albero generazionale delle n_cell cellule
        if(conta_err==0){
           ifstream in("tree.txt");
           for(int j=0; j<n_gen; j++){
                for(int i=0; i<n_fin; i++){
                    in>>a;
                    for(int k=0; k<n_cellule; k++){
                       if(i==cell[k]){
                            branch[k][j]=a;} 
                    } 
                }
            }
            for (int i=0; i<n_gen; i++)
            conta[i]=0;


        for (int i=n_gen-1; i>=0; i--){
             for (int k=0; k<n_cellule; k++){ 
                 int conta_ripetizioni=0;
                 for (int l=0; l<n_cellule; l++){
                    if(l<k){
                       if(branch[l][i]==branch[k][i]){
                          conta_ripetizioni++;
                        }
                    } //conta le coalescenze 
                    if (branch[k][i]==branch[l][i] and conta_ripetizioni==0){
                         if(l!=k)
                            conta[i]++;
                    }
                 }
             }
        }
       
       in.close();
       //stampa le coalescenze
       for(int i=0; i<n_gen; i++){
   
             out_matr <<n_cellule- conta[i] <<"      " ;
       }
   
        out_matr << endl;
    } 
    out.close();
}
out_matr.close();
*/
// ALGORITMO CHE SIMULA LA POPOLAZIONE EFFICACE E LE PROBABILITà DI AVERE 0, 1, 2 FIGLIE NELLA POPOLAZIONE EFFICACE
//////////////////////


ofstream out_vec("test_vec_50cell_N0100_1.txt"); //per l'algoritmo che testa la dimensione della popolazione efficace
ofstream out_prob("probabilita.txt"); //per l'algoritmo che testa le probabilità di avere 0, 1 o 2 figlie nella popolazione efficace
for(int n_tr=0; n_tr<n_tr_tot; n_tr++){
    P[0]=P_0;P[1]=P_1;P[2]=P_2;
        v[0]=N_0;
        for(int i=1; i<n_gen; i++){
            conta_0[i]=0;
            conta_1[i]=0;
            conta_2[i]=0;
         }
        
        do{
            for (int i=1; i<n_gen; i++){
                 v[0]=N_0;
                 const gsl_rng_type * T;
                 gsl_rng * r;
                 gsl_rng_env_setup();
                 struct timeval tv; // Seed generation based on time
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
        }while(v[n_gen-1]<=n_cellule);
         v_possibili[n_gen-1]=n_cellule;
   
         out_vec << v_possibili[n_gen-1] << "  ";
   
         for(int i= n_gen-1 ; i>0; i--){
            for (int l=0;l < v_possibili[i]; l++){
                conta_uguali=0;
                unsigned long conta_norip=0; 
                 do{
                     conta_norip=0;
                     uniform_int_distribution<> dist(1,v[i]); 
                     a_i= dist(generator);
                     for (int k=0; k< bott.size(); k++){
                         if(a_i==bott[k])
                             conta_norip++;
                     }
                 }while(conta_norip>0); 
                  c=a_i;
                  
                  if(a_i>(v_1[i-1]+v_2[i-1])){
                      c=a_i-v_2[i-1];
                  }
                  for (int k=0; k<bott_coppie.size(); k++){
                        if(c==bott_coppie[k])
                             conta_uguali+=1;
                        
                  }
                  bott.push_back(a_i);
                  bott_coppie.push_back(c);
                  if(conta_uguali==0){
                      bott_fin.push_back(a_i); 
                  }
                  if(a_i<=(v_1[i-1])){
                       conta_1[i]++;
                 }
                 if(a_i>(v_1[i-1]) and a_i<=((v_1[i-1]) +(v_2[i-1]))){
                    conta_2[i]++;
                 }
                  if(a_i>((v_1[i-1]) +2*v_2[i-1])){
                     conta_0[i]++;
                 
                 }
                 
             
               

               }
               v_possibili[i-1]=bott_fin.size();
               double intensita=double((bott.size()-bott_fin.size()))/bott.size();
               out_vec   << v_possibili[i-1]<< "   ";
               if(i>5)
               out_prob << (double)conta_0[i]/(conta_0[i]+conta_1[i]+conta_2[i])<<"  "<<  (double)conta_1[i]/(conta_0[i]+conta_1[i]+conta_2[i]) <<"  "<< (double)conta_2[i]/(conta_0[i]+conta_1[i]+conta_2[i]) << endl;
               
              bott.clear(); 
              bott_fin.clear();
              bott_coppie.clear();

             
    
      }
      out_vec << endl;
    

         }

out_vec.close();

out_prob.close();
*/
return 0;
}






