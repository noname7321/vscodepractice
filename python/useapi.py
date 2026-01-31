import requests
import json
from helpers import display
def fetch_data(api_url):
    try:
        response = requests.get(api_url)
        response.raise_for_status()  # Raise an error for bad status codes
        data = response.json()
        display("Data fetched successfully.")
        return data
    except requests.exceptions.RequestException as e:
        display(f"An error occurred: {e}")
        return None