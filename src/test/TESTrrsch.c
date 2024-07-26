void add( int a, int b, int *c ){
    *c = a + b;
}

void sub( int a, int b, int *c ){
    *c = a - b;
}

void mul( int a, int b, int *c ){
    *c = a * b;
}

void div( int a, int b, int *c ){
    *c = a / b;
}

void TEST_rrsch(void){
    void (*functions[4])(int, int, int*);

    functions[0] = add;
    functions[1] = sub;
    functions[2] = mul;
    functions[3] = div;

    int a, b, c;
    for( int i = 0; i < 4; i++ ){
        a = (i + 1)*4;
        b = (i + 1)*12;
        (*functions[i]) (a, b, &c);
    }

}