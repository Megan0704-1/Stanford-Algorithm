class Solution:
    def __init__(self, filename):
        self.filename = filename
        self.arr = self.read_file(filename)
        self.count = 0

    def read_file(self, filename):
        with open(filename) as f:
            arr = []
            for line in f:
                arr.append(int(line))
        return arr
    
    def find_mid(self, arr, l, r):
        diff = r-l
        if diff % 2 == 0:
            mid = l + diff // 2 - 1
        else:
            mid = l + diff // 2
        tmp = [arr[l], arr[mid], arr[r]]
        tmp = sorted(tmp)
        return tmp[1]

    def partition(self, arr, l, r):
        # when quicksort is called, the median of the first, middle and last element is the pivot
        midian = self.find_mid(arr, l, r)
        arr[l], arr[midian] = arr[midian], arr[l]
        pivot = arr[l]
        i = l + 1
        for j in range(l + 1, r + 1):
            if arr[j] < pivot:
                arr[j], arr[i] = arr[i], arr[j]
                i += 1
        arr[l], arr[i - 1] = arr[i - 1], arr[l]
        return i - 1
    
    def QuickSort(self, arr, l, r):
        if l < r:
            pi = self.partition(arr, l, r)
            self.count += (pi-1-l+1)
            self.QuickSort(arr, l, pi - 1)
            self.count += (r-pi)
            self.QuickSort(arr, pi + 1, r)

    def result(self):
        self.QuickSort(self.arr, 0, len(self.arr) - 1)
        # print(self.arr)
        return self.count
    
if __name__ == "__main__":
    arr = [3,8,2,5,1,4,7,6]
    file_name = "./assignment1.txt"
    s = Solution(file_name)
    print(s.result())