import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
from sklearn.mixture import GaussianMixture
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt

# -----------------------------
# 1. Load the dataset
# -----------------------------
data = pd.read_csv("data.csv")   

# Select only numeric columns
X = data.select_dtypes(include='number')

# Normalize data
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# -----------------------------
# 2. K-Means Clustering
# -----------------------------
k = 3   # set clusters, or choose using elbow method

kmeans = KMeans(n_clusters=k, random_state=42)
kmeans_labels = kmeans.fit_predict(X_scaled)

sil_kmeans = silhouette_score(X_scaled, kmeans_labels)
print("Silhouette Score (K-Means):", sil_kmeans)

# -----------------------------
# 3. EM Algorithm → Gaussian Mixture Model
# -----------------------------
gmm = GaussianMixture(n_components=k, random_state=42)
gmm_labels = gmm.fit_predict(X_scaled)

sil_gmm = silhouette_score(X_scaled, gmm_labels)
print("Silhouette Score (EM / GMM):", sil_gmm)

# -----------------------------
# 4. Visualization (2D PCA)
# -----------------------------
from sklearn.decomposition import PCA

pca = PCA(n_components=2)
components = pca.fit_transform(X_scaled)

plt.figure(figsize=(12,5))

# K-Means plot
plt.subplot(1,2,1)
plt.scatter(components[:,0], components[:,1], c=kmeans_labels)
plt.title("K-Means Clustering")
plt.xlabel("PC1")
plt.ylabel("PC2")

# GMM / EM plot
plt.subplot(1,2,2)
plt.scatter(components[:,0], components[:,1], c=gmm_labels)
plt.title("EM Algorithm (Gaussian Mixture Model)")
plt.xlabel("PC1")
plt.ylabel("PC2")

plt.show()
