#include <stdio.h>
#include <cmath>
#include "message.h"
#include "crates.h"

#define min(a,b) ((a>b)?b:a)

int main() {
  int numNodes = NumberOfNodes();
  int curNode = MyNodeId();
  int numStacks = GetNumStacks();
  int stackStart = ceil((double)numStacks*curNode/numNodes);
  int stackEnd = ceil((double)numStacks*(1+curNode)/numNodes);
  int myNumStacks = stackEnd-stackStart;
  int sum = 0, behindSum = 0, totalSum = 0;
  int numSteps = 0;

  // get sum
  int stacks[myNumStacks];
  for (int i=0; i<myNumStacks; i++) {
    stacks[i] = GetStackHeight(1+stackStart+i);
    sum += stacks[i];
  }

  if (numNodes == 1) {
    totalSum = sum;
  } else {
    // get behindSum
    if (curNode > 0) {
      Receive(curNode-1);
      behindSum = GetInt(curNode-1);
    }
    if (curNode < numNodes-1) {
      PutInt(curNode+1, behindSum+sum);
      Send(curNode+1);
    }

    // get totalSum
    if (curNode == numNodes-1) {
      totalSum = behindSum+sum;
      for (int i=0; i<curNode; i++) {
        PutInt(i, totalSum);
        Send(i);
      }
    } else {
      Receive(numNodes-1);
      totalSum = GetInt(numNodes-1);
    }
  }

  // get numSteps
  int desired = 0;
  int minStackHeight = totalSum/numStacks;
  int extraCrates = totalSum%numStacks;
  for (int i=0; i<myNumStacks; i++) {
    behindSum += stacks[i];
    stacks[i] = behindSum;
    desired = (1+stackStart+i)*minStackHeight + min(1+stackStart+i, extraCrates);
    numSteps += abs(behindSum-desired);
  }

  // get totalNumSteps
  if (curNode == 0) {
    for (int i=1; i<numNodes; i++) {
      Receive(i);
      numSteps += GetInt(i);
    }
    printf("%d\n", numSteps);
  } else {
    PutInt(0, numSteps);
    Send(0);
  }
}
