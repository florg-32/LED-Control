class Color {
public:
    const static int R = 9;
    const static int G = 10;
    const static int B = 11;

    int curr[3];

    Color();

    void error();
    void set(int r, int g, int b);
    void fade(int r, int g, int b, float speed);
};

Color::Color() {
    curr[0] = 0;
    curr[1] = 0;
    curr[2] = 0;
}

void Color::set(int r, int g, int b) {
    analogWrite(R, b);
    analogWrite(G, g);
    analogWrite(B, r);
    curr[0] = r;
    curr[1] = g;
    curr[2] = b;
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

void Color::fade(int r, int g, int b, float speed) {
    float stepR = (r - curr[0]) * 1/100;
    float stepG = (g - curr[1]) * 1/100;
    float stepB = (b - curr[2]) * 1/100;

    for (int i = 0; i < 100; i++) {
        set(curr[0]+stepR, curr[1]+stepG, curr[2]+stepB);
        delay(10);
    }
}