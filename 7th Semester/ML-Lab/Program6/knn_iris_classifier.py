import pandas as pd
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report, confusion_matrix

def knn_iris_classifier(k=5):
    # Load the Iris dataset
    iris = datasets.load_iris()
    X = iris.data
    y = iris.target
    target_names = iris.target_names
    
    # Split into training and testing sets (70% training, 30% testing)
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.1, random_state=22, stratify=y
    )
    
    # Standardize the features
    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_train)
    X_test_scaled = scaler.transform(X_test)
    
    # Initialize and train the k-NN classifier
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train_scaled, y_train)
    
    # Predict on test data
    y_pred = knn.predict(X_test_scaled)
    
    # Evaluate predictions
    cm = confusion_matrix(y_test, y_pred)
    cr = classification_report(y_test, y_pred, target_names=target_names)
    print("Confusion Matrix:")
    print(cm)
    print("\nClassification Report:")
    print(cr)
    
    # Identify correct and wrong predictions
    correct = y_pred == y_test
    incorrect = y_pred != y_test
    correct_indices = [i for i, c in enumerate(correct) if c]
    incorrect_indices = [i for i, c in enumerate(incorrect) if c]
    
    print("\nCorrect Predictions:")
    for i in correct_indices:
        print(f"Index {i}: Predicted={target_names[y_pred[i]]}, Actual={target_names[y_test[i]]}")
    
    print("\nWrong Predictions:")
    for i in incorrect_indices:
        print(f"Index {i}: Predicted={target_names[y_pred[i]]}, Actual={target_names[y_test[i]]}")

# Example usage
knn_iris_classifier(k=5)
