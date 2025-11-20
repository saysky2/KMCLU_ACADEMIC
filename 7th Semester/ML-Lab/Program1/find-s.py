import csv

def read_csv(file_path):
    data = []
    with open(file_path, "r") as file:
        reader = csv.reader(file)
        headers = next(reader)
        for row in reader:
            data.append(row)
    return data


def find_s_algorithm(training_data):
    hypothesis = []

    for sample in training_data:
        attributes = sample[:-1]
        label = sample[-1]

        if label.lower() == "yes":
            if not hypothesis:
                hypothesis = attributes.copy()
            else:
                for i in range(len(attributes)):
                    if hypothesis[i] != attributes[i]:
                        hypothesis[i] = "?"
    return hypothesis


file_path = "training_data.csv"  # <-- your correct path
data = read_csv(file_path)

hypothesis = find_s_algorithm(data)
print("Most specific hypothesis found:", hypothesis)
