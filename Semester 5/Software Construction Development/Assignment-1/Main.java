package assign1;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        phonebook obj1 = new phonebook();
//        obj1.menu();
//        obj1.setname();
        //obj1.insert();
//       obj1.view();
        // obj1.search();
//        obj1.deleteall();
//        
        // obj1.deleteparticular();

        //   obj1.edit();
        
        int s2;
        Scanner Sc = new Scanner(System.in);
        boolean sw = true;
        if (sw) {

            obj1.menu();
            do {
                System.out.println("\n");
                s2 = Sc.nextInt();
                if (s2 == 1) {
                    obj1.insert();
                    System.out.println("\n");
                    obj1.menu();
                } else if (s2 == 2) {
                    obj1.view();
                    System.out.println("\n");
                    obj1.menu();
                } else if (s2 == 3) {
                    obj1.search();
                    System.out.println("\n");
                    obj1.menu();
                } else if (s2 == 4) {
                    obj1.edit();
                    System.out.println("\n");
                    obj1.menu();
                } else if (s2 == 5) {
                    obj1.deleteparticular();
                    System.out.println("\n");
                    obj1.menu();
                } else if (s2 == 6) {
                    obj1.deleteall();
                    System.out.println("\n");
                    obj1.menu();
                } else if (s2 == 7) {
                    System.out.println("BYE BYE ............");
                    break;
                }

            } while (sw);
        }

    }

}
