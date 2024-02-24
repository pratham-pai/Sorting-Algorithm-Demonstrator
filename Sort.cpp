#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

// Function prototypes
void displayMenu();
void printArray(int arr[], int n);
void printFloatArray(float arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);
void radixSort(int arr[], int n);
void countSort(std::vector<int>& arr, int exp);
void bucketSort(int arr[], int n);
void shellSort(int arr[], int n);
void cycleSort(int arr[], int n);
void gnomeSort(int arr[], int n);
void bogoSort(int arr[], int n);

int main() {
    int n;
    
    // Ask the user for the array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Check if memory allocation is successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // return with error
    }
    
    // Input values for the array
    printf("Enter %d values for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display menu
    std::cout << "Choose an option:\n";
    std::cout << "1. Execute a specific sorting algorithm\n";
    std::cout << "2. Run all sorting algorithms sequentially\n";
    
    int option;
    std::cin >> option;

    if (option == 1) {
        // Display menu for specific sorting algorithm choice
        displayMenu();

        // Get user choice
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Perform sorting based on user choice
        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                break;
            case 2:
                selectionSort(arr, n);
                break;
            case 3:
                insertionSort(arr, n);
                break;
            case 4:
                mergeSort(arr, 0, n - 1);
                break;
            case 5:
                quickSort(arr, 0, n - 1);
                break;
            case 6:
                heapSort(arr, n);
                break;
            case 7:
                radixSort(arr, n);
                break;
            case 8: 
                bucketSort(arr, n);
                break;
            case 9:
                shellSort(arr, n);
                break;
            case 10:
                cycleSort(arr, n);
                break;
            case 11:
                gnomeSort(arr, n);
                break;
            case 12:
                bogoSort(arr, n);
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }

        // Display sorted array
        std::cout << "Sorted array: \n";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    else if (option == 2) {
        std::cout << "Running all sorting algorithms sequentially:\n";
        std::cout << "-------------------------------------------\n";

        // Bubble Sort
        std::cout << "Bubble Sort: ";
        //int arrBubble[] = {34, 2, 10, -9, 20};
        //int nBubble = sizeof(arr) / sizeof(arr[0]);
        bubbleSort(arr, n);
        printArray(arr, n);

        // Selection Sort
        std::cout << "Selection Sort: ";
        //int arrSelection[] = {34, 2, 10, -9, 20};
        //int nSelection = sizeof(arr) / sizeof(arr[0]);
        selectionSort(arr, n);
        printArray(arr, n);

        // Insertion Sort
        std::cout << "Insertion Sort: ";
        //int arrInsertion[] = {34, 2, 10, -9, 20};
        //int nInsertion = sizeof(arr) / sizeof(arr[0]);
        insertionSort(arr, n);
        printArray(arr, n);

        // Merge Sort
        std::cout << "Merge Sort: ";
        //int arrMerge[] = {34, 2, 10, -9, 20};
        //int nMerge = sizeof(arr) / sizeof(arr[0]);
        mergeSort(arr, 0, n - 1);
        printArray(arr, n);

        // Quick Sort
        std::cout << "Quick Sort: ";
        //int arrQuick[] = {34, 2, 10, -9, 20};
        //int nQuick = sizeof(arr) / sizeof(arr[0]);
        quickSort(arr, 0, n - 1);
        printArray(arr, n);

        // Heap Sort
        std::cout << "Heap Sort: ";
        //int arrHeap[] = {34, 2, 10, -9, 20};
        //int nHeap = sizeof(arr) / sizeof(arr[0]);
        heapSort(arr, n);
        printArray(arr, n);

        // Radix Sort
        std::cout << "Radix Sort: ";
        //int arrRadix[] = {34, 2, 10, -9, 20};
        //int nRadix = sizeof(arr) / sizeof(arr[0]);
        radixSort(arr, n);
        printArray(arr, n);

        // Bucket Sort (with float array)
        std::cout << "Bucket Sort: ";
        //int arrBucket[] = {34, 2, 10, -9, 20};
        //int nBucket = sizeof(arr) / sizeof(arr[0]);
        bucketSort(arr, n);
        printArray(arr, n);

        // Shell Sort
        std::cout << "Shell Sort: ";
        //int arrShell[] = {34, 2, 10, -9, 20};
        //int nShell = sizeof(arr) / sizeof(arr[0]);
        shellSort(arr, n);
        printArray(arr, n);

        // Cycle Sort
        std::cout << "Cycle Sort: ";
        //int arrCycle[] = {34, 2, 10, -9, 20};
        //int nCycle = sizeof(arr) / sizeof(arr[0]);
        cycleSort(arr, n);
        printArray(arr, n);

        // Gnome Sort
        std::cout << "Gnome Sort: ";
        //int arrGnome[] = {34, 2, 10, -9, 20};
        //int nGnome = sizeof(arr) / sizeof(arr[0]);
        gnomeSort(arr, n);
        printArray(arr, n);

        // Bogo Sort
        std::cout << "Bogo Sort: ";
        //int arrBogo[] = {34, 2, 10, -9, 20};
        //int nBogo = sizeof(arr) / sizeof(arr[0]);
        bogoSort(arr, n);
        printArray(arr, n);

    }
    else {
        std::cout << "Invalid option\n";
    }

    // Freeing the dynamically allocated array
    free(arr);
    return 0;
}


