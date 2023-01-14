package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Q1Test {

    @Test
    void myQuestion() {
        int Arr[] = {1,3,4,5};
        var A = new Q1();
      assertEquals('P', A.myQuestion(Arr,Arr.length));


    }

    @Test
    void myQuestionMaxNegative() {
        int Arr[] = {-1,-3,-4,-5};

        var A = new Q1();
        assertEquals('P', A.myQuestion(Arr,Arr.length));



    }
    @Test
    void myQuestionNegative() {
        int Arr[] = {1,3,4,5};

        var A = new Q1();
        assertThrows(IllegalArgumentException.class,()->
        {
            A.myQuestion(Arr,-1);
        });

    }
    @Test
    void myQuestionZeroCase() {
        int Arr[] = {1,3,4,5};

        var A = new Q1();

        assertThrows(IllegalArgumentException.class,()->
        {
            A.myQuestion(Arr,0);
        });

    }
}