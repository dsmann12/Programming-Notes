import java.util.Random;

class InsertionSort {
	public static void main(String args[]) {
		System.out.println("Hello World!");
		Random r = new Random();

		int nums[] = new int[10];
		for(int i = 0; i < nums.length; i++) {
			int n = r.nextInt(100);
			nums[i] = n;
			System.out.println(n);
		}

		//Insertion sort
		//Start at first index
		//Compare to all numbers ahead
		//if element ahead is greater than i
		//swap
		//now cur is new index
		for(int i = 1; i < nums.length; i++) {
			int n = nums[i];
			//what is j
			int j = i;
			while(j > 0 && nums[j-1] > n) {
				nums[j] = nums[--j];
			}
			nums[j] = n;
		}

		System.out.println();

		for(int n : nums) {
			System.out.println(n);
		}  
	}
}
