import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

# Get CSV file from the same folder as this Python file
file_path = Path(__file__).with_name("sorting_times.csv")

# Read CSV
data = pd.read_csv(file_path)

print(data)

# Plot graph
plt.bar(data["Algorithm"], data["Time"])

plt.xlabel("Sorting Algorithm")
plt.ylabel("Execution Time (seconds)")
plt.title("Comparison of Sorting Algorithms")

plt.xticks(rotation=20)
plt.tight_layout()

plt.show()