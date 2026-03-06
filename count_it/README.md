# Count It! — Reddit API Keyword Counter

## Description

This project implements a recursive Python function that queries the Reddit API and counts occurrences of given keywords in the titles of hot posts from a specified subreddit.

The function retrieves posts using pagination and recursively processes all available pages. It then prints a sorted count of keyword occurrences found in the titles.

The matching is case-insensitive and only counts full words (e.g., java will not match javascript).

## Requirements

- Python 3.x
- `requests` library

## Function Prototype

def count_words(subreddit, word_list)

### Parameters

- subreddit (str)
The subreddit to query.

- word_list (list)
List of keywords to search for in post titles.

## Behavior

Queries the Reddit API endpoint:

- https://www.reddit.com/r/<subreddit>/hot.json

Uses recursive calls to process all pages of results.

Counts how many times each keyword appears in post titles.

- Keywords are matched case-insensitively.

- Only full word matches are counted.

### Example:

javascript → counted
java → NOT counted inside "javascript"

- If duplicate keywords appear in word_list, their counts are combined.

### Example:

["java", "Java"]

will count all occurrences of java twice.

## Output Rules

The results are printed:

- Sorted by count (descending)

- Alphabetically (ascending) when counts are equal

- Only keywords with occurrences > 0 are printed

- All words are printed in lowercase

### Example output:

- python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'

java: 27
javascript: 20
python: 17
react: 17
scala: 4

- python3 0-main.py programming 'JavA java'

java: 54

- python3 0-main.py not_a_valid_subreddit 'python java'



### Error Handling

If the subreddit is invalid or inaccessible, nothing is printed.

Redirects are disabled to avoid false results from Reddit search pages.

## Author

Alexis BILLEMONT — Algorithm Projects — Holberton School
