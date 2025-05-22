#include <iostream>
using namespace std;
int main()
{ int i,j, n=7, x[7]={7,23,4,29,11,9,14};
  cout <<"Data Sebelum diurutkan:\n"; 
  for(i=0; i<n; i++){
	cout <<x[i]<<" "; 
  }
 for(i=0; i<n-1; i++){
    for(j=i+1; j<n; j++){
        if(x[i]>x[j]){
	      swap(x[i],x[j]);    // Tukar posisi
        }   
    }
  }  
  cout <<"\n\nData Setelah diurutkan:\n";
  for(i=0; i<n; i++){
	cout <<x[i]<<" "; 
  }
  cout <<"\n\n";
  system("pause");
}
