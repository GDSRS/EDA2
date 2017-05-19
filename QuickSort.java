import java.util.Random;

class QuickSort{

	/*public static void populateArray(int[] nums){
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
	}*/

	public static void quickSort(int[] array, int startArray, int endArray){
		if (array == null || array.length == 0) {return;}
		if (startArray >= endArray) {return;}

		int beginning = startArray;
		int finale = endArray;
		int pivot = array[(startArray+endArray)/2];
		System.out.printf("Pivot: %d\ntheBeginning:%d\ntheEnd:%d\n",pivot,array[beginning],array[finale]);

		while(beginning <= finale){
			while(array[beginning] < pivot){beginning++;}
			while(array[finale] > pivot){finale--;}
			if (beginning <= finale) {
				int aux = array[beginning];
				array[beginning] = array[finale];
				array[finale] = aux;
				beginning++;
				finale--;
				ArrayBasicOperations.printArray(array);
			}
		}
		if (finale > startArray) { quickSort(array,startArray,finale); }
		if(beginning < endArray){ quickSort(array,beginning,endArray); }
	}

	public static void main(String[] args) {
		int[] array = new int[20];
		ArrayBasicOperations.populateArray(array);
		ArrayBasicOperations.printArray(array);
		quickSort(array,0,array.length-1);
		ArrayBasicOperations.printArray(array);
	}
}