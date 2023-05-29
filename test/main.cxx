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


// seed = chrono::system_clock::now().time_since_epoch().count();
//default_random_engine generator(seed);


ofstream out_v_i ("v_i_matr0.txt", ios::app);
ofstream out_br_short("br_short_15gen1.txt");
ofstream out_br_long("br_long_15gen1.txt");
ofstream out_out("out_4.txt", ios::app);
//ofstream albero1("albero1.txt", ios::app);
for(int n_tr=0; n_tr<n_tr_tot; n_tr++){
   
  do{  ofstream out("tree.txt");
    x=0;
   for(int y=0; y<N_0; y++){
      for( long i=0; i<n_fin/N_0; i++){
          tree[x]=y+1;
         out<< tree[x] << setw(20);
         x++;
     
      }
   }  
   out << endl;
  
      for(int l=1; l<n_gen-1; l++){
         j=0; 
         for( long m=0; m<N_0*pow(2,l); m++){
               uniform_real_distribution<double> unif_dist(0,1); 
      prob=unif_dist(generator);
    //  int contavivi=0;
      //do{
             for( long i=0; i<n_fin/(N_0*pow(2,l)); i++){
               
                    if(P_alive>prob and tree[j]!=0 ){
                      tree_new[j]=m+1;//+N_0*pow(2,l);
                    //  contavivi++;
                    }
                    else{ tree_new[j]=0;}
                    out << tree_new[j] <<setw(20);
              
               j++; 
             } 
        // }while(contavivi==0);
         }
         for( long z=0; z<n_fin; z++){tree[z]=tree_new[z];}
         out << endl;
    }
    k=0;

    for( long i=0; i<n_fin; i++){ 
         uniform_real_distribution<double> unif_dist(0,1); 
         prob=unif_dist(generator);
         if(P_alive>prob and tree[i]!=0 ){
            k++;
              tree_new[i]=k;//+N_0*pow(2,n_gen-1);
               
         }
         else {tree_new[i]=0;}
         out << tree_new[i]<< setw(20);
    } 
    out_v_i << k << endl;
   out.close();
   //cout << k-1 << endl;
   }while (k<n_cellule);

do{errore=0;
   for (int i=0; i< n_cellule; i++){
         do{ 
            uniform_int_distribution< long> unif_int(0,n_fin-1); 
            cell[i]=unif_int(generator);
          ///  cout << cell[i] << endl;
       }while(tree_new[cell[i]]==0);
      // cout << "tree senza zeri" << endl;
    //  cout << "tree!!" << tree_new[cell[i]] << "  " << tree_new[0] << "  " << tree_new[n_fin-1] << endl;
   }
   if (cell[0]==cell[1]){cout << "errore!!!"<< endl;
   errore=1;}
   if(cell[0]==cell[2]){cout << "errore!!!"<< endl;
   errore=1;}
 if(cell[1]==cell[2]) {cout << "errore!!!"<< endl;
    errore=1;}
}while(errore>0);
   if(errore==0){
          ifstream in("tree.txt");
          for( long j=0; j<n_gen; j++){
          for( long i=0; i<n_fin; i++){
            in>>a;
            if(i==cell[0]){
               branch_a[j]=a;}
            if(i==cell[1]) {
               branch_b[j]=a;}
            if(i==cell[2]){
               branch_c[j]=a;}
         } 
      }in.close();
      //cout << "cell: " << endl;
      //cout << cell[0] << "  " << cell[1] << "  " << cell[2] << "  " << endl; 
      //cout << "treee" << endl;

      for (int i=0; i<n_cellule; i++){
         conta[i]=30;
      }

      for (int i=n_gen-1; i>=0; i--){
         if (branch_a[i]!=branch_b[i]) conta[0]=i;
        cout << branch_a[i] << "  " << branch_b[i] <<"  "<<branch_c[i]<< endl;
         if (branch_b[i]!=branch_c[i]) conta[1]=i;
         if (branch_a[i]!=branch_c[i]) conta[2]=i;
      }
 cout << endl;
     // cout <<"conta: " << conta[0] << "  "<< conta[1] << "  "<< conta[2] << "  " << endl;
      
     
      
    for (int i=0; i<n_cellule; i++){
      conta[i]=n_gen-conta[i];
   }
  // cout << endl;
     // cout <<"conta: " << conta[0] << "  "<< conta[1] << "  "<< conta[2] << "  " << endl;
      
   
   mn=conta[0];
   mx=conta[0];
   for (int i=1; i<n_cellule; i++){
      if (conta[i] < mn) mn = conta[i];
      if (conta[i]> mx) mx = conta[i];
   }
   br_short+=mn;
   br_long+=(mx-mn);
if(mn<mx){
   if(mn<n_gen and mn>0){
   out_br_short << mn+1 <<"      " << n_tr <<  endl;
  // cout << "br_short " << n_tr << "  "<< mn+1 << endl;
  }
   else {
   cout << mn << "   " << mx << "  " << conta[0] << "  " << conta[1] << "  " << conta[2] << endl;}

   if(mx<n_gen and mx>0){
   out_br_long << mx+1<< setw(20) << mx-mn << endl;
   cout << "br_long " << n_tr << "  "<< mx+1 << endl;
   }
  
   }
   else{
      conta_out++;
   }
    
   }
}
//albero1.close();
out_out << conta_out <<endl;
out_v_i.close();
out_out.close();
out_br_long.close();
out_br_short.close();
*/

 ofstream out_rev("test_paper_2cell.txt");
 ofstream out("test_short_1.txt");
 for(int k=0; k<n_gen-1; k++){
 v_tot[k]=0;
 N_av[k]=0;
 }
 P[0]=P_0;
      P[1]=P_1;
      P[2]= P_2;
  for (int y=0; y<n_tr_tot; y++){
      conta1_rev=30;
      conta_rev=30;

     do{  v[0]=N_0;

     
       
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
    
        

 gsl_ran_multinomial ( r,3 ,v[i-1] , P, n_figlie);
           // binomial_distribution< unsigned long long> distr1(v[i-1], P_1);
           //  v_1[i-1]=distr1(generator); 
            v_1[i-1]=n_figlie[1];
            v_2[i-1]=n_figlie[2];
            v_0[i-1]=n_figlie[0];
            v[i]=((2*v_2[i-1])+v_1[i-1]);
            gsl_rng_free (  r );  
           
          //  cout << v[i] << "  " << v_2[i-1] << "  " <<v_1[i-1] <<  endl; 
         } 
       }while(v[n_gen-1]<n_cellule);
       //  out << v[n_gen-1] <<endl;
     // diff[1]=0;
      gen[0]=0;
      gen[1]=1;
     gen[2]=2;  

      for(int i=n_gen-1; i>0; i--){ 
      
         if (gen[0]!=gen[1] and gen[0]!=gen[2]){
           if(gen[1]!=gen[2]){
                   
                
                     uniform_int_distribution< long> dista(1,v[i]);
                     gen[0]= dista(generator);
                     do{
                     uniform_int_distribution< long> distb(1,v[i]);
                     gen[1]= distb(generator);
                     // cout <<gen[0] << "  "<< gen[1] << "  " <<i << endl;
                     }while(gen[0]==gen[1]);
                
                    do{
                     uniform_int_distribution< long > distc(1,v[i]);
                     gen[2]= distc(generator);
                     //cout <<gen[0] << "  "<< gen[1] << "  " << gen[2] << "  " <<v[i] << "  " <<v_2[i-1] << "  " << v_1[i-1] <<  endl;
                     }while(gen[0]==gen[2] or gen[2]==gen[1]);
                  
              //  cout << "prima  "   << "step= " <<conta_rev << "  "<< i << " cellula1= " << gen[0] << "  cellula2=  "<< gen[1] << "  cellula2=  "<< gen[2] << endl;
                 for (int l=0;l < n_cellule; l++){
                
                  if( gen[l]>(v_2[i-1]+v_1[i-1])){
                 // cout << "prima"  << gen[l] << "  " << v_2[i-1] << endl;
                  gen[l]=gen[l]-v_2[i-1];
                 // cout <<"dopo"  << gen[l] << endl;
                 }
               
                 }
               conta_rev=i;

          //    cout << "step= " <<conta_rev << "  "<< i << " cellula1= " << gen[0] << "  cellula2=  "<< gen[1] << "  cellula2=  "<< gen[2] << endl;
            //    cout << v[i] << "  " << v[i-1] <<"  " << y <<  endl;
         //28
       
      }
      }
      }
    //  cout << conta_rev << "  " << n_gen - conta_rev  << endl;
   // if (gen[0]==gen[1] and gen[2]==gen[1]) 
   //  gen[2]=(gen[0]+1)%v[conta_rev];
     if(gen[0]==gen[1] or gen[0]==gen[2]){
       out <<n_gen+1-conta_rev << endl;
     }
      else if( gen[2]==gen[1]){
      
       out <<n_gen +1- conta_rev << endl;
      }
    if(gen[0]==gen[1] and gen[0]==gen[2]){
        // if(conta_rev!=0){
        // cout << "err tutte e tre sono uguali!" << n_gen+1- conta_rev << "  "<< v[conta_rev] << "  "<<  endl;
        // gen[0]=gen[1];
        //  out_rev <<n_gen- conta_rev << endl;
         }
        // }
