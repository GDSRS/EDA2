import java.util.Random;

class ShellSort{

	public  static void shellSortMethod(int[] nums){
		int arraySize = nums.length;
		int arrayGap = arraySize/2;
		System.out.printf("GAP: %d\n",arrayGap);
		while(arrayGap > 0){

			for (int i = arrayGap;i < arraySize ;i++ ) {
				int value_compared = nums[i];
				int j = i;
				while((j>=arrayGap) && (nums[j - arrayGap] > value_compared)){
					nums[j] = nums[j - arrayGap];
					j = j - arrayGap;
				}
				nums[j] = value_compared;
				printArray(nums);

			}
			arrayGap = arrayGap/2;
			System.out.printf("GAP: %d\n",arrayGap);
		};
	}
// public static void quickSort(int[] arr, int low, int high) {
// 		if (arr == null || arr.length == 0)
// 			return;
 
// 		if (low >= high)
// 			return;
 
// 		// pick the pivot
// 		int middle = low + (high - low) / 2;
// 		int pivot = arr[middle];
 
// 		// make left < pivot and right > pivot
// 		int i = low, j = high;
// 		while (i <= j) {
// 			while (arr[i] < pivot) {
// 				i++;
// 			}
 
// 			while (arr[j] > pivot) {
// 				j--;
// 			}
 
// 			if (i <= j) {
// 				int temp = arr[i];
// 				arr[i] = arr[j];
// 				arr[j] = temp;
// 				i++;
// 				j--;
// 			}
// 		}
 
// 		// recursively sort two sub parts
// 		if (low < j)
// 			quickSort(arr, low, j);
 
// 		if (high > i)
// 			quickSort(arr, i, high);
// 	}

	public static void populateArray(int[] nums){
		Random rd = new Random();

		for (int i = nums.length - 1;i >= 0 ;i--) {
			nums[i] = rd.nextInt(20) + 1;
		}
		nums[nums.length - 1 ] = 0;
	}
	public static void printArray(int[] nums){
		for(int number : nums){
			System.out.printf("|%2d",number);
		}
		System.out.printf("\n");
	}
	public static void printIndex(int[] array){
		for (int i  = 0;i < array.length ;i++ ) {
			System.out.printf("|%2d",i);
		}
		System.out.printf("\n");
				for (int i  = 0;i < array.length ;i++ ) {
			System.out.printf("----");
		}
		System.out.printf("\n");
	}
	public static void main(String[] args) {
		int[] array = new int[9];
		populateArray(array);
		printIndex(array);
		printArray(array);
		shellSortMethod(array);
		printArray(array);
	}
}