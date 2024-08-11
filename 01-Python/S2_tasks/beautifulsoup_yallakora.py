import requests
from bs4 import BeautifulSoup
import pandas as pd

# URL of the website to scrape
url = 'https://www.yallakora.com'

# Send a GET request to the website
response = requests.get(url)
response.raise_for_status()  # Ensure we notice bad responses

# Parse the HTML content
soup = BeautifulSoup(response.content, 'lxml')

# Define lists to store the scraped data
match_dates = []
team_1 = []
team_2 = []
scores = []
leagues = []

# Locate the data on the website
for match in soup.find_all('div', class_='match-card'):
    league = match.find('div', class_='match-card-league').get_text(strip=True)
    for match_info in match.find_all('li', class_='match-card-item'):
        date = match_info.find('div', class_='date').get_text(strip=True)
        team1 = match_info.find('div', class_='teamA').get_text(strip=True)
        team2 = match_info.find('div', class_='teamB').get_text(strip=True)
        score = match_info.find('div', class_='MResult').get_text(strip=True)

        match_dates.append(date)
        team_1.append(team1)
        team_2.append(team2)
        scores.append(score)
        leagues.append(league)

# Create a DataFrame
df = pd.DataFrame({
    'Date': match_dates,
    'Team 1': team_1,
    'Team 2': team_2,
    'Score': scores,
    'League': leagues
})

# Save the DataFrame to an Excel file
df.to_excel('yallakora_matches.xlsx', index=False)

print("Data has been successfully scraped and saved to 'yallakora_matches.xlsx'")
