"""
Test Generator for DCJ 2017 Online Round 1 - CRATES problem
Author- Nikhil Reddy Ramolla
Execute :- python3 crates_gen.py -n=10 -H=10 > crates.h
"""

import argparse
import random

argument = argparse.ArgumentParser()
argument.add_argument("-n")
argument.add_argument("-H")
parser = argument.parse_args()
numStacks=int(parser.n)
maxStackHeight = int(parser.H)

print('#include<cassert>\n')

print('long long int GetNumStacks() {\n  return %iLL;\n}\n' % numStacks)

print('long long GetStackHeight(long long i) {\n  switch((int)i) {')

for i in range(1,numStacks+1):
  print('    case %i: return %i;' % (i, random.randint(0, maxStackHeight)))

print('    default: assert(0);\n  }\n}')
