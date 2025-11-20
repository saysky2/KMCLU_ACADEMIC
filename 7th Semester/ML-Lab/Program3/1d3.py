import math
import pandas as pd

# -----------------------------
#   Calculate Entropy
# -----------------------------
def entropy(target_col):
    elements, counts = np.unique(target_col, return_counts=True)
    entropy_val = 0
    for i in range(len(elements)):
        probability = counts[i] / sum(counts)
        entropy_val += -probability * math.log2(probability)
    return entropy_val


# -----------------------------
#   Calculate Information Gain
# -----------------------------
def info_gain(data, split_attribute_name, target_name):
    total_entropy = entropy(data[target_name])
    vals, counts = np.unique(data[split_attribute_name], return_counts=True)

    weighted_entropy = 0
    for i in range(len(vals)):
        subset = data[data[split_attribute_name] == vals[i]]
        weighted_entropy += (counts[i] / sum(counts)) * entropy(subset[target_name])

    return total_entropy - weighted_entropy


# -----------------------------
#   ID3 Algorithm
# -----------------------------
def ID3(data, original_data, features, target_attribute_name, parent_node_class=None):

    # If all target values have same value → return that value
    if len(np.unique(data[target_attribute_name])) <= 1:
        return np.unique(data[target_attribute_name])[0]

    # If dataset empty → return most common value of original dataset
    if len(data) == 0:
        return np.unique(original_data[target_attribute_name])[np.argmax(
            np.unique(original_data[target_attribute_name], return_counts=True)[1]
        )]

    # If no more features → return parent node class
    if len(features) == 0:
        return parent_node_class

    # Most common target attribute
    parent_node_class = np.unique(data[target_attribute_name])[np.argmax(
        np.unique(data[target_attribute_name], return_counts=True)[1]
    )]

    # Select the best feature
    gains = [info_gain(data, feature, target_attribute_name) for feature in features]
    best_feature = features[gains.index(max(gains))]

    tree = {best_feature: {}}

    # Remove best feature
    remaining_features = [f for f in features if f != best_feature]

    # For each value of the best feature → grow subtree
    for value in np.unique(data[best_feature]):
        sub_data = data[data[best_feature] == value]
        subtree = ID3(sub_data, original_data,
                      remaining_features,
                      target_attribute_name,
                      parent_node_class)

        tree[best_feature][value] = subtree

    return tree


# -----------------------------
#   Predict a sample
# -----------------------------
def predict(query, tree):
    for key in query.keys():
        if key in tree:
            value = query[key]
            if value in tree[key]:
                result = tree[key][value]
                if isinstance(result, dict):
                    return predict(query, result)
                else:
                    return result
    return None


# -----------------------------
#   MAIN PROGRAM
# -----------------------------
import numpy as np

# Play Tennis Dataset
data = pd.DataFrame({
    'Outlook': ['Sunny', 'Sunny', 'Overcast', 'Rain', 'Rain', 'Rain', 'Overcast', 
                'Sunny', 'Sunny', 'Rain', 'Sunny', 'Overcast', 'Overcast', 'Rain'],
    'Temperature': ['Hot', 'Hot', 'Hot', 'Mild', 'Cool', 'Cool', 'Mild', 
                    'Cool', 'Mild', 'Mild', 'Mild', 'Hot', 'Cool', 'Mild'],
    'Humidity': ['High', 'High', 'High', 'High', 'Normal', 'Normal', 'High',
                 'High', 'Normal', 'Normal', 'Normal', 'High', 'Normal', 'High'],
    'Windy': ['False', 'True', 'False', 'False', 'False', 'True', 'True',
              'False', 'False', 'False', 'True', 'True', 'False', 'True'],
    'Play': ['No', 'No', 'Yes', 'Yes', 'Yes', 'No', 'Yes', 
             'No', 'Yes', 'Yes', 'Yes', 'Yes', 'Yes', 'No']
})

features = ['Outlook', 'Temperature', 'Humidity', 'Windy']
target = 'Play'

# Build Decision Tree
tree = ID3(data, data, features, target)

print("Decision Tree:\n", tree)

# -----------------------------
#   Classify a New Sample
# -----------------------------
new_sample = {
    'Outlook': 'Sunny',
    'Temperature': 'Cool',
    'Humidity': 'High',
    'Windy': 'False'
}

prediction = predict(new_sample, tree)
print("\nPrediction for new sample:", prediction)
