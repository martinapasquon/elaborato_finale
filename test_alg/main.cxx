   

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

ofstream out_matr("br_matr_50cell_N0100_0.8.txt", ios::app);

//ofstream albero1("albero1.txt", ios::app);
for(int n_tr=0; n_tr<n_tr_tot; n_tr++){
   ofstream out("tree.txt");
   do{
   j=0;
   for(int k=0; k<N_0; k++){
      for(int i=0; i<n_fin/N_0; i++){
        // if(P_alive>P)
          tree[j]=k+1;
        // else tree[j]=0;
         out<< tree[j] << setw(10);
         j++;
      }
   }  }while(j==0);
   out << endl;
  do{
      for(int l=1; l<n_gen-1; l++){
         j=0; 
         for(int m=0; m<N_0*pow(2,l); m++){
               uniform_real_distribution<double> unif_dist(0,1); 
      prob=unif_dist(generator);
             for(int i=0; i<n_fin/(N_0*pow(2,l)); i++){
                if(l<(n_gen-1)){
                    if(P_alive>=prob and tree[j]!=0 ){
                      tree_new[j]=m+1;//+N_0*pow(2,l);
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

    for(int i=0; i<n_fin; i++){ 
         uniform_real_distribution<double> unif_dist(0,1); 
         prob=unif_dist(generator);
         if(P_alive>=prob and tree[i]!=0 ){
              tree_new[i]=k+1;//+N_0*pow(2,n_gen-1);
               k++;
         }
         else tree_new[i]=0;
         out << tree_new[i]<< setw(10);
    } 
   out.close();
   
 }while (k<=n_cellule);
 do{
   for (int i=0; i< n_cellule; i++){
         do{
            uniform_int_distribution<int> unif_int(0,n_fin-1); 
            cell[i]=unif_int(generator);
       }while(tree_new[cell[i]]==0);
      // cout << "tree senza zeri" << endl;
     //  cout << tree_new[cell[i]] << endl;
   }
   conta_err=0;
   for (int i=0; i<n_cellule; i++){
      for (int j=i+1; j<n_cellule; j++){
         if(cell[i]==cell[j] and i!=j)
         conta_err++;
      }
   }
}while(conta_err!=0);
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
     // cout << "cell: " << endl;
     // for (int i=0; i<n_cellule; i++)
     // cout << cell[i] <<"  "; 
     // cout <<endl;
      //cout << "treee" << endl;

      for (int i=0; i<n_gen; i++)
        conta[i]=0;

      for(int l=n_gen-1; l>=0; l--){
         for(int k=0; k<n_cellule; k++){
          //   cout << branch[k][l] << "  ";

      }
    //  cout << endl;
      }

 

 for (int i=n_gen-1; i>=0; i--){
      for (int k=0; k<n_cellule; k++){ 
      int conta_ripetizioni=0;
         for (int l=0; l<n_cellule; l++){
            if(l<k){
               if(branch[l][i]==branch[k][i]){
                  conta_ripetizioni++;
               }
            }

           
            
           // cout <<"conta rip  " <<  conta_ripetizioni <<"  "<< i << "  " <<l << "  " << k <<  endl;
            if (branch[k][i]==branch[l][i] and conta_ripetizioni==0){
               if(l!=k)
                conta[i]++;
             //  cout <<i << "  "<<  conta[i] << "   " << conta_ripetizioni << endl;
            }
        // if(i==1)
        // cout <<k << "  "<<  conta[i] << "   " << conta_ripetizioni << endl;
         }
         //conta[i]=n_cellule +1-conta[i];
      }//cout << branch[k][i] << "  " ;
      
     // cout << endl;
  }
      
     
  in.close();
   

   for(int i=0; i<n_gen; i++){
   
   out_matr <<n_cellule- conta[i] <<"      " ;
 //  cout << "conta br " << n_tr << "  "<< n_cellule-conta[i]<< endl;
   }
   
   out_matr << endl;
 
}  out.close();
}
out_matr.close();


/*

          ofstream out_vec("test_vec_50cell_N0100_1.txt");
          ofstream out_v("????.txt", ios::app);
           ofstream out_prob("??.txt");
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
    
 // cout << *r << endl;
          //  cout << i << endl;
            gsl_ran_multinomial ( r,3 ,v[i-1] , P, n_figlie);
           // binomial_distribution< unsigned long long> distr1(v[i-1], P_1);
           //  v_1[i-1]=distr1(generator); 
            v_1[i-1]=n_figlie[1];
            v_2[i-1]=n_figlie[2];
            v_0[i-1]=n_figlie[0];
            v[i]=((2*v_2[i-1])+v_1[i-1]);
          //  cout << v[i] << "  " << v_0[i] << endl;
           // if(v[i]>200)
            //cout << n_figlie[1] << "  " << n_figlie[2] << "  " << n_figlie[0] << "  "<< v[i-1] << "  " << P[0]<<  endl;
            // double p=(P_2)/(P_0+P_2);
           // binomial_distribution<unsigned  long long> distr2((v[i-1]-v_1[i-1]), p);
             //v_2[i-1]=distr2(generator); 
          //out_gen_0 << v[n_gen_0 -1] << endl;   
          //   cout << v[i] << endl;
         gsl_rng_free (  r );
         }//cout << v[n_gen-1] << endl;
        }while(v[n_gen-1]<=n_cellule);
         out_v << v[n_gen-1] << endl;
       //  }while(v[n_gen-1] < n_cellule)
    v_possibili[n_gen-1]=n_cellule;
   
      
      out_vec << v_possibili[n_gen-1] << "  ";
   

       
      // v_possibili[n_gen-1]=v[n_gen-1];
      for(int i= n_gen-1 ; i>0; i--){
       

         
          for (int l=0;l < v_possibili[i]; l++){
             conta_uguali=0;
            unsigned long conta_norip=0; 
             do{
               conta_norip=0;
                     uniform_int_distribution<> dist(1,v[i]); 
                     a_i= dist(generator);
                     //cout << "a_i prima " << a_i << endl;
                     for (int k=0; k< bott.size(); k++){
                      if(a_i==bott[k])
                        conta_norip++;
                     //   cout << conta_norip<< "  " << i <<  endl;
                     }
             }while(conta_norip>0); 

                  c=a_i;
                  
                  if(a_i>(v_1[i-1]+v_2[i-1])){
                 // cout << "prima"  << gen[l] << "  " << v_2[i-1] << endl;
                  c=a_i-v_2[i-1];
                 // cout <<"dopo"  << gen[l] << endl;
                 }

                     for (int k=0; k<bott_coppie.size(); k++){
                       
                      if(c==bott_coppie[k])
                        conta_uguali+=1;
                         //cout << "ai= " << a_i << "  bott=" << bott[k] << "conta uguali= " << conta_uguali << endl;
                     }
               // cout << (a_i+1) << "  " << v_dead << "  "  << (double)v[i-1]/v[i] << "  "<<v_dead*v[i-1]/v[i] << "  "<< ((a_i+1)*v_dead*v[i-1]/v[i]) << "  " << c <<    endl;
              //  cout <<"alla fine: " <<  "  ai= " << a_i  << "conta uguali= " << conta_uguali << endl;
                  bott.push_back(a_i);
                  bott_coppie.push_back(c);
                  if(conta_uguali==0){
                bott_fin.push_back(a_i); }
                 if(a_i<=(v_1[i-1])){
                     conta_1[i]++;
                 
                 }
                 if(a_i>(v_1[i-1]) and a_i<=((v_1[i-1]) +(v_2[i-1]))){
                 // if((c-(v_1[i-1]))%2==1) 
                     conta_2[i]++;
                    // cout << conta_2[i] << endl;
                 
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
               //cout << conta_0[i]+conta_1[i]+conta_2[i] << "  "<< v_1[i-1]+v_2[i-1] << endl;
              bott.clear(); 
              bott_fin.clear();
              bott_coppie.clear();

              // cout << "step= " <<n_gen-i << " cellula1= " << gen[0] << "  cellula2=  "<< gen[1] << "  cellula2=  "<< gen[2] << endl;
    
      }
      out_vec << endl;
    

         }

out_vec.close();
out_v.close();
out_prob.close();
*/
return 0;
}







