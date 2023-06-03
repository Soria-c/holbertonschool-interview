# 0x10-rain

# Files

### 0. Rain
### [0-rain.py](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x10-rain/0-rain.py)
Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.
- Prototype: `def rain(walls)`.
- `walls` is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
- If the list is empty return `0`.
```Python
jesse@ubuntu:~/0x10$ cat 0_main.py
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))

jesse@ubuntu:~/0x10$ 
jesse@ubuntu:~/0x10$ ./0_main.py
6
6
jesse@ubuntu:~/0x10$ 

```

Visual representation of the walls [0, 1, 0, 2, 0, 3, 0, 4]
<img src="https://holbertonintranet.s3.amazonaws.com/uploads/medias/2021/4/85ef782020ac6efdc7004b62ea86724a552285b4.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20221128%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20221128T222901Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=ca3e9e1a193da06ddaa3587719e8be4201acaf1cfe12ac2bff01512fb4685db4">

Visual representation of the walls [2, 0, 0, 4, 0, 0, 1, 0]

<img src="https://holbertonintranet.s3.amazonaws.com/uploads/medias/2021/4/9a27c3e4e214e55b3c0b8b1439fdc99b4a184ff5.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20221128%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20221128T222901Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=bf43cf44cd4488fc5a17233ab9545a17b1fc20c671c04c21e151984ea539785f">