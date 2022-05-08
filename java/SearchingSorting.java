import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.function.Supplier;
import java.util.stream.Collectors;

public class SearchingSorting {
    public static int[] bubbleSort(int[] arr) {
        int length = arr.length;
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; i < length; i++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr;
    }

    public static int[] selectionSort(int[] arr) {
        int length = arr.length;
        for (int i = 0; i < length - 1; i++) {
            int minValue = arr[i], minIndex = i;
            for (int j = i + 1; j < length; j++) {
                if (arr[j] < minValue) {
                    minValue = arr[j];
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return arr;
    }

    public static int[] countSort(int[] arr) {
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (int i : arr) {
            if (freqMap.containsKey(i)) {
                freqMap.put(i, freqMap.get(i) + 1);
            } else {
                freqMap.put(i, 1);
            }
        }
        int index = 0;
        for (int i : freqMap.keySet()) {
            for (int e = 0; e < freqMap.get(i); e++) {
                arr[index++] = i;
            }
        }
        return arr;
    }

    public static void display(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static int linearSearch(int arr[], int key) {
        for (int i : arr) {
            if (i == key) {
                return i;
            }
        }
        return -1;
    }

    public static int binarySearch(int[] arr, int key) {
        int low = 0;
        int high = arr.length - 1;
        while(low <= high && key >= arr[low] && key <= arr[high]) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    public static int interpolationearch(int[] arr, int key) {
        int low = 0;
        int high = arr.length - 1;
        while(low <= high && key >= arr[low] && key <= arr[high]) {
            int pos = low + (key - arr[low]) / (arr[high] - arr[low]) * (high - low);
            if (arr[pos] == key) {
                return pos;
            } else if (key < arr[pos]) {
                high = pos - 1;
            } else {
                low = pos + 1;
            }
        }
        return -1;
    }

    public static int[] arraySort(int[] arr) {
        Arrays.sort(arr);
        return arr;
    }

    public static int[] inputArray() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inArr = br.readLine().split(" ");
        int[] arr = new int[inArr.length];
        int i = 0;
        for (String str: inArr) {
            arr[i] = Integer.parseInt(str);
        }
        return arr;
    }

    public static void main(String[] args) {

    }
}
