
// MUDEI A CLASSE ARRAYBASICOPERATIONS, ATUALIZAR METODO
class SelectionSort{

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
	public static void insertionSort(int[] array){
		for (int i = 1;i < array.length ;i++ ) {
			int currentValue = array[i];
			int indexPreviousValue = i - 1;
			while((indexPreviousValue >= 0) && (array[indexPreviousValue] > currentValue) ){
				array[indexPreviousValue + 1] = array[indexPreviousValue];
				indexPreviousValue = indexPreviousValue - 1;
			}
			array[indexPreviousValue + 1] = currentValue;
		}
	}
	public static void main(String[] args) {
		ArrayBasicOperations array = new ArrayBasicOperations(20);
		array.populateArray();
		array.printArray();
		// selectionSort(array);
		insertionSort(array.getArray());
		array.printArray();
		
	}
}