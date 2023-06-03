# 0x13-count_it

# Files

### 0. Count it!
### [0-count.py](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x13-count_it/0-count.py)

```Python
bob@dylan $ cat 0-main.py 
#!/usr/bin/python3
"""
0-main
"""
import sys

if __name__ == '__main__':
    count_words = __import__('0-count').count_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        result = count_words(sys.argv[1], [x for x in sys.argv[2].split()])
bob@dylan $             
bob@dylan $ python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4
bob@dylan $ python3 0-main.py programming 'JavA java'
java: 54
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java'
bob@dylan $ 

```

