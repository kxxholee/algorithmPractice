#include <stdio.h>

char* BI;
char* BO;

int c, I, J;

int i_stoi() {
  int n = 0, s = 1;
  for(;;) {
    c = BI[I++];
    if (c < '-') return n * s;
    c == '-' ? s = -1 : (n = 10 * n + c - '0');
  }
}

int o_itos(int n, int b) {
  n / 10 ? o_itos(n / 10, 0) : 0;
  n || b ? BO[J++] = n % 10 + 48 : 0;
}

int main(void) {
  char bi[1 << 12]; BI=bi;
  char bo[1 << 12]; BO=bo;

  read(0, BI, 1<<12);
  int L = i_stoi();

  int F[41];
  for (int i = 0; i < 41; i++) F[i] = i < 2 ? i : F[i-1] + F[i-2];

  for (int i = 0; i < L; i++) {
    int n = i_stoi();
    n < 2 ? (BO[J++]=49-n, BO[J++]=32, BO[J++]=48+n):
    (o_itos(F[n-1], 1), BO[J++]=32, o_itos(F[n], 1));
    BO[J++]=10;
  }

  write(1, BO, J);

  return 0;
}