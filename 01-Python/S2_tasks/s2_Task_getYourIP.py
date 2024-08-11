import requests


IP = requests.get("https://api.ipify.org/?format=json")

print(IP.content)








