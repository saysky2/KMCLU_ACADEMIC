import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score

# Define the function first
def naive_bayes_classifier(filename):
    # Load the dataset
    data = pd.read_csv(filename)

    # Separate features and target
    X = data.iloc[:, :-1]
    y = data.iloc[:, -1]

    # Split into training and testing sets (70% training, 30% testing)
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.3, random_state=42, stratify=y
    )

    # Initialize and train the Gaussian Naive Bayes classifier
    clf = GaussianNB()
    clf.fit(X_train, y_train)

    # Predict on test data
    y_pred = clf.predict(X_test)

    # Compute accuracy
    accuracy = accuracy_score(y_test, y_pred)
    print(f"Accuracy of Naïve Bayesian Classifier: {accuracy * 100:.2f}%")

    # Display detailed results
    results = pd.DataFrame({
        'Actual': y_test.values,
        'Predicted': y_pred
    })
    print("\nDetailed Classification Results:")
    print(results)

    # Calculate number of correct and wrong predictions
    correct = (y_pred == y_test).sum()
    wrong = (y_pred != y_test).sum()
    print(f"\nCorrect Predictions: {correct}")
    print(f"Wrong Predictions: {wrong}")

# Example usage
filename = r'C:\Users\10582\Desktop\ML-Lab\Program5\naive_bayes_data.csv'
naive_bayes_classifier(filename)