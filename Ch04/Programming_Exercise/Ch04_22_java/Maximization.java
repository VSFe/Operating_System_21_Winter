public class Maximization extends Thread {
    private String[] calculates;
    private CalculateResult maxValue;

    public Maximization(String[] args, CalculateResult maxValue) {
        this.calculates = args;
        this.maxValue = maxValue;
    }

    public void run() {
        int max = Integer.MIN_VALUE;
        for(String number : this.calculates) {
            max = Integer.max(Integer.parseInt(number), max);
        }
        maxValue.setResult(max);
    }    
}
