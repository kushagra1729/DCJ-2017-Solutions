/*
Brute solver for DCJ 2017 Online Round 1- RPS problem
Author- Kushagra Juneja
Execute :- g++ rps_brute.cpp -o rps_brute
		   ./rps_brute
*/

#include "rps.h"
#include <bits/stdc++.h>
using namespace std;

bool result(char b, char a)
{
	if((a=='R' and b=='S') or (a=='S' and b=='P') or (a=='P' and b=='R')) return false ;
	return true ;// first is winner
}

void proceedGame(int ids[], char vals[], int len) {
	while(len != 1) {
		for(int i=0; i<len; i+=2) {
			if (result(vals[ids[i]], vals[ids[i+1]])) {
				ids[i/2] = ids[i];
			} else {
				ids[i/2] = ids[i+1];
			}
		}
		len = len /2;
	}
}

int main()
{
	int n=GetN() ;
	int N=1 ;
	while(n--)
		N*=2 ;

	char arr[N];
	int ids[N] ;
	for(int i=0 ; i<N ; i++){
		ids[i]=i ;
		arr[i]=GetFavoriteMove(i) ;
	}

	proceedGame(ids, arr, N) ;
	cout << ids[0] << endl ; 

}