import java.util.Random;

public class ArrayBasicOperations{

	private static int[] array;

	public ArrayBasicOperations(int sizeArray){
		setArraySize(sizeArray);
	}

	public void setArraySize(int sizeArray){
		if (sizeArray > 0 ) {
			array = new int[sizeArray];
		}
	}

	public static int getArraySize(){
		return array.length;
	}

	public static int[] getArray(){
		return array;
	}

	public static void populateArray(){
		Random rd = new Random();

		for (int i = array.length - 1;i >= 0 ;i--) {
			array[i] = rd.nextInt(800) + 1;
		}

	}

	public static void printArray(){
		for(int number : array){
			System.out.printf("|%2d",number);
		}
		System.out.printf("\n");
	}

	public static void arraySwap(int[] array ,int indexA, int indexB){
		int aux = array[indexA];
		array[indexA] = array[indexB];
		array[indexB] = aux;
	}
}