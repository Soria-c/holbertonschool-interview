# 0x1C-island_perimeter

# Files

### 0. Island Perimeter
### [0-island_perimeter.py](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x1C-island_perimeter/0-island_perimeter.py)

```Python
guillaume@ubuntu:~/0x1C$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
island_perimeter = __import__('0-island_perimeter').island_perimeter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))

guillaume@ubuntu:~/0x1C$ 
guillaume@ubuntu:~/0x1C$ ./0-main.py
12
guillaume@ubuntu:~/0x1C$ 

```

