"""
demo of pypdf capabilities
"""

import tempfile
import requests
from pypdf import PdfReader


def download_pdf_from_url(link, timeout=10):
    """
    utility function to dl pdf from web
    """
    response = requests.get(link, timeout=timeout)
    with tempfile.NamedTemporaryFile(delete=False) as temp_file:
        temp_file.write(response.content)
        return temp_file.name


def print_pdf(pdf):
    """
    extracts text from the whole pdf
    """
    reader = PdfReader(pdf)
    number_of_pages = len(reader.pages)
    print(f"Number of pages is {number_of_pages}")
    for page_num in range(number_of_pages):
        page = reader.pages[page_num]
        text = page.extract_text()
        print(f"Page {page_num + 1}:")
        print(text)


def print_page(pdf):
    """
    prints one page of user's choice
    """
    reader = PdfReader(pdf)
    number_of_pages = len(reader.pages)
    print(f"Number of pages is {number_of_pages}")
    while True:
        try:
            choicen = int(input("Enter the page number to print:"))
            if choicen < 1 or choice > number_of_pages:
                raise IndexError
            break
        except (ValueError, IndexError):
            print("Invalid input. Please enter a valid number.")
    page = reader.pages[choicen - 1]
    text = page.extract_text()
    print(text)


def search_text_in_pdf(pdf, searched_text):
    """
    search text and print the line where its found
    """
    reader = PdfReader(pdf)
    number_of_pages = len(reader.pages)

    for page_num in range(number_of_pages):
        page = reader.pages[page_num]
        text = page.extract_text()
        lines = text.split("\n")
        for line_num, line in enumerate(lines, start=1):
            if search_text in line:
                print(
                    f"Found '{searched_text}' on page {page_num + 1}, line {line_num}:"
                )
                print(line)


# Usage example
pdf_urls = [
    "https://greenteapress.com/thinkdsp/thinkdsp.pdf",
    "https://makarovpa.ru/practice/familiarization-practice-IST-2023.pdf",
    "https://greenteapress.com/thinkpython2/thinkpython2.pdf",
]

print("Choose a PDF file to search:")
for i, url in enumerate(pdf_urls, start=1):
    print(f"{i}. {url}")

while True:
    try:
        choice = int(
            input("Enter the number of the PDF file you want to search: ")
        )
        if choice < 1 or choice > len(pdf_urls):
            raise IndexError
        break
    except (ValueError, IndexError):
        print("Invalid input. Please enter a valid number.")

selected_url = pdf_urls[choice - 1]
pdf_file = download_pdf_from_url(selected_url)

search_text = input("Enter the text to search: ")
search_text_in_pdf(pdf_file, search_text)

print_page(pdf_file)

# print_pdf(pdf_file)
