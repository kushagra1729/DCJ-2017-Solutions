/*
Solution code for DCJ 2017 Online Round 1- RPS problem
Author- Nikhil Reddy Ramolla & Kushagra Juneja 
Execute :- ./dcj.sh build --source=rps.cpp
		   ./dcj.sh run --executable=./rps --nodes=1 --output=all
*/

#include "message.h"
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
	int nodes = NumberOfNodes();
	int curNode = MyNodeId();
	int n= GetN() ;

	int cur=1 ;
	while(cur<=nodes){
		cur*=2 ;
	}
	cur/=2 ;
	int active=min((int)pow(2,n),cur) ;

	int serving=pow(2,n)/active;
	char arr[serving] ;
	if (curNode >= active) {	
	exit(0);
	}
	int offset=curNode*serving;
	int ids[serving];
	for(int i=0 ; i<serving ; i++){
		arr[i]=GetFavoriteMove(i+offset);
		ids[i] =i;
	}

	proceedGame(ids, arr, serving);
	int winner = offset + ids[0];
	if (curNode != 0) {
		PutInt(0, winner);
		PutChar(0, arr[ids[0]]) ;
		Send(0);
	}
	else{
		int winnerid[active] ;
		char winnerarr[active] ;
		int ids[active];
		winnerid[0]=winner ;
		winnerarr[0]=arr[winner] ;
		ids[0] = 0;
		for(int i=1 ; i<active ; i++){
			Receive(i) ;
			winnerid[i]=GetInt(i) ;
			winnerarr[i]=GetChar(i) ;
			ids[i] = i;
		}
		proceedGame(ids, winnerarr, active) ;
		cout << winnerid[ids[0]] << endl ;
	}

}