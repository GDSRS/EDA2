//java version: 1.8.0_121
class MergeSort{
	
 	public static void merge(int[] array, int start, int end){
 		if (start == end) {
 			return ;
 		}
 		int middle = (start + end)/2;
 		int goToCoda = middle + 1;
 		int goToMezzi = start;
 		int index = 0;

 		int [] auxArray = new int[(end - start) + 1]; 
 		//insert sort elements on auxArray
 		while(goToMezzi <= middle &&  goToCoda <= end){
 			if (array[goToMezzi] < array[goToCoda]) {
 				auxArray[index] = array[goToMezzi];
 				goToMezzi++;
 				index++;
 			}else{
 				auxArray[index] = array[goToCoda];
 				goToCoda++;
 				index++;
 			}
 		}
 		System.out.printf("Index is : %d\n",index);
 		// copy the rest of the right numbers
 		if (goToCoda <= end) {
 			while(goToCoda <= end){
 				auxArray[index] = array[goToCoda];
 				index++;
 				goToCoda++;
 			}
 		}
 		// copy the rest of the left numbers
 		if (goToMezzi <= middle) {
 			while(goToMezzi <= middle){
	 			auxArray[index] = array[goToMezzi];
	 			index++;
	 			goToMezzi++;
 				
 			}
 		}
 		// copy the elements from auxArray (sorted) to array
 		for (index = start; index <= end ; index++) {
 			array[index] = auxArray[index - start];
 		}

 	}

	public static void mergeSort(int[] array, int start, int end){
		if (start < end) {
			int middle = (start + end)/2;
			mergeSort(array,start,middle); // Calling to left
			mergeSort(array,middle+1,end); // Calling to right
			merge(array,start,end);
		}
	}

	public static void main(String[] args) {

		ArrayBasicOperations array = new ArrayBasicOperations(8);
		array.populateArray();
		array.printArray();
		System.out.printf("%d\n",array.getArraySize());
		mergeSort(array.getArray(),0,array.getArraySize() - 1);
		array.printArray();
	}
}