#define BLUE  1 // 0000000000000001
#define GREEN 2 // 0000000000000010
#define RED   4 // 0000000000000100

int main(void) {
    unsigned i = 0;
    i |= (BLUE | GREEN);
    i &= ~(BLUE | GREEN);
    if(i & (BLUE | GREEN)){}

    unsigned short j;
    i = 13;     // i is now 13             (binary 00000000000001101)
    j = i << 2; // left shift, j is 52     (binary 00000000000110100)
    j = i >> 2; // right shift, j is now 3 (binary 00000000000000011)

    unsigned short x;
    x = i << 2 + 1;
    x = i << (2 + 1);

    unsigned short l, j, k, notJ;
    l = 21;    // (binary 0000000000010101)
    k = ~l;    // (binary 1111111111101010)
    k = l & j; // (binary 0000000000010000)
    k = l ^ j; // (binary 0000000000101101)
    k = l | j; // (binary 0000000000111101)

    /* Symbol  Meaning
         ~     bitwise complement
         &     bitwise and
         ^     bitwise exclusive or
         |     bitwise inclusive or
    */

    i = 0x0000; // hex for 0000000000000000
    j = 0x0010; // hex for 0000000000010000
    i = i | j;  // hex for 0000000000010000

    j    = 0x0010;   // hex for 0000000000010000
    notJ = ~j;       // hex for 1111111111101111
    i    = 0x00ff;   // hex for 0000000011111111
    i    = i & notJ; // hex for 0000000011101111

    int u = 0x0050; // hex for 0000000001010000
    int g = 0x0;    // hef for 0000000000000000
    

}