package org.example;
public class Bracket {
    char symbol;
    int index;

    public Bracket(char symbol, int index) {
        this.symbol = symbol;
        this.index = index;
    }

    public char getSymbol() {
        return symbol;
    }

    public int getIndex() {
        return index;
    }
}
