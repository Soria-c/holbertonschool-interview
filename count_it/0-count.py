#!/usr/bin/python3
""" Count it! REDDIT API"""
from requests import get


def get_data(subreddit: str, hot_list: list, after: str) -> list:
    """Recursive function that queries the Reddit API, parses hot articles"""
    if after is None:
        return hot_list
    url = "https://www.reddit.com/r/{}/hot.json?limit=100".format(subreddit)
    res = get(url, headers={'User-Agent': 'Gozu'}, params={'after': after})
    if res.status_code != 200:
        return []
    after = res.json().get('data').get('after')
    data = res.json().get('data').get('children', [])
    for i in data:
        hot_list += (i.get('data').get('title').lower().split())
    return get_data(subreddit, hot_list, after)


def count_words(subreddit: str, word_list: list) -> None:
    """Prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count as
    javascript, but java should not)"""
    new_list = [i.lower() for i in word_list]
    hot_list = get_data(subreddit, [], "")
    current_dict = {}
    for i in new_list:
        if current_dict.get(i):
            current_dict[i] += hot_list.count(i)
        else:
            current_dict[i] = hot_list.count(i)
    new = sorted(current_dict.items(), key=lambda y: y[1], reverse=True)
    for i, j in new:
        if j != 0:
            print("{}: {}".format(i, j))


if __name__ == '__main__':
    if subreddit is not None and type(subreddit) is str:
        count_words(subreddit, word_list)
