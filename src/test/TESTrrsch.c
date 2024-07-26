int add( int a, int b ){
    return a + b;
}

int sub( int a, int b ){
    return a - b;
}

int mul( int a, int b ){
    return a * b;
}

int div( int a, int b ){
    return a / b;
}

void TEST_rrsch(void){
    int (*functions[4])(int, int);

    functions[0] = add;
    functions[1] = sub;
    functions[2] = mul;
    functions[3] = div;

    int a, b, c;
    for( int i = 0; i < 4; i++ ){
        a = (i + 1)*4;
        b = (i + 1)*12;
        c = (*functions[i]) (a, b);
    }

}