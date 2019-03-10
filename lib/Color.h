class Color {
public:

    const static int R = 9;
    const static int G = 10;
    const static int B = 11;

    static void error();
    static void set(int r, int g, int b);
};

void Color::set(int r, int g, int b) {
    analogWrite(R, r);
    analogWrite(G, g);
    analogWrite(B, b);
}

void Color::error() {
    set(255, 0, 0);
    delay(250);
    set(0,0,0);
    delay(250);
    set(255, 0, 0);
    delay(250);
    set(0,0,0);
}