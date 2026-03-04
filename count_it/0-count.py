#!/usr/bin/python3
"""
Module that queries the Reddit API recursively and counts
occurrences of given keywords in the titles of hot articles.
"""

from collections import Counter
import re
import requests


def count_words(subreddit, word_list, after=None, word_freq=None, counts=None):
    """
    Recursively queries the Reddit API and counts occurrences of
    keywords in the titles of hot posts for a given subreddit.
    """
    if counts is None:
        word_list = [word.lower() for word in word_list]
        word_freq = Counter(word_list)
        counts = {word: 0 for word in word_list}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"

    response = requests.get(
        url,
        headers={"User-Agent": "reddit-hot-article-keyword-counter"},
        params={"limit": 25, "after": after},
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json()

    pattern = re.compile(r"\b(" + "|".join(counts.keys()) + r")\b")

    for post in data["data"]["children"]:
        matches = pattern.findall(post["data"]["title"].lower())
        for word in matches:
            counts[word] += word_freq[word]

    after = data["data"]["after"]

    if after:
        return count_words(subreddit, word_list, after, word_freq, counts)
    else:
        for word, count in sorted(counts.items(),
                                  key=lambda item: (-item[1], item[0])):
            if count > 0:
                print(f"{word}: {count}")
        return
