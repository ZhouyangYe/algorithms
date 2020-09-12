def swap(i, j, arr):
  temp = arr[i]
  arr[i] = arr[j]
  arr[j] = temp

def partition(low, high, arr):
  if low >= high:
    return

  pivot = high
  i = low
  for j in range(low, high + 1):
    if arr[j] < arr[pivot]:
      continue
    if i == j:
      i += 1
      continue
    swap(i, j, arr)
    i += 1

  pivot = i
  partition(low, pivot - 2, arr)
  partition(pivot, high, arr)

def quickSort(arr):
  partition(0, len(arr) - 1, arr)

arr = [1, 20, 13, 2, 8, 36, 15, 10]
quickSort(arr)
print(arr)
