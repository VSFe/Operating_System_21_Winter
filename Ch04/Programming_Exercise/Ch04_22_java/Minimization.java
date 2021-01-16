public class Minimization extends Thread {
    private String[] calculates;
    private CalculateResult minValue;

    public Minimization(String[] args, CalculateResult minValue) {
        this.calculates = args;
        this.minValue = minValue;
    }

    public void run() {
        int min = Integer.MAX_VALUE;
        for(String number : this.calculates) {
            min = Integer.min(Integer.parseInt(number), min);
        }
        minValue.setResult(min);
    }    
}
