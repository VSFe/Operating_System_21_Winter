public class Summutation extends Thread {
    private String[] calculates;
    private CalculateResult sumValue;

    public Summutation(String[] args, CalculateResult sumValue) {
        this.calculates = args;
        this.sumValue = sumValue;
    }

    public void run() {
        int sum = 0;
        for(String number : this.calculates) {
            sum += Integer.parseInt(number);
        }
        sumValue.setResult(sum);
    }
}
