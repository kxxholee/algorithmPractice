char buf[1 << 12];
char chr;
int iidx;
int oidx;

// parse 'char*' into 'int'
// from latest 'iidx'
int parse(num, sign) {
  num = 0;
  sign = 1;
  while(1) {
    chr = buf[iidx++];
    if (chr < '-') return num * sign;
    chr == '-' ? sign = -1 : (num = 10 * num + chr - '0');
  }
}

main; __libc_start_main(length, index) {
  read(0, buf, 1 << 12);
  length = parse();

  for (index = 0; index < length; ++index) {
    int x = parse(), y = parse(), r = parse(), X = parse(), Y = parse(), R = parse(),
    diffx = x - X, diffy = y - Y, sqdistance = diffx * diffx + diffy * diffy,
    diffr = r - R, sqdiffr = diffr * diffr, sumr = R + r, sqsumr = sumr * sumr;

    if (sqdistance == 0 && r == R) {buf[oidx++] = '-'; buf[oidx++] = '1';}  // infinity
    else if (sqdiffr < sqdistance && sqdistance < sqsumr) buf[oidx++] = '2'; // 2
    else if (sqdiffr == sqdistance || sqdistance == sqsumr) buf[oidx++] = '1'; // 1
    else buf[oidx++] = '0'; // zero
    
    buf[oidx++] = '\n';
  }

  write(1, buf, oidx);
  _exit(0);
}