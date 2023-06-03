# 0x16-rotate_2d_matrix

# Files

### 0. Rotate 2D Matrix
### [0-rotate_2d_matrix.py](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x16-rotate_2d_matrix/0-rotate_2d_matrix.py)

```Python
jessevhedden$ cat main_0.py
#!/usr/bin/python3
"""
Test 0x16 - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix)
    print(matrix)

jessevhedden$
jessevhedden$ ./main_0.py
[[7, 4, 1],
[8, 5, 2],
[9, 6, 3]]
jessevhedden$

```

