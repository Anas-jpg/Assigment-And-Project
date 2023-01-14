package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Q6Test {

    @Test
    void setArray() {

        int Arr[] = {1,3,4,5};
        var A = new Q6();
       assertEquals('P',A.setArray(Arr.length,Arr));

    }

    @Test
    void setArrayZerSize() {

        int Arr[] = {1,3,4,5};

        var A = new Q6();
        assertThrows(IllegalArgumentException.class,()->
        {
            A.setArray(0,Arr);
        });

    }

    @Test
    void printerValid() {

        int Arr[] = {1,3,4,5};

        var A = new Q6();
        assertEquals('P',A.printer(Arr.length,Arr));
    }

    @Test
    void printerInvalid() {
        int Arr[] = {1,3,4,5};
        var A = new Q6();
        assertThrows(IllegalArgumentException.class,()->
        {
            A.printer(-1,Arr);
        });

    }

    @Test
    void arraySwapperIthNegtive() {
        var A = new Q6();
        int Arr[] = {1,3,4,5};
        assertThrows(IllegalArgumentException.class,()->
        {
            A.arraySwapper(-1,1,Arr);
        });

    }

    @Test
    void arraySwapperJthNegtive() {
        var A = new Q6();
        int Arr[] = {1,3,4,5};
        assertThrows(IllegalArgumentException.class,()->
        {
            A.arraySwapper(1,-1,Arr);
        });

    }

    @Test
    void arraySwapper() {
        var A = new Q6();
        int Arr[] = {1,3,4,5};
        assertEquals('P',A.arraySwapper(1,1,Arr));
    }

    @Test
    void mySort() {
        var A = new Q6();
        int Arr[] = {1,3,4,5};
        assertEquals('P', A.mySort(Arr,0,3));
    }
}