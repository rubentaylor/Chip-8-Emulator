class Chip8 {

private:
    unsigned short opcode; // 2 bytes, 8 bits
    unsigned char memory[4096]; // 4k memory

    unsigned char R[16]; // Chip 8 has 16 8-bit registers
    unsigned short I; // Index register
    unsigned short pc; // Program counter

    unsigned char gfx[64 * 32]; // pixel state / window

    unsigned char delay_timer;
    unsigned char sound_timer;

    unsigned short stack[16]; 
    unsigned short stack_pointer; // stack pointer

    unsigned char key[16]; // hex based keypad

public:
    Chip8();
    ~Chip8();

    bool drawFlag;

    void emulateCycle();
    bool loadApplication(const char * filename);
    void setKeys();
};