//cout <<"alla fine :  " <<  gen[0] << "  "<< gen[1]<<"  "<<  gen[2]<<endl;*//*
if (gen[0]==gen[1] and gen[0]!=gen[2]){ gen_i(0,1,2, y);}
else if (gen[0]==gen[2] and gen[0]!=gen[1]){ gen_i(0,2,1, y) ;}
else if (gen[1]==gen[2] and gen[1]!=gen[0]){ gen_i(1,2,0, y);}

    
  
  if (out_rev.eof()){
        cout << "è stata raggiunta la fine del file, esco!"<< endl;
        exit(11);
      }
    
  
  gen[0]=1;
  gen[1]=2;
  gen[2]=3;    
  }
  for(int k=0; k<n_gen-1; k++){
 cout << v_tot[k]/n_tr_tot << "  "<< N_av[k]/n_tr_tot << endl;
 
 }
   
// out_cell.close();
out_rev.close();

out.close();

return 0;
}



int factorial(int n, int b)
{
    int ret = 1;
    while (n > b)
        ret *= n--;
    return ret;
}



void gen_i(int a, int b, int c, int y) {
   int n_cell=n_cellule-1;
   //ofstream out_cell("cellule.txt",  ios:: app);
ofstream Rami_grandi("test_long_1.txt", ios::app);
//cout << "conta gen " << conta << endl;
  //out_cell << "step =  " << n_gen*n_alb- conta  << " le cellule " << a << " e " << b << " sono uguali tra loro" << endl;
       // out_cell << " ==========================================================" << endl;

    for(int i=conta_rev-1; i>0; i--){
      if ( gen[a]!=gen[c]){
      
                   
                    
                     
     // cout << "VV  " << v_1[i-1] << "   "<< v_2[i-1] << endl;
        uniform_int_distribution< long> distl(1,v[i]);
         gen[a]= distl(generator);
         do{
         uniform_int_distribution< long> distk(1,v[i]); 
         gen[c]= distk(generator);
      
         }while(gen[a]==gen[c]);
        //   cout <<"fin "<< gen[c] << "  " << gen[a] << endl;
         if(gen[a]>(v_2[i-1]+v_1[i-1])){
       
         gen[a]=gen[a]-v_2[i-1];
         }
               
          if(gen[c]>(v_2[i-1]+v_1[i-1])){
           
         gen[c]=gen[c]-v_2[i-1];  
          }   
        //scout <<"fin2 "<< gen[c] << "  " << gen[a] << endl;   
    //    cout <<" ramo " <<  v[i] << "  " << v[i-1] <<"  " << y <<  endl;
      //   cout << "step ramo= " << i  << " cellula1= " << gen[a] << "  cellula2=  "<< gen[b] << "  cellula2=  "<< gen[c] << endl;
         conta1_rev=i;
    }
}
 
                

if (gen[a]==gen[c]){
// cout << "step= " << n_gen-conta1_rev << "  tutte le cellule sono uguali tra loro"<< endl;
//out_cell << " ==========================================================" << endl;
  Rami_grandi  <<  conta_rev-conta1_rev  << setw(20) << n_gen +1-conta1_rev << endl;
  
}
    
  
Rami_grandi.close();
}
