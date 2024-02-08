char* W, *R;
int* F;
c, I, J, i, j;

U(n, s){
  n=0,s=1;
  for(;;){
    c=R[I++];
    if(c<45)return n*s;
    c==45 ? s=-1 : (n = 10 * n + c - '0');
  }
}

V(n,b) {
  n/10?V(n/10,0):0;
  n||b?W[J++]=n%10+48:0;
}

main; __libc_start_main(L,n) {
  char w[1<<12];W=w;
  char r[1<<12];R=r;
  int f[41];F=f;
  read(0, R, 1<<9);
  L=U();
  while(j++<41)F[j-1]=j<3?j-1:F[j-2]+F[j-3];
  while(i++<L) {
    n=U();
    n<2?(W[J++]=49-n,W[J++]=32,W[J++]=48+n):
    (V(F[n-1],1),W[J++]=32,V(F[n],1));
    W[J++]=10;
  }
  write(1, W, J);
  _exit(0);
}
