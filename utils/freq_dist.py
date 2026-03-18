import nltk
from collections import Counter
from pathlib import Path

# Download if not already present
nltk.download('gutenberg', quiet=True)
from nltk.corpus import gutenberg

PRINTABLE_ASCII_CHARS = tuple(
    chr(code_point)
    for code_point in range(32, 127)
    if not ('A' <= chr(code_point) <= 'Z')
)
OUTPUT_PATH = Path(__file__).with_name("freq_dist.csv")


def generate_printable_ascii_distribution():
    raw_text = gutenberg.raw().lower()

    printable_ascii_set = set(PRINTABLE_ASCII_CHARS)
    printable_chars = [char for char in raw_text if char in printable_ascii_set]
    char_counts = Counter(printable_chars)
    total_count = sum(char_counts.values())

    if total_count == 0:
        raise ValueError("No printable ASCII characters were found in the source corpus.")

    frequencies = [
        (char, char_counts.get(char, 0) / total_count)
        for char in PRINTABLE_ASCII_CHARS
        if char_counts.get(char, 0) > 0
    ]
    frequencies.sort(key=lambda item: item[1], reverse=True)

    lines = [f"{char}-D-{frequency}\n" for char, frequency in frequencies]
    OUTPUT_PATH.write_text("".join(lines), encoding="utf-8")

if __name__ == "__main__":
    generate_printable_ascii_distribution()