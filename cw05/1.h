#ifndef _1_h
#define _1_h

struct ulamek {
    int l;
    int m;
};

ulamek add(ulamek a, ulamek b);
ulamek sub(ulamek a, ulamek b);
ulamek mul(ulamek a, ulamek b);
ulamek div(ulamek a, ulamek b);
ulamek pow(ulamek a, int n);
ulamek skroc(ulamek a);
void print(ulamek a);
ulamek get();

#endif
