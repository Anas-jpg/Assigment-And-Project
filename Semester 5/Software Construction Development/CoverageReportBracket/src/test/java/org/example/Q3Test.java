package org.example;

import org.junit.jupiter.api.BeforeEach;

import static org.junit.jupiter.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.assertEquals;

class Q3Test {

    @org.junit.jupiter.api.Test
    void isIntegerTrue() {

        var A = new Q3();
                assertEquals(true,A.isInteger("3"));
    }

    @org.junit.jupiter.api.Test
    void isIntegerFalse() {

        var A = new Q3();
        assertEquals(false,A.isInteger("abc"));
    }
    @org.junit.jupiter.api.Test
    void isInteger0() {

        var A = new Q3();
        assertEquals(false,A.isInteger(null));
    }

    @org.junit.jupiter.api.Test
    void balancer() {
        var A = new Q3();
        A.balancer(1,"2+2*1");

        // Null Cases Equation and Edge Cases
        assertThrows(IllegalArgumentException.class,()->
        {
            A.balancer(0,"");
            A.balancer(-1,"2+2*1");
        });

    }

    @org.junit.jupiter.api.Test
    void mytempBalanceFalseCase() {
        var A = new Q3();
        assertEquals(false,A.mytempBalance("}}})()(2+2)*2"));

    }
    @org.junit.jupiter.api.Test
    void mytempBalanceFalseCase2() {
        var A = new Q3();
        assertEquals(false,A.mytempBalance("(]}}]]"));

    }

    @org.junit.jupiter.api.Test
    void mytempBalanceFalseCase3() {
        var A = new Q3();
        assertEquals(false,A.mytempBalance("(}]}]"));

    }

    @org.junit.jupiter.api.Test
    void mytempBalanceFalseCase4() {
        var A = new Q3();
        assertEquals(false,A.mytempBalance("{)]}]"));

    }

    @org.junit.jupiter.api.Test
    void method1() {

        var A = new Q3();
        assertEquals('*',A.method1("2*2*2"));
        assertEquals('+',A.method1("2+2+2"));
        assertEquals('F',A.method1("2/0/0"));
      //  assertEquals('/',A.method1("10/10"));
        assertEquals('-',A.method1("2-1-2"));

    }

    @org.junit.jupiter.api.Test
    void bracketMultiply() {
        var A = new Q3();
        assertEquals('P', A.bracketMultiply(")("));
        assertEquals('F', A.bracketMultiply("()"));

    }

    @org.junit.jupiter.api.Test
    void myQuestion() {

        var A = new Q3();
        try {
            assertEquals('P', A.myQuestion("2+2*2"));
        }
        catch (NullPointerException e)
        {
            System.out.println("Is NULL");
        }
    }


    @org.junit.jupiter.api.Test
    void convertIntoHash() {
    }

    @org.junit.jupiter.api.Test
    void toPostfix() {
        var A = new Q3();

        //assertEquals("2+2+4",A.toPostfix(1,"(2+2+4)"));
       // assertEquals("a+b+c",);
        A.toPostfix(1,"(a+b+c)");
        A.toPostfix(1,"((1+2+3))");
        A.toPostfix(1,"{(1+2+3)}");
        A.toPostfix(1,"[(1+2+3)]");
        A.toPostfix(1,"[(1+2+3)]");
    }

    @org.junit.jupiter.api.Test
    void precPlusMinus() {

        var A = new Q3();
        assertEquals(1,A.prec('+'));
        assertEquals(1,A.prec('-'));
    }

    @org.junit.jupiter.api.Test
    void precMulDivRemndr() {

        var A = new Q3();
        assertEquals(2,A.prec('*'));
        assertEquals(2,A.prec('/'));
        assertEquals(2,A.prec('%'));
    }
    @org.junit.jupiter.api.Test
    void precEdgeCases() {

        var A = new Q3();
        assertEquals(0,A.prec('A'));
        assertEquals(0,A.prec('&'));
        assertEquals(0,A.prec('1'));
    }

}