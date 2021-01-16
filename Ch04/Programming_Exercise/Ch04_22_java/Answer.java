public class Answer {
    public static void main(String[] args) {
        if(args.length < 1) {
            System.out.println("usage: Answer <Integer Values>\n");
        } else {
            CalculateResult[] cal = new CalculateResult[3];
            Thread[] thrds = new Thread[3];

            for(int i = 0; i < 3; i++) cal[i] = new CalculateResult();
            
            thrds[0] = new Thread(new Summutation(args, cal[0]));
            thrds[1] = new Thread(new Maximization(args, cal[1]));
            thrds[2] = new Thread(new Minimization(args, cal[2]));

            for(int i = 0; i < 3; i++) thrds[i].start();

            try {
                thrds[0].join();
                thrds[1].join();
                thrds[2].join();

                System.out.println("The sum of " + args.length + " elements is " + cal[0].getResult());
                System.out.println("The largest value of " + args.length + " elements is " + cal[1].getResult());
                System.out.println("The smallest value of " + args.length + " elements is " + cal[2].getResult());
            } catch(InterruptedException ie) {
                ie.printStackTrace();
            }
        }
    }
}
