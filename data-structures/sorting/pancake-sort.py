def flip(self, arr: list[int], end: int):
        start = 0
        while start <= end:
            arr[start], arr[end] = arr[end], arr[start]
            start += 1
            end -= 1
    def pancakeSort(self, arr: list[int]) -> list[int]:
        length = len(arr)
        placeholder = length - 1
        flips = []
        while placeholder > 0:
            maxVal = 0
            for i in range(placeholder+1):
                if arr[maxVal] < arr[i]:
                    maxVal = i
            if maxVal == 0:
                self.flip(arr, placeholder)
                flips.append(placeholder+1)
            elif maxVal < placeholder:
                self.flip(arr, maxVal)
                flips.append(maxVal+1)
                self.flip(arr, placeholder)
                flips.append(placeholder+1)
            placeholder -= 1
        print(arr)
        return flips