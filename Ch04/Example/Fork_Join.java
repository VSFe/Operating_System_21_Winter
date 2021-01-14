import java.util.concurrent.*;

@SuppressWarnings("serial")
public class Fork_Join extends RecursiveTask <Integer> {
	static final int THRESHOLD = 1000;
    private int begin;
    private int end;
    private int[] array;

    public Fork_Join(int begin, int end, int[] array) {
        this.begin = begin;
        this.end = end;
        this.array = array;
    }

    protected Integer compute() {
        if (end - begin < THRESHOLD) {
            int sum = 0;
            for (int i = begin; i <= end; i++)
                sum += array[i];
            return sum;
        } else {
            int mid = (begin + end) / 2;

            Fork_Join leftTask = new Fork_Join(begin, mid, array);
            Fork_Join rightTask = new Fork_Join(mid + 1, end, array);

            leftTask.fork();
            rightTask.fork();

            return rightTask.join() + leftTask.join();
        }
    }
}