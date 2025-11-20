import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score, precision_score, recall_score, classification_report

def document_classification(filename):
    # Load the dataset
    data = pd.read_csv(filename)

    # Features and target
    X = data['Text']
    y = data['Class']

    # Check class distribution
    class_counts = y.value_counts()
    print("Class Distribution:")
    print(class_counts)
    if min(class_counts) < 5:
        print("\nWarning: One or more classes have very few samples. Consider adding more data.\n")

    # Preprocess the text data
    vectorizer = CountVectorizer(stop_words='english')
    X_vectorized = vectorizer.fit_transform(X)

    # Split into training and testing sets (80% training, 20% testing)
    X_train, X_test, y_train, y_test = train_test_split(
        X_vectorized, y, test_size=0.2, random_state=42, stratify=y
    )

    # Initialize and train the Multinomial Naive Bayes classifier
    clf = MultinomialNB()
    clf.fit(X_train, y_train)

    # Predict on test data
    y_pred = clf.predict(X_test)

    # Calculate metrics
    accuracy = accuracy_score(y_test, y_pred)
    precision = precision_score(y_test, y_pred, pos_label='Spam', zero_division=0)
    recall = recall_score(y_test, y_pred, pos_label='Spam', zero_division=0)

    print(f"\nAccuracy: {accuracy * 100:.2f}%")
    print(f"Precision (Spam): {precision * 100:.2f}%")
    print(f"Recall (Spam): {recall * 100:.2f}%\n")

    # Detailed classification report
    print("Classification Report:")
    print(classification_report(y_test, y_pred, target_names=['Ham', 'Spam'], zero_division=0))

    # Example: Predicting a new document
    new_docs = [
        "Congratulations, you have won a free ticket",
        "Let's discuss the project details tomorrow"
    ]
    new_docs_vectorized = vectorizer.transform(new_docs)
    new_preds = clf.predict(new_docs_vectorized)
    for doc, pred in zip(new_docs, new_preds):
        print(f"Document: \"{doc}\" --> Predicted Class: {pred}")

# Example usage
filename = r"document_classification.csv"
document_classification(filename)