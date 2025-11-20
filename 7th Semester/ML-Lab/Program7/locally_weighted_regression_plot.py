import numpy as np
import matplotlib.pyplot as plt

def locally_weighted_regression(x_train, y_train, tau, x_query):
    """
    Performs Locally Weighted Regression for a single query point.

    Parameters:
    - x_train: Training feature values (1D array)
    - y_train: Training target values (1D array)
    - tau: Bandwidth parameter
    - x_query: Query point

    Returns:
    - y_pred: Predicted value at x_query
    """
    # Compute weights using the Gaussian kernel
    weights = np.exp(- (x_train - x_query) ** 2 / (2 * tau ** 2))
    W = np.diag(weights)

    # Add a column of ones for the intercept term
    X = np.vstack((np.ones(len(x_train)), x_train)).T

    # Closed-form solution for weighted linear regression
    theta = np.linalg.pinv(X.T @ W @ X) @ (X.T @ W @ y_train)

    # Predict the output
    y_pred = theta[0] + theta[1] * x_query
    return y_pred

def plot_lwr(x_train, y_train, tau):
    # Generate query points
    x_query = np.linspace(min(x_train), max(x_train), 100)
    y_pred = np.array([locally_weighted_regression(x_train, y_train, tau, x) for x in x_query])

    # Plotting
    plt.figure(figsize=(10, 6))
    plt.scatter(x_train, y_train, color='blue', label='Training Data')
    plt.plot(x_query, y_pred, color='red', label='Locally Weighted Regression')
    plt.title(f'Locally Weighted Regression (tau={tau})')
    plt.xlabel('Feature')
    plt.ylabel('Target')
    plt.legend()
    plt.show()

def locally_weighted_regression_demo():
    # Generate synthetic data
    np.random.seed(42)
    X = np.linspace(0, 10, 100)
    y = np.sin(X) + np.random.normal(0, 0.5, 100)

    # Choose tau
    tau = 1.0  # Bandwidth parameter

    # Plot LWR
    plot_lwr(X, y, tau)

# Example usage
locally_weighted_regression_demo()
