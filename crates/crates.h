#include<cassert>

long long int GetNumStacks() {
  return 10LL;
}

long long GetStackHeight(long long i) {
  switch((int)i) {
    case 1: return 5;
    case 2: return 6;
    case 3: return 1;
    case 4: return 5;
    case 5: return 1;
    case 6: return 5;
    case 7: return 4;
    case 8: return 5;
    case 9: return 6;
    case 10: return 7;
    default: assert(0);
  }
}
