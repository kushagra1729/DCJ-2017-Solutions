"""
Test Generator for DCJ 2017 Online Round 1- RPS problem
Author- Kushagra Juneja
Execute :- python3 rps_gen.py -n=10 >rps.h
"""

import argparse
import random

argument = argparse.ArgumentParser()
argument.add_argument("-n")
parser = argument.parse_args()
N=int(parser.n)

print("#include <cassert>\n\n\
long long GetN() {\
")

print("  return ",N,";\n\
}\n\
\n\
char GetFavoriteMove(long long id) {\n\
  switch ((int)id) {\
")

N=2**N
arr=['R','P','S']
for i in range(0,N):
	print("    case ",i,": return '",arr[random.randint(0,2)],"' ;",sep='')

print("    default: assert(0);\n\
  }\n\
}\n\
")