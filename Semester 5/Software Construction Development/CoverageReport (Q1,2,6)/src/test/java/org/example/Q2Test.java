package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Q2Test {

    @Test
    void myQuestion() {
        var A = new Q2();
        assertEquals('P', A.myQuestion(1,1,2012));
    }
    @Test
    void myQuestionF() {
        var A = new Q2();

        assertThrows(IllegalArgumentException.class,()->
        {
            A.myQuestion(1,1,1000000000);
        });
    }
}