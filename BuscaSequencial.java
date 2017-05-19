import java.util.Scanner; 
import java.util.Random;

class BuscaSequencial{
	public static int sequencialSearch(int[] array, int key, int startPosition){
		for (int i = startPosition ;i < array.length ;i++ ) {
			if (array[i] == key)
				return i;
		}
		return -1;

	}

	public static int sequencialSearchIndex(int[] arrayIndex, int[] array,int key){
		for (int i = 0;i < arrayIndex.length ;i++ ) {
			if (key <= array[ arrayIndex[i] ]) {
				return arrayIndex[i - 1];
			}
		}
		return -1;
	}

	public static void generateIndex(int[] arrayIndex){
		for (int iArray = 0, iArraIndex = 0; iArraIndex < arrayIndex.length ;iArray+=5 , iArraIndex++) {
			arrayIndex[iArraIndex] = iArray;
		}
	}

	public static void populateArray(int[] nums){
		Random rd = new Random();

		for (int i = nums.length - 1;i >= 0 ;i--) {
			nums[i] = rd.nextInt(20) + 1;
		}

	}

	public static void printArray(int[] nums){
		for(int number : nums){
			System.out.printf("|%2d",number);
		}
		System.out.printf("\n");
	}

	public static void selectionSort(int[] array){
		for (int i = 0;i < array.length - 1;i++ ) {
			int index_minimun_value = i;
			for (int j = i + 1;j < array.length ;j++ ) {
				if (array[j] < array[index_minimun_value]) {
					index_minimun_value = j;
				}
			}
			if (i != index_minimun_value) {
				ArrayBasicOperations.arraySwap(array,i,index_minimun_value);
			}
		}
	}

	public static void main(String[] args) {
		int[] array = new int[20];
		populateArray(array);
		printArray(array);
		selectionSort(array);
		printArray(array);
		int [] arrayIndex = new int[4];
		generateIndex(arrayIndex);
		printArray(arrayIndex);

		Scanner scanner = new Scanner(System.in);
		int userInput = scanner.nextInt();
		int startIndex = sequencialSearchIndex(arrayIndex,array,userInput);
		int position = sequencialSearch(array,userInput,startIndex);
		System.out.printf("Position: %d\n", position);

	}
}