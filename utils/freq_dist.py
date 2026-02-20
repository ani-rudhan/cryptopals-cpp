import nltk
from collections import Counter
import string

# Download if not already present
nltk.download('gutenberg', quiet=True)
from nltk.corpus import gutenberg

def analyze_with_whitespace():
    # Load raw text from the Gutenberg corpus
    raw_text = gutenberg.raw()
    
    # Define our allowed characters: a-z plus whitespace
    # We use a set for O(1) lookup speed
    allowed = set(string.ascii_lowercase + ' ')
    
    # Process text: lowercase it once, then filter
    # Using a generator expression to be memory efficient
    filtered_chars = (char for char in raw_text.lower() if char in allowed)
    
    counts = Counter(filtered_chars)
    total = sum(counts.values())
    
    # Sort by frequency descending
    most_common = counts.most_common() 
    
    print(f"{'Character':<15} | {'Frequency (%)':<10}")
    print("-" * 30)
    
    with open("freq_dist.csv", "w") as file:
        for char, count in most_common:
            # Make whitespace visible in the printout
            display_char = repr(char) if char in string.whitespace else char
            percentage = (count / total)
            line = display_char + ',' + str(percentage) + '\n'
            file.write(line)
            # print(f"{display_char:<15} | {percentage:>10.2f}%")

if __name__ == "__main__":
    analyze_with_whitespace()