// Function to display the menu
void displayMenu() {
    std::cout << "Sorting Algorithms Menu\n";
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Selection Sort\n";
    std::cout << "3. Insertion Sort\n";
    std::cout << "4. Merge Sort\n";
    std::cout << "5. Quick Sort\n";
    std::cout << "6. Heap Sort\n";
    std::cout << "7. Radix Sort\n";
    std::cout << "8. Bucket Sort\n";
    std::cout << "9. Shell Sort\n";
    std::cout << "10. Cycle Sort\n";
    std::cout << "11. Gnome Sort\n";
    std::cout << "12. Bogo Sort\n";
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


// Radix Sort
//Normal Radix Sort cannot handle negative numbers

/*int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}
*/

// Function to handle negative numbers in Radix Sort
void radixSort(int arr[], int n) {
    // Separate positive and negative numbers into separate arrays
    std::vector<int> positive, negative;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            positive.push_back(arr[i]);
        else
            negative.push_back(-arr[i]); // Make negative numbers positive for sorting
    }

    // Apply Radix Sort to positive numbers
    if (!positive.empty()) {
        int maxPositive = *max_element(positive.begin(), positive.end());
        for (int exp = 1; maxPositive / exp > 0; exp *= 10) {
            countSort(positive, exp);
        }
    }

    // Apply Radix Sort to negative numbers
    if (!negative.empty()) {
        int maxNegative = *max_element(negative.begin(), negative.end());
        for (int exp = 1; maxNegative / exp > 0; exp *= 10) {
            countSort(negative, exp);
        }
    }

    // Merge positive and negative arrays into the original array
    int posIndex = 0, negIndex = negative.size() - 1;
    for (int i = 0; i < n; i++) {
        if (i < negative.size())
            arr[i] = -negative[negIndex--]; // Restore original negative numbers
        else
            arr[i] = positive[posIndex++];
    }
}

// Modified countSort function to handle vectors
void countSort(std::vector<int>& arr, int exp) {
    std::vector<int> output(arr.size());
    std::vector<int> count(10, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}


// Bucket Sort
// Normal bucket sort code for decimal numbers
/*
void bucketSort(float arr[], int n) {
    std::vector<float> buckets[n];

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        buckets[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
*/

// Bucket sort code for integers
void bucketSort(int arr[], int n) {
    // Find the minimum and maximum elements in the array
    int min_val = *std::min_element(arr, arr + n);
    int max_val = *std::max_element(arr, arr + n);

    // Determine the range of values
    int range = max_val - min_val + 1;

    // Create buckets
    std::vector<int> buckets[range];

    // Distribute elements into buckets
    for (int i = 0; i < n; ++i) {
        buckets[arr[i] - min_val].push_back(arr[i]);
    }

    // Sort individual buckets using any sorting algorithm
    for (int i = 0; i < range; ++i) {
        if (!buckets[i].empty()) {
            std::sort(buckets[i].begin(), buckets[i].end());
        }
    }

    // Concatenate the sorted buckets to obtain the final sorted array
    int index = 0;
    for (int i = 0; i < range; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Cycle Sort
void cycleSort(int arr[], int n) {
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }
        if (pos == cycle_start) {
            continue;
        }
        while (item == arr[pos]) {
            pos++;
        }
        if (pos != cycle_start) {
            std::swap(item, arr[pos]);
        }
        while (pos != cycle_start) {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }
            while (item == arr[pos]) {
                pos++;
            }
            if (item != arr[pos]) {
                std::swap(item, arr[pos]);
            }
        }
    }
}

// Gnome Sort
void gnomeSort(int arr[], int n) {
    int index = 0;
    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}

// Bogo Sort
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        std::swap(arr[i], arr[j]);
    }
}

void bogoSort(int arr[], int n) {
    while (!isSorted(arr, n)) {
        shuffle(arr, n);
    }
}

// Function to print an integer array